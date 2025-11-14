/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0x4E, 0x99, 0x4F, 0x33, 0x9E, 0xB1, 0xDC, 0x37}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 13 }

// Reduce EEPROM usage for wireless keyboards
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define DYNAMIC_KEYMAP_MACRO_COUNT 0
// Minimize tap dance and combo to save EEPROM (cannot be 0)
#define VIAL_TAP_DANCE_ENTRIES 1
#define VIAL_COMBO_ENTRIES 1
