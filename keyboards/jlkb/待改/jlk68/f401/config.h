#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x9658
#define PRODUCT_ID      0x0003
#define DEVICE_VER      0x0001
#define MANUFACTURER    JL
#define PRODUCT         \u591a\u529f\u80fd\u952e\u76d8-68

/* #define ANALOG_JOYSTICK_X_AXIS_PIN A5    */ /* 上拉 X轴右移 */
/* #define ANALOG_JOYSTICK_Y_AXIS_PIN A1    */ /* 上拉 Y轴下移 */
// #define ANALOG_JOYSTICK_CLICK_PIN B1

/* 映射按键
#ifdef JOYSTICK_TRIGGER_ENABLE
#define ADC_RESOLUTION ADC_CFGR1_RES_10BIT
#define JOYSTICK_ADC_RESOLUTION 10
#define JOYSTICK_USE_LPF
#define JOYSTICK_LPF_PROPORTION (0.2)
#define JOYSTICK_AXES_X_PIN { A5 }
#define JOYSTICK_AXES_Y_PIN { A1 }
#define JOYSTICK_AXES_PX_KEY_POS {2, 1}
#define JOYSTICK_AXES_NX_KEY_POS {4, 1}
#define JOYSTICK_AXES_PY_KEY_POS {4, 0}
#define JOYSTICK_AXES_NY_KEY_POS {4, 2}
#endif
*/

// OLED屏幕
//#define OLED_DISPLAY_128X64
// #define OLED_FONT_H "zyfont.c"
//#define OLED_TIMEOUT 0  //oled不熄屏

 /* 层指示灯 */
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK   
#define RGBLIGHT_MAX_LAYERS 16

/* 层数 */
#  define DYNAMIC_KEYMAP_LAYER_COUNT 16

/* key matrix size */
#define MATRIX_ROWS 9
#define MATRIX_COLS 9
 
 /* 层指示灯
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK
*/
 
/* key matrix pins */
#define MATRIX_ROW_PINS { B12, B13, B14, B15, A8, A10, A15, B3, A6 }
#define MATRIX_COL_PINS { B12, B13, B14, B15, A8, A10, A15, B3, A6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* 编码器 */
#define ENCODERS_PAD_A { B0, A1 }
#define ENCODERS_PAD_B { A7, A0 }
#define ENCODER_RESOLUTIONS {4, 4}
/* 映射矩阵 C，R*/
#define ENCODER_PAD_A_KEY_POS {7, 5}, {8, 0}
#define ENCODER_PAD_B_KEY_POS {7, 4}, {8, 2}

/* 编码器01 */
#define ENCODER_DEFAULT_POS 0x3

/* 指示灯 */
#define LED_CAPS_LOCK_PIN B10
#define LED_NUM_LOCK_PIN C13
/* #define LED_SCROLL_LOCK_PIN B1*/
#define LED_PIN_ON_STATE 0  /*指示灯 LED“亮”时指示灯引脚的状态 -1高电平，0低电平*/

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


#define RGB_DI_PIN B4
#ifdef RGB_DI_PIN 
#define RGBLED_NUM 4
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8    /* 增减色调步数 */
#define RGBLIGHT_SAT_STEP 8    /* 增减饱和度步数 */
#define RGBLIGHT_VAL_STEP 8    /* 增减亮度步数 */
#define RGBLIGHT_LIMIT_VAL 255	/* 最大亮度 */
// #define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }
/* 
#define RGBLIGHT_EFFECT_BREATHING
#define RGBLIGHT_EFFECT_RAINBOW_MOOD
#define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#define RGBLIGHT_EFFECT_SNAKE
#define RGBLIGHT_EFFECT_KNIGHT
#define RGBLIGHT_EFFECT_CHRISTMAS
#define RGBLIGHT_EFFECT_STATIC_GRADIENT
#define RGBLIGHT_EFFECT_RGB_TEST
#define RGBLIGHT_EFFECT_ALTERNATING
#define RGBLIGHT_EFFECT_TWINKLE
*/
#endif