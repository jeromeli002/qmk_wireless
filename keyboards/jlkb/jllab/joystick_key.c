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

bool arrows[4 * NUMBER_OF_JOYSTICKS]= {false};   // 存储每个摇杆四个方向按键的状态，false表示未按下，true表示按下
void matrix_scan_user(void) {
    static int x_value[NUMBER_OF_JOYSTICKS]; // 存储每个摇杆X轴的原始模拟值
    static int y_value[NUMBER_OF_JOYSTICKS]; // 存储每个摇杆Y轴的原始模拟值

    for (uint8_t i = 0; i < NUMBER_OF_JOYSTICKS; i++) { // 遍历每个摇杆
        x_value[i] = analogReadPin(joystick_axes_x_pin[i]); // 读取X轴模拟值
        y_value[i] = analogReadPin(joystick_axes_y_pin[i]); // 读取Y轴模拟值
	  // 上 (X 轴正方向)
        if (!arrows[i * 4 + 0] && x_value[i] - 512 > actuation + hysteresis) { // 如果当前状态为未按下，且摇杆值超过触发点加上滞后量
            arrows[i * 4 + 0] = true; // 设置当前状态为按下
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), joykey_xp[i].row, joykey_xp[i].col); // 获取对应按键的键码
            register_code16(keycode); // 注册按键按下
        } else if (arrows[i * 4 + 0] && x_value[i] - 512 < actuation - hysteresis) { // 如果当前状态为按下，且摇杆值低于触发点减去滞后量
            arrows[i * 4 + 0] = false; // 设置当前状态为未按下
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), joykey_xp[i].row, joykey_xp[i].col); // 获取对应按键的键码
            unregister_code16(keycode); // 注销按键释放
        }

        // 下 (X 轴负方向)
        if (!arrows[i * 4 + 1] && x_value[i] - 512 < -actuation - hysteresis) { // 如果当前状态为未按下，且摇杆值小于负的触发点减去滞后量
            arrows[i * 4 + 1] = true; // 设置当前状态为按下
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), joykey_xn[i].row, joykey_xn[i].col); // 获取对应按键的键码
            register_code16(keycode); // 注册按键按下
        } else if (arrows[i * 4 + 1] && x_value[i] - 512 > -actuation + hysteresis) { // 如果当前状态为按下，且摇杆值大于负的触发点加上滞后量
            arrows[i * 4 + 1] = false; // 设置当前状态为未按下
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), joykey_xn[i].row, joykey_xn[i].col); // 获取对应按键的键码
            unregister_code16(keycode); // 注销按键释放
        }

        // 左 (Y 轴正方向)
        if (!arrows[i * 4 + 2] && y_value[i] - 512 > actuation + hysteresis) { // 如果当前状态为未按下，且摇杆值超过触发点加上滞后量
            arrows[i * 4 + 2] = true; // 设置当前状态为按下
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), joykey_yp[i].row, joykey_yp[i].col); // 获取对应按键的键码
            register_code16(keycode); // 注册按键按下
        } else if (arrows[i * 4 + 2] && y_value[i] - 512 < actuation - hysteresis) { // 如果当前状态为按下，且摇杆值低于触发点减去滞后量
            arrows[i * 4 + 2] = false; // 设置当前状态为未按下
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), joykey_yp[i].row, joykey_yp[i].col); // 获取对应按键的键码
            unregister_code16(keycode); // 注销按键释放
        }
    // 右 (Y 轴负方向)
        if (!arrows[i * 4 + 3] && y_value[i] - 512 < -actuation - hysteresis) { // 如果当前状态为未按下，且摇杆值小于负的触发点减去滞后量
            arrows[i * 4 + 3] = true; // 设置当前状态为按下
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), joykey_yn[i].row, joykey_yn[i].col); // 获取对应按键的键码
            register_code16(keycode); // 注册按键按下
        } else if (arrows[i * 4 + 3] && y_value[i] - 512 > -actuation + hysteresis) { // 如果当前状态为按下，且摇杆值大于负的触发点加上滞后量
            arrows[i * 4 + 3] = false; // 设置当前状态为未按下
            uint16_t keycode = dynamic_keymap_get_keycode(biton32(layer_state), joykey_yn[i].row, joykey_yn[i].col); // 获取对应按键的键码
            unregister_code16(keycode); // 注销按键释放
        }
    }
}

