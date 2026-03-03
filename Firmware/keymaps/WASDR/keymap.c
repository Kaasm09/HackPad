// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// ─────────────────────────────
// 1️⃣ Custom keycodes
// ─────────────────────────────
enum custom_keycodes {
    SPOTIFY = SAFE_RANGE,
    EMAIL1,
    EMAIL2,
    PASSWORD
};

// ─────────────────────────────
// 2️⃣ Keymap
// ─────────────────────────────
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
        SPOTIFY,
        EMAIL1,
        EMAIL2,
        PASSWORD,
        KC_MUTE
    )

};

// ─────────────────────────────
// 3️⃣ Macros
// ─────────────────────────────
bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    if (!record->event.pressed) {
        return true;
    }

    switch (keycode) {

        case SPOTIFY:
            tap_code(KC_LGUI);      // Open Start
            wait_ms(150);           // Short delay (usually enough)
            SEND_STRING("spotify");
            wait_ms(75);
            tap_code(KC_ENTER);
            return false;

        case EMAIL1:
            SEND_STRING("****");
            return false;

        case EMAIL2:
            SEND_STRING("*****");
            return false;

        case PASSWORD:
            SEND_STRING("*****");
            return false;
    }

    return true;
}

// ─────────────────────────────
// 4️⃣ Rotary Encoder
// ─────────────────────────────
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
    return false;

}
