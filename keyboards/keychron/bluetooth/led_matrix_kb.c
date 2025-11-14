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

#ifdef LED_MATRIX_ENABLE

// Compatibility stubs for Keychron's bluetooth indicator functions
// These provide basic functionality for the indicator system

static uint32_t led_matrix_disable_timeout = 0;
static uint32_t led_matrix_last_activity = 0;

void led_matrix_disable_timeout_set(uint32_t timeout_ms) {
    led_matrix_disable_timeout = timeout_ms;
    led_matrix_last_activity = timer_read32();
}

void led_matrix_disable_time_reset(void) {
    led_matrix_last_activity = timer_read32();
}

bool led_matrix_driver_allow_shutdown(void) {
#if defined(LED_MATRIX_DRIVER_SHUTDOWN_ENABLE)
    // Don't allow shutdown if any lock LED is active
#    if defined(NUM_LOCK_INDEX)
    if (host_keyboard_led_state().num_lock) return false;
#    endif
#    if defined(CAPS_LOCK_INDEX) && !defined(DIM_CAPS_LOCK)
    if (host_keyboard_led_state().caps_lock) return false;
#    endif
#    if defined(SCROLL_LOCK_INDEX)
    if (host_keyboard_led_state().scroll_lock) return false;
#    endif
#    if defined(COMPOSE_LOCK_INDEX)
    if (host_keyboard_led_state().compose) return false;
#    endif
#    if defined(KANA_LOCK_INDEX)
    if (host_keyboard_led_state().kana) return false;
#    endif
    // Allow shutdown if timeout is set and exceeded
    if (led_matrix_disable_timeout > 0) {
        return (timer_elapsed32(led_matrix_last_activity) > led_matrix_disable_timeout);
    }
#endif
    return false;
}

bool led_matrix_is_driver_shutdown(void) {
    // Return true if driver is shut down (not enabled)
    return !led_matrix_is_enabled();
}

#endif // LED_MATRIX_ENABLE
