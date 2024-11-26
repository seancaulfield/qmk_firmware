// Copyright 2024 Jason Williams (@wilba)
// SPDX-License-Identifier: GPL-2.0-or-later

// Default layout for WT65-H2
#include QMK_KEYBOARD_H
#include "quantum.h"
#include "os_detection.h"  

enum {
  _BASE_LINUX,
  _BASE_MACOS,
  _FN_LINUX,
  _FN_MACOS,
};

#define FNLINUX MO(_FN_LINUX)
#define FNMACOS MO(_FN_MACOS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE_LINUX] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP,
        KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   FNLINUX,
        KC_LCTL,          KC_LALT,                            KC_SPC,                                      KC_RGUI,          KC_LEFT, KC_DOWN, KC_RGHT),

    [_BASE_MACOS] = LAYOUT_all(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,  KC_DEL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,          KC_PGUP,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                    KC_PGDN,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,                   KC_UP,   FNMACOS,
        KC_LGUI,          KC_LALT,                            KC_SPC,                                      KC_RALT,          KC_LEFT, KC_DOWN, KC_RGHT),

    [_FN_LINUX] = LAYOUT_all(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______,          _______,
        _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT, _______, _______, _______, KC_HOME, KC_PGUP, _______, _______, _______,                   _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, KC_END,  KC_PGDN, _______, _______,                   _______, _______,
        _______,          _______,                            _______,                                     _______,          _______, _______, _______),

    [_FN_MACOS] = LAYOUT_all(
        QK_BOOT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, _______, KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SCRL, KC_PAUS, _______, _______, _______,          _______,
        _______, KC_MUTE, KC_VOLD, KC_VOLU, KC_EJCT, _______, _______, _______, KC_HOME, KC_PGUP, _______, _______, _______,                   _______,
        _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, _______, _______, KC_END,  KC_PGDN, _______, _______,                   _______, _______,
        _______,          _______,                            _______,                                     _______,          _______, _______, _______),
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

