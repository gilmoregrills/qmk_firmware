/* Copyright 2019 funderburker
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define _______ KC_TRNS
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _SETTINGS 3

#define LOWER  MO(_LOWER)
#define RAISE  MO(_RAISE)
#define SETTINGS MO(_SETTINGS)

// Emoji name list
enum unicode_names {
  HEART
};

// Emoji mappings
const uint32_t PROGMEM unicode_map[] = {
  [HEART]  = 0x1F496,  // heart with sparkles
};

// Macro name list
enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  TILDE,
  PIPE
};

// SEND_STRING macros
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case TILDE:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING("~");
      } else {
        // when keycode is released
      }
      break;
    case PIPE:
      if (record->event.pressed) {
        // when keycode is pressed
        SEND_STRING("|");
      } else {
        // when keycode is released
      }
      break;

  }
  return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // Default layer
  [0] = LAYOUT(
		SETTINGS,          KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I,    KC_O,   KC_P,    KC_LBRC, KC_RBRC, KC_MINS,
		KC_PGUP,  KC_TAB,  KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K,    KC_L,   KC_SCLN, KC_QUOT, KC_ENT,
		KC_PGDN,  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, LOWER,
		HEART,    KC_ESC,           KC_LGUI, LOWER, LT(RAISE, KC_SPC), KC_BSPC, KC_LALT, KC_RCTRL
  ),

  // LOWER layer
  [1] = LAYOUT(
		_______,          KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,     KC_LPRN, KC_RPRN, KC_EQL,
		_______, TILDE,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, _______, _______,  _______,  _______,
		_______, _______, PIPE,    _______, _______, KC_SPC,  _______, KC_SPC,  _______, _______, _______, KC_BSLS,  _______, _______,
		_______, KC_GRV,              _______, _______, _______, KC_DEL, _______, _______
  ),

  // RAISE layer
  [2] = LAYOUT(
		_______,          KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,
		_______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______, _______,
		_______, _______, KC_MPLY, KC_MPRV, KC_MNXT, _______, _______, KC_HOME, _______, _______, KC_END,   _______, _______, _______,
		_______, _______,             _______, _______, _______, _______, _______, _______
  ),

  // SETTINGS layer
  [3] = LAYOUT(
        _______,          _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
		_______, _______, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, BL_TOGG, BL_INC,  _______, _______, _______, _______, _______, _______,
		_______, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, BL_STEP, BL_DEC,  _______, _______, _______, _______, _______, _______,
		_______, RESET,               _______, _______, _______, _______, _______, _______
  ),
};
