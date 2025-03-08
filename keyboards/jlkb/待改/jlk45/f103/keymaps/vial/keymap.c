#include QMK_KEYBOARD_H
#include "f103.h"


enum keycodes {
  LAYERS_DOWN = SAFE_RANGE,
  LAYERS_UP,
  jltb
};

// 1st layer on the cycle
#define LAYER_CYCLE_START 0
// Last layer on the cycle
#define LAYER_CYCLE_END   16


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	LAYOUT(
	    KC_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, 
		KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_ENT,  KC_BSPC,
		KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_DOT, KC_LSFT, KC_NO, KC_BSPC, 
		KC_HYPR, KC_LGUI, KC_RALT, KC_SPC, KC_RALT, KC_RALT, KC_RALT, KC_LGUI, KC_BSPC, KC_BSPC, KC_BSPC, KC_BSPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),

	LAYOUT(
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),

	LAYOUT(
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),

	LAYOUT(
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),

	LAYOUT(
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),
	LAYOUT(
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),

	LAYOUT(
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC),

	LAYOUT(
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, 
		KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC, KC_SPC)
		
};


// Add the behaviour of this new keycode
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  // 下一层
  switch (keycode) {
    case LAYERS_DOWN:
      // Our logic will happen on presses, nothing is done on releases
      if (!record->event.pressed) { 
        // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
        return false;
      }

      uint8_t current_layer = get_highest_layer(layer_state);

      // Check if we are within the range, if not quit
      if (current_layer > LAYER_CYCLE_END || current_layer < LAYER_CYCLE_START) {
        return false;
      }

      uint8_t next_layer = current_layer + 1;
      if (next_layer > LAYER_CYCLE_END) {
          next_layer = LAYER_CYCLE_START;
      }
      layer_move(next_layer);
      return false;

    // Process other keycodes normally

     return true;
     break;
   // 上一层  
      case LAYERS_UP:
      // Our logic will happen on presses, nothing is done on releases
      if (!record->event.pressed) { 
        // We've already handled the keycode (doing nothing), let QMK know so no further code is run unnecessarily
        return false;
      }

      uint8_t current1_layer = get_highest_layer(layer_state);

      // Check if we are within the range, if not quit
      if (current1_layer > LAYER_CYCLE_END || current1_layer < LAYER_CYCLE_START) {
        return false;
      }

      uint8_t previous_layer = current1_layer - 1;
      if (previous_layer > LAYER_CYCLE_END) {
          previous_layer = LAYER_CYCLE_START;
      }
      layer_move(previous_layer);
      return false;

    // Process other keycodes normally
     default:
     return true;
     break;
     
 case jltb:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LGUI) SS_TAP(X_R) SS_UP(X_LGUI) SS_DELAY(100) "https://jlkb.taobao.com" SS_TAP(X_ENTER) SS_TAP(X_ENTER));
        }
        
 //OLED   
      if (record->event.pressed) {
#ifdef OLED_ENABLE
        oled_timer = timer_read32();
#endif
    }
    return true;
    break;
  }
}


/*/// 按下 Capslock 的時候，第6颗RGB之后(也就第7颗) 的4颗灯会亮与第12個灯(也就是第12个) 之后的第4颗会亮紅色。
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 1, RGB_AZURE}       // Light 4 LEDs, starting with LED 6
);
 */
// Layer 1 启用的時候，{1,2, RGB_WHITE}第 1颗开始2颗灯会亮白色
const rgblight_segment_t PROGMEM my_layer0_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0,1, HSV_AZURE}
);
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,1, HSV_AZURE}
);
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {7,1, HSV_AZURE}
);
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6,1, HSV_AZURE}
);
const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {5,1, HSV_AZURE}
);
const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {4,1, HSV_PINK}
);
const rgblight_segment_t PROGMEM my_layer6_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {3,1, HSV_PINK}
);
const rgblight_segment_t PROGMEM my_layer7_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {2,1, HSV_PINK}
);
const rgblight_segment_t PROGMEM my_layer8_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {1,1, HSV_PINK}
);
const rgblight_segment_t PROGMEM my_layer9_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,1, HSV_WHITE},{7,1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer10_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,1, HSV_WHITE},{6,1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer11_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,1, HSV_WHITE},{5,1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer12_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,1, HSV_WHITE},{4,1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer13_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,1, HSV_WHITE},{3,1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer14_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,1, HSV_WHITE},{2,1, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_layer15_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {8,1, HSV_WHITE},{1,1, HSV_PURPLE}
);
// etc..

// 接着將您的 rgblight_segment_t 放到 RGBLIGHT_LAYERS_LIST 內
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
//    my_capslock_layer,   // Overrides caps lock layer
    my_layer0_layer, // Overrides other layer 
    my_layer1_layer, // Overrides other layer 
    my_layer2_layer, 
    my_layer3_layer, 
    my_layer4_layer, 
    my_layer5_layer, 
    my_layer6_layer, 
    my_layer7_layer, 
    my_layer8_layer, 
    my_layer9_layer, 
    my_layer10_layer, 
    my_layer11_layer, 
    my_layer12_layer, 
    my_layer13_layer, 
    my_layer14_layer, 
    my_layer15_layer      
);

void keyboard_post_init_user(void) {
    // 启用LED层指示
    rgblight_layers = my_rgb_layers;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    // 如果两个 kb 层都处于活动状态，则两个层都会亮起
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    rgblight_set_layer_state(4, layer_state_cmp(state, 4));
    rgblight_set_layer_state(5, layer_state_cmp(state, 5));
    rgblight_set_layer_state(6, layer_state_cmp(state, 6));
    rgblight_set_layer_state(7, layer_state_cmp(state, 7));
    rgblight_set_layer_state(8, layer_state_cmp(state, 8));
    rgblight_set_layer_state(9, layer_state_cmp(state, 9));
    rgblight_set_layer_state(10, layer_state_cmp(state, 10));
    rgblight_set_layer_state(11, layer_state_cmp(state, 11));
    rgblight_set_layer_state(12, layer_state_cmp(state, 12));
    rgblight_set_layer_state(13, layer_state_cmp(state, 13));
    rgblight_set_layer_state(14, layer_state_cmp(state, 14));
    rgblight_set_layer_state(15, layer_state_cmp(state, 15));
    return state;
}

/*
bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
} */
