/* Copyright 2024 @ Keychron (https://www.keychron.com)
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

#include <stdint.h>
#include <stdbool.h>

#ifdef LED_MATRIX_ENABLE

// Compatibility functions for Keychron's bluetooth indicator system
void led_matrix_disable_timeout_set(uint32_t timeout_ms);
void led_matrix_disable_time_reset(void);
bool led_matrix_driver_allow_shutdown(void);
bool led_matrix_is_driver_shutdown(void);

// Compatibility constant
#ifndef LED_MATRIX_TIMEOUT_INFINITE
#    define LED_MATRIX_TIMEOUT_INFINITE 0
#endif

#endif // LED_MATRIX_ENABLE
