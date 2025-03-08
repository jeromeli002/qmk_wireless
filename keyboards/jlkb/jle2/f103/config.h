#pragma once
// 游戏摇杆
//#define ADC_PIN A1
//#define JOYSTICK_AXIS_RESOLUTION 10
//#define JOYSTICK_AXIS_COUNT 2       // 最大6 最小0
//#define JOYSTICK_BUTTON_COUNT 32    // 按钮数最大32 最小0

/*指点杆*/
//#define ANALOG_JOYSTICK_X_AXIS_PIN A1     /* 上拉 X轴右移 */
//#define ANALOG_JOYSTICK_Y_AXIS_PIN A2     /* 上拉 Y轴下移 */
// #define ANALOG_JOYSTICK_CLICK_PIN B1
//#define POINTING_DEVICE_ROTATION_90   /* 将 X 和 Y 数据旋转 180 度 */
// #define POINTING_DEVICE_INVERT_X	（可选）反转 X 轴报告。
//#define POINTING_DEVICE_INVERT_Y	（可选）反转 Y 轴报告。

/* 摇杆映射
#ifdef JOYSTICK_TRIGGER_ENABLE
#define ADC_RESOLUTION ADC_CFGR1_RES_10BIT
#define JOYSTICK_ADC_RESOLUTION 10
#define JOYSTICK_USE_LPF
#define JOYSTICK_LPF_PROPORTION (0.2)
#define JOYSTICK_AXES_X_PIN { A2 }
#define JOYSTICK_AXES_Y_PIN { A1 }
#define JOYSTICK_AXES_PX_KEY_POS {1, 0}
#define JOYSTICK_AXES_NX_KEY_POS {2, 0}
#define JOYSTICK_AXES_PY_KEY_POS {2, 1}
#define JOYSTICK_AXES_NY_KEY_POS {3, 1}
#endif
 */

// 矩阵位置
#define JOYSTICK_ACTUATION 256  // 触发点，即摇杆偏移多少开始触发按键 (0-511)
#define JOYSTICK_HYSTERESIS 50  // 滞后量，防止抖动，调整此值以达到最佳效果
#define JOYSTICK_KEY_X_PIN  {A1,A6}
#define JOYSTICK_KEY_Y_PIN  {A2,A7}
#define JOYSTICK_KEY_PX_POS {{1, 3},{0,0}}
#define JOYSTICK_KEY_NX_POS {{1, 2},{0,0}}
#define JOYSTICK_KEY_PY_POS {{0, 2},{0,0}}
#define JOYSTICK_KEY_NY_POS {{0, 1},{0,0}}

// 摇杆按键数 Max 32
#define JOYSTICK_BUTTON_COUNT 0
// 每个摇杆轴数量 Max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 2 //轴数量X/Y轴


/* 层数 */
#  define DYNAMIC_KEYMAP_LAYER_COUNT 16

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

