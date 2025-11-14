# Enter lower-power sleep mode when on the ChibiOS idle thread
OPT_DEFS += -DCORTEX_ENABLE_WFI_IDLE=TRUE
OPT_DEFS += -DNO_USB_STARTUP_CHECK -DENABLE_FACTORY_TEST

SRC += matrix.c

# Include keychron common files for custom keycodes
VPATH += keyboards/keychron/common
SRC += keychron_common.c

include keyboards/keychron/bluetooth/bluetooth.mk
