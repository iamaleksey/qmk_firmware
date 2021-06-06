#include QMK_KEYBOARD_H

enum layers { _HOME_ROW_MODS_ON, _HOME_ROW_MODS_OFF, _LOWER, _RAISE, _ADJUST };

enum custom_keycodes { HRM_TOG = SAFE_RANGE };

// Home row mods
#define CTL_A   LCTL_T(KC_A)
#define OPT_S   LOPT_T(KC_S)
#define CMD_D   LCMD_T(KC_D)
#define SFT_F   LSFT_T(KC_F)
#define SFT_J   RSFT_T(KC_J)
#define CMD_K   RCMD_T(KC_K)
#define OPT_L   LOPT_T(KC_L)
#define CTL_SCN RCTL_T(KC_SCLN)

// Layer switching / mod taps
#define LWR_TAB LT(_LOWER, KC_TAB)
#define RSE_ENT LT(_RAISE, KC_ENT)

// Text manipulation
#define LNE_BEG LCMD(KC_LEFT)
#define LNE_END LCMD(KC_RGHT)
#define DEL_LNE LCMD(KC_BSPC)
#define PRV_WRD LOPT(KC_LEFT)
#define NXT_WRD LOPT(KC_RGHT)

// Undo/redo/cut/copy/paste
#define UNDO  LCMD(KC_Z)
#define REDO  LSFT(UNDO)
#define CUT   LCMD(KC_X)
#define COPY  LCMD(KC_C)
#define PASTE LCMD(KC_V)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY with home row mods ON
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | Esc ~ |  1 !  |  2 @  |  3 #  |  4 $  |  5 %  |                    |  6 ^  |  7 &  |  8 *  |  9 (  |  0 )  | Bspc  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Tab   |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   |  \ |  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Cpslk | A/Ctl | S/Opt | D/Cmd | F/Sft |   G   |-------.    ,-------|   H   | J/Sft | K/Cmd | L/Opt | ;:/Ctl|  ' "  |
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * | Sft   |   Z   |   X   |   C   |   V   |   B   |-------|    |-------|   N   |   M   |  , <  |  . >  |  / ?  | Sft   |
 * `----------------------------------------------/       /      \       \----------------------------------------------'
 *            | Ctl   | Opt   | Cmd   | Tab/  |  / Space /        \ Bspc  \  | Enter/| Cmd   | Opt   | Ctl   |
 *            |       |       |       | Lower | /       /          \       \ | Raise |       |       |       |
 *            `-------------------------------''-------'            '-------''-------------------------------'
 */
[_HOME_ROW_MODS_ON] = LAYOUT(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
  KC_CAPS, CTL_A,   OPT_S,   CMD_D,   SFT_F,   KC_G,                         KC_H,    SFT_J,   CMD_K,   OPT_L,   CTL_SCN, KC_QUOT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                    KC_LCTL, KC_LOPT, KC_LCMD, LWR_TAB, KC_SPC,     KC_BSPC, RSE_ENT, KC_RCMD, KC_ROPT, KC_RCTL
),

/*
 * QWERTY with home row mods OFF
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | Esc ~ |  1 !  |  2 @  |  3 #  |  4 $  |  5 %  |                    |  6 ^  |  7 &  |  8 *  |  9 (  |  0 )  | Bspc  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Tab   |   Q   |   W   |   E   |   R   |   T   |                    |   Y   |   U   |   I   |   O   |   P   |  \ |  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Cpslk |   A   |   S   |   D   |   F   |   G   |-------.    ,-------|   H   |   J   |   K   |   L   |  ; :  |  ' "  |
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * | Sft   |   Z   |   X   |   C   |   V   |   B   |-------|    |-------|   N   |   M   |  , <  |  . >  |  / ?  | Sft   |
 * `----------------------------------------------/       /      \       \----------------------------------------------'
 *            | Ctl   | Opt   | Cmd   | Tab/  |  / Space /        \ Bspc  \  | Enter/| Cmd   | Opt   | Ctl   |
 *            |       |       |       | Lower | /       /          \       \ | Raise |       |       |       |
 *            `-------------------------------''-------'            '-------''-------------------------------'
 */
[_HOME_ROW_MODS_OFF] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______,
  _______, KC_A,     KC_S,   KC_D,    KC_F,    _______,                      _______, KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
  _______, _______, _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,
                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
),

/*
 * Lower: digits and symbols
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | Esc ~ |  F1   |  F2   |  F3   |  F4   |  F5   |                    |  F6   |  F7   |  F8   |  F9   | F10   | F11   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Tab   |   1   |   2   |   3   |   4   |   5   |                    |   6   |   7   |   8   |   9   |   0   | F12   |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Cpslk |   !   |   +   |   (   |   )   |   #   |-------.    ,-------|   |   |   -   |   =   |   _   |   *   | Bspc  |
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * | Sft   |   $   |   @   |   {   |   }   |   &   |-------|    |-------|   `   |   [   |   ]   |   %   |   ^   | Sft   |
 * `----------------------------------------------/       /      \       \----------------------------------------------'
 *            | Ctl   | Opt   | Cmd   |       |  / Space /        \ Bspc  \  | Enter/| Cmd   | Opt   | Ctl   |
 *            |       |       |       |       | /       /          \       \ | Adjust|       |       |       |
 *            `-------------------------------''-------'            '-------''-------------------------------'
 */
[_LOWER] = LAYOUT(
  _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_F12,
  _______, KC_EXLM, KC_PLUS, KC_LPRN, KC_RPRN, KC_HASH,                      KC_PIPE, KC_MINS, KC_EQL,  KC_UNDS, KC_ASTR, KC_BSPC,
  _______, KC_DLR,  KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, XXXXXXX,    XXXXXXX, KC_GRV,  KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, _______,
                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
),

/*
 * Raise: navigation and misc.
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |       |       |       |       |       |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Esc   | Ins   | Prev  | Play  | Next  |       |                    | PgUp  | PrvWrd| Up    | NxtWrd| DelLne| Bspc  |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * | Tab   | Ctl   | Opt   | Cmd   | Sft   | Cpslk |-------.    ,-------| PgDown| Left  | Down  | Right | Del   | Bspc  |
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * | Sft   | Undo  | Cut   | Copy  | Paste |       |-------|    |-------|       | LneBeg|       | LneEnd|       | Sft   |
 * `----------------------------------------------/       /      \       \----------------------------------------------'
 *            | Ctl   | Opt   | Cmd   | Tab/  |  / Space /        \ Bspc  \  |       | Cmd   | Opt   | Ctl   |
 *            |       |       |       | Adjust| /       /          \       \ |       |       |       |       |
 *            `-------------------------------''-------'            '-------''-------------------------------'
 */
[_RAISE] = LAYOUT(
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_ESC,  KC_INS,  KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX,                      KC_PGUP, PRV_WRD, KC_UP,   NXT_WRD, DEL_LNE, KC_BSPC,
  KC_TAB,  KC_LCTL, KC_LOPT, KC_LCMD, KC_LSFT, KC_CAPS,                      KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_DEL,  KC_BSPC,
  _______, UNDO,    CUT,     COPY,    PASTE,   XXXXXXX, _______,    XXXXXXX, XXXXXXX, LNE_BEG, XXXXXXX, LNE_END, XXXXXXX, _______,
                    _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
),

/*
 * Adjust: meta
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * | Reset |       |       |       |       |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |-------.    ,-------|       |Tog HRM|       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |-------|    |-------|       |       |       |       |       |       |
 * `----------------------------------------------/       /      \       \----------------------------------------------'
 *            |       |       |       |       |  /       /        \       \  |       |       |       |       |
 *            |       |       |       |       | /       /          \       \ |       |       |       |       |
 *            `-------------------------------''-------'            '-------''-------------------------------'
 */
[_ADJUST] = LAYOUT(
  RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, HRM_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/*
 * New layer template
 * ,-----------------------------------------------.                    ,-----------------------------------------------.
 * |       |       |       |       |       |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |                    |       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|                    |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |-------.    ,-------|       |       |       |       |       |       |
 * |-------+-------+-------+-------+-------+-------|       |    |       |-------+-------+-------+-------+-------+-------|
 * |       |       |       |       |       |       |-------|    |-------|       |       |       |       |       |       |
 * `----------------------------------------------/       /      \       \----------------------------------------------'
 *            |       |       |       |       |  /       /        \       \  |       |       |       |       |
 *            |       |       |       |       | /       /          \       \ |       |       |       |       |
 *            `-------------------------------''-------'            '-------''-------------------------------'
 */
/*[_LAYER] = LAYOUT(*/
  /*XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
  /*XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
  /*XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
  /*XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,*/
                    /*XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX*/
/*),*/
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (keycode == HRM_TOG && record->event.pressed) {
        if (get_highest_layer(default_layer_state) == _HOME_ROW_MODS_OFF)
            set_single_persistent_default_layer(_HOME_ROW_MODS_ON);
        else
            set_single_persistent_default_layer(_HOME_ROW_MODS_OFF);
        return false;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

#ifdef ENCODER_ENABLE

void encoder_scroll_down_up(bool clockwise) {
    if (clockwise) { tap_code(KC_PGDN); }
    else           { tap_code(KC_PGUP); }
}

void encoder_volume_up_down(bool clockwise) {
    if (clockwise) { tap_code(KC_VOLU); }
    else           { tap_code(KC_VOLD); }
}

void encoder_redo_undo(bool clockwise) {
    if (clockwise) { tap_code16(REDO); }
    else           { tap_code16(UNDO); }
}

void encoder_zoom_in_out(bool clockwise) {
    if (clockwise) { tap_code16(LCMD(KC_EQL )); }
    else           { tap_code16(LCMD(KC_MINS)); }
}

void left_encoder_update(uint8_t layer, bool clockwise) {
    switch (layer) {
        case _RAISE:
            encoder_volume_up_down(clockwise);
            break;
	default:
            encoder_scroll_down_up(clockwise);
    }
}

void right_encoder_update(uint8_t layer, bool clockwise) {
    switch (layer) {
        case _LOWER:
            encoder_zoom_in_out(clockwise);
            break;
	default:
            encoder_redo_undo(clockwise);
    }
}

void encoder_update_user(uint8_t index, bool clockwise) {
    uint8_t layer = get_highest_layer(layer_state);
    if      (index == 0) {  left_encoder_update(layer, clockwise); }
    else if (index == 1) { right_encoder_update(layer, clockwise); }
}

#endif

#ifdef OLED_DRIVER_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    oled_write_P(PSTR("\n\n"), false);

    // Print current layer
    switch (get_highest_layer(layer_state)) {
        case _HOME_ROW_MODS_ON:
        case _HOME_ROW_MODS_OFF:
            oled_write_P(PSTR("QWERT"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("LOWER"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("RAISE"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJST"), false);
            break;
    }
    oled_write_ln_P(PSTR("LAYER"), false);

    oled_write_P(PSTR("\n\n\n\n"), false);

    bool hrm_on = get_highest_layer(default_layer_state) == _HOME_ROW_MODS_ON;
    oled_write_ln_P(PSTR("HRMOD"), hrm_on);

    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
}

#endif
