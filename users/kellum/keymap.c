#include "keycodes.h"
#include "layers.h"
#include "oneshot.h"

#include "g/keymap_combo.h"

#include QMK_KEYBOARD_H

// Window manipulation
#define TABL C(S(KC_TAB))
#define TABR C(KC_TAB)
#define WINB S(KC_TAB)

// General utility (Windows)
#define CUT C(KC_X)
#define CPY C(KC_C)
#define PST C(KC_V)
#define UND C(KC_Z)
#define RED C(KC_Y)
#define FND C(KC_F)
#define SAVE C(KC_S)
// windows snip shortcut (will copy to clipboard)
#define WN_SNIP G(S(KC_S))
// record clip using Windows game bar
#define RC_CLIP G(A(KC_G))

// Art related
#define ZIN C(KC_PLUS)
#define ZOUT C(KC_MINS)
#define TFRM C(KC_T)

enum {
  TD_TO_MOUSE_TO_GAME = 0,
  TD_RESET,
  TD_UNDO_REDO,
  TD_COPY_CUT,
};

void safe_reset(qk_tap_dance_state_t *state, void *user_data) {
  if (state->count >= 3) {
    // Reset the keyboard if you tap the key more than three times
    reset_keyboard();
    reset_tap_dance(state);
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [TD_TO_MOUSE_TO_GAME] = ACTION_TAP_DANCE_DOUBLE(TO_MSE, TO_GME),
  [TD_RESET] = ACTION_TAP_DANCE_FN(safe_reset),
  [TD_UNDO_REDO] = ACTION_TAP_DANCE_DOUBLE(UND, RED),
  [TD_COPY_CUT] = ACTION_TAP_DANCE_DOUBLE(CPY, CUT),
};

#define MSE_GME TD(TD_TO_MOUSE_TO_GAME)
#define TD_RST TD(TD_RESET)
#define TD_UNRE TD(TD_UNDO_REDO)
#define TD_CPCT TD(TD_COPY_CUT)

void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger1,
    uint16_t trigger2,
    uint16_t keycode,
    keyrecord_t *record
);

void toggle_brush (
    bool *brush_on,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [DEF] = LAYOUT_split_3x5_2(
        KC_QUOT, KC_COMMA,KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,
        KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,
        KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,
                                   LA_NAV,  KC_LSFT, KC_SPC,  LA_SYM
    ),
    // https://github.com/Apsu/Canary
    [CAN] = LAYOUT_split_3x5_2(
        KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,    KC_Z,    KC_F,    KC_O,    KC_U,    KC_QUOT,
        KC_C,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_A,
        KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,    KC_X,    KC_H,    KC_SLSH, KC_COMMA,KC_DOT,
                                   LA_NAV,  KC_LSFT, KC_SPC,  LA_SYM
    ),
    // https://colemak.com/
    [COL] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
        KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_QUOT,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMMA,KC_DOT,  KC_SLSH,
                                   LA_NAV,  KC_LSFT, KC_SPC,  LA_SYM
    ),
    [QWE] = LAYOUT_split_3x5_2(
        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMMA,KC_DOT,  KC_SLSH,
                                   LA_NAV,  KC_LSFT, KC_SPC,  LA_SYM
    ),
    // https://sites.google.com/alanreiser.com/handsdown
    [HDN] = LAYOUT_split_3x5_2(
        KC_W,    KC_F,    KC_M,    KC_P,    KC_V,    KC_SCLN, KC_Z,    KC_Q,    KC_J,    KC_K,
        KC_R,    KC_S,    KC_N,    KC_T,    KC_G,    KC_COMMA,KC_A,    KC_E,    KC_I,    KC_H,
        KC_X,    KC_C,    KC_L,    KC_D,    KC_B,    KC_DOT,  KC_U,    KC_O,    KC_Y,    KC_QUOT,
                                   LA_NAV,  KC_LSFT, KC_SPC, LA_SYM
    ),
    [SYM] = LAYOUT_split_3x5_2(
        KC_GRV,  KC_LBRC, KC_LPRN, KC_LCBR, KC_TILD, KC_CIRC, KC_RCBR, KC_RPRN, KC_RBRC, KC_GRV,
        KC_MINS, KC_ASTR, KC_EQL,  KC_UNDS, KC_DLR,  KC_HASH, OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,
        KC_PLUS, KC_PIPE, KC_AT,   KC_BSLS, KC_PERC, KC_AMPR, KC_SLSH, KC_QUES, KC_COLN, KC_EXLM,
                                    _______, KC_F15, KC_F14,  _______
    ),
    [NAV] = LAYOUT_split_3x5_2(
        TABL,    TABR,    SW_WINF,  SW_WINB, KC_VOLU, CAPSWRD, KC_HOME, KC_UP,   KC_END,  KC_DEL,
        OS_GUI,  OS_ALT,  OS_CTRL,  OS_SHFT, KC_TAB,  KC_ESC,  KC_LEFT, KC_DOWN, KC_RGHT, KC_BSPC,
        UND,     RED,     TD_CPCT,  PST,     KC_VOLD, TD_RST,  KC_PGDN, KC_PGUP, SW_LANG, SAVE,
                                    _______, WN_SNIP, KC_ENT, _______
    ),
    [NUM] = LAYOUT_split_3x5_2(
        XXXXXXX, KC_6,    KC_5,     KC_4,    TD_RST,  KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        KC_0,    KC_3,    KC_2,     KC_1,    XXXXXXX, KC_F7,   OS_SHFT, OS_CTRL, OS_ALT,  OS_GUI,
        KC_DOT,  KC_9,    KC_8,     KC_7,    KC_F13,  KC_F6,   KC_F5,   KC_F4,   KC_F3,   KC_F2,
                                    _______, CMB_TOG, KC_F1, _______
    ),
    // Currently optimized for Minecraft
    [GME] = LAYOUT_split_3x5_2(
        KC_ESC,  KC_Q,    KC_W,     KC_E,    KC_R,     KC_T,    KC_Y,    KC_UP,   KC_I,    KC_O,
        KC_LSFT, KC_A,    KC_S,     KC_D,    KC_F,     KC_G,    KC_LEFT, KC_DOWN, KC_RGHT, KC_L,
        KC_TAB,  KC_Z,    KC_X,     KC_C,    KC_V,     KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,
                                    KC_LCTL, KC_SPACE, _______, TO_DEF
    ),
    // Currently optimized for Medibang Paint Pro
    [ART] = LAYOUT_split_3x5_2(
        KC_ESC,  SAVE,    ZIN,      ZOUT,    TFRM,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_LEFT, KC_RGHT, TD_UNRE,  TG_BRSH, KC_LBRC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_UP,   KC_DOWN, TD_CPCT,  PST,     KC_RBRC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                    KC_LCTL, KC_LSFT,  _______, XXXXXXX
    ),
    // Very experimental
    [MSE] = LAYOUT_split_3x5_2(
        KC_ESC,  XXXXXXX, XXXXXXX,  FND,     XXXXXXX, TO_DEF,  KC_WH_U, KC_MS_U, KC_WH_D, XXXXXXX,
        KC_ACL0, KC_ACL1, KC_BTN1,  KC_BTN2, KC_ACL2, KC_WH_L, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_R,
        KC_TAB,  XXXXXXX, TD_CPCT,  PST,     XXXXXXX, XXXXXXX, KC_BTN3, KC_BTN4, KC_BTN5, KC_BTN6,
                                    KC_LCTL, KC_LSFT, _______, XXXXXXX
    ),
    [SPD] = LAYOUT_split_3x5_2(
        KC_PSCR, KC_MPRV, KC_MPLY, KC_MNXT, KC_PAUS, KC_SLEP, KC_F21, KC_F22, KC_F23, KC_F24,
        KC_MUTE, XXXXXXX, KC_VOLD, KC_VOLU, KC_INS,  QK_MAKE, KC_F17, KC_F18, KC_F19, KC_F20,
        KC_SCRL, KC_CAPS, XXXXXXX, XXXXXXX, KC_NUM,  QK_BOOT, KC_F13, KC_F14, KC_F15, KC_F16,
                                   XXXXXXX, XXXXXXX, KC_LSFT, XXXXXXX
    )
};

bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
        return true;
    default:
        return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
    case LA_SYM:
    case LA_NAV:
    case TO_DEF:
    case KC_LSFT:
    case OS_SHFT:
    case OS_CTRL:
    case OS_ALT:
    case OS_GUI:
        return true;
    default:
        return false;
    }
}

bool sw_win_active = false;
bool brush_state = true;

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state OS_GUI_state = os_up_unqueued;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    update_swapper(&sw_win_active, KC_LALT, KC_TAB, SW_WINF, SW_WINB, keycode, record);
    update_swapper(&sw_win_active, KC_LALT, WINB, SW_WINB, SW_WINF, keycode, record);

    toggle_brush(&brush_state, TG_BRSH, keycode, record);

    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&OS_GUI_state, KC_LCMD, OS_GUI, keycode, record);

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, SYM, NAV, NUM);
}

// TODO make swap window forward and backward functions
// note: they will neeed to share "active" bool
void update_swapper(
    bool *active,
    uint16_t cmdish,
    uint16_t tabish,
    uint16_t trigger1,
    uint16_t trigger2,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger1) {
        if (record->event.pressed) {
            if (!*active) {
                *active = true;
                register_code(cmdish);
            }
            if (tabish == WINB) {
                register_code(KC_LSFT);
            }
            wait_ms(TAP_CODE_DELAY);
            register_code(tabish);
        } else {
            unregister_code(tabish);
            if (tabish == WINB) {
                unregister_code(KC_LSFT);
            }
            // Don't unregister cmdish until some other key is hit or released.
        }
    } else if (keycode == trigger2) {
    } else if (*active) {
        unregister_code(cmdish);
        *active = false;
    }
}

void toggle_brush (
    bool *brush_on,
    uint16_t trigger,
    uint16_t keycode,
    keyrecord_t *record
) {
    if (keycode == trigger) {
        if (*brush_on) {
            register_code(KC_E);
            unregister_code(KC_E);
            *brush_on = false;
        }
        else {
            register_code(KC_B);
            unregister_code(KC_B);
            *brush_on = true;
        }
    }
}
