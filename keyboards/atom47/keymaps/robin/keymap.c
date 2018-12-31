#include QMK_KEYBOARD_H
/*
 * Each layer gets a name for readability, which is then used in the keymap matrix below.
 * The underscores don't mean anything - you can have a layer called STUFF or any other name.
 * Layer names don't all need to be of the same length, obviously, and you can also skip them
 * entirely and just use numbers.
 */

#define _MA 0 //Main layer
#define _FN 1 //Fn
#define _FN1 3 //Fn1
#define _FN2 4 //Fn2

#define _______ KC_TRNS

/* MACROS
 * To add a new macro, simply add a new case to the process_record_user() switch statement like:
 *
 * case MACRO_NAME:
 *   if (record->event.pressed) {
 *     // do something on press, like SEND_STRING()
 *   } else {
 *     // do something on release
 *   }
 *   break;
 *
 * Then add the macro name to the macro_aliases enum, and add it to the keymap!
 */

enum macro_aliases {
  M_EMAIL = SAFE_RANGE,
  M_EMAIL2,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_EMAIL:
      if (record->event.pressed) {
        // when macro keycode is pressed
        SEND_STRING("robinfarrowyonge@gmail.com");
      } else {
        // when macro keycode is released
      }
      break;
    case M_EMAIL2:
      if (record->event.pressed) {
        // when macro keycode is pressed
        SEND_STRING("robin.farrow-yonge@news.co.uk");
      } else {
        // when macro keycode is released
      }
      break;

  }
  return true;
};

/* EMOJIS
 * Add emojis to the map below, ideally following the naming convention used already: [E_<emoji_name>] = 0x<unicode code>, //<emoji>
 * Then, make sure that E_<emoji_name> is added to the unicode_aliases enum (the map and the enum should be in the same order, too).
 * Once the emoji's been added like that, you can use it in keymaps with X(<unicode_alias>)
 */

enum unicode_aliases {
  E_QQ,
  E_WINK,
  E_EGGP,
  E_RAIN,
  E_TONG,
  E_YY,
  E_SNEK,
};

const uint32_t PROGMEM unicode_map[] = {
  [E_QQ]   = 0x1F62D, // 😭
  [E_WINK] = 0x1F609, // 😉
  [E_EGGP] = 0x1F346, // 🍆
  [E_RAIN] = 0x1F4A6, // 💦
  [E_TONG] = 0x1F61B, // 😛
  [E_YY]   = 0x1F914, // 🤔
  [E_SNEK] = 0x1F40D, // 🐍
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_MA] = LAYOUT(
  KC_ESC,       KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,    KC_RBRC,   \
  KC_TAB,       KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,                KC_ENT,    \
  KC_LSPO,                  KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_RSPC,    MO(_FN),   \
  KC_LCTL,      KC_LALT,    KC_LGUI,    MO(_FN),                LT(_FN1, KC_SPC),       KC_BSPC,                MO(_FN2),   KC_MINUS,   KC_APP,     KC_RCTRL), \

[_FN] = LAYOUT(
  KC_GRV,       KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_LPRN,    KC_RPRN,    \
  _______,      KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,    KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_EQL,     KC_QUOT,                _______,    \
  _______,                  KC_BSLS,    KC_GRAVE,   _______,    _______,    _______,    _______,    _______,    _______,    KC_SLSH,    _______,    _______,    \
  _______,      _______,    _______,    _______,                _______,                KC_DEL,                 _______,    _______,    _______,    _______),   \

[_FN1] = LAYOUT(
  KC_POWER,     KC_F1,      KC_F2,      KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,     KC_F12,     \
  _______,      _______,    M_EMAIL,    M_EMAIL2,   _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,                _______,    \
  _______,                  _______,    _______,    _______,    _______,    KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     _______,    _______,    _______,    \
  _______,      _______,    _______,    _______,                _______,                KC_DEL,                 _______,    _______,    _______,    RESET),     \

[_FN2] = LAYOUT(
  UC_M_OS,     X(E_QQ),     X(E_WINK),  X(E_EGGP),  X(E_RAIN),  X(E_TONG),  X(E_YY),    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,     _______,     X(E_SNEK),  _______,    _______,    _______,    KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    _______,                _______,    \
  _______,                  _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    \
  _______,     _______,     _______,    _______,                _______,                _______,                _______,    _______,    _______,    _______),   \
};

void led_set_user(uint8_t usb_led) {
    if (usb_led & (1<<USB_LED_CAPS_LOCK)) {
        // Turn capslock on
        PORTE &= ~(1 << 6);
    } else {
        // Turn capslock offp
        PORTE |= (1 << 6);
    }
}
