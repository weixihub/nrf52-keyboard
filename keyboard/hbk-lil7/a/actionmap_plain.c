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
 * 定义需使用的FN按键
 */
#define AC_FN0	ACTION_LAYER_MOMENTARY(1)	//跳转1层
#define AC_FN1	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_0)//蓝牙0
#define AC_FN2	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_1)//蓝牙1
#define AC_FN3	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_READV)//广播
#define AC_FN4	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_REBOND)//解绑
#define AC_FN5	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_TOGGLE)//开关灯
#define AC_FN6	ACTION_FUNCTION_OPT(USER_KEYBOARD_CONTROL, CONTROL_TOGGLE_INDICATOR_LIGHT)// 开关指示灯
#define AC_FN7  ACTION_LAYER_MOMENTARY(2) //跳转2层
#define AC_FN8  ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_MODE_INCREASE)//模式+
#define AC_FN9	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_VAL_INCREASE)//亮度+
#define AC_FN10	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_VAL_DECREASE)//亮度-
#define AC_FN11	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_HUE_INCREASE)//色相+
#define AC_FN12	ACTION_FUNCTION_OPT(RGBMATRIX_CONTROL, RGBLIGHT_HUE_DECREASE)//色相-

/* 
 * @brief 按键映射
 * 下面的按键映射与按键布局的第一组实际布局对应
 */


const action_t actionmaps[][MATRIX_ROWS][MATRIX_COLS] = { 
	[0] = ACTIONMAP_ENC(
		Q,  W,  E, \
		FN0,   C,    V,   PENT),

	[1] = ACTIONMAP_ENC(
		FN7,  FN1,   FN2, \
		NO,   NO,   FN4,  FN3),

	[2] = ACTIONMAP_ENC(  //Android电视遥控器
		NO,    FN12,   FN11, \
		NO,    FN8,    FN6,   FN5),
};
