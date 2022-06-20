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
#define AC_FN0    ACTION_LAYER_TAP(1, KC_SPC)

/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */
const action_t actionmaps[][MATRIX_ROWS][MATRIX_COLS] = { 
	[0] = ACTIONMAP_ROT(
		ESC, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, MINS, EQL, BSPC, 
		TAB, Q, W, E, R, T, Y, U, I, O, P, LBRC, RBRC, BSLS, 
		CAPS, A, S, D, F, G, H, J, K, L, SCLN, QUOT, ENT, 
		LSFT, Z, X, C, V, B, N, M, COMM, DOT, SLSH, UP, RSFT, 
		LCTL, LGUI, LALT, FN0, SPC, RALT, RCTL, LEFT, DOWN, RGHT,
		VOLU, VOLD, MUTE),

	[1] = ACTIONMAP(
		GRV, F1, F2, F3, F4, F5, F6, F7, F8, F9, F10, F11, F12, DEL, 
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, 
		TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS, TRNS)
};

#define NO NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {   0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,NO },
        {  27,26,25,24,23,22,21,20,19,18,17,16,15,14,NO },
        {  28,29,30,31,32,33,34,35,36,37,38,39,40,NO,NO },
        {  53,52,51,50,49,48,47,46,45,44,43,42,41,NO,NO },
		{  54,55,56,57,NO,NO,58,59,60,61,62,63,NO,NO, 0 },
    },
    { // LED Index to Physical Position
		// x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
		// y = 64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
        { 8, 0 },{ 24, 0 },{ 40, 0 },{ 56, 0 },{ 72, 0 },{ 88, 0 },{ 104, 0 },{ 120, 0 },{ 136, 0 },{ 152, 0 },{ 168, 0 },{ 184, 0 }, { 200, 0 },{ 224, 0 }, \
        { 228, 16 },{ 208, 16 },{ 192, 16 },{ 176, 16 },{ 160, 16 },{ 144, 16 },{ 128, 16 },{ 112, 16 },{ 96, 16 },{ 80, 16 },{ 64, 16 },{ 48, 16 }, { 32, 16 },{ 12, 16 }, \
		{ 14, 32 }, { 36, 32 },{ 52, 32 },{ 68, 32 },{ 84, 32 },{ 100, 32 },{ 116, 32 }, { 132, 32 }, { 148, 32 },{ 164, 32 },{ 180, 32 },{ 196, 32 },{ 222, 32 }, \
        { 232, 48 },{ 216, 48 },{ 194, 48 },{ 172, 48 },{ 156, 48 },{ 140, 48 },{ 124, 48 },{ 108, 48 },{ 92, 48 },{ 76, 48 },{ 60, 48 },{ 44, 48 },{ 18, 48 }, \
		{ 12, 64 },{ 34, 64 },{ 56, 64 },{ 86, 64 },{ 126, 64 },{ 160, 64 },{ 182, 64 },{ 200, 64 },{ 216, 64 },{ 232, 64 } \
	 },
    { // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4 }
};
