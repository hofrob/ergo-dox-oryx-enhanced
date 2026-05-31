import tempfile
import contextlib
import subprocess
import shutil
import zipfile
import fnmatch
import rich
import pathlib

import os

import requests
import yaml
import cyclopts

REPO_ROOT = pathlib.Path(__file__).parent.parent.parent
QMK_FIRMWARE = REPO_ROOT / "qmk_firmware"
WORKFLOW_YAML = REPO_ROOT / ".github" / "workflows" / "fetch-and-build-layout.yml"
TEMP_DIR = REPO_ROOT / "temp"
LAYOUT_SRC = TEMP_DIR / "source.zip"
QUERY = """
query getLayout($hashId: String!, $revisionId: String!, $geometry: String) {
  layout(hashId: $hashId, geometry: $geometry, revisionId: $revisionId) {
    revision { hashId, qmkVersion, title }
  }
}
"""

app = cyclopts.App()


@app.command
def main() -> None:
    config_layout = _config_layout()
    variables = {
        "hashId": config_layout["id"],
        "geometry": config_layout["geometry"],
        "revisionId": "latest",
    }

    response = requests.post(
        "https://oryx.zsa.io/graphql",
        json={"query": QUERY, "variables": variables},
        timeout=5,
    )
    response.raise_for_status()

    hash_id, qmk_version, title = _layout_details()

    os.chdir(REPO_ROOT)
    _commit_oryx(hash_id, config_layout["id"])
    _update_qmk(qmk_version)

    _build_qmk(config_layout["id"], config_layout["geometry"])
    subprocess.run(
        [
            "zapp",
            "flash",
            REPO_ROOT / "qmk_firmware" / "zsa_ergodox_ez_m32u4_glow_5Lplq.hex",
        ],
        check=True,
    )


def _layout_details() -> tuple:
    config_layout = _config_layout()
    variables = {
        "hashId": config_layout["id"],
        "geometry": config_layout["geometry"],
        "revisionId": "latest",
    }

    response = requests.post(
        "https://oryx.zsa.io/graphql",
        json={"query": QUERY, "variables": variables},
        timeout=5,
    )
    response.raise_for_status()

    revision = response.json()["data"]["layout"]["revision"]
    hash_id = revision["hashId"]
    qmk_version = revision["qmkVersion"].split(".", 1)[0]
    title = revision["title"]

    rich.print(revision)

    return hash_id, qmk_version, title


@app.command
def build_qmk() -> None:
    config_layout = _config_layout()
    _build_qmk(config_layout["id"], config_layout["geometry"])


def _build_qmk(layout_id: str, geometry: str) -> None:
    keyboard_directory = REPO_ROOT / "qmk_firmware/keyboards/zsa"
    keymaps = keyboard_directory / geometry / "keymaps"
    os.chdir(REPO_ROOT / "docker")
    _docker(
        "build",
        "-t",
        "qmk",
        ".",
    )
    os.chdir(REPO_ROOT)
    subprocess.run(["rm", "-rf", keymaps / layout_id])
    keymaps.mkdir(exist_ok=True)
    subprocess.run(["cp", "-r", str(REPO_ROOT / layout_id), str(keymaps)])
    _docker(
        "run",
        "-v",
        "./qmk_firmware:/app",
        "--rm",
        "qmk",
        "make",
        f"zsa/{geometry}:{layout_id}",
    )


def _git(*args) -> None:
    subprocess.run(["git", *args], check=True)


def _docker(*args) -> None:
    subprocess.run(["docker", *args], check=True)


def _pending_changes(layout_id: str) -> bool:
    pending_changes = True
    with contextlib.suppress(subprocess.CalledProcessError):
        _git("diff", "--cached", "--quiet", "--", layout_id)
        _git("diff", "--quiet", "--", layout_id)
        pending_changes = False

    return pending_changes


def _commit_oryx(hash_id: str, layout_id: str) -> None:
    if _pending_changes(layout_id):
        raise Exception("pending changes in the layout. commit first")
    with tempfile.TemporaryDirectory() as temp_dir:
        rich.print(f"oryx worktree checked out in {temp_dir}")
        _git(
            "worktree",
            "prune",
        )
        _git(
            "worktree",
            "add",
            temp_dir,
            "oryx",
        )
        os.chdir(temp_dir)
        _get_sources(temp_dir, hash_id, layout_id)
        _git("add", layout_id, temp_dir)
        try:
            _git("commit", "-m", "latest oryx", "--no-verify")
        except subprocess.CalledProcessError:
            rich.print("commit failed. press enter to continue")
        _git("worktree", "remove", temp_dir)
    input()
    os.chdir(REPO_ROOT)
    _git("merge", "--no-edit", "-Xignore-all-space", "oryx")


def _get_sources(temp_dir: str, hash_id: str, layout_id: str) -> None:
    TEMP_DIR.mkdir(exist_ok=True)
    response = requests.get(f"https://oryx.zsa.io/source/{hash_id}", timeout=10)

    with LAYOUT_SRC.open("wb") as layout_src:
        layout_src.write(response.content)

    with zipfile.ZipFile(LAYOUT_SRC) as zf:
        for info in zf.infolist():
            if info.is_dir():
                continue
            if not fnmatch.fnmatchcase(info.filename, "*_source/*"):
                continue

            target = (
                pathlib.Path(temp_dir) / layout_id / pathlib.Path(info.filename).name
            )
            with zf.open(info) as src, target.open("wb") as out:
                shutil.copyfileobj(src, out)


def _update_qmk(firmware_version: str) -> None:
    _git("submodule", "update", "--init", "--remote", "--depth=1", "--no-single-branch")
    os.chdir(QMK_FIRMWARE)
    _git(
        "checkout",
        "-B",
        f"firmware{firmware_version}",
        f"origin/firmware{firmware_version}",
    )
    _git("submodule", "update", "--init", "--recursive")
    os.chdir(REPO_ROOT)
    _git("add", "qmk_firmware")
    with contextlib.suppress(subprocess.CalledProcessError):
        _git("commit", "-m", "qmk firmware update")


def _config_layout() -> dict:
    inputs = config()["on"]["workflow_dispatch"]["inputs"]
    id_ = inputs["layout_id"]["default"]
    geometry = inputs["layout_geometry"]["default"]

    return {"id": id_, "geometry": geometry}


@app.command
def config() -> dict:
    with WORKFLOW_YAML.open("r") as workflow_yaml:
        workflow = yaml.safe_load(workflow_yaml)

    return workflow


def run() -> None:
    app()
