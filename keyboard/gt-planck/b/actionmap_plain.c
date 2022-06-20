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
#define AC_FN0	ACTION_LAYER_TAP(1, KC_SPC)

/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */


const action_t actionmaps[][MATRIX_ROWS][MATRIX_COLS] = { 
	[0] = ACTIONMAP_ENC(
	ESC,    Q,    W,    E,    R,    T,    Y,    U,    I,    O,    P,     BSPC,
	TAB,    A,    S,    D,    F,    G,    H,    J,    K,    L,    SCLN,  ENTER,
	LSFT,   Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,  RSFT,
	LCTL,  LGUI, LALT, CAPS,  FN0,   SPACE,     FN0,  DEL,  RALT, APP,   RCTL,
	VOLU,  VOLD,  ESC ),

	[1] = ACTIONMAP_ENC(
	ESC,    1,    2,    3,    4,    5,    6,    7,    8,    9,    0,     BSPC,
	F1,     F2,   F3,   F4,   F5,   F6,   F7,   F8,   F9,   F10,  F11,   F12,
	LSFT,   Z,    X,    C,    V,    B,    N,    M,    COMM, DOT,  SLSH,  RSFT,
	LCTL,  LGUI, LALT, CAPS,  FN0,   SPACE,     FN0,  DEL,  RALT, APP,   RCTL,
	VOLU,  VOLD,  ESC ),
};

#define NO NO_LED

led_config_t g_led_config = {
    {
        // Key Matrix to LED Index
        {   0, 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,NO },
        {  23,22,21,20,19,18,17,16,15,14,13,12,NO },
        {  24,25,26,27,28,29,30,31,32,33,34,35,NO },
        {  46,45,44,43,42,41,NO,40,39,38,37,36,NO },
		{  NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO,NO },
    },
    { // LED Index to Physical Position
		// x = 224 / (NUMBER_OF_COLS - 1) * COL_POSITION
		// y = 64 / (NUMBER_OF_ROWS - 1) * ROW_POSITION
        { 8,  0 },{ 24,  0 },{ 40,  0 },{ 56,  0 },{ 72,  0 },{ 88,  0 },{ 104,  0 },{ 120,  0 },{ 136,  0 },{ 152,  0 },{ 168,  0 },{ 184,  0 },  \
        { 184, 16 },{ 168, 16 },{ 152, 16 },{ 136, 16 },{ 120, 16 },{ 104, 16 },{ 88, 16 },{ 72, 16 },{ 56, 16 },{ 40, 16 },{ 24, 16 },{ 8, 16 },  \
        { 8, 32 },{ 24, 32 },{ 40, 32 },{ 56, 32 },{ 72, 32 },{ 88, 32 },{ 104, 32 },{ 120, 32 },{ 136, 32 },{ 152, 32 },{ 168, 32 },{ 184, 32 },  \
        { 184, 48 },{ 168, 48 },{ 152, 48 },{ 136, 48 },{ 120, 48 },{ 96, 48 },{ 72, 48 },{ 56, 48 },{ 40, 48 },{ 24, 48 },{ 8, 48 },  \
	 },
    { // LED Index to Flag
        4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, \
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, \
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, \
		4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, }
};
