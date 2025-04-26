# https://github.com/qmk/qmk_firmware/blob/master/docs/reference_info_json.md
# https://github.com/qmk/qmk_firmware/blob/master/data/schemas/keyboard.jsonschema

#  https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md
TAP_DANCE_ENABLE = yes

# LEADER_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes

LTO_ENABLE = yes
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no

POINTING_DEVICE_RIGHT = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball

SRC += drivers/sensors/pimoroni_trackball.c

# MACCEL
SRC += ./features/maccel/maccel.c
ifeq ($(strip $(VIA_ENABLE)), yes)
	ifeq ($(strip $(MACCEL_VIA_ENABLE)), yes)
		SRC += ./features/maccel/maccel_via.c
	endif
endif
OPT_DEFS += -DMACCEL_ENABLE

MOUSE_ENABLE = yes
MACCEL_ENABLE = yes