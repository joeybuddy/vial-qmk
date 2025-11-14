/* Copyright 2022 @ Keychron (https://www.keychron.com)
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

#include "quantum.h"
#ifdef VIA_ENABLE
#    include "via.h"
#endif

#define ___ KC_NO

#include "keychron_common.h"

// clang-format off
enum {
#ifdef KC_BLUETOOTH_ENABLE
    BT_HST1 = NEW_SAFE_RANGE,
    BT_HST2,
    BT_HST3,
    BAT_LVL,
    KB_SAFE_RANGE
#else
    BT_HST1 = KC_TRNS,
    BT_HST2 = KC_TRNS,
    BT_HST3 = KC_TRNS,
    BAT_LVL = KC_TRNS,
    KB_SAFE_RANGE = NEW_SAFE_RANGE
#endif
};
