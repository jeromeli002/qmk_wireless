#pragma once

#pragma once
 
# define REPORT_BUFFER_QUEUE_SIZE 64

#ifdef BLUETOOTH_BHQ
// Its active level is "BHQ_IRQ_AND_INT_LEVEL of bhq.h " 
#   define BHQ_RUN_STATE_INPUT_PIN  B13             // Module operating status
#   define QMK_RUN_OUTPUT_PIN       B12             // QMK operating status

#   define UART_DRIVER          SD1
#   define UART_TX_PIN          A9
#   define UART_TX_PAL_MODE     7
#   define UART_RX_PIN          A10
#   define UART_RX_PAL_MODE	    7

#endif

 /* 层指示灯 */
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK   
#define RGBLIGHT_MAX_LAYERS 16

/* 层数 */
#  define DYNAMIC_KEYMAP_LAYER_COUNT 8

/* 编码器01 */
#define ENCODER_DEFAULT_POS 0x3

/* 指示灯 */
/* #define LED_CAPS_LOCK_PIN B10
#define LED_NUM_LOCK_PIN C13
#define LED_SCROLL_LOCK_PIN B1
#define LED_PIN_ON_STATE 0  指示灯 LED“亮”时指示灯引脚的状态 -1高电平，0低电平*/

/* number of backlight levels */



/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/* key combination for command */
#define IS_COMMAND() ( \
    keyboard_report->mods == (MOD_BIT(KC_LSHIFT) | MOD_BIT(KC_RSHIFT)) \
)

