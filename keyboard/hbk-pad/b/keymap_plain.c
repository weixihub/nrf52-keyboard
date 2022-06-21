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
#include "rgb_matrix_types.h"
led_config_t g_led_config = {
    {
        // RGB顺序
        { 0   ,  NO_LED  ,  NO_LED  ,  NO_LED },
		{ 1   ,    2     ,    3     ,    4    },
		{ 5   ,    6     ,    7     ,  NO_LED },
		{ 8   ,    9     ,    10    ,    11   },
		{ 12  ,    13    ,    14    ,  NO_LED },
		{ 15  ,    16    ,  NO_LED  ,    17   },
    },
    { 	// RGB物理位置
        { 0, 64 },
		{ 16, 64 },{ 16, 48 },{ 16, 32 },{ 16, 16 },
		{ 32, 64 },{ 32, 48 }, { 32, 32 },
		{ 48, 64 },{ 48, 48 },{ 48, 32 },{ 40, 16 },
		{ 64, 64 },{ 64, 48 },{ 64, 32 },
		{ 80, 56 },{ 80, 32 },{ 74, 16 },

	 },
    { 	// RGB功能标志
        0xff ,
		0xff , 0xff , 0xff , 0xff,
		0xff , 0xff , 0xff,
		0xff , 0xff , 0xff , 0xff,
		0xff , 0xff , 0xff,
		0xff , 0xff , 0xff,}
};
#endif
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
		KC_TRNS,   KC_FN19,  KC_FN20,  KC_FN18,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  
		KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,
		KC_TRNS,   KC_TRNS,  KC_TRNS,  
		KC_TRNS,   KC_TRNS,	 KC_TRNS
		),

    KEYMAP_ENC(
		KC_TRNS,   KC_FN14,  KC_FN13,
		KC_FN2,    KC_FN3,   KC_FN4,   KC_FN17,
		KC_FN10,   KC_FN9,   KC_TRNS,  
		KC_FN12,   KC_FN11,  KC_TRNS,  KC_FN6,
		KC_FN16,   KC_FN15,  KC_TRNS,  
		KC_FN7,    KC_TRNS,	 KC_FN5
		),

};

const action_t fn_actions[] = {
	ACTION_MODS_KEY(MOD_LGUI,KC_D),//fn0 老板键回到桌面
	ACTION_LAYER_TAP(1, KC_NLCK),//fn1  长按跳到1层 短按是nlck
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_0),//fn2 蓝牙通道
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_1),//fn3
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_2),//fn4
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_READV),//fn5	蓝牙广播
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_REBOND),//fn6	解绑
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_USB),//fn7			usb模式
	ACTION_LAYER_TAP(2, KC_PDOT),//fn8 短按.长按跳到2层
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_MODE_INCREASE),	//fn9 灯效模式+
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_MODE_DECREASE),	//fn10 灯效模式-
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_VAL_INCREASE),	//fn11 亮度+
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_VAL_DECREASE),	//fn12 亮度-
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_HUE_INCREASE),	//fn13 色相+
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_HUE_DECREASE),	//fn14 色相-
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_SPEED_INCREASE),//fn15 速度+
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_SPEED_DECREASE),//fn16 速度-
	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_TOGGLE),		//fn17 开关

	ACTION_FUNCTION_OPT(KEYBOARD_CONTROL, CONTROL_SLEEP),			//fn18 软关机

	ACTION_FUNCTION_OPT(USER_KEYBOARD_CONTROL, CONTROL_TOGGLE_INDICATOR_LIGHT),	//fn19 开关指示灯
	ACTION_FUNCTION_OPT(USER_KEYBOARD_CONTROL, CONTROL_TOGGLE_BOOTCHECK),		//fn20 开关按键激活
};
