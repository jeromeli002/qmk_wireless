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

#include_next <mcuconf.h>

#define HAL_USE_SERIAL  TRUE        // enabled SERIAL

#    undef STM32_SERIAL_USE_USART2
#    define STM32_SERIAL_USE_USART2 TRUE

#undef STM32_ADC_USE_ADC1
#define STM32_ADC_USE_ADC1          TRUE

#undef STM32_PLLXTPRE
#define STM32_PLLXTPRE STM32_PLLXTPRE_DIV2