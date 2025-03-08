
#ifdef OLED_ENABLE
 #include "logo.c"      //层logo标志
   oled_rotation_t oled_init_user(oled_rotation_t rotation) {
	return OLED_ROTATION_180; /*将屏幕旋转180度*/
}
 bool oled_task_user(void) {
switch (get_highest_layer(layer_state)) {
        case 0:
            oled_write_raw_P(logo, sizeof(logo));
            break;
        case 1:
            oled_write_raw_P(L1, sizeof(L1));
            break;
        case 2:
            oled_write_raw_P(L2, sizeof(L2));
            break;
        case 3:
            oled_write_raw_P(L3, sizeof(L3));
            break;
        case 4:
            oled_write_raw_P(L4, sizeof(L4));
            break ;
        case 5:
            oled_write_raw_P(L5, sizeof(L5));
            break;
        case 6:
            oled_write_raw_P(L6, sizeof(L6));
            break;           
        case 7:
            oled_write_raw_P(L7, sizeof(L7));
            break;          
        case 8:
            oled_write_raw_P(L8, sizeof(L8));
            break;         
        case 9:
            oled_write_raw_P(L9, sizeof(L9));
            break;           
        case 10:            
            oled_write_raw_P(L10, sizeof(L10));
            break;
        case 11:            
            oled_write_raw_P(L11, sizeof(L11));
            break;           
        case 12:            
            oled_write_raw_P(L12, sizeof(L12));
            break;           
        case 13:            
            oled_write_raw_P(L13, sizeof(L13));
            break;           
        case 14:            
            oled_write_raw_P(L14, sizeof(L14));
            break;           
        case 15:            
            oled_write_raw_P(L15, sizeof(L15));
            break;       
    }
/*
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("\nNUM ") : PSTR("\n    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    */
    return false;

}

#endif
