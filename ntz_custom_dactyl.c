#include "ntz_custom_dactyl.h"
#include "quantum.h"

#include "inc/mod_tap_interrupt.c"
#include "inc/permissive_hold.c"
#include "inc/tapping_term.c"
#include "inc/hold_on_other_key_press.c"
#include "inc/leader_key.c"
#include "inc/utils/maybe_deactivate_mod_key_on_mod_key.c"
#include "inc/utils/sarcasm_mode.c"

#define MODS_MASK (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL))

// https://docs.qmk.fm/#/feature_advanced_keycodes?id=alt-escape-for-alt-tab
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{

  if (record->event.pressed)
  {
    switch (keycode)
    {
    case NTZ_HOME:
      return ntz_send_string_with_mod("~/", "cd ~/");

    case NTZ_CD_UP:
      return ntz_send_string_with_mod("../", "cd ../");

      // case NTZ_ARROWS:
      //   return ntz_send_string_with_mod("=>", "<=>");
    }
  }

  switch (keycode)
  {
  case KC_A ... KC_Z:
    return maybe_type_in_sarcasm_mode(keycode, record);

  case KC_F24:
    if ((keyboard_report->mods & MODS_MASK) && record->event.pressed)
      toggle_sarcasm_mode();
    return true;
    break;

  case KC_LGUI:
    return maybe_deactivate_mod_key_on_mod_key(KC_LCBR, KC_RALT, keycode, record, 0) &&
           maybe_deactivate_mod_key_on_mod_key(KC_TAB, KC_LCTL, keycode, record, MOD_MASK_SHIFT) &&
           maybe_deactivate_mod_key_on_mod_key(KC_TAB, KC_LALT, keycode, record, MOD_MASK_SHIFT);

  case KC_TAB:
    return maybe_deactivate_mod_key_on_mod_key(KC_RCBR, KC_RALT, keycode, record, 0);
  }

  return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case KC_A ... KC_Z:
    maybe_type_in_sarcasm_mode_post(keycode, record);
  }
}
