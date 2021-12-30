#include "keymap.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* QWERTY
 * ,-----------------------------------------.
 * |      |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+------|
 * |  Tab |   Q  |   W  |   E  |   R  |   T  |
 * |------+------+------+------+------+------|
 * |  Esc |   A  |   S  |   D  |   F  |   G  |-------.
 * |------+------+------+------+------+------|  Ent  |
 * |  Sft |   Z  |   X  |   C  |   V  |   B  |-------|
 * `-------------+------+------+------+------|       /
 *               |  Ctl |  Opt |      | Raise|  Spc /
 *               `---------------------------------'
 */

 [_QWERTY] = LEFT(
    XXXXXXX, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
    KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,
    KC_ESC , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_ENT ,
                      KC_LCTL, KC_LOPT, XXXXXXX, RAISE  , KC_SPC
),

/* RAISE
 * ,-----------------------------------------.
 * |  Rst |  F1  |  F2  |  F3  |  F4  |  F5  |
 * |------+------+------+------+------+------|
 * |  Tab |   1  |   2  |   3  |   4  |   5  |
 * |------+------+------+------+------+------|
 * |  Esc | Togl | Sat+ | Hue+ | Bri+ | Mod+ |-------.
 * |------+------+------+------+------+------|  Bspc |
 * |  Sft | Togl | Sat- | Hue- | Bri- | Mod- |-------|
 * `-------------+------+------+------+------|       /
 *               |  Ctl |  Opt |      |      |  Spc /
 *               `---------------------------------'
 */
[_RAISE] = LEFT(
    RESET  , KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,
    _______, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,
    _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,
    _______, RGB_TOG, RGB_SAD, RGB_HUD, RGB_VAD,RGB_RMOD, KC_BSPC,
                      _______, _______, _______, _______, _______
)};
