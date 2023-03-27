# https://github.com/qmk/qmk_firmware/blob/master/docs/reference_info_json.md
# https://github.com/qmk/qmk_firmware/blob/master/data/schemas/keyboard.jsonschema

#  https://github.com/qmk/qmk_firmware/blob/master/docs/feature_tap_dance.md
TAP_DANCE_ENABLE = yes

# LEADER_ENABLE = yes

KEY_OVERRIDE_ENABLE = yes

POINTING_DEVICE_ROTATION_90 = yes

POINTING_DEVICE_RIGHT = yes
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = pimoroni_trackball

SRC += drivers/sensors/pimoroni_trackball.c