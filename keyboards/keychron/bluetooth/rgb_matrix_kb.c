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

#include "quantum.h"

#ifdef RGB_MATRIX_ENABLE

// Compatibility stubs for Keychron's bluetooth indicator functions
// These provide basic functionality for the indicator system

static uint32_t rgb_matrix_disable_timeout = 0;
static uint32_t rgb_matrix_last_activity = 0;

void rgb_matrix_disable_timeout_set(uint32_t timeout_ms) {
    rgb_matrix_disable_timeout = timeout_ms;
    rgb_matrix_last_activity = timer_read32();
}

void rgb_matrix_disable_time_reset(void) {
    rgb_matrix_last_activity = timer_read32();
}

bool rgb_matrix_driver_allow_shutdown(void) {
    // Allow shutdown if timeout is set and exceeded
    if (rgb_matrix_disable_timeout > 0) {
        return (timer_elapsed32(rgb_matrix_last_activity) > rgb_matrix_disable_timeout);
    }
    return false;
}

bool rgb_matrix_is_driver_shutdown(void) {
    // Return true if driver is shut down (not enabled)
    return !rgb_matrix_is_enabled();
}

#endif // RGB_MATRIX_ENABLE
