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

const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	KEYMAP_ENC(
		KC_FN0,  KC_FN1,  KC_FN4,  KC_FN6,  KC_A,  KC_FN5),

    KEYMAP_ENC(
		KC_TRNS,  KC_TRNS,   KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

};
const action_t fn_actions[] = {
	ACTION_LAYER_TAP(1, KC_NLCK),//fn0  长按跳到1层 短按是后面的按键
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_0),
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_1),
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_2),
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_READV),	//蓝牙广播
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_BLE_REBOND),	//解绑
	ACTION_FUNCTION_OPT(SWITCH_DEVICE, SWITCH_DEVICE_USB),			//usb模式
};