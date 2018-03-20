#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_jp.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Keycodes define
#define LOW_ES  LT(_LOWER, KC_LANG2)  // タップで英数 ホールドでLower
#define RIS_KN  LT(_RAISE, KC_LANG1)  // タップでかな ホールドでRaise
#define KC_DQOT KC_DOUBLE_QUOTE
#define JA_CLON KC_QUOTE  // : and +
#define JA_AT   KC_LBRACKET  // @ and `
#define JA_HAT  KC_EQUAL   // ^ and ~
#define JA_ENUN KC_INT1    // \ and _ (EN mark and UNder score)
#define JA_ENVL KC_INT3  // \ and | (EN mark and Vertical Line)
#define JA_LBRC KC_RBRACKET  // [ and {
#define JA_RBRC KC_BSLASH   // ] and }


#define ADJUST  TG(_ADJUST)           // ホールドでAdjustレイヤーをon

#define TGL_LOW TG(_LOWER)            // Lowerトグル
#define TGL_RIS TG(_RAISE)            // Raiseトグル

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {


/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  | ENTR |  TAB |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  | ESC  | ENTR |   H  |   J  |   K  |   L  |   @  |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  | SPACE| SPACE|   N  |   M  |   ,  |   .  |   :  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |L_SFT |  GUI |  ALT | LOWER| BACK |ES/LW |RIS/KN| SHFT | RAISE|   -  |   [  |   ]  |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_Q,    KC_W,     KC_E,    KC_R,   KC_T,     KC_ENT,         KC_ENT,  KC_Y,    KC_U,   KC_I,    KC_O,   KC_P, \
  KC_A,    KC_S,     KC_D,    KC_F,   KC_G,     KC_ESC,        KC_TAB,  KC_H,    KC_J,   KC_K,    KC_L,   JA_AT, \
  KC_Z,    KC_X,     KC_C,    KC_V,   KC_B,     KC_SPC,         KC_SPC,  KC_N,    KC_M,   KC_COMM, KC_DOT, JA_CLON, \
  KC_LSFT,  KC_LGUI,  KC_LALT, TGL_LOW,KC_BSPC,  LOW_ES,         RIS_KN,  KC_RSFT, TGL_RIS,KC_MINS, JA_LBRC, JA_RBRC \
),


/* Lower   (switched to # because KP# were weird in terminal emulators)
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp | DEL  |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   4  |   5  |   6  |   .  |  *   |  ~   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |   1  |   2  |   3  |   /  |Enter | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |   0  |   =  |RAISE |   -  |  +   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_1,    KC_2,    KC_3,   KC_4,    KC_5,    KC_6,       KC_7,  KC_8,   KC_9,   KC_0,    KC_BSPC, KC_DEL, \
  KC_F1,   KC_F2,   KC_F3,  KC_F4,   KC_F5,   KC_F6,      KC_4,  KC_5,   KC_6,   KC_DOT,  KC_ASTR, KC_TILD, \
  KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,     KC_1,  KC_2,   KC_3,   KC_SLSH, _______, _______, \
  _______, _______, _______, _______, _______,_______,    KC_0,  KC_EQL, _______, KC_MINS, KC_PLUS, KC_RCTRL  \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   !  |   "  |   #  |   $  |   %  |   &  |   '  |   (  |   )  |   =  |   ~  |  |   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |   !  |   "  |   #  |   $  |   %  |   &  |   '  |   (  |   )  |   -  |   ^  |  ¥   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      | PGUP |      |      | ENTER|SPACE | SPACE| ENTER|QWERTY|  /   |  UP  |  ¥ _ |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | HOME | PGDN | END  |LOWER | BACK | EISU | KANA | SHIFT| RAISE| LEFT | DOWN | RIGHT|
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_EXLM,   KC_DQOT,   KC_HASH, KC_DLR,  KC_PERC, KC_AMPR,   KC_QUOTE, KC_ASTR, KC_LPRN, KC_RPRN,   JA_HAT,   JA_ENVL, \
  KC_EXLM,   KC_WH_U,   KC_BTN2, KC_MS_U, KC_BTN1, QWERTY,    KC_LEFT,  KC_DOWN, KC_UP,   KC_RGHT,   KC_PIPE,  KC_GRV, \
  _______,   KC_PGUP,   _______, _______, KC_ENT,  KC_SPC,    KC_SPC,   KC_ENT,  QWERTY, KC_SLSH,   KC_UP,    JA_ENUN, \
  KC_HOME,   KC_PGDN,   KC_END, _______,  _______,  LOW_ES,    RIS_KN,   KC_RSFT, _______, KC_LEFT,   KC_DOWN,  KC_RIGHT \
),

/* ADJUST
 * ,-----------------------------------------------------------------------------------.
 * | RESET| WH_U |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |      | WH_U | RESET|
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | WH_L | WH_D | WH_R |   D  |   F  |   G  |   H  |   J  |   K  | WH_L | WH_D | WH_R |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | L_CL | MS_UP| R_CL |   C  |   V  |QWERTY|QWERTY|   M  |   ,  | L_CL | MS_UP| R_CL |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | MS_LF| MS_DN|MS_RF |RESET | Lower|    Space    |Raise | Left | MS_LF| MS_DN| MS_RF|
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
  RESET,   KC_WH_U,    _______,    _______,    _______,    _______,    _______,    _______,   _______,    _______,   KC_WH_U,    RESET, \
  KC_WH_L,   KC_WH_D,    KC_WH_R,    _______,    _______,    _______,    _______,    _______,   _______,    KC_WH_L,   KC_WH_D, KC_WH_R, \
  KC_BTN1,   KC_MS_U,    KC_BTN2,    _______,    _______,   QWERTY, QWERTY,    _______,   KC_COMM, KC_BTN1, KC_MS_U, KC_BTN2 , \
  KC_MS_L,   KC_MS_D,    KC_MS_R,    RESET,    LOWER,  KC_SPC,  KC_SPC,   RAISE,  KC_LEFT, KC_MS_L, KC_MS_D, KC_MS_R \
)


};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
