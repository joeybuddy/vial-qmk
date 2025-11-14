# Keychron Keyboard Troubleshooting Guide

## Firmware Not Responding After Flash

### Symptoms
- Keyboard does not respond to any key presses after flashing firmware
- Both wired (USB) and wireless (Bluetooth) connections are non-functional
- No LED activity or key response

### Root Cause
The issue was caused by missing `keychron_common.c` source file in the build for some keymaps. The keyboard firmware depends on the `key_comb_list` array and custom keycode handlers defined in `keychron_common.c`, but only the vial keymap was explicitly including this file.

### Technical Details
- `k2_pro.h`, `k3_pro.h`, and `q8_pro.h` include `keychron_common.h`
- These files declare custom keycodes like `KC_LOPTN`, `KC_LCMMD`, `KC_TASK`, `KC_FILE`, `KC_SNAP`
- The keyboard implementation files (`k2_pro.c`, etc.) use the `key_comb_list` array for key combination handling
- Without `keychron_common.c` being compiled and linked, the firmware had undefined symbols or incorrect initialization

### Solution
The fix adds `keychron_common.c` to the base `rules.mk` file for each keyboard (k2_pro, k3_pro, q8_pro), ensuring all keymaps (default, via, vial) properly include the required source file.

### Changes Made
1. Added to `keyboards/keychron/k2_pro/rules.mk`:
   ```makefile
   # Include keychron common files for custom keycodes
   VPATH += keyboards/keychron/common
   SRC += keychron_common.c
   ```

2. Applied the same fix to `k3_pro/rules.mk` and `q8_pro/rules.mk`

3. Removed redundant includes from vial keymap `rules.mk` files (now inherited from base)

### Verification
After applying this fix:
1. Rebuild the firmware using the GitHub Actions workflow
2. Flash the new firmware to your keyboard
3. Test both wired and wireless connectivity
4. Verify all keys respond correctly
5. Test custom keycodes (Bluetooth host switching, battery level, etc.)

### Related Issues
- Custom keycodes not working
- Bluetooth host switching (BT_HST1-3) not functional
- Battery level indicator (BAT_LVL) not working
- Windows/Mac specific keys (KC_TASK, KC_FILE, KC_SNAP) not responding

All of these symptoms share the same root cause and are fixed by this change.
