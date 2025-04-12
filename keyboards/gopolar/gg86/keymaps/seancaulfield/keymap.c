/* Copyright 2023 Gopolar
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
#include "lib/wave.h" // OLED animation

enum {
  _BASE_LINUX,
  _BASE_MACOS,
  _FN_LINUX,
  _FN_MACOS,
};

#define FNLINUX MO(_FN_LINUX)
#define FNMACOS MO(_FN_MACOS)
#define RGB_RMD RGB_RMOD


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE_LINUX] = LAYOUT_all(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUSE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,          KC_UP,
        KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT, FNLINUX, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_BASE_MACOS] = LAYOUT_all(
        KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,           KC_PSCR, KC_SCRL, KC_PAUSE,
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_INS,  KC_HOME, KC_PGUP,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL,  KC_END,  KC_PGDN,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,
        KC_LSFT, KC_NUBS, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_RSFT,          KC_UP,
        KC_LCTL, KC_LOPT, KC_LCMD,                   KC_SPC,                                      KC_RCMD, FNLINUX, KC_RCTL,          KC_LEFT, KC_DOWN, KC_RIGHT
    ),

    [_FN_LINUX] = LAYOUT_all(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,  _______, EE_CLR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, RGB_RMD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_VOLU,
        _______, _______, _______,                   _______,                                     _______, _______, _______,          KC_MPRV,  KC_VOLD, KC_MNXT
    ),

    [_FN_MACOS] = LAYOUT_all(
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,          _______,  _______, EE_CLR,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        RGB_TOG, RGB_MOD, RGB_VAI, RGB_HUI, RGB_SAI, RGB_SPI, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, RGB_RMD, RGB_VAD, RGB_HUD, RGB_SAD, RGB_SPD, _______, _______, _______, _______, _______, _______,          _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_VOLU,
        _______, _______, _______,                   _______,                                     _______, _______, _______,          KC_MPRV,  KC_VOLD, KC_MNXT
    ),

};

#ifdef OLED_ENABLE
    static void render_layer_info(void) {
        switch (get_highest_layer(layer_state)) {
            case _BASE_LINUX:
                oled_write_P(PSTR("Linux/Win    "), false);
                break;
            case _BASE_MACOS:
                oled_write_P(PSTR("MacOS/iOS    "), false);
                break;
            case _FN_LINUX:
                oled_write_P(PSTR("Linux Fn     "), false);
                break;
            case _FN_MACOS:
                oled_write_P(PSTR("MacOS Fn     "), false);
                break;
            default:
                oled_write_P(PSTR("Undefined    "), false);
        }
    }

    static void render_layer_number(void) {
        switch (get_highest_layer(layer_state)) {
            case 0:
                oled_write_P(PSTR("0"), false);
                break;
            case 1:
                oled_write_P(PSTR("1"), false);
                break;
            case 2:
                oled_write_P(PSTR("2"), false);
                break;
            case 3:
                oled_write_P(PSTR("3"), false);
                break;
            default:
                oled_write_P(PSTR("?"), false);
        }
    }

    bool oled_task_user(void) {
        led_t led_usb_state = host_keyboard_led_state();

        oled_write_P(led_usb_state.caps_lock ? PSTR("CAPLK ") : PSTR("----- "), false);
        oled_write_P(PSTR(" GOPOLAR "), false);
        //oled_write_P(led_usb_state.scroll_lock ? PSTR(" SCRLK") : PSTR(" -----"), false);
        oled_write_P(PSTR(" moooo"), false);

        // sleep if it has been long enough since we last got a char
        //if (timer_elapsed32(wave_sleep) > OLED_TIMEOUT) {
        //    oled_off();
        //} else {
        //    oled_on();
        //}
        // time for the next frame?
        if (timer_elapsed(wave_timer) > FRAME_TIMEOUT) {
            wave_timer = timer_read();
            render_frame();
        }

        oled_set_cursor(0, 3);
        render_layer_info();
        oled_write_P(PSTR("Layer: "), false);
        render_layer_number();

        return true;
    }
#endif

bool rgb_matrix_indicators_user(void) {
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(25, 255, 255, 255);
        //rgb_matrix_set_color(73, 255, 255, 255);
        return false;
    }
    return true;
}
