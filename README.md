# ErgoDox EZ — Layout & Shortcut Reference

Documentation of every shortcut, macro, combo, and dual-role key defined in this
QMK layout ([`5Lplq/keymap.c`](5Lplq/keymap.c)).

The layout is authored in [ZSA Oryx](https://oryx.zsa.io) (base layers, colors,
layer-taps) and then **enhanced by hand** in `keymap.c` with combos, key
overrides, custom dual-function keys, and a Magic-SysRq combo. The Python tool in
[`src/oryx`](src/oryx/main.py) pulls the latest Oryx revision, rebuilds the QMK
firmware in Docker, and flashes it.

## Notation

| Symbol | Meaning |
| --- | --- |
| **Super** | GUI / Win / Cmd key (`KC_LGUI` / `KC_RGUI`) |
| **Meh** | Ctrl + Alt + Shift (`LCTL(LSFT(LALT(...)))`) |
| **Hyper** | Ctrl + Alt + Shift + Super (`LALT(LGUI(LCTL(LSFT(...))))`) |
| **MT** | Mod-Tap — tap = key, hold = modifier |
| **LT** | Layer-Tap — tap = key, hold = momentary layer |
| **OSL** | One-Shot Layer — next keypress comes from that layer |
| `→` | "then" (keys sent in sequence by a macro) |

______________________________________________________________________

## 1. Layers & how they are reached

Seven layers are defined (`[0]`–`[6]`). The RGB underglow color changes per
layer, and the three right-hand indicator LEDs encode the active layer in binary.

| Layer | Purpose (inferred) | How to reach it |
| --- | --- | --- |
| **0** | Base (QWERTY) | Default |
| **1** | Number / secondary base | Double-tap `TD(DANCE_0)` (top-right key) → `layer_move(1)`; `TO(0)` returns |
| **2** | Window-manager / app macros + Hyper keys | `TG(2)` (toggle, top-row key), `OSL(2)` via **A + F** combo, momentary via dual-func holds |
| **3** | tmux control layer | `OSL(3)` via **F + Right** combo, or `LT(3)` holds |
| **4** | Function keys + numpad | Hold `Space` (`LT(4,Space)`), hold `PgDn` (`LT(4,PgDn)`), hold the `5` key (`DUAL_FUNC_0`) |
| **5** | Vim / editor + window & mouse control | Hold `Delete` / `'` / `End` (`LT(5,…)`), `OSL(6)`→… |
| **6** | Leader macros / navigation | Hold `Tab` (`LT(6,Tab)`), `OSL(6)` (bottom-right key) |

> Note: several dual-function keys are encoded as `LT()` into non-existent
> layers (currently 8, 9, 12) — their tap/hold behavior is fully handled in
> firmware (see §6), so no layer switch occurs.

______________________________________________________________________

## 2. Modifiers & home-row / thumb mod-taps (Layer 0)

Dual-role keys that type a character when tapped and act as a modifier when held.

| Key | Tap | Hold |
| --- | --- | --- |
| `MT(MOD_LCTL, KC_Z)` | `z` | Left Ctrl |
| `MT(MOD_LALT, KC_X)` | `x` | Left Alt |
| `MT(MOD_RCTL, KC_SLASH)` | `/` | Right Ctrl |
| `MT(MOD_LSFT \| MOD_LALT, KC_GRAVE)` | `` ` `` | Shift + Alt |
| `MT(MOD_LALT, KC_APPLICATION)` | Menu | Left Alt |
| `MT(MOD_LCTL, KC_ESCAPE)` | `Esc` | Left Ctrl |
| `MT(MOD_LGUI, KC_PAGE_UP)` | `PgUp` | Super |
| `LSFT(KC_LEFT_CTRL)` | — | Shift + Left Ctrl (combined-modifier key) |
| `LCTL(KC_LEFT_ALT)` | — | Ctrl + Left Alt (combined-modifier key) |

______________________________________________________________________

## 3. Layer-tap keys (Layer 0)

| Key | Tap | Hold |
| --- | --- | --- |
| `LT(6, KC_TAB)` | `Tab` | Layer 6 |
| `LT(5, KC_DELETE)` | `Delete` | Layer 5 |
| `LT(5, KC_QUOTE)` | `'` | Layer 5 |
| `LT(5, KC_END)` | `End` | Layer 5 |
| `LT(4, KC_SPACE)` | `Space` | Layer 4 |
| `LT(4, KC_PGDN)` | `PgDn` | Layer 4 |
| `OSL(6)` | — | One-shot Layer 6 |

______________________________________________________________________

## 4. Combos (press two keys at once)

Defined in `key_combos[]`. `COMBO_COUNT = 8`.

| Combo keys | Action | Meaning |
| --- | --- | --- |
| `Z` + `LSFT(LeftCtrl)` | `Ctrl+Z` | **Undo** |
| `Ctrl(LeftAlt)` + `X` | `Ctrl+Shift+Z` | **Redo** |
| `2` + `4` | `Alt+F4` | **Close window** |
| `3` + `5` | `Ctrl+F5` | Refresh / run |
| `A` + `F` | `OSL(2)` | One-shot into Layer 2 |
| `Z` + `5`-key (`DUAL_FUNC_0`) | `F5` | Refresh |
| `F` + `Right` | `OSL(3)` | One-shot into Layer 3 (tmux) |
| `` ` `` + `=` + `-` + `LeftSuper` | **Magic SysRq REISUB** | Safe reboot (see §8) |

______________________________________________________________________

## 5. Key overrides

Remap a modified keypress to a different symbol (`KEY_OVERRIDE_ENABLE = yes`).

| Input | Output |
| --- | --- |
| `Shift` + `[` | `&` |
| `Shift` + `]` | `*` |

______________________________________________________________________

## 6. Custom dual-function keys

Fully firmware-handled tap/hold keys (see `process_record_user`). The encoded
`LT(...)` layer is **not** used; the tap/hold actions below are what fire.

| Key | Placed on | Tap | Hold |
| --- | --- | --- | --- |
| `DUAL_FUNC_0` | Layer 0 | `v` | `Shift` + Middle-click (`LSFT(MS_BTN3)`) |
| `DUAL_FUNC_1` | Layer 2 | `Meh+Q` | `Hyper+Q` |
| `DUAL_FUNC_2` | Layer 2 | `Ctrl+W` (close tab) | `Ctrl+Shift+T` (reopen tab) |
| `DUAL_FUNC_3` | Layer 5 | `Meh+1` | `Meh+5` |
| `DUAL_FUNC_4` | Layer 5 | `Meh+2` | `Meh+4` |

______________________________________________________________________

## 7. Tap dance

| Key | 1 tap | Hold | 2 taps | 3+ taps |
| --- | --- | --- | --- | --- |
| `DANCE_0` (top-right, L0) | — | — | Switch to **Layer 1** | — |
| `DANCE_1` (L5) | `Super` | `Alt` | `Hyper + Keypad-0` | repeated `Super` taps |

______________________________________________________________________

## 8. Magic SysRq — REISUB safe reboot

The `` ` `` + `=` + `-` + `LeftSuper` combo triggers a Linux Magic-SysRq
sequence (`process_combo_event`) to safely reboot a frozen machine: holds
`Alt+SysRq`, then taps **R E I S U B** (unraw → terminate → kill → sync →
remount-RO → reboot), each spaced 200 ms.

______________________________________________________________________

## 9. Macros

All macros are `SEND_STRING` sequences (`ST_MACRO_*`), grouped below by target
application. Sequences are chained taps with ~100 ms delays.

### 9a. tmux (prefix = `Ctrl+A`) — mostly Layer 3

| Macro | Sends | tmux action |
| --- | --- | --- |
| `ST_MACRO_7`–`11` | `C-a` → `1`…`5` | Select window 1–5 |
| `ST_MACRO_16`–`19` | `C-a` → `6`…`9` | Select window 6–9 |
| `ST_MACRO_12` | `C-a` → `w` | Choose window / tree |
| `ST_MACRO_13` | `C-a` → `C-a` | Last window |
| `ST_MACRO_14` | `C-a` → `z` | Zoom pane |
| `ST_MACRO_15` | `C-a` → `c` | New window |
| `ST_MACRO_20` | `C-a` → `-` | Split (horizontal) |
| `ST_MACRO_21` | `C-a` → `\` | Split (vertical) |
| `ST_MACRO_22`–`25` | `C-a` → `h` `j` `k` `l` | Select pane left/down/up/right |
| `ST_MACRO_26` | `C-a` → `:` | tmux command prompt |
| `ST_MACRO_27` | `C-a` → `Alt+Up` | Resize pane up |
| `ST_MACRO_28` | `C-a` → `Alt+Down` | Resize pane down |

### 9b. Vim / Neovim — Layer 5 & 6

| Macro | Types | Editor action |
| --- | --- | --- |
| `ST_MACRO_30` | `Esc :w ⏎` | Save |
| `ST_MACRO_31`, `ST_MACRO_34` | `Esc ZZ` | Save & quit |
| `ST_MACRO_29`, `ST_MACRO_35` | `Esc ZQ` | Quit without saving |
| `ST_MACRO_32` | `:set wrap! ⏎` | Toggle line wrap |
| `ST_MACRO_40` | `@@` | Repeat last macro |
| `ST_MACRO_41` | `:%s/` | Start global substitute |
| `ST_MACRO_42` | `gT` | Previous tab |
| `ST_MACRO_43` | `gt` | Next tab |
| `ST_MACRO_44` | `[h` | Previous change/hunk |
| `ST_MACRO_45` | `]h` | Next change/hunk |
| `ST_MACRO_36`–`39` | `Space` → `s` → `j`/`k`/`h`/`l` | Leader-based window/split navigation |

### 9c. Super / window-manager chords — Layer 0 & 2

Tap `Super` then letters (likely launcher / tiling-WM bindings).

| Macro | Sends |
| --- | --- |
| `ST_MACRO_0` | `Super` → `o` → `o` |
| `ST_MACRO_1` | `Super` → `e` → `=` |
| `ST_MACRO_2` | `Super` → `a` → `"` |
| `ST_MACRO_3` | `Super` → `s` → `s` |
| `ST_MACRO_5` | `Super` → `u` → `"` |
| `ST_MACRO_6` | `Super` → `o` → `"` |

### 9d. Miscellaneous macros

| Macro | Sends | Purpose |
| --- | --- | --- |
| `ST_MACRO_4` | `Shift+L` → `s` → `j` | (app-specific) |
| `ST_MACRO_33` | `Meh+4` → (300 ms) → Media Play/Pause | Screenshot region + play/pause |

______________________________________________________________________

## 10. Direct global / application shortcuts placed on keys

These emit a shortcut directly (no macro), spread across Layers 2, 4, and 5. The
**Trigger** column tells you exactly how to fire it: how to reach the layer, then
which physical key to press (named by its base-layer/Layer-0 legend).

**How to reach each layer:**

| Layer | Reach it by |
| --- | --- |
| **Layer 2** | Tap `TG(2)` (top row, the key right of `5`) to toggle it on/off |
| **Layer 4** | **Hold** `Space` (left thumb) or `PgDn` (right thumb) |
| **Layer 5** | **Hold** `Delete` (row 3, far left), `'` (right pinky), or `End` (left thumb) |

### Hyper (`Ctrl+Alt+Shift+Super`) — resolved to GNOME shortcuts

Each fires a GNOME custom keybinding that runs the personal `vm` CLI
(`yavr` = Yamaha AVR, `ha` = Home Assistant, `desktop` = window control).

| Trigger (layer → key) | Sends | Function |
| --- | --- | --- |
| L4 → `A` key | Hyper + A | Cycle **kitty** windows |
| L4 → `S` key | Hyper + S | Cycle **signal / slack / discord** |
| L4 → `D` key · also L2 & L5 `D` | Hyper + D | Cycle **terminal / kitty** |
| L4 → `F` key · also L2 `F` | Hyper + F | Cycle **browsers** (firefox ↔ chrome) |
| L5 → `G` key | Hyper + G | **Goto project** (`nvim project-wrapper`) |
| L2 → **hold** `Q` key (`DUAL_FUNC_1`) | Hyper + Q | Home-Assistant light **100 %** |
| L5 → double-tap the `Esc` key (`DANCE_1`) | Hyper + Keypad-0 | **Quit all** (`quit_all.py`) |

> On Layer 4 the home-row `A S D F` keys form an app-launcher cluster
> (kitty · signal/slack · terminal · browsers).

### Meh (`Ctrl+Alt+Shift`) — resolved to GNOME shortcuts

| Trigger (layer → key) | Sends | Function |
| --- | --- | --- |
| L5 → **tap** left-thumb `Tab` key (`DUAL_FUNC_3`) | Meh + 1 | AVR volume upsert |
| L5 → **hold** left-thumb `Tab` key (`DUAL_FUNC_3`) | Meh + 5 | AVR "meeting" (volume −25) |
| L5 → **tap** left-thumb `Home` key (`DUAL_FUNC_4`) | Meh + 2 | AVR volume down |
| L5 → **hold** left-thumb `Home` key (`DUAL_FUNC_4`) | Meh + 4 | AVR "music" (volume −50) |
| L5 → left-thumb `Menu` key | Meh + 3 | AVR mute |
| L5 → left big thumb (`Space`) key | Meh + 6 | **Mic mute / unmute** (GNOME built-in) |
| L2 → **tap** `Q` key (`DUAL_FUNC_1`) | Meh + Q | Home-Assistant light **50 %** |
| L5 → bottom-left `` ` `` key | Meh + F9 | Move window → lower-left (secondary) |
| L4 → bottom-left `` ` `` key | Meh + F10 | Move windows (scene after-start) |
| L5 → `Backspace` thumb key (`ST_MACRO_33`) | Meh + 4 → Play/Pause | AVR "music" then toggle playback |

> The Meh + `F6`/`F7`/`F8`/`F12` cluster that used to sit on the Layer 5 top row
> was **removed** in the latest revision.

### Other direct shortcuts

| Trigger (layer → key) | Sends | Action |
| --- | --- | --- |
| L5 → `Left` arrow key | Ctrl + Page Up | Previous browser tab |
| L5 → `Right` arrow key | Ctrl + Page Down | Next browser tab |
| L5 → `F` key | AltGr + F | (app-specific) |
| L4 → `G` key · L5 → the `v` key (row 4, between `C` and `B`) | Middle-click | Mouse middle button |
| L5 → right big thumb (`Space`) key | `MS_BTN5` | Mouse forward |
| L2 → `Right` arrow key | Shift + M | (app-specific) |
| L4 → left inner `Enter` key | `PrtSc` | Print screen |
| L4 → top-right `→` key | `QK_BOOT` | Enter firmware bootloader |

Layer 4 also carries **F1–F12** and a full **numpad**; Layer 4 has plain
function keys (not Meh-modified).

______________________________________________________________________

## Building & flashing

```bash
uv run oryx        # fetch latest Oryx revision, rebuild in Docker, flash
uv run build-qmk   # build only
```

See [`src/oryx/main.py`](src/oryx/main.py) for the full pipeline.
