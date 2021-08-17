#include QMK_KEYBOARD_H

enum layers { _COLEMAK, _QWERTY, _SYMBOL, _EXTEND, _ADJUST };

// Layer switching / mod taps
#define COLEMAK DF(_COLEMAK)
#define QWERTY  DF(_QWERTY)
#define EXTEND  MO(_EXTEND)
#define SYMBOL  MO(_SYMBOL)
#define ADJUST  MO(_ADJUST)
#define TAB_SYM LT(_SYMBOL, KC_TAB)
#define BSP_EXT LT(_EXTEND, KC_BSPC)

// Home row mods (Colemak-DHm)
#define LCTL_A LCTL_T(KC_A)
#define LOPT_R LOPT_T(KC_R)
#define LCMD_S LCMD_T(KC_S)
#define SHFT_T LSFT_T(KC_T)
#define RSFT_N RSFT_T(KC_N)
#define RCMD_E RCMD_T(KC_E)
#define ROPT_I LOPT_T(KC_I)
#define RCTL_O RCTL_T(KC_O)

// Home row mods (QWERTY)
#define LCTL_A LCTL_T(KC_A)
#define LOPT_S LOPT_T(KC_S)
#define LCMD_D LCMD_T(KC_D)
#define SHFT_F LSFT_T(KC_F)
#define RSFT_J RSFT_T(KC_J)
#define RCMD_K RCMD_T(KC_K)
#define ROPT_L ROPT_T(KC_L)
#define CTL_SCLN RCTL_T(KC_SCLN)

// Text navigation / manipulation
#define LNE_BEG LCMD(KC_LEFT)
#define LNE_END LCMD(KC_RGHT)
#define DEL_LNE LCMD(KC_BSPC)
#define PRV_WRD LOPT(KC_LEFT)
#define NXT_WRD LOPT(KC_RGHT)

// Undo / redo / cut / copy / paste
#define UNDO  LCMD(KC_Z)
#define REDO  LSFT(UNDO)
#define CUT   LCMD(KC_X)
#define COPY  LCMD(KC_C)
#define PASTE LCMD(KC_V)
