#pragma once

#define VIAL_KEYBOARD_UID {0x2E, 0x4D, 0xC1, 0xC9, 0xEF, 0xC3, 0xD6, 0x42}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 2 }

/*指点杆*/
#define ANALOG_JOYSTICK_X_AXIS_PIN A2     /* 上拉 X轴右移 */
#define ANALOG_JOYSTICK_Y_AXIS_PIN A1     /* 上拉 Y轴下移 */
// #define ANALOG_JOYSTICK_CLICK_PIN B1
#define POINTING_DEVICE_ROTATION_180   /* 将 X 和 Y 数据旋转 180 度 */
//#define POINTING_DEVICE_INVERT_X	（可选）反转 X 轴报告。
//#define POINTING_DEVICE_INVERT_Y	（可选）反转 Y 轴报告。