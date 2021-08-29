#include QMK_KEYBOARD_H

enum layers { _COLEMAK, _SYMBOL, _EXTEND, _ADJUST };

enum keycodes { CAPS_WRD = SAFE_RANGE };

// Layer switching
#define TAB_SYM LT(_SYMBOL, KC_TAB)
#define ESC_EXT LT(_EXTEND, KC_ESC)
#define BSP_EXT LT(_EXTEND, KC_BSPC)

// Home row mods
#define A_LCTL LCTL_T(KC_A)
#define R_LOPT LOPT_T(KC_R)
#define S_LCMD LCMD_T(KC_S)
#define T_LSFT LSFT_T(KC_T)
#define N_RSFT RSFT_T(KC_N)
#define E_RCMD RCMD_T(KC_E)
#define I_ROPT ROPT_T(KC_I)
#define O_RCTL RCTL_T(KC_O)

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

// Caps word
bool caps_word_on;
void caps_word_enable(void);
void caps_word_disable(void);

// Tap dances
enum dances { _TD_DOT };
#define TD_DOT TD(_TD_DOT)