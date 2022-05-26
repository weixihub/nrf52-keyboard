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
// #include "rgb_matrix_types.h"

/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */
const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	KEYMAP_ENC(
		KC_FN0,  KC_VOLD,  KC_VOLU,
		KC_FN1,  KC_PSLS,  KC_PAST,  KC_PMNS,
		KC_P7,   KC_P8,    KC_P9,
		KC_P4,   KC_P5,    KC_P6,  	 KC_PPLS,
		KC_P1,   KC_P2,    KC_P3,
		KC_P0,   KC_FN8,   KC_PENT		
		),

    KEYMAP_ENC(
		KC_TRNS,   KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  
		KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  
		KC_TRNS,   KC_TRNS,	 KC_TRNS
		),

    KEYMAP_ENC(
		KC_TRNS,   KC_TRNS,  KC_TRNS,
		KC_FN2,    KC_FN3,   KC_FN4,  KC_FN5,
		KC_FN7,    KC_TRNS,  KC_TRNS,  
		KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_FN6,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  
		KC_TRNS,   KC_TRNS,	 KC_TRNS
		),

};
// led_config_t g_led_config = {
//     {
//         // RGB顺序
//         { 0 }
//     },
//     { 	// RGB物理位置
//         { 32, 25 }
// 	 },
//     { 	// RGB功能标志
//         4 }
// };
// led_config_t g_led_config = {
//     {
//         // Key Matrix to LED Index
//         { 0   ,  1    ,  2     ,  3,       NO_LED },
//         { 6   ,  5    ,  4     ,  10,      NO_LED},
//         { 7   ,  8    ,  9     ,  NO_LED,  NO_LED },
//         { 13  ,  12   ,  11    ,  16    ,  NO_LED },
//         { 14  ,NO_LED ,  15    ,  NO_LED,  NO_LED },
//     },
//     { // LED Index to Physical Position
//         { 32, 25 }, { 96, 25 }, { 160, 25 }, { 224, 25 }, 
// 		{ 160, 75 }, { 96, 75 }, { 32, 75 }, 
// 		{ 32, 125 }, { 96, 125 }, { 160, 125 },   { 204, 105 },
// 		{ 160, 175 }, { 96, 175 }, { 32, 175 },  
// 		{ 64, 225 }, { 160, 225 },{ 204, 205 },
// 	 },
//     { // LED Index to Flag
//         255, 4, 4, 4,
// 		4, 4, 4,
// 		4, 4, 4, 4,
// 		4, 4, 4,
//         4, 4, 4, }
// };
const action_t fn_actions[] = {
	ACTION_MODS_KEY(MOD_LGUI,KC_D),//fn0 老板键回到桌面
	ACTION_LAYER_TAP(1, KC_NLCK),//fn1  长按跳到1层 短按是nlck
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_0),//fn2 蓝牙通道
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_1),//fn3
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_2),//fn4
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_READV),//fn5	蓝牙广播
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_REBOND),//fn6	解绑
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_USB),//fn7			usb模式
	ACTION_LAYER_TAP(2, KC_PDOT)//fn8 短按.长按跳到2层
};