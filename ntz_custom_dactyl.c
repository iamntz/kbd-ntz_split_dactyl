#include "quantum.h"
#include "print.h"
#include QMK_KEYBOARD_H

#include "ntz_custom_dactyl.h"

#include "inc/mod_tap_interrupt.c"
#include "inc/permissive_hold.c"
#include "inc/tapping_term.c"
#include "inc/hold_on_other_key_press.c"
#include "inc/key_overrides.c"
// #include "inc/leader_key.c"
#include "inc/utils/maybe_deactivate_mod_key_on_mod_key.c"
// #include "inc/utils/sarcasm_mode.c"

// #define MODS_MASK (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL))
uint8_t mod_state;

// https://docs.qmk.fm/#/feature_advanced_keycodes?id=alt-escape-for-alt-tab
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{

#ifdef CONSOLE_ENABLE
  const uint8_t debug_mods = get_mods();
  const uint8_t debug_mods_1 = get_oneshot_mods();
  const uint8_t debug_mods_weak = get_weak_mods();
  uprintf("KL: kc: 0x%04X, mods: 0x%04X, mods_1: 0x%04X, mods_weak: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n",
          keycode,
          debug_mods,
          debug_mods_1,
          debug_mods_weak,
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

    case NTZ_ARROWS:
      return ntz_send_string_with_mod("=>", "<=>");

    case NTZ_PHP_OPEN:
      return ntz_send_string_with_mod("<?= ", "<?php ");

    case NTZ_PHP_CLOSE:
      return ntz_send_string_with_mod("?>", "?>");
    }
  }
  mod_state = get_mods();

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