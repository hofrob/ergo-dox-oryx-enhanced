#include QMK_KEYBOARD_H
#include "version.h"

#ifndef ZSA_SAFE_RANGE
#define ZSA_SAFE_RANGE SAFE_RANGE
#endif

enum custom_keycodes {
  RGB_SLD = ZSA_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
  ST_MACRO_4,
  ST_MACRO_5,
  ST_MACRO_6,
  ST_MACRO_7,
  ST_MACRO_8,
  ST_MACRO_9,
  ST_MACRO_10,
  ST_MACRO_11,
  ST_MACRO_12,
  ST_MACRO_13,
  ST_MACRO_14,
  ST_MACRO_15,
  ST_MACRO_16,
  ST_MACRO_17,
  ST_MACRO_18,
  ST_MACRO_19,
  ST_MACRO_20,
  ST_MACRO_21,
  ST_MACRO_22,
  ST_MACRO_23,
  ST_MACRO_24,
  ST_MACRO_25,
  ST_MACRO_26,
  ST_MACRO_27,
  ST_MACRO_28,
  ST_MACRO_29,
  ST_MACRO_30,
  ST_MACRO_31,
  ST_MACRO_32,
  ST_MACRO_33,
  ST_MACRO_34,
  ST_MACRO_35,
  ST_MACRO_36,
  ST_MACRO_37,
  ST_MACRO_38,
  ST_MACRO_39,
  ST_MACRO_40,
  ST_MACRO_41,
  ST_MACRO_42,
};


enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

#define DUAL_FUNC_0 LT(6, KC_Y)
#define DUAL_FUNC_1 LT(2, KC_U)
#define DUAL_FUNC_2 LT(3, KC_Z)
#define DUAL_FUNC_3 LT(8, KC_5)
#define DUAL_FUNC_4 LT(5, KC_F10)
#define DUAL_FUNC_5 LT(3, KC_T)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_EQUAL,       KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           TG(2),                                          KC_RIGHT,       KC_6,           KC_LBRC,        KC_RBRC,        KC_LCBR,        KC_RCBR,        KC_MINUS,
    LT(6, KC_TAB),  KC_Q,           KC_W,           KC_E,           KC_R,           KC_T,           KC_ESCAPE,                                      TD(DANCE_0),    KC_Y,           KC_U,           KC_I,           KC_O,           KC_P,           KC_BSLS,
    LT(5, KC_DELETE),KC_A,           KC_S,           KC_D,           KC_F,           KC_G,                                                                           KC_H,           KC_J,           KC_K,           KC_L,           KC_SCLN,        LT(5, KC_QUOTE),
    KC_LEFT_SHIFT,  MT(MOD_LCTL, KC_Z),MT(MOD_LALT, KC_X),KC_C,           DUAL_FUNC_0,    KC_B,           KC_ENTER,                                       KC_ENTER,       KC_N,           KC_M,           KC_COMMA,       KC_DOT,         MT(MOD_RCTL, KC_SLASH),KC_RIGHT_SHIFT,
    MT(MOD_LSFT | MOD_LALT, KC_GRAVE),LSFT(KC_LEFT_CTRL),LCTL(KC_LEFT_ALT),KC_LEFT,        KC_RIGHT,                                                                                                       KC_UP,          KC_DOWN,        KC_LPRN,        KC_RPRN,        DUAL_FUNC_1,
                                                                                                    MT(MOD_LALT, KC_APPLICATION),KC_TAB,         KC_RIGHT_ALT,   MT(MOD_LCTL, KC_ESCAPE),
                                                                                                                    KC_HOME,        KC_PAGE_UP,
                                                                                    LT(4, KC_SPACE),KC_BSPC,        LT(5, KC_END),  LT(4, KC_PGDN), KC_TAB,         KC_SPACE
  ),
  [1] = LAYOUT_ergodox_pretty(
    KC_GRAVE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_PAUSE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TAB,         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 TO(0),          KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_Z,           KC_X,           KC_TRANSPARENT, KC_V,           KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_LEFT_CTRL,   KC_LEFT_ALT,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_SPACE,       KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [2] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, DUAL_FUNC_2,    KC_TRANSPARENT, ST_MACRO_0,     KC_TRANSPARENT, KC_TRANSPARENT, KC_RIGHT_GUI,                                   KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_4,     KC_TRANSPARENT, ST_MACRO_5,     KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_1,     ST_MACRO_2,     LALT(LGUI(LCTL(LSFT(KC_D)))),LALT(LGUI(LCTL(LSFT(KC_F)))),KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, LCTL(KC_PAGE_UP),LCTL(KC_PGDN),  ST_MACRO_3,     DUAL_FUNC_3,    KC_MS_BTN3,     KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LSFT(KC_M),                                                                                                     KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, ST_MACRO_6,     ST_MACRO_7,     ST_MACRO_8,     ST_MACRO_9,     ST_MACRO_10,    KC_TRANSPARENT,                                 KC_TRANSPARENT, ST_MACRO_15,    ST_MACRO_16,    ST_MACRO_17,    ST_MACRO_18,    KC_TRANSPARENT, ST_MACRO_19,
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_11,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_20,
    KC_TRANSPARENT, ST_MACRO_12,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 ST_MACRO_21,    ST_MACRO_22,    ST_MACRO_23,    ST_MACRO_24,    ST_MACRO_25,    KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_13,    KC_TRANSPARENT, ST_MACRO_14,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                                                 ST_MACRO_26,    ST_MACRO_27,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [4] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,          KC_TRANSPARENT,                                 QK_BOOT,        KC_TRANSPARENT, KC_AMPR,        KC_ASTR,        KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F12,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_7,        KC_KP_8,        KC_KP_9,        KC_KP_ASTERISK, KC_TRANSPARENT,
    KC_TRANSPARENT, LALT(LGUI(LCTL(LSFT(KC_A)))),LALT(LGUI(LCTL(LSFT(KC_S)))),LALT(LGUI(LCTL(LSFT(KC_D)))),LALT(LGUI(LCTL(LSFT(KC_F)))),KC_MS_BTN3,                                                                     KC_TRANSPARENT, KC_KP_4,        KC_KP_5,        KC_KP_6,        KC_KP_PLUS,     KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_DOT,         KC_COMMA,       KC_UNDS,        KC_PSCR,                                        KC_TRANSPARENT, KC_TRANSPARENT, KC_KP_1,        KC_KP_2,        KC_KP_3,        KC_KP_MINUS,    KC_TRANSPARENT,
    LALT(LCTL(LSFT(KC_F10))),KC_TRANSPARENT, KC_TRANSPARENT, KC_HOME,        KC_END,                                                                                                         KC_TRANSPARENT, KC_KP_0,        KC_KP_DOT,      KC_EQUAL,       KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_NUM,         KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [5] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 LALT(LCTL(LSFT(KC_F12))),LALT(LCTL(LSFT(KC_F6))),LALT(LCTL(LSFT(KC_F7))),LALT(LCTL(LSFT(KC_F8))),LALT(LCTL(LSFT(KC_F9))),LALT(LCTL(LSFT(KC_F10))),KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_28,    ST_MACRO_29,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, TD(DANCE_1),                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, LALT(LGUI(LCTL(LSFT(KC_D)))),RALT(KC_F),     LALT(LGUI(LCTL(LSFT(KC_G)))),                                                                LALT(LSFT(KC_O)),ST_MACRO_33,    ST_MACRO_34,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_30,    KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN3,     KC_TRANSPARENT, ST_MACRO_31,                                    KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_F12),   KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    LALT(LCTL(LSFT(KC_F9))),KC_TRANSPARENT, KC_TRANSPARENT, LCTL(KC_PAGE_UP),LCTL(KC_PGDN),                                                                                                  KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    LALT(LCTL(LSFT(KC_3))),DUAL_FUNC_4,    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    DUAL_FUNC_5,    KC_TRANSPARENT,
                                                                                    KC_MS_BTN4,     ST_MACRO_32,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_MS_BTN5
  ),
  [6] = LAYOUT_ergodox_pretty(
    KC_TRANSPARENT, ST_MACRO_35,    ST_MACRO_36,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, ST_MACRO_37,    ST_MACRO_38,    KC_TRANSPARENT, ST_MACRO_39,    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_40,    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, ST_MACRO_41,    ST_MACRO_42,                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                                                    KC_TRANSPARENT, KC_TRANSPARENT,
                                                                                    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT
  ),
};



const uint16_t PROGMEM combo0[] = { MT(MOD_LCTL, KC_Z), LSFT(KC_LEFT_CTRL), COMBO_END};
const uint16_t PROGMEM combo1[] = { LCTL(KC_LEFT_ALT), MT(MOD_LALT, KC_X), COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_2, KC_4, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_3, KC_5, COMBO_END};
const uint16_t PROGMEM combo4[] = { KC_A, KC_F, COMBO_END};
const uint16_t PROGMEM combo5[] = { MT(MOD_LCTL, KC_Z), DUAL_FUNC_0, COMBO_END};
const uint16_t PROGMEM combo6[] = { KC_F, KC_RIGHT, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, LCTL(KC_Z)),
    COMBO(combo1, LCTL(LSFT(KC_Z))),
    COMBO(combo2, LALT(KC_F4)),
    COMBO(combo3, LCTL(KC_F5)),
    COMBO(combo4, OSL(2)),
    COMBO(combo5, KC_F5),
    COMBO(combo6, OSL(3)),
};



extern rgb_config_t rgb_matrix_config;

RGB hsv_to_rgb_with_value(HSV hsv) {
  RGB rgb = hsv_to_rgb( hsv );
  float f = (float)rgb_matrix_config.hsv.v / UINT8_MAX;
  return (RGB){ f * rgb.r, f * rgb.g, f * rgb.b };
}

void keyboard_post_init_user(void) {
  rgb_matrix_enable();
}

const uint8_t PROGMEM ledmap[][RGB_MATRIX_LED_COUNT][3] = {
    [0] = { {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255}, {131,255,255} },

    [1] = { {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245}, {0,245,245} },

    [2] = { {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255}, {41,255,255} },

    [4] = { {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255}, {168,255,255} },

    [5] = { {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255}, {152,255,255} },

};

void set_layer_color(int layer) {
  for (int i = 0; i < RGB_MATRIX_LED_COUNT; i++) {
    HSV hsv = {
      .h = pgm_read_byte(&ledmap[layer][i][0]),
      .s = pgm_read_byte(&ledmap[layer][i][1]),
      .v = pgm_read_byte(&ledmap[layer][i][2]),
    };
    if (!hsv.h && !hsv.s && !hsv.v) {
        rgb_matrix_set_color( i, 0, 0, 0 );
    } else {
        RGB rgb = hsv_to_rgb_with_value(hsv);
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
  }
}

bool rgb_matrix_indicators_user(void) {
  if (rawhid_state.rgb_control) {
      return false;
  }
  if (!keyboard_config.disable_layer_led) { 
    switch (biton32(layer_state)) {
      case 0:
        set_layer_color(0);
        break;
      case 1:
        set_layer_color(1);
        break;
      case 2:
        set_layer_color(2);
        break;
      case 4:
        set_layer_color(4);
        break;
      case 5:
        set_layer_color(5);
        break;
     default:
        if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
          rgb_matrix_set_color_all(0, 0, 0);
        }
    }
  } else {
    if (rgb_matrix_get_flags() == LED_FLAG_NONE) {
      rgb_matrix_set_color_all(0, 0, 0);
    }
  }

  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,      
    SINGLE_HOLD,         
    DOUBLE_TAP,          
    DOUBLE_HOLD,         
    DOUBLE_SINGLE_TAP,   
    MORE_TAPS            
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case DOUBLE_TAP: layer_move(1); break;
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_LEFT_GUI);
        tap_code16(KC_LEFT_GUI);
        tap_code16(KC_LEFT_GUI);
    }
    if(state->count > 3) {
        tap_code16(KC_LEFT_GUI);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_LEFT_GUI); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: register_code16(LALT(LCTL(LGUI(LSFT(KC_KP_0))))); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_LEFT_GUI); register_code16(KC_LEFT_GUI);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_LEFT_GUI); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_ALT); break;
        case DOUBLE_TAP: unregister_code16(LALT(LCTL(LGUI(LSFT(KC_KP_0))))); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_LEFT_GUI); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RIGHT_GUI)SS_DELAY(100)  SS_TAP(X_E)SS_DELAY(100)  SS_TAP(X_EQUAL));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RIGHT_GUI)SS_DELAY(100)  SS_TAP(X_A)SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE)));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RIGHT_GUI)SS_DELAY(100)  SS_TAP(X_S)SS_DELAY(100)  SS_TAP(X_S));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_L))SS_DELAY(100)  SS_TAP(X_S)SS_DELAY(100)  SS_TAP(X_J));
    }
    break;
    case ST_MACRO_4:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RIGHT_GUI)SS_DELAY(100)  SS_TAP(X_U)SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE)));
    }
    break;
    case ST_MACRO_5:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_RIGHT_GUI)SS_DELAY(100)  SS_TAP(X_O)SS_DELAY(100)  SS_LSFT(SS_TAP(X_QUOTE)));
    }
    break;
    case ST_MACRO_6:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_1));
    }
    break;
    case ST_MACRO_7:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_2));
    }
    break;
    case ST_MACRO_8:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_3));
    }
    break;
    case ST_MACRO_9:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_4));
    }
    break;
    case ST_MACRO_10:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_5));
    }
    break;
    case ST_MACRO_11:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_W));
    }
    break;
    case ST_MACRO_12:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_LCTL(SS_TAP(X_A)));
    }
    break;
    case ST_MACRO_13:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_Z));
    }
    break;
    case ST_MACRO_14:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_C));
    }
    break;
    case ST_MACRO_15:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_6));
    }
    break;
    case ST_MACRO_16:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_7));
    }
    break;
    case ST_MACRO_17:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_8));
    }
    break;
    case ST_MACRO_18:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_9));
    }
    break;
    case ST_MACRO_19:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_MINUS));
    }
    break;
    case ST_MACRO_20:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_BSLS));
    }
    break;
    case ST_MACRO_21:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_H));
    }
    break;
    case ST_MACRO_22:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_J));
    }
    break;
    case ST_MACRO_23:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_K));
    }
    break;
    case ST_MACRO_24:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_TAP(X_L));
    }
    break;
    case ST_MACRO_25:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_LSFT(SS_TAP(X_SCLN)));
    }
    break;
    case ST_MACRO_26:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_LALT(SS_TAP(X_UP)));
    }
    break;
    case ST_MACRO_27:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_A))SS_DELAY(100)  SS_LALT(SS_TAP(X_DOWN)));
    }
    break;
    case ST_MACRO_28:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(100)  SS_LSFT(SS_TAP(X_Z))SS_DELAY(100)  SS_LSFT(SS_TAP(X_Q)));
    }
    break;
    case ST_MACRO_29:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(100)  SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(100)  SS_TAP(X_W)SS_DELAY(100)  SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_30:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(100)  SS_LSFT(SS_TAP(X_Z))SS_DELAY(100)  SS_LSFT(SS_TAP(X_Z)));
    }
    break;
    case ST_MACRO_31:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(10)  SS_TAP(X_S)SS_DELAY(10)  SS_TAP(X_E)SS_DELAY(10)  SS_TAP(X_T)SS_DELAY(10)  SS_TAP(X_SPACE)SS_DELAY(10)  SS_TAP(X_W)SS_DELAY(10)  SS_TAP(X_R)SS_DELAY(10)  SS_TAP(X_A)SS_DELAY(10)  SS_TAP(X_P)SS_DELAY(9)  SS_LSFT(SS_TAP(X_1))SS_DELAY(100)  SS_TAP(X_ENTER));
    }
    break;
    case ST_MACRO_32:
    if (record->event.pressed) {
      SEND_STRING(SS_LALT(SS_LCTL(SS_LSFT(SS_TAP(X_4))))SS_DELAY(300)  SS_TAP(X_MEDIA_PLAY_PAUSE));
    }
    break;
    case ST_MACRO_33:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(100)  SS_LSFT(SS_TAP(X_Z))SS_DELAY(100)  SS_LSFT(SS_TAP(X_Z)));
    }
    break;
    case ST_MACRO_34:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_ESCAPE)SS_DELAY(100)  SS_LSFT(SS_TAP(X_Z))SS_DELAY(100)  SS_LSFT(SS_TAP(X_Q)));
    }
    break;
    case ST_MACRO_35:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE)SS_DELAY(100)  SS_TAP(X_S)SS_DELAY(100)  SS_TAP(X_J));
    }
    break;
    case ST_MACRO_36:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE)SS_DELAY(100)  SS_TAP(X_S)SS_DELAY(100)  SS_TAP(X_K));
    }
    break;
    case ST_MACRO_37:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE)SS_DELAY(100)  SS_TAP(X_S)SS_DELAY(100)  SS_TAP(X_H));
    }
    break;
    case ST_MACRO_38:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_SPACE)SS_DELAY(100)  SS_TAP(X_S)SS_DELAY(100)  SS_TAP(X_L));
    }
    break;
    case ST_MACRO_39:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_2))SS_DELAY(100)  SS_LSFT(SS_TAP(X_2)));
    }
    break;
    case ST_MACRO_40:
    if (record->event.pressed) {
      SEND_STRING(SS_LSFT(SS_TAP(X_SCLN))SS_DELAY(100)  SS_LSFT(SS_TAP(X_5))SS_DELAY(100)  SS_TAP(X_S)SS_DELAY(100)  SS_TAP(X_SLASH));
    }
    break;
    case ST_MACRO_41:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G)SS_DELAY(100)  SS_LSFT(SS_TAP(X_T)));
    }
    break;
    case ST_MACRO_42:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_G)SS_DELAY(100)  SS_TAP(X_T));
    }
    break;

    case DUAL_FUNC_0:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_V);
        } else {
          unregister_code16(KC_V);
        }
      } else {
        if (record->event.pressed) {
          register_code16(LSFT(KC_MS_BTN3));
        } else {
          unregister_code16(LSFT(KC_MS_BTN3));
        }  
      }  
      return false;
    case DUAL_FUNC_1:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(KC_LEFT_GUI);
        } else {
          unregister_code16(KC_LEFT_GUI);
        }
      } else {
        if (record->event.pressed) {
          register_code16(KC_LEFT_CTRL);
        } else {
          unregister_code16(KC_LEFT_CTRL);
        }  
      }  
      return false;
    case DUAL_FUNC_2:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LALT(LCTL(LSFT(KC_Q))));
        } else {
          unregister_code16(LALT(LCTL(LSFT(KC_Q))));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LGUI(LCTL(LSFT(KC_Q)))));
        } else {
          unregister_code16(LALT(LGUI(LCTL(LSFT(KC_Q)))));
        }  
      }  
      return false;
    case DUAL_FUNC_3:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LCTL(KC_W));
        } else {
          unregister_code16(LCTL(KC_W));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LCTL(LSFT(KC_T)));
        } else {
          unregister_code16(LCTL(LSFT(KC_T)));
        }  
      }  
      return false;
    case DUAL_FUNC_4:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LALT(LCTL(LSFT(KC_1))));
        } else {
          unregister_code16(LALT(LCTL(LSFT(KC_1))));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LCTL(LSFT(KC_5))));
        } else {
          unregister_code16(LALT(LCTL(LSFT(KC_5))));
        }  
      }  
      return false;
    case DUAL_FUNC_5:
      if (record->tap.count > 0) {
        if (record->event.pressed) {
          register_code16(LALT(LCTL(LSFT(KC_2))));
        } else {
          unregister_code16(LALT(LCTL(LSFT(KC_2))));
        }
      } else {
        if (record->event.pressed) {
          register_code16(LALT(LCTL(LSFT(KC_4))));
        } else {
          unregister_code16(LALT(LCTL(LSFT(KC_4))));
        }  
      }  
      return false;
    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}

uint8_t layer_state_set_user(uint8_t state) {
    uint8_t layer = biton(state);
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();
  switch (layer) {
    case 1:
      ergodox_right_led_1_on();
      break;
    case 2:
      ergodox_right_led_2_on();
      break;
    case 3:
      ergodox_right_led_3_on();
      break;
    case 4:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      break;
    case 5:
      ergodox_right_led_1_on();
      ergodox_right_led_3_on();
      break;
    case 6:
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    case 7:
      ergodox_right_led_1_on();
      ergodox_right_led_2_on();
      ergodox_right_led_3_on();
      break;
    default:
      break;
  }
  return state;
};

