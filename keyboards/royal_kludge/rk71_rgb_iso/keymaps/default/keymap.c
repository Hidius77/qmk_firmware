/* Copyright (C) 2023 Fernando Birra
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H

#define CAPS_LOCK_LED   32

enum layer_names {
    WINBASE,
    FNS
};



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Windows Base
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┬───┐
     * │Esc│ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Ins│Hom│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┼───┤§§§§§/.//
     * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │     │Del│End│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ Ent├───┼───┤
     * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │    │PAU│PgU│
     * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┼───┼───┤
     * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │ Shift    │ ↑ │PgD│
     * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬┬───┼───┼───┤
     * │Ctrl│GUI │Alt │                        │ Alt│ GUI│Ctrl││ ← │ ↓ │ → │
     * └────┴────┴────┴────────────────────────┴────┴────┴────┘└───┴───┴───┘
     */
    [WINBASE] = LAYOUT_68_iso(
        QK_GESC,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,       KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       KC_MINS,     KC_EQL,     KC_BSPC,   KC_INS,     KC_HOME,
        KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,       KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_LBRC,     KC_RBRC,               KC_DEL,     KC_END,
        KC_CAPS,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,       KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,     KC_BSLS,    KC_ENT,    KC_PAUSE,   KC_PGUP,
        KC_LSFT,    KC_NUBS,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,       KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,     KC_RSFT,               KC_UP,     KC_PGDN,
        KC_LCTL,    KC_LGUI,    KC_LALT,                                        KC_SPC,                             KC_RALT,    MO(FNS),    KC_RCTL,                 KC_LEFT,   KC_DOWN,   KC_RGHT
    ),
    /* Fn 
     * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┬───┐§
     * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │   │Tog│
     * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┼───┤
     * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │Nex│
     * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐    ├───┼───┤
     * │      │   │   │   │   │   │   │   │   │   │   │   │   │    │Prn│HuU│
     * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴────┼───┼───┤
     * │        │   │   │   │   │   │   │   │   │   │   │          │VaU│HuD│
     * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬────┬┬───┼───┼───┤
     * │    │    │    │                        │    │    │    ││SpD│VaD│SpU│
     * └────┴────┴────┴────────────────────────┴────┴────┴────┘└───┴───┴───┘
     */
    [FNS] = LAYOUT_68_iso(
        QK_BOOT,    KC_F1,      KC_F2,       KC_F3,      KC_F4,      KC_F5,      KC_F6,      KC_F7,      KC_F8,      KC_F9,      KC_F10,     KC_F11,      KC_F12,     _______,   _______,     RM_TOGG,
        _______,    _______,    _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,               _______,     RM_NEXT,
        _______,    _______,    _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,    _______,   KC_PSCR,     RM_HUEU,
        _______,    _______,    _______,     _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,    _______,     _______,               RM_VALU,     RM_HUED,
        _______,    _______,    _______,                                         _______,                            _______,    _______,    _______,                 RM_SPDD,   RM_VALD,     RM_SPDU
    )
};


bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    // Couleur violette pour le layer FN
    uint8_t purple[3] = {200, 0, 255};

    // Caps Lock toujours violet
    if (host_keyboard_led_state().caps_lock) {
        rgb_matrix_set_color(CAPS_LOCK_LED, purple[0], purple[1], purple[2]);
    }

    return false;
}
