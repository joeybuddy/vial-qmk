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

#include "snled27351_driver_compat.h"

#ifdef RGB_MATRIX_ENABLE

#include "snled27351.h"

// Access to the driver's internal buffers
// This is defined in drivers/led/snled27351.c
typedef struct snled27351_driver_t {
    uint8_t pwm_buffer[192];  // SNLED27351_PWM_REGISTER_COUNT = 192
    bool    pwm_buffer_dirty;
    uint8_t led_control_buffer[24];  // SNLED27351_LED_CONTROL_REGISTER_COUNT = 24
    bool    led_control_buffer_dirty;
} snled27351_driver_t;

extern snled27351_driver_t driver_buffers[SNLED27351_DRIVER_COUNT];

uint32_t snled27351_get_brightness_sum(void) {
    uint32_t total = 0;
    for (uint8_t i = 0; i < SNLED27351_DRIVER_COUNT; i++) {
        for (uint16_t j = 0; j < 192; j++) {
            total += driver_buffers[i].pwm_buffer[j];
        }
    }
    return total;
}

#endif // RGB_MATRIX_ENABLE
