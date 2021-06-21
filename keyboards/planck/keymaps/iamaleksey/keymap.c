#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DHm
 * ,-----------------------------------------------------------------------------------.
 * |      |Q..Esc|   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  | ;  : | \  | |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc `| A/Ctl| R/Opt| S/Cmd| T/Sft|   G  |   M  | N/Sft| E/Cmd| I/Opt| O/Ctl| '  " |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   D  |   V  |   K  |   H  | ,  < | .  > | /  ? |CpsWrd|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |LwrTab| Space| Bspc |RseEnt|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_ortho_4x12(
    XXXXXXX, Q_ESC,   KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    KC_GESC, LCTL_A,  LOPT_R,  LCMD_S,  SHFT_T,  KC_G,    KC_M,    RSFT_N,  RCMD_E,  ROPT_I,  RCTL_O,  KC_QUOT,
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, CAPS_WRD,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LWR_TAB, KC_SPC,  KC_BSPC, RSE_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* QWERTY
 * ,-----------------------------------------------------------------------------------.
 * |      |Q..Esc|   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \  | |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc `| A/Ctl| S/Opt| D/Cmd| F/Sft|   G  |   H  | J/Sft| K/Cmd| L/Opt|;:/Ctl| '  " |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   Z  |   X  |   C  |   V  |   B  |   N  |   M  | ,  < | .  > | /  ? |CpsWrd|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |LwrTab| Space| Bspc |RseEnt|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    XXXXXXX, Q_ESC,   KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
    KC_GESC, LCTL_A,  LOPT_S,  LCMD_D,  SHFT_F,  KC_G,    KC_H,    RSFT_J,  RCMD_K,  ROPT_L,  CTL_SCLN,KC_QUOT,
    XXXXXXX, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, CAPS_WRD,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LWR_TAB, KC_SPC,  KC_BSPC, RSE_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* WASD
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | \  | |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc `|   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  | ;  : | '  " |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Sft  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  | ,  < | .  > | /  ? | Ent  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Ctl  | Opt  | Cmd  | Lower| Space| Bspc | Raise| Cmd  | Opt  | Ctl  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_WASD] = LAYOUT_ortho_4x12(
    KC_TAB,  KC_Q,    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_A,    KC_S,    KC_D,    KC_F,    _______, _______, KC_J,    KC_K,    KC_L,    KC_SCLN, _______,
    KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_ENT,
    XXXXXXX, KC_LCTL, KC_LOPT, KC_LCMD, LOWER,   _______, _______, RAISE,   KC_RCMD, KC_ROPT, KC_RCTL, XXXXXXX
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   +  |   (  |   )  |   #  |   |  |   -  |   =  |   _  |   *  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   $  |   @  |   {  |   }  |   &  |   `  |   [  |   ]  |   %  |   ^  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Space| Bspc |Adjust|      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
    XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    XXXXXXX,
    XXXXXXX, KC_EXLM, KC_PLUS, KC_LPRN, KC_RPRN, KC_HASH, KC_PIPE, KC_MINS, KC_EQL,  KC_UNDS, KC_ASTR, XXXXXXX,
    XXXXXXX, KC_DLR,  KC_AT,   KC_LCBR, KC_RCBR, KC_AMPR, KC_GRV,  KC_LBRC, KC_RBRC, KC_PERC, KC_CIRC, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_SPC,  KC_BSPC, RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Prev | Play | Next |      | Left | Down |  Up  | Right|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Vol- | Mute | Vol+ |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |Adjust| Space| Bspc |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, KC_VOLD, KC_MUTE, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   KC_SPC,  KC_BSPC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * | Reset| F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Togl | Sat+ | Hue+ | Bri+ | Mode+|      |COLEMK|QWERTY| WASD | F11  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Togl | Sat- | Hue- | Bri- | Mode-|      |      |      |      | F12  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    RESET,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX,
    XXXXXXX, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD, XXXXXXX, COLEMAK, QWERTY,  WASD,    KC_F11,  XXXXXXX,
    XXXXXXX, RGB_TOG, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_F12,  XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
)

};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

qk_tap_dance_action_t tap_dance_actions[] = {
    [_Q_ESC] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_ESC)
};

// CAPS_WORD: A "smart" Caps Lock key that only capitalizes the next identifier you type
// and then toggles off Caps Lock automatically when you're done.
void caps_word_enable(void) {
    caps_word_on = true;
    if (!(host_keyboard_led_state().caps_lock)) {
        tap_code(KC_CAPS);
    }
}

void caps_word_disable(void) {
    caps_word_on = false;
    if (host_keyboard_led_state().caps_lock) {
        tap_code(KC_CAPS);
    }
}

// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

void process_caps_word(uint16_t keycode, const keyrecord_t *record) {
    // Update caps word state
    if (caps_word_on) {
        switch (keycode) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                // Earlier return if this has not been considered tapped yet
                if (record->tap.count == 0) { return; }
                // Get the base tapping keycode of a mod- or layer-tap key
                keycode = GET_TAP_KC(keycode);
                break;
            default:
                break;
        }

        switch (keycode) {
            // Keycodes to shift
            case KC_A ... KC_Z:
                if (record->event.pressed) {
                    caps_word_enable();
                }
            // Keycodes that enable caps word but shouldn't get shifted
            case KC_MINS:
            case KC_BSPC:
            case KC_UNDS:
            case KC_PIPE:
            case CAPS_WRD:
                // If chording mods, disable caps word
                if (record->event.pressed && (get_mods() != MOD_LSFT) && (get_mods() != 0)) {
                    caps_word_disable();
                }
                break;
            default:
                // Any other keycode should automatically disable caps
                if (record->event.pressed) {
                    caps_word_disable();
                }
                break;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_caps_word(keycode, record);

    switch (keycode) {
    case CAPS_WRD:
	// Toggle `caps_word_on`
	if (record->event.pressed) {
	    if (caps_word_on) {
		caps_word_disable();
	    } else {
		caps_word_enable();
	    }
	    return false;
	}
	break;
    case COLEMAK:
	set_single_persistent_default_layer(_COLEMAK);
	return false;
    case QWERTY:
	set_single_persistent_default_layer(_QWERTY);
	return false;
    case WASD:
	set_single_persistent_default_layer(_WASD);
	return false;
    }

    return true;
}
