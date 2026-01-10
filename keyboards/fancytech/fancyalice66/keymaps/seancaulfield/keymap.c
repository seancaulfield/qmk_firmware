/* Copyright 2023 Adophoxia <https://github.com/Adophoxia>
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
#include "quantum.h"
#include "os_detection.h"

enum my_layers {
  _BASE_LINUX,
  _BASE_MACOS,
  _FN_LINUX,
  _FN_MACOS,
};

#define FNLINUX MO(_FN_LINUX)
#define FNMACOS MO(_FN_MACOS)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /*
     *    ┌───┬───┬───┬───┬───┬───┬───┐   ┌───┬───┬───┬───┬───┬───┬───────┐  ┌───┐
     *    │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │   │ 7 │ 8 │ 9 │ 0 │ - │ = │Backsp │  │Del│
     *   ┌┴───┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┘ ┌─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┴┐ └┬──┴┐
     *   │ Tab │ Q │ W │ E │ R │ T │    │ Y │ U │ I │ O │ P │ [ │ ] │  \   │  │PgD│
     *  ┌┴─────┼───┼───┼───┼───┼───┤    └┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴──────┴┐ └┬──┴┐
     *  │ Caps │ A │ S │ D │ F │ G │     │ H │ J │ K │ L │ ; │ ' │  Enter   │  │PgU│
     * ┌┴──────┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    └─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───────┬─┬┴──┼───┘
     * │ Shift  │ Z │ X │ C │ V │ B │      │ N │ M │ , │ . │ / │  Shift  │ │Up │
     * ├─────┬──┴───┼───┴─┬─┴───┴─┬─┴─┐  ┌─┴───┴───┴┬──┴──┬┴───┴───────┬─┴─┼───┼───┐
     * │ Ctl │      │ Alt │       │FN │  │          │ Alt │            │Lft│Dwn│Rgt│
     * └─────┘      └─────┴───────┴───┘  └──────────┴─────┘            └───┴───┴───┘
     */

    [_BASE_LINUX] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
        KC_LCTL,          KC_LALT, KC_SPC,                    FNLINUX, KC_SPC,                    KC_RGUI,                   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_BASE_MACOS] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,           KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,             KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,
        KC_LCTL,          KC_LCMD, KC_SPC,                    FNMACOS, KC_SPC,                    KC_ROPT,                   KC_LEFT, KC_DOWN, KC_RGHT
    ),

    [_FN_LINUX] = LAYOUT(
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          QK_BOOT,
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU,          _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD,          _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,          KC_VOLU,
	_______,          _______, _______,                   _______, _______,                   _______,                   KC_MPRV, KC_VOLD, KC_MNXT
    ),

    [_FN_MACOS] = LAYOUT(
        KC_TILD, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_PSCR,          QK_BOOT,
        RM_TOGG, RM_NEXT, RM_VALU, RM_HUEU, RM_SATU, RM_SPDU,          _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, RM_PREV, RM_VALD, RM_HUED, RM_SATD, RM_SPDD,          _______, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______,          KC_VOLU,
	_______,          _______, _______,                   _______, _______,                   _______,                   KC_MPRV, KC_VOLD, KC_MNXT
    )
};

bool process_detected_host_os_kb(os_variant_t detected_os) {
    if (!process_detected_host_os_user(detected_os)) {
        return false;
    }
    switch (detected_os) {
        case OS_MACOS:
        case OS_IOS:
            layer_move(_BASE_MACOS);
            break;
        case OS_LINUX:
        case OS_WINDOWS:
        case OS_UNSURE:
        default:
            layer_move(_BASE_LINUX);
            break;
    }

    return true;
}
