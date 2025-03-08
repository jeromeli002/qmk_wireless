
#ifdef OLED_ENABLE
#include "logo.c"      //层logo标志
   oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180; /*将屏幕旋转180度*/
}
 bool oled_task_user(void) {/*
switch (get_highest_layer(layer_state)) 
     {
        case 0:
            oled_write_raw_P(logo, sizeof(logo));
            break;     
    }*/

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("\nNUM ") : PSTR("\n    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;

}

#endif
