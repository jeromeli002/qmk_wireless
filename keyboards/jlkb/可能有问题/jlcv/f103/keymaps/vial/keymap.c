#include QMK_KEYBOARD_H
#include "oled.c"

void board_init(void) {
   //禁用JTAG-DP调试，启用A13、A14脚    
   AFIO->MAPR = (AFIO->MAPR & ~AFIO_MAPR_SWJ_CFG_Msk) | AFIO_MAPR_SWJ_CFG_DISABLE;
}
enum custom_keycodes {
  LAYERS_DOWN = QK_KB_0,
  LAYERS_UP,
  jltb,
  jld6u7
};

#define HIGHEST_LAYER 15 //最高层数 0开始算起默认15(16层)
static uint8_t current_layer = 0; //默认0层开始


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
		RESET, RESET, RESET,
		RESET, RESET, RESET,
		RESET, RESET, RESET),
		
	LAYOUT(
		RESET, RESET, RESET,
		RESET, RESET, RESET,
		RESET, RESET, RESET)
		};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN),    ENCODER_CCW_CW(KC_VOLD, KC_VOLU) ,    ENCODER_CCW_CW(KC_VOLD, KC_VOLU) ,    ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [1] =   { ENCODER_CCW_CW(RGB_HUD, RGB_HUI),              ENCODER_CCW_CW(RGB_SAD, RGB_SAI) ,    ENCODER_CCW_CW(KC_VOLD, KC_VOLU) ,    ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },

    //                  旋钮 1                                     旋钮 2                                       旋钮 3                                旋钮 4                  
};
#endif


// 添加新的按键
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // 下一层
  switch (keycode) {
     case LAYERS_DOWN:
      if(record->event.pressed) {
      if (current_layer == HIGHEST_LAYER){
        current_layer=0;
      } else {
        current_layer++;
      }
      layer_clear();
      layer_on(current_layer);
    }
    return false;
    
   // 上一层  
      case LAYERS_UP:
      if(record->event.pressed) {
      if (current_layer == 0){
        current_layer=HIGHEST_LAYER;
      } else {
        current_layer--;
      }
      layer_clear();
      layer_on(current_layer);
    }
    return false;

    // 处理其他键
     default:
     return true;
     break;

    case jltb:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "https://jlkb.taobao.com" SS_TAP(X_ENTER) SS_TAP(X_ENTER));
        }
        break; 
    
      //按下6层抬起7层    
     case jld6u7:
        if (record->event.pressed) {
           tap_code16(keymap_key_to_keycode(6, record->event.key));
        }else {
           tap_code16(keymap_key_to_keycode(7, record->event.key)); 
      }
    return false;
    break;
    
   // 下一个自定义键
   
  }
   return true;
}

