// Copyright 2020 QMK / James Young (@noroadsleft)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"
#include "os_detection.h"  

enum {
  _BASE_LINUX,
  _BASE_MACOS,
  _LAYER_FN1,
  _LAYER_FN2,
};

#define KC_FN1 MO(_LAYER_FN1)
#define KC_FN2 MO(_LAYER_FN2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE_LINUX] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_ENT,
        KC_LCTL, KC_LALT, KC_FN1,                    KC_SPC,                             KC_FN2,  KC_SLSH, KC_RGUI
    ),

    [_BASE_MACOS] = LAYOUT(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
        KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_ENT,
        KC_LCTL, KC_LCMD, KC_FN1,                    KC_SPC,                             KC_FN2,  KC_SLSH, KC_ROPT
    ),

    [_LAYER_FN1] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_QUOT, KC_BSLS, _______, _______, KC_PGUP, KC_PGDN, KC_INS,
        _______, _______, _______, _______, _______, KC_HOME, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_END,
        _______, _______, _______,                   _______,                            _______, _______, _______
    ),

    [_LAYER_FN2] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______,                   _______,                            _______, _______, _______
    ),

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
