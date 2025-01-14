/* Copyright 2024 keymagichorse
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

# define REPORT_BUFFER_QUEUE_SIZE 256 //f401 需要启用
 
#ifdef BLUETOOTH_BHQ
// Its active level is "BHQ_IRQ_AND_INT_LEVEL of bhq.h " 
#   define BHQ_RUN_STATE_INPUT_PIN  B10             // 无线模块运行状态IQR/+
#   define QMK_RUN_OUTPUT_PIN       B11             // QMK运行状态INT/-
#   define USB_POWER_SENSE_PIN      A13                  // USB插入检测/低功耗
#   define USB_POWER_CONNECTED_LEVEL 1           //1高，0低。配置USB插入时是高电平还是低电平的

#   define UART_DRIVER          SD1
#   define UART_TX_PIN          A9
#   define UART_TX_PAL_MODE     7
#   define UART_RX_PIN          A10
#   define UART_RX_PAL_MODE	    7

// STM32使用到的高速晶振引脚号，做低功耗需要用户配置，每款芯片有可能不一样的
#define LPM_STM32_HSE_PIN_IN     H1  
#define LPM_STM32_HSE_PIN_OUT    H0

#endif


#define WS2812_BYTE_ORDER       WS2812_BYTE_ORDER_GRB

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYERS_RETAIN_VAL
