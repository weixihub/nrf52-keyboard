#pragma once

enum fn_user_functions {
	TRICKY_KEY = 0x10, //0x0F以前为系统保留，自定义从0x10开始；
	RGB_LIGHT_CONTROL = 0x11,
	USER_KEYBOARD_CONTROL, //键盘控制（USER自定义）
};

enum fn_user_fn_key {
    AF_TRICKY_ESC,
    AF_TRICKY_SLSH,
    AF_TRICKY_ENTER,
    AF_TRICKY_L,
    AF_TRICKY_UP,
    AF_TRICKY_BSPC,
};

enum fn_user_rgb_light_control {
    RGB_LIGHT_STEP,
    RGB_LIGHT_TOGGLE,
    RGB_LIGHT_IHUE,
    RGB_LIGHT_DHUE,
    RGB_LIGHT_ISAT,
    RGB_LIGHT_DSAT,
    RGB_LIGHT_IVAL,
    RGB_LIGHT_DVAL,
    RGB_LIGHT_TML,
};

enum fn_user_keyboard_control {
    CONTROL_SYSTEMOFF, //关机
    CONTROL_TOGGLE_INDICATOR_LIGHT, //开关指示灯
    CONTROL_TOGGLE_BOOTCHECK //开关启动按键检测
};