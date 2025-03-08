#include "analog.h"

// ********************* 摇杆按键映射相关参数 *********************
static const int actuation = 256;    // 触发点，摇杆偏移超过此值时触发按键 (范围: 0-511)
static const int hysteresis = 50;     // 滞后量，防止抖动，适当调整以优化体验

// 定义 X 轴和 Y 轴的模拟输入引脚
static pin_t joystick_axes_x_pin[] = JOYSTICK_KEY_X_PIN;  
static pin_t joystick_axes_y_pin[] = JOYSTICK_KEY_Y_PIN;  

// 计算当前连接的摇杆数量
#define NUMBER_OF_JOYSTICKS (sizeof(joystick_axes_x_pin) / sizeof(pin_t))

// ********************* 矩阵键盘按键位置定义 *********************

// 定义一个结构体，表示按键在矩阵键盘中的行列位置
typedef struct {
    uint8_t row; // 行号
    uint8_t col; // 列号
} matrix_pos_t;

// 定义摇杆八个方向在矩阵键盘中的对应按键位置
static const matrix_pos_t joykey_pos[][8] = {
    JOYSTICK_KEY_PX_POS, // X 轴正方向 (向右)
    JOYSTICK_KEY_NX_POS, // X 轴负方向 (向左)
    JOYSTICK_KEY_PY_POS, // Y 轴正方向 (向上)
    JOYSTICK_KEY_NY_POS, // Y 轴负方向 (向下)
    JOYSTICK_KEY_UP_RIGHT, // 上右 (X+Y)
    JOYSTICK_KEY_UP_LEFT,  // 上左 (X-Y)
    JOYSTICK_KEY_DOWN_RIGHT, // 下右 (X-Y)
    JOYSTICK_KEY_DOWN_LEFT  // 下左 (X+Y)
};

// 记录每个摇杆的八个方向按键状态 (false：未按下，true：按下)
static bool arrows[8 * NUMBER_OF_JOYSTICKS] = {false};  

// ********************* 处理单个方向的摇杆输入 *********************

/**
 * 处理单个方向的摇杆输入，根据摇杆偏移量判断是否触发按键
 * @param index     摇杆编号
 * @param x_value   X 轴的偏移量 (已减去 512，中心点为 0)
 * @param y_value   Y 轴的偏移量 (已减去 512，中心点为 0)
 * @param direction 方向索引 (0~7: 各个方向)
 */
static void process_joystick_movement(int index, int x_value, int y_value, int direction) {
    bool *arrow_state = &arrows[index * 8 + direction]; // 获取当前方向的按键状态
    const matrix_pos_t *key_pos = &joykey_pos[direction][index]; // 获取矩阵键盘中的按键位置

    // 判断是否触发按键
    if (!(*arrow_state) && (abs(x_value) > actuation + hysteresis || abs(y_value) > actuation + hysteresis)) {
        *arrow_state = true; // 标记按键已按下
        register_code16(dynamic_keymap_get_keycode(biton32(layer_state), key_pos->row, key_pos->col)); // 触发按键
    } 
    else if (*arrow_state && (abs(x_value) < actuation - hysteresis && abs(y_value) < actuation - hysteresis)) {
        *arrow_state = false; // 标记按键已释放
        unregister_code16(dynamic_keymap_get_keycode(biton32(layer_state), key_pos->row, key_pos->col)); // 释放按键
    }
}

// ********************* 主摇杆扫描函数 *********************

/**
 * 遍历所有摇杆，读取 X 轴和 Y 轴的模拟值，并检查是否需要触发按键
 */
void matrix_scan_user(void) {
    for (uint8_t i = 0; i < NUMBER_OF_JOYSTICKS; i++) { // 遍历所有摇杆
        int x_value = analogReadPin(joystick_axes_x_pin[i]) - 512; // 读取 X 轴模拟值，并将范围归一化到 -512 ~ 512
        int y_value = analogReadPin(joystick_axes_y_pin[i]) - 512; // 读取 Y 轴模拟值，并将范围归一化到 -512 ~ 512

        // 处理 X 轴和 Y 轴的四个方向 (上下左右)
        process_joystick_movement(i, x_value, 0, 0);  // X 轴正方向 (向右)
        process_joystick_movement(i, -x_value, 0, 1); // X 轴负方向 (向左)
        process_joystick_movement(i, 0, y_value, 2);  // Y 轴正方向 (向上)
        process_joystick_movement(i, 0, -y_value, 3); // Y 轴负方向 (向下)

        // 处理 X 轴和 Y 轴的斜对角方向
        process_joystick_movement(i, x_value, y_value, 4);  // 上右 (X+Y)
        process_joystick_movement(i, -x_value, y_value, 5); // 上左 (X-Y)
        process_joystick_movement(i, x_value, -y_value, 6); // 下右 (X-Y)
        process_joystick_movement(i, -x_value, -y_value, 7); // 下左 (X+Y)
    }
}
