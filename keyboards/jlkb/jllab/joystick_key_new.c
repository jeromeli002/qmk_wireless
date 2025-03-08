#include "analog.h"

//摇杆映射按键相关
static int actuation = 256;       // 触发点，即摇杆偏移多少开始触发按键 (0-511)
static int hysteresis = 50;        // 滞后量，防止抖动，调整此值以达到最佳效果

static pin_t joystick_axes_x_pin[] = JOYSTICK_KEY_X_PIN;  //X轴引脚
static pin_t joystick_axes_y_pin[] = JOYSTICK_KEY_Y_PIN;  //Y轴引脚
#define NUMBER_OF_JOYSTICKS (sizeof(joystick_axes_x_pin) / sizeof(pin_t)) //计算摇杆数量

// 定义引脚类型
typedef struct {
    uint8_t row; // 行
    uint8_t col; // 列
} matrix_pos_t;
// 定义四个方向按键在矩阵键盘中的位置
matrix_pos_t joykey_xp[] = JOYSTICK_KEY_PX_POS; // X轴正方向按键在矩阵中的位置
matrix_pos_t joykey_xn[] = JOYSTICK_KEY_NX_POS; // X轴负方向按键在矩阵中的位置
matrix_pos_t joykey_yp[] = JOYSTICK_KEY_PY_POS; // Y轴正方向按键在矩阵中的位置
matrix_pos_t joykey_yn[] = JOYSTICK_KEY_NY_POS; // Y轴负方向按键在矩阵中的位置

bool arrows[4 * NUMBER_OF_JOYSTICKS] = {false}; // 存储每个摇杆四个方向按键的状态，false表示未按下，true表示按下

// 按键状态更新函数
void update_arrow_state(int joystick_index, int value, bool* state, matrix_pos_t* key_pos) {
    if (!(*state) && value > actuation + hysteresis) {
        *state = true;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), key_pos[joystick_index].row, key_pos[joystick_index].col);
        register_code16(keycode);
    } else if (*state && value < actuation - hysteresis) {
        *state = false;
        uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), key_pos[joystick_index].row, key_pos[joystick_index].col);
        unregister_code16(keycode);
    }
}

void matrix_scan_user(void) {
    static int x_value[NUMBER_OF_JOYSTICKS]; // 存储每个摇杆X轴的原始模拟值
    static int y_value[NUMBER_OF_JOYSTICKS]; // 存储每个摇杆Y轴的原始模拟值

    for (uint8_t i = 0; i < NUMBER_OF_JOYSTICKS; i++) { // 遍历每个摇杆
        x_value[i] = analogReadPin(joystick_axes_x_pin[i]); // 读取X轴模拟值
        y_value[i] = analogReadPin(joystick_axes_y_pin[i]); // 读取Y轴模拟值

        // 处理 X 轴方向
        update_arrow_state(i, x_value[i] - 512, &arrows[i * 4 + 0], &joykey_xp[i]); // 上 (X 轴正方向)
        update_arrow_state(i, -(x_value[i] - 512), &arrows[i * 4 + 1], &joykey_xn[i]); // 下 (X 轴负方向)

        // 处理 Y 轴方向
        update_arrow_state(i, y_value[i] - 512, &arrows[i * 4 + 2], &joykey_yp[i]); // 左 (Y 轴正方向)
        update_arrow_state(i, -(y_value[i] - 512), &arrows[i * 4 + 3], &joykey_yn[i]); // 右 (Y 轴负方向)
    }
}
