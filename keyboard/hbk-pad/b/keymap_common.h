/*
Copyright 2012,2013 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/**
 * 键盘矩阵基配置文件
 * 
 * 定义各个按键的位置，方便编写Keymap
 */
#pragma once

#include <stdint.h>
#include "keymap.h"
#include "config.h"

extern const uint8_t keymaps[][MATRIX_ROWS][MATRIX_COLS];
extern const action_t fn_actions[];

/* 
 * @brief 按键阵列
 * 第一组为实际布局
 * 第二组为按键实际矩阵
 * 只有一个按键
 * RON反转 ROP正转（旋钮）
 */
#define KEYMAP_ENC( 	\
	K00, R0N, R0P,	 	\
	K10, K11, K12, K13,	\
	K20, K21, k22,		\
	k30, k31, k32, k33, \
	k40, k41, k42,		\
	k50, k51,      k53	\
){ 							    	\
	{ K00, R0N, R0P,   KC_NO  },	\
	{ K10, K11, K12,   K13    },	\
	{ K20, K21, k22,   KC_NO  }, 	\
	{ k30, k31, k32,   k33    }, 	\
	{ k40, k41, k42,   KC_NO  }, 	\
	{ k50, k51, KC_NO, k53    }, 	\
}

