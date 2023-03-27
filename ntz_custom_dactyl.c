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
    ntz_pointing_multiplier = 10;
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

/**
void pointing_device_init_user(void)
{
  set_auto_mouse_layer(5);     // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
  set_auto_mouse_enable(true); // always required before the auto mouse feature will work
}
*/

// https://docs.qmk.fm/#/feature_advanced_keycodes?id=alt-escape-for-alt-tab
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  mod_state = get_mods();

  if (ntz_pointing_multiplier != 100)
  {
    trackball_set_rgbw(0x00, 0x00, 0x00, 0x00);
    ntz_pointing_multiplier = 100;
  }
  else
  {
    if (mod_state & MOD_MASK_SHIFT)
    {
      trackball_set_rgbw(0x10, 0x5, 0x10, 0x00);
      ntz_pointing_multiplier = 50;
    }
    else if (mod_state & MOD_MASK_CTRL)
    {
      trackball_set_rgbw(0x20, 0x5, 0x5, 0x00);
      ntz_pointing_multiplier = 150;
    }
  }

#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, mods: 0x%04X, mods_1: 0x%04X, mods_weak: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
          keycode,
          get_mods(),
          get_oneshot_mods(),
          get_weak_mods(),
          record->event.key.col,
          record->event.key.row,
          record->event.pressed,
          record->event.time,
          record->tap.interrupted,
          record->tap.count);
#endif

  if (record->event.pressed && layer_state_is(2))
  {
    switch (keycode)
    {
    case NTZ_HOME:
      return ntz_send_string_with_mod("~/", "cd ~/");

    case NTZ_CD_UP:
      return ntz_send_string_with_mod("../", "cd ../");

    case NTZ_ARROWS_DOUBLE:
      return ntz_send_string_with_mod("=>", "<=>");

    case NTZ_ARROWS_SINGLE:
      return ntz_send_string_with_mod("->", "->");

    case NTZ_PHP_OPEN_SHORT:
      return ntz_send_string_with_mod("<?= ", "?>");

    case NTZ_PHP_OPEN:
      return ntz_send_string_with_mod("<?php", "?>");
    }
  }

  switch (keycode)
  {
    // case KC_A ... KC_Z:
    //   return maybe_type_in_sarcasm_mode(keycode, record);

    // case KC_F24:
    //   if ((keyboard_report->mods & MODS_MASK) && record->event.pressed)
    //     toggle_sarcasm_mode();
    //   return true;
    //   break;

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
  }

  return true;
}
