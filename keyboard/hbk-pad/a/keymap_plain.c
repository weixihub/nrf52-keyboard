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
        { 0   ,  NO_LED  ,  NO_LED  ,  NO_LED },
		{ 1   ,    2     ,     3    ,    4    },
    },
    { 	// RGB物理位置
        { 32, 25 },
		{ 160, 75 },{ 160, 75 },{ 160, 75 },{ 160, 75 },
	 },
    { 	// RGB功能标志
        0xff ,
		4 , 4 , 4 , 4,}
};
#endif
/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	KEYMAP_ENC(
		KC_TRNS,  KC_VOLD,  KC_VOLU,
		KC_FN0,  KC_PSLS,  KC_PAST,  KC_PMNS,
		KC_P7,   KC_P8,    KC_P9,
		KC_P4,   KC_P5,    KC_P6,  	 KC_PPLS,
		KC_P1,   KC_P2,    KC_P3,
		KC_P0,   KC_TRNS,   KC_PENT		
		),

    KEYMAP_ENC( 
		KC_TRNS,   KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_FN1,  KC_FN2,  KC_FN3,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  
		KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  
		KC_TRNS,   KC_TRNS,	 KC_TRNS
		),

    KEYMAP_ENC(
		KC_TRNS,   KC_BRTD,  KC_BRTI,
		KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  
		KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  
		KC_TRNS,    KC_TRNS,	 KC_TRNS
		),

};

const action_t fn_actions[] = {
	ACTION_LAYER_TAP(1, KC_NLCK),
	ACTION_FUNCTION_OPT(USER_KEYBOARD_CONTROL, CONTROL_SYSTEMOFF),
	ACTION_FUNCTION_OPT(USER_KEYBOARD_CONTROL, CONTROL_TOGGLE_BOOTCHECK),
	// ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_0),
	// ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_1),
	// ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_2),
	// ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_READV),
	// ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_REBOND),
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_TOGGLE),
    // ACTION_FUNCTION_OPT(RGB_LIGHT_CONTROL, RGB_LIGHT_TOGGLE),
    // ACTION_FUNCTION_OPT(RGB_LIGHT_CONTROL, RGB_LIGHT_TML),
	// ACTION_FUNCTION_OPT(RGB_LIGHT_CONTROL, RGB_LIGHT_IHUE),
	// ACTION_FUNCTION_OPT(RGB_LIGHT_CONTROL, RGB_LIGHT_DHUE),
	// ACTION_LAYER_TAP(2, KC_PDOT),
	
};
