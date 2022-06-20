/*
 Copyright (C) 2021,2022 Geno <geno@live.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include "actionmap.h"
#include "action_code.h"
#include "actionmap_common.h"
#include "keyboard_fn.h"
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"
#include "user_fn.h"

/* 
 * 定义需使用的FN按键
 */
#define AC_FN0    ACTION_LAYER_TAP(3, KC_UP)
#define AC_FN1    ACTION_LAYER_TAP(1, KC_SPC)
#define AC_FN2    ACTION_LAYER_TAP(2, KC_DEL)
#define AC_FN3    ACTION_MODS_TAP_KEY(MOD_RALT, KC_LEFT)
#define AC_FN4    ACTION_LAYER_TAP(3, KC_DOWN)
#define AC_FN5    ACTION_MODS_TAP_KEY(MOD_RCTL, KC_RGHT)
#define AC_FN6    ACTION_FUNCTION(7)

/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */
const action_t actionmaps[][MATRIX_ROWS][MATRIX_COLS] = { 
	[0] = ACTIONMAP_ROT(
        TAB, Q, W, E, R, T, Y, U, I, O, P, BSPC,
        CAPS, A, S, D, F, G, H, J, K, L, SCLN, ENT,
        LSFT, Z, X, C, V, B, N, M, COMM, DOT, FN0, RSFT,
        LCTL, LGUI, LALT, FN1, SPC, FN2, FN3, FN4, FN5,
		VOLU, VOLD,  ESC),
		
	[1] = ACTIONMAP(
        ESC, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, BSPC,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, LBRC, RBRC, BSLS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),

	[2] = ACTIONMAP(
        F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MINS, EQL, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, MUTE, VOLD, VOLU, TRNS, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS),

	[3] = ACTIONMAP(
        GRV, MYCM, MAIL, CALC, MSEL, TRNS, TRNS, TRNS, MPLY, MPRV, MNXT, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, QUOT, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, FN6, TRNS, MUTE, VOLD, VOLU, SLSH, TRNS,
        TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS)
};

#define NO NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {  0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,      NO },
        { 23,22,21,20,19,18,17,16,15,14,13,12,      NO },
        { 24,25,26,27,28,29,30,31,32,33,34,35,      NO },
        { 44,43,42,41,NO,40,NO,NO,39,38,37,36,      0  },
    },
    { // LED Index to Physical Position
        { 12, 5 },{ 31, 5 },{ 50, 5 },{ 69, 5 },{ 88, 5 },{ 107, 5 },{ 126, 5 },{ 145, 5 },{ 164, 5 },{ 183, 5 },{ 202, 5 },{ 230, 5 }, 
        { 233, 24 },{ 207, 24 },{ 188, 24 },{ 169, 24 },{ 150, 24 },{ 131, 24 },{ 112, 24 },{ 93, 24 },{ 74, 24 },{ 55, 24 },{ 36, 24 },{ 17, 24 },   
		{ 24, 43 }, { 45, 43 },{ 64, 43 },{ 83, 43 },{ 102, 43 },{ 121, 43 },{ 140, 43 }, { 159, 43 }, { 178, 43 },{ 197, 43 },{ 216, 43 },{ 239, 43 }, 
        { 239, 62 },{ 216, 62 },{ 197, 62 },{ 178, 62 },{ 142, 62 },{ 97, 62 },{ 61, 62 },{ 38, 62 },{ 14, 62 },
	 },
    { // LED Index to Flag
        12, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4  , 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 12,
		4  , 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4  , 4, 4, 4, 4, 4, 4, 4, 4 }
};
