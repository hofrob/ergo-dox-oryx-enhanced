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
layer (layers 0, 1, 2, 4, 5), and the three right-hand indicator LEDs encode the
active layer in binary.

| Layer | Purpose | How to reach it |
| --- | --- | --- |
| **0** | Base (QWERTY) | Default |
| **1** | Gaming (plain `Z`/`X`/`V`, plain modifiers, latched-hold keys) | Double-tap `TD(DANCE_0)` (right inner key, row 2) → `layer_move(1)`; `TO(0)` (same key on L1) returns |
| **2** | Window-manager / app macros, tab & media control | `TG(2)` (toggle, top-row key right of `5`), `OSL(2)` via **A + F** combo |
| **3** | tmux control layer | `OSL(3)` via **F + Right** combo |
| **4** | Function keys + numpad + app-launcher (Hyper) | Hold `Space` (`LT(4,Space)`) or `PgDn` (`LT(4,PgDn)`) |
| **5** | Vim / editor + media & mouse control | Hold `Delete` / `'` / `End` (`LT(5,…)`) |
| **6** | Leader macros / navigation | Hold `Tab` (`LT(6,Tab)`), `OSL(6)` (bottom-right key) |

> Note: the dual-function keys are encoded as `LT()` (currently into layers 2,
> 6, 9, 10) — their tap/hold behavior is fully handled in firmware and
> `process_record_user` returns `false`, so no layer switch occurs (see §6).

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
| `DUAL_FUNC_0` | L0 → `V` key | `v` | `Shift` + Middle-click (`LSFT(MS_BTN3)`) |
| `DUAL_FUNC_1` | L2 → `Q` key | `Meh+Q` | `Hyper+Q` |
| `DUAL_FUNC_2` | L2 → `V` key | `Ctrl+W` (close tab) | `Ctrl+Shift+T` (reopen tab) |
| `DUAL_FUNC_3` | L2 & L5 → left-thumb `Tab` key | `Meh+1` | `Meh+5` |
| `DUAL_FUNC_4` | L2 & L5 → left-thumb `Home` key | `Meh+2` | `Meh+4` |

______________________________________________________________________

## 7. Tap dance

| Key | Placed on | 1 tap | Hold | 2 taps | 3+ taps |
| --- | --- | --- | --- | --- | --- |
| `DANCE_0` | L0 → right inner key (row 2) | — | — | Switch to **Layer 1** | — |
| `DANCE_1` | L2 → `4` key | `Meh+F19` | `Meh+F20` | `Meh+F21` | repeated `Meh+F19` taps |
| `DANCE_2` | L2 → `5` key | `Meh+F22` | `Meh+F23` | `Meh+F24` | repeated `Meh+F22` taps |
| `DANCE_3` | L2 → `Left` key | `Meh+F19` | `Meh+F20` | `Meh+F21` | repeated `Meh+F19` taps |
| `DANCE_4` | L2 → `Right` key | `Meh+F22` | `Meh+F23` | `Meh+F24` | repeated `Meh+F22` taps |
| `DANCE_5` | L5 → `Esc` key (left inner, row 2) | `Super` | `Alt` | `Hyper + Keypad-0` (**quit all**) | repeated `Super` taps |

> `DANCE_1`/`DANCE_3` and `DANCE_2`/`DANCE_4` are identical pairs (number row
> and arrow row). The `Meh+F19`–`F24` chords are not yet bound to any GNOME
> custom shortcut.

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

### 9a. tmux (prefix = `Ctrl+A`) — Layer 3

Keys are named by their Layer-0 legend.

| Macro | Key | Sends | tmux action |
| --- | --- | --- | --- |
| `ST_MACRO_8`–`12` | `1`…`5` | `C-a` → `1`…`5` | Select window 1–5 |
| `ST_MACRO_17`–`20` | `6` `[` `]` `{` | `C-a` → `6`…`9` | Select window 6–9 |
| `ST_MACRO_13` | `W` | `C-a` → `w` | Choose window / tree |
| `ST_MACRO_14` | `A` | `C-a` → `C-a` | Last window |
| `ST_MACRO_15` | `Z` | `C-a` → `z` | Zoom pane |
| `ST_MACRO_16` | `C` | `C-a` → `c` | New window |
| `ST_MACRO_21` | `-` | `C-a` → `-` | Split (horizontal) |
| `ST_MACRO_22` | `\` | `C-a` → `\` | Split (vertical) |
| `ST_MACRO_23`–`26` | `H` `J` `K` `L` | `C-a` → `h` `j` `k` `l` | Select pane left/down/up/right |
| `ST_MACRO_27` | `;` | `C-a` → `:` | tmux command prompt |
| `ST_MACRO_28` | `Up` | `C-a` → `Alt+Up` | Resize pane up |
| `ST_MACRO_29` | `Down` | `C-a` → `Alt+Down` | Resize pane down |

### 9b. Vim / Neovim — Layer 5 & 6

| Macro | Key | Types | Editor action |
| --- | --- | --- | --- |
| `ST_MACRO_31` | L5 → `W` | `Esc :w ⏎` | Save |
| `ST_MACRO_32`, `ST_MACRO_35` | L5 → `Z`, L5 → `J` | `Esc ZZ` | Save & quit |
| `ST_MACRO_30`, `ST_MACRO_36` | L5 → `Q`, L5 → `K` | `Esc ZQ` | Quit without saving |
| `ST_MACRO_33` | L5 → left inner `Enter` | `:set wrap! ⏎` | Toggle line wrap |
| `ST_MACRO_41` | L6 → `R` | `@@` | Repeat last macro |
| `ST_MACRO_42` | L6 → `S` | `:%s/` | Start global substitute |
| `ST_MACRO_43` | L6 → `Left` | `gT` | Previous tab |
| `ST_MACRO_44` | L6 → `Right` | `gt` | Next tab |
| `ST_MACRO_45` | L6 → `Up` | `[h` | Previous change/hunk |
| `ST_MACRO_46` | L6 → `Down` | `]h` | Next change/hunk |
| `ST_MACRO_37`–`40` | L6 → `1` `2` `Q` `W` | `Space` → `s` → `j`/`k`/`h`/`l` | Leader-based window/split navigation |

### 9c. Super / window-manager chords — Layer 2

Tap right `Super` then letters (likely launcher / tiling-WM bindings).

| Macro | Key | Sends |
| --- | --- | --- |
| `ST_MACRO_0` | `=` (top-left) | `Super` → `o` → `o` |
| `ST_MACRO_1` | `E` | `Super` → `e` → `=` |
| `ST_MACRO_2` | `A` | `Super` → `a` → `"` |
| `ST_MACRO_3` | `S` | `Super` → `s` → `s` |
| `ST_MACRO_6` | `U` | `Super` → `u` → `"` |
| `ST_MACRO_7` | `O` | `Super` → `o` → `"` |

> `ST_MACRO_0` moved from the Layer-0 right inner top key (now unassigned) to
> the Layer-2 top-left key.

### 9d. Miscellaneous macros

| Macro | Key | Sends | Purpose |
| --- | --- | --- | --- |
| `ST_MACRO_4` | L2 → `C` | `Shift+L` → `s` → `j` | (app-specific) |
| `ST_MACRO_5`, `ST_MACRO_34` | L2 & L5 → `Backspace` thumb | `Meh+4` → (300 ms) → Media Play/Pause | AVR "music" + play/pause |

______________________________________________________________________

## 10. Direct global / application shortcuts placed on keys

These emit a shortcut directly (no macro), spread across Layers 2, 4, and 5. The
**Trigger** column tells you exactly how to fire it: how to reach the layer, then
which physical key to press (named by its base-layer/Layer-0 legend).

**How to reach each layer:**

| Layer | Reach it by |
| --- | --- |
| **Layer 2** | Tap `TG(2)` (top row, the key right of `5`) to toggle it on/off, or **A + F** combo (one-shot) |
| **Layer 4** | **Hold** `Space` (left thumb) or `PgDn` (right thumb) |
| **Layer 5** | **Hold** `Delete` (row 3, far left), `'` (right pinky), or `End` (left thumb) |

### Hyper (`Ctrl+Alt+Shift+Super`) — resolved to GNOME shortcuts

Each fires a GNOME custom keybinding that runs the personal `vm` CLI
(`yavr` = Yamaha AVR, `ha` = Home Assistant, `desktop` = window control).

| Trigger (layer → key) | Sends | Function |
| --- | --- | --- |
| L4 → `A` key | Hyper + A | Cycle **kitty** windows |
| L4 → `S` key | Hyper + S | Cycle **signal / slack / discord** |
| L4 → `D` key · also L5 `D` | Hyper + D | Cycle **terminal / kitty** |
| L4 → `F` key | Hyper + F | Cycle **browsers** (firefox ↔ chrome) |
| L5 → `G` key | Hyper + G | **Goto project** (`nvim project-wrapper`) |
| L2 → **hold** `Q` key (`DUAL_FUNC_1`) | Hyper + Q | Home-Assistant light **100 %** |
| L5 → double-tap the `Esc` key (`DANCE_5`) | Hyper + Keypad-0 | **Quit all** (`quit_all.py`) |

> On Layer 4 the home-row `A S D F` keys form an app-launcher cluster
> (kitty · signal/slack · terminal · browsers).

### Meh (`Ctrl+Alt+Shift`) — resolved to GNOME shortcuts

The AVR / mic thumb cluster is identical on Layers 2 and 5.

| Trigger (layer → key) | Sends | Function |
| --- | --- | --- |
| L2/L5 → **tap** left-thumb `Tab` key (`DUAL_FUNC_3`) | Meh + 1 | AVR volume upsert |
| L2/L5 → **hold** left-thumb `Tab` key (`DUAL_FUNC_3`) | Meh + 5 | AVR "meeting" (volume −25) |
| L2/L5 → **tap** left-thumb `Home` key (`DUAL_FUNC_4`) | Meh + 2 | AVR volume down |
| L2/L5 → **hold** left-thumb `Home` key (`DUAL_FUNC_4`) | Meh + 4 | AVR "music" (volume −50) |
| L2/L5 → left-thumb `Menu` key | Meh + 3 | AVR mute |
| L2/L5 → left big thumb (`Space`) key | Meh + 6 | **Mic mute / unmute** (GNOME built-in) |
| L2/L5 → `Backspace` thumb key (`ST_MACRO_5`/`34`) | Meh + 4 → Play/Pause | AVR "music" then toggle playback |
| L2 → **tap** `Q` key (`DUAL_FUNC_1`) | Meh + Q | Home-Assistant light **50 %** |
| L5 → bottom-left `` ` `` key | Meh + F9 | Move window → lower-left (secondary) |
| L2 & L4 → bottom-left `` ` `` key | Meh + F10 | Move windows (scene after-start) |
| L2 → `4` / `5` / `Left` / `Right` (`DANCE_1`–`4`) | Meh + F19…F24 | Unbound so far (see §7) |

### Other direct shortcuts

| Trigger (layer → key) | Sends | Action |
| --- | --- | --- |
| L2 → `Z` key · L5 → `Left` arrow key | Ctrl + Page Up | Previous browser tab |
| L2 → `X` key · L5 → `Right` arrow key | Ctrl + Page Down | Next browser tab |
| L2 → `D` key | Page Up | Page up |
| L2 → `F` key | Page Down | Page down |
| L2 → left inner `Esc` key | Right Super | Super key |
| L5 → `F` key | AltGr + F | (app-specific) |
| L2 → `B` key · L4 → `G` key · L5 → `V` key | Middle-click | Mouse middle button |
| L5 → right big thumb (`Space`) key | `MS_BTN5` | Mouse forward |
| L4 → left inner `Enter` key | `PrtSc` | Print screen |
| L4 → right thumb `RAlt` key | `Num Lock` | Toggle numpad |
| L4 → right inner top key | `QK_BOOT` | Enter firmware bootloader |

Layer 4 also carries **F1–F10 + F12** (left half; no F11), a full **numpad**
on the right half (`7 8 9 *` / `4 5 6 +` / `1 2 3 -` / `0 . =`), `&` and `*` on
the `[` / `]` keys, `.` `,` `_` on `C` / `V` / `B`, and `Home` / `End` on the
left arrow keys.

______________________________________________________________________

## 11. Gaming layer (Layer 1)

Entered by double-tapping the right inner key on row 2 (`DANCE_0`); the same key
(`TO(0)`) returns to the base layer. Everything not listed falls through to
Layer 0.

| Key (Layer-0 legend) | Layer 1 |
| --- | --- |
| `=` (top-left) | `` ` `` |
| `Tab` (row 2, far left) | plain `Tab` (no layer-tap) |
| `Z` / `X` | plain `z` / `x` (no mod-tap) |
| `V` | plain `v` (no dual function) |
| bottom-left `` ` `` / `Shift+Ctrl` | plain Left Ctrl / Left Alt |
| right top row `[` `]` `{` `}` | `7` `8` `9` `0` |
| right inner top key | `Pause` |
| left big thumb (`Space`) | plain `Space` (no layer-tap) |
| left-thumb `Menu` key | **`HOLD_F`** — latch `F` held; press again to release, auto-releases after 3 s |
| left-thumb `Tab` key | **`HOLD_SHIFT_W`** — latch `Shift+W` held (auto-run); press again to release |

______________________________________________________________________

## Building & flashing

```bash
uv run oryx        # fetch latest Oryx revision, rebuild in Docker, flash
uv run oryx build-qmk  # build only
```

See [`src/oryx/main.py`](src/oryx/main.py) for the full pipeline.
