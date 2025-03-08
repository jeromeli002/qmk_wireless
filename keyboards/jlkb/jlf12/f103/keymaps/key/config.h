#pragma once

#define VIAL_KEYBOARD_UID {0x2E, 0x4D, 0xC1, 0xC9, 0xEF, 0xC3, 0xD6, 0x42}
#define VIAL_UNLOCK_COMBO_ROWS { 0, 0 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 2 }

// 矩阵位置
#define JOYSTICK_ACTUATION 256  // 触发点，即摇杆偏移多少开始触发按键 (0-511)
#define JOYSTICK_HYSTERESIS 50  // 滞后量，防止抖动，调整此值以达到最佳效果
#define JOYSTICK_KEY_X_PIN  {A1}
#define JOYSTICK_KEY_Y_PIN  {A2}
#define JOYSTICK_KEY_PX_POS {{3, 0}}
#define JOYSTICK_KEY_NX_POS {{3, 1}}
#define JOYSTICK_KEY_PY_POS {{3, 2}}
#define JOYSTICK_KEY_NY_POS {{3, 3}}

// 摇杆按键数 Max 32
#define JOYSTICK_BUTTON_COUNT 0
// 每个摇杆轴数量 Max 6: X, Y, Z, Rx, Ry, Rz
#define JOYSTICK_AXIS_COUNT 2 //轴数量X/Y轴

