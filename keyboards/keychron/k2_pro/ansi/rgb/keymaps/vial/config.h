/* SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#define VIAL_KEYBOARD_UID {0xD3, 0x66, 0x1B, 0xB7, 0xAE, 0x80, 0x63, 0xC3}

#define VIAL_UNLOCK_COMBO_ROWS { 0, 3 }
#define VIAL_UNLOCK_COMBO_COLS { 0, 13 }

// Reduce EEPROM usage for wireless keyboards
#define DYNAMIC_KEYMAP_LAYER_COUNT 4
#define DYNAMIC_KEYMAP_MACRO_COUNT 0
// Disable tap dance to save EEPROM
#define VIAL_TAP_DANCE_ENTRIES 0
#define VIAL_COMBO_ENTRIES 0
