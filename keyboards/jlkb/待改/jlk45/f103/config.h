#pragma once
#include "config_common.h"

/* 层数 */
#define DYNAMIC_KEYMAP_LAYER_COUNT 16

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12
 
 /* 层指示灯 
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK */

/* 编码器 */
#define ENCODERS_PAD_A { B4, A15 , A8, B14 }
#define ENCODERS_PAD_B { B3 , A14, B18, B13 }
#define ENCODER_RESOLUTIONS {2, 2, 2, 2 }
#define ENCODER_PAD_A_KEY_POS {0, 4}, {2, 4}, {4, 4}, {6, 4}
#define ENCODER_PAD_B_KEY_POS {1, 4}, {3, 4}, {5, 4}, {7, 4}
/* 编码器01 */
#define ENCODER_DEFAULT_POS 0x3

/* 指示灯 */
/* #define LED_CAPS_LOCK_PIN B10
#define LED_NUM_LOCK_PIN C13
#define LED_SCROLL_LOCK_PIN B1
#define LED_PIN_ON_STATE 0  指示灯 LED“亮”时指示灯引脚的状态 -1高电平，0低电平*/

/* number of backlight levels */

#ifdef BACKLIGHT_PIN
#define BACKLIGHT_LEVELS 3
#endif

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

#define RGB_DI_PIN B15
#define RGBLED_NUM 45
//#define RGBLIGHT_ANIMATIONS
#define RGBLIGHT_HUE_STEP 8    /* 增减色调步数 */
#define RGBLIGHT_SAT_STEP 8    /* 增减饱和度步数 */
#define RGBLIGHT_VAL_STEP 8    /* 增减亮度步数 */
#define RGBLIGHT_LIMIT_VAL 255	/* 最大亮度 */
// #define RGBLIGHT_LED_MAP { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15 }
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