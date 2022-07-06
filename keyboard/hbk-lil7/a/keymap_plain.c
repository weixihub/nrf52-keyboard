/*
Copyright (C) 2018,2019 Jim Jiang <jim@lotlab.org>

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

#include "keymap_common.h"
#include "keyboard_fn.h"
#include "user_fn.h"
#ifdef RGB_MATRIX_ENABLE
#include "rgb_matrix.h"
#include "rgb_matrix_types.h"
led_config_t g_led_config = {
    {
        // RGB顺序
        { 0   ,  1  ,  2  ,  NO_LED },
		{ 3   ,  4  ,  5  ,    6    },
    },
    { 	// RGB物理位置
        { 16, 64 }, { 16, 48 }, { 16, 32 },
		{ 32,64 },{ 32, 48 },{ 32, 32 },{ 24, 16 },
	 },
    { 	// RGB功能标志
        0xff , 0xff , 0xff , 
		0xff , 0xff , 0xff , 0xff}
};
#endif
/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	KEYMAP_ENC(
		KC_Q,  KC_W,  KC_E,
		KC_FN0,  KC_C,  KC_V,  KC_PENT	
		),

    KEYMAP_ENC( 
		KC_FN6,   KC_FN2,  KC_FN1,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_FN3
		),

    KEYMAP_ENC(
		KC_TRNS,   KC_TRNS,  KC_2,
		KC_TRNS,    KC_TRNS,   KC_FN5,   KC_FN4
		),

};

const action_t fn_actions[] = {
	ACTION_LAYER_TAP(1, KC_LCTRL),
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_0),
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_1),
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_READV),
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_TOGGLE),
	ACTION_FUNCTION_OPT(USER_KEYBOARD_CONTROL, CONTROL_TOGGLE_INDICATOR_LIGHT),	//fn5 开关指示灯	
	ACTION_LAYER_MOMENTARY(2),
};