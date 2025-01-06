/*
Copyright 2021 Michał Szczepaniak

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#define WS2812_PWM_DRIVER   PWMD4
#define WS2812_PWM_CHANNEL  4
#define WS2812_PWM_PAL_MODE 2
#define WS2812_PWM_DMA_STREAM   STM32_DMA1_STREAM6  // DMA Stream for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.
#define WS2812_PWM_DMA_CHANNEL  2                   // DMA Channel for TIMx_UP, see the respective reference manual for the appropriate values for your MCU.


# define REPORT_BUFFER_QUEUE_SIZE 256

#ifdef BLUETOOTH_BHQ
// Its active level is "BHQ_IRQ_AND_INT_LEVEL of bhq.h " 
#   define BHQ_RUN_STATE_INPUT_PIN  B13             // Module operating status
#   define QMK_RUN_OUTPUT_PIN       B12             // QMK operating status

#   define UART_DRIVER          SD1
#   define UART_TX_PIN          A9
#   define UART_TX_PAL_MODE     7
#   define UART_RX_PIN          A10
#   define UART_RX_PAL_MODE	    7

#endif


#define WS2812_BYTE_ORDER       WS2812_BYTE_ORDER_GRB

#define RGBLIGHT_LAYERS
#define RGBLIGHT_LAYER_BLINK
#define RGBLIGHT_LAYERS_OVERRIDE_RGB_OFF
#define RGBLIGHT_LAYERS_RETAIN_VAL
