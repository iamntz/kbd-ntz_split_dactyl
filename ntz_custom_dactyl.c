#include "quantum.h"
#include "print.h"
#include QMK_KEYBOARD_H

#include "ntz_custom_dactyl.h"

#include "inc/rgb.c"
#include "inc/mod_tap_interrupt.c"
#include "inc/permissive_hold.c"
#include "inc/tapping_term.c"
#include "inc/hold_on_other_key_press.c"
#include "inc/key_overrides.c"
#include "inc/pointer.c"
// #include "inc/leader_key.c"
#include "inc/utils/maybe_deactivate_mod_key_on_mod_key.c"

#include "drivers/sensors/pimoroni_trackball.h"

// #include "inc/utils/sarcasm_mode.c"

// #define MODS_MASK (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL))
uint8_t mod_state;

static bool scrolling_mode = false;
uint8_t ntz_pointing_multiplier = 100;

layer_state_t layer_state_set_user(layer_state_t state)
{
  switch (get_highest_layer(state))
  {
  case 1:
    trackball_set_rgbw(0x30, 0x00, 0x00, 0x00);
    scrolling_mode = true;
    ntz_pointing_multiplier = 1;
    break;

  case 2:
    trackball_set_rgbw(0x00, 0x40, 0x00, 0x00);
    break;

  case 3:
    trackball_set_rgbw(0x00, 0x40, 0x40, 0x00);
    break;

  case 4:
    trackball_set_rgbw(0x20, 0x20, 0x20, 0x00);
    break;

  case 5:
    trackball_set_rgbw(0x40, 0x40, 0x40, 0x00);
    break;

  default:
    trackball_set_rgbw(0x00, 0x00, 0x00, 0x00);
    scrolling_mode = false;
    ntz_pointing_multiplier = 100;
    break;
  }

  return state;
}

report_mouse_t pointing_device_task_user(report_mouse_t mouse_report)
{
  mouse_report.x = (mouse_report.x * ntz_pointing_multiplier) / 100;
  mouse_report.y = (mouse_report.y * ntz_pointing_multiplier) / 100;

  if (scrolling_mode)
  {
    mouse_report.h = mouse_report.x;
    mouse_report.v = mouse_report.y;
    mouse_report.x = 0;
    mouse_report.y = 0;
  }

  return mouse_report;
}


// https://docs.qmk.fm/#/feature_advanced_keycodes?id=alt-escape-for-alt-tab
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  mod_state = get_mods();

  switch (keycode)
  {
  case KC_LGUI:
    if (maybe_deactivate_mod_key_on_mod_key(KC_LCBR, KC_RALT, keycode, record, 0)) // Instead of GUI Press [ when altGR is pressed ( for „)
    {
      return false;
    }

    if (record->event.pressed)
    {
      if (mod_state & MOD_MASK_CTRL || // Press shift+tab when ctrl or alt are active
          mod_state & MOD_MASK_ALT)
      {
        tap_code16(LSFT(KC_TAB));
        return false;
      }
    }

  case KC_TAB:
    if (maybe_deactivate_mod_key_on_mod_key(KC_RCBR, KC_RALT, keycode, record, 0)) // // Press ] when altGR is pressed ( for ”)
    {
      return false;
    }

  // case MO(4):
  //   if (!record->tap.count && record->event.pressed) {
  //       tap_code16(C(KC_B)); // Intercept tap function to send Ctrl-C
  //       return false;
  //       // tap_code16(C(KC_V)); // Intercept hold function to send Ctrl-V
  //   }

  }

  return true;
}
