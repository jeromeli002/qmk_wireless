/* Copyright 2021 ZhaQian
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#define ANALOG_JOYSTICK_X_AXIS_PIN A2  
#define ANALOG_JOYSTICK_Y_AXIS_PIN A1   
// #define ANALOG_JOYSTICK_CLICK_PIN B1
/*
 #ifdef JOYSTICK_TRIGGER_ENABLE
#define ADC_RESOLUTION ADC_CFGR1_RES_10BIT
#define JOYSTICK_ADC_RESOLUTION 10
#define JOYSTICK_USE_LPF
#define JOYSTICK_LPF_PROPORTION (0.2)
#define JOYSTICK_AXES_X_PIN { A1 }
#define JOYSTICK_AXES_Y_PIN { A2 }
#define JOYSTICK_AXES_PX_KEY_POS {3, 3}
#define JOYSTICK_AXES_NX_KEY_POS {2, 3}
#define JOYSTICK_AXES_PY_KEY_POS {0, 3}
#define JOYSTICK_AXES_NY_KEY_POS {1, 3}
#endif
*/
 /* 层指示灯 
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK   
#define RGBLIGHT_MAX_LAYERS 16
*/

/* 层数 */
#  define DYNAMIC_KEYMAP_LAYER_COUNT 16

// QMK宏数量，最多128个
#define DYNAMIC_KEYMAP_MACRO_COUNT 64

/* COL2ROW or ROW2COL */
//#define DIODE_DIRECTION COL2ROW
#define DEBOUNCE 5   //去抖时间5毫秒

/* 编码器01 */
#define ENCODER_DEFAULT_POS 0x3

/* 指示灯 */
/* #define LED_CAPS_LOCK_PIN B10
#define LED_NUM_LOCK_PIN C13
#define LED_SCROLL_LOCK_PIN B1
#define LED_PIN_ON_STATE 0  指示灯 LED“亮”时指示灯引脚的状态 -1高电平，0低电平*/

/* number of backlight levels */

/*
#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif
*/

/* Set 0 if debouncing isn't needed */
/* #define DEBOUNCING_DELAY 5 */

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

/* prevent stuck modifiers */
/* #define PREVENT_STUCK_MODIFIERS */


//  OLED设置项
//#define OLED_FONT_H "glcdfont.c"//自定义字体
//#define OLED_FONT_WIDTH 6 //字体宽度
//#define OLED_FONT_HEIGHT 8 //字体高度
// #define OLED_FADE_OUT         //动画淡出
// #define OLED_FADE_OUT_INTERVAL 10     //淡出速度0~15 越大越快
//#define OLED_SCROLL_TIMEOUT	 5000 //2000毫秒后开始滚动
// #define OLED_SCROLL_TIMEOUT_RIGHT //向右滚动 不设置默认向左滚动
//#define OLED_TIMEOUT 30000  // 10分钟（毫秒）无操作后关闭屏幕
