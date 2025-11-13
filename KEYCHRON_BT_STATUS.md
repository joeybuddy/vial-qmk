# Keychron Bluetooth Keyboards Status

## Summary
This document tracks the status of adding Vial-QMK support for Keychron's bluetooth keyboards (k2_pro, k3_pro, q8_pro).

## Completed Work

### 1. Keyboard Definitions Added
- ✅ k2_pro (ansi/rgb variant)
- ✅ k3_pro (ansi/rgb variant)  
- ✅ q8_pro (ansi_encoder variant)

### 2. Bluetooth Support Infrastructure
- ✅ Downloaded all bluetooth support files from Keychron's bluetooth_playground branch
- ✅ Added bluetooth directory with core bluetooth functionality
- ✅ Includes: bluetooth.c, ckbt51.c, battery.c, indicator.c, transport.c, lpm.c, rtc_timer.c, etc.

### 3. Vial Support
- ✅ Created vial keymaps for all three keyboards
- ✅ Added vial.json files with keyboard layouts
- ✅ Added config.h with unique VIAL_KEYBOARD_UID for each keyboard
- ✅ Added rules.mk with VIAL_ENABLE and VIALRGB_ENABLE
- ✅ Included custom keycodes for bluetooth (BT_HST1-3, BAT_LVL) and Mac/Windows shortcuts

### 4. Configuration Fixes
- ✅ Fixed deprecated config options (RGB_MATRIX_SLEEP, LED_MATRIX_SLEEP)
- ✅ Added MCU configuration for LSE (Low Speed External) clock required by RTC
- ✅ Fixed LSE driver configuration for bluetooth operation

### 5. API Compatibility Fixes
- ✅ Updated host_driver_t structure to match current QMK API
- ✅ Added bluetooth_send_nkro() wrapper function
- ✅ Fixed eeconfig_read_keymap() API call
- ✅ Added RAW_EPSIZE fallback definition

## Remaining Work

### Build System Issues
The bluetooth code from Keychron's fork is based on an older version of QMK and has several API mismatches:

1. **indicator.c API Issues:**
   - Missing LED_DRIVER_IS_ENABLED() function
   - Missing indicator helper functions (indicator_reset_backlit_time, indicator_set_backlit_timeout)
   - Missing DECIDE_TIME macro
   - Missing timeout constants (DISCONNECTED_BACKLIGHT_DISABLE_TIMEOUT, CONNECTED_BACKLIGHT_DISABLE_TIMEOUT)
   - Missing bat_level_animiation_task() function

2. **Potential Additional Issues:**
   - Other bluetooth files may have similar API mismatches
   - LED/RGB matrix integration may need updates
   - Factory test functionality may not compile

### Solutions

#### Option 1: Complete API Updates (Recommended for Full Functionality)
- Update all bluetooth files to match current QMK APIs
- Add missing helper functions and macros
- Test thoroughly on actual hardware

#### Option 2: Simplified Build (Quick Solution)
- Disable problematic features (indicator, factory_test) temporarily
- Create stub functions for missing APIs
- Focus on core keyboard functionality first
- Add bluetooth features incrementally

#### Option 3: Wait for Official Support
- Monitor Keychron's vial-qmk fork for updates
- Use updated code when available

## Files Structure

```
keyboards/keychron/
├── bluetooth/              # Bluetooth support infrastructure
│   ├── bluetooth.c/h      # Core bluetooth functionality
│   ├── ckbt51.c/h         # Bluetooth module driver
│   ├── battery.c/h        # Battery management
│   ├── indicator.c/h      # LED indicators for BT status
│   ├── transport.c/h      # Transport layer
│   ├── lpm.c/h            # Low power mode
│   ├── rtc_timer.c/h      # RTC timer for bluetooth
│   └── ...                # Other support files
├── k2_pro/
│   ├── ansi/rgb/
│   │   ├── keymaps/
│   │   │   ├── default/   # Default keymap
│   │   │   ├── via/       # VIA keymap  
│   │   │   └── vial/      # ✨ VIAL keymap (NEW)
│   │   └── keyboard.json
│   ├── config.h
│   ├── k2_pro.c/h
│   └── ...
├── k3_pro/                 # Similar structure to k2_pro
└── q8_pro/                 # Similar structure to k2_pro
```

## Testing Status
- ⏳ k2_pro compilation: In progress (bluetooth API issues)
- ⏳ k3_pro compilation: Not tested yet
- ⏳ q8_pro compilation: Not tested yet
- ❌ Hardware testing: Not performed (requires actual keyboards)

## Next Steps
1. Decide on approach (Option 1, 2, or 3 above)
2. Complete API fixes for chosen approach
3. Test compilation for all three keyboards
4. Document build instructions
5. Hardware testing with actual keyboards (requires user involvement)

## Notes
- The keyboards use STM32L432 MCU
- Bluetooth is handled by CKBT51 module
- All keyboards support both wired (USB) and wireless (BT) operation
- The implementation includes battery level monitoring and power management
- NKRO (N-Key Rollover) is supported over bluetooth
