#pragma once

 /* 分体相关配置 */
 #define SERIAL_USART_DRIVER SD1
#define SERIAL_USART_FULL_DUPLEX   // 全双工.
#define SERIAL_USART_TX_PIN A9     // 串口TX脚
#define SERIAL_USART_RX_PIN A10     // 串口RX脚
// #define USART1_REMAP               // Remap USART TX and RX pins on STM32F103 MCUs, see table below.
// #define SERIAL_USART_TX_PAL_MODE 7 // 默认 7
#define SPLIT_HAND_PIN B7           //上拉为主/左-下拉为副/右 **硬件区分主副手
#define	SPLIT_HAND_PIN_LOW_IS_LEFT  //对换主副手**选配
// #define SPLIT_HAND_MATRIX_GRID A0, C1   //按键矩阵区分主副手****软件区分主副手（第一个引脚是输出引脚，第二个引脚是输入引脚。）
// #define SPLIT_HAND_MATRIX_GRID_LOW_IS_LEFT  //对调主副手**软件区分
// #define MASTER_RIGHT   //右主手
// #define MASTER_LEFT    //左主手 **默认


 /* 层指示灯 */
#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYER_BLINK   
#define RGBLIGHT_MAX_LAYERS 16

/* 层数 */
#  define DYNAMIC_KEYMAP_LAYER_COUNT 16

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

