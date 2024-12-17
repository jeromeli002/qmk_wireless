#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x5003
#define DEVICE_VER      0x0001
#define MANUFACTURER    \u952e\u76d8\u4fa0\u7684
#define PRODUCT         \u8d85\u5927\u676f\u952e\u76d8


/* 层数 */
#  define DYNAMIC_KEYMAP_LAYER_COUNT 9

/* key matrix size */
#define MATRIX_ROWS 15
#define MATRIX_COLS 15
 
 /* 层指示灯 */
#define RGBLIGHT_LAYERS

/* key matrix pins */
#define MATRIX_ROW_PINS {  B12, B13, B14, B15, A8, A10, A15, B3, B4, B5, B8, B9, B10, B1, A5}
#define MATRIX_COL_PINS {  B12, B13, B14, B15, A8, A10, A15, B3, B4, B5, B8, B9, B10, B1, A5}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* 编码器 */
#define ENCODERS_PAD_A { A0, A7, A4, A2, B0}
#define ENCODERS_PAD_B { C15, A6, A3, A1, C14}
#define ENCODER_RESOLUTIONS {4, 4, 4, 2, 4}
#define ENCODER_PAD_A_KEY_POS {14, 0}, {14, 2}, {14, 4}, {14, 6}, {14, 8}
#define ENCODER_PAD_B_KEY_POS {14, 1}, {14, 3}, {14, 5}, {14, 7}, {14, 9}
/* 编码器01 */
#define ENCODER_DEFAULT_POS 0x3

/* 指示灯 */
#define LED_CAPS_LOCK_PIN C13
/*#define LED_NUM_LOCK_PIN B0
#define LED_SCROLL_LOCK_PIN B14*/
#define LED_PIN_ON_STATE 1 /* 指示灯 LED“亮”时指示灯引脚的状态 -1高电平，0低电平*/

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

/* Set 0 if debouncing isn't needed */
/*  #define DEBOUNCING_DELAY 5 */

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

/*#define RGB_DI_PIN C14
#ifdef RGB_DI_PIN 
#define RGBLED_NUM 8
#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8
#define RGBLIGHT_SAT_STEP 8
#define RGBLIGHT_VAL_STEP 8
#endif*/