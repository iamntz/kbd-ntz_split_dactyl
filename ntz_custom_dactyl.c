#include "ntz_custom_dactyl.h"
#include "quantum.h"
#include "print.h"

#include "inc/mod_tap_interrupt.c"
#include "inc/permissive_hold.c"
#include "inc/tapping_term.c"
#include "inc/hold_on_other_key_press.c"
// #include "inc/leader_key.c"
#include "inc/utils/maybe_deactivate_mod_key_on_mod_key.c"
// #include "inc/utils/sarcasm_mode.c"

// #define MODS_MASK (MOD_BIT(KC_LSFT) | MOD_BIT(KC_LCTL))

// https://docs.qmk.fm/#/feature_advanced_keycodes?id=alt-escape-for-alt-tab
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{

#ifdef CONSOLE_ENABLE
  uprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
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
    return maybe_deactivate_mod_key_on_mod_key(KC_LCBR, KC_RALT, keycode, record, 0) &&             // Instead of GUI Press [ when altGR is pressed ( for „)
           maybe_deactivate_mod_key_on_mod_key(KC_TAB, KC_LCTL, keycode, record, MOD_MASK_SHIFT) && // Press shift+tab when ctrl is active
           maybe_deactivate_mod_key_on_mod_key(KC_TAB, KC_LALT, keycode, record, MOD_MASK_SHIFT)    // press shift+tab when alt is active
        ;

  case KC_TAB:
    return maybe_deactivate_mod_key_on_mod_key(KC_RCBR, KC_RALT, keycode, record, 0); // // Press ] when altGR is pressed ( for ”)

  }

  return true;
}

const key_override_t ntz_override_1 = ko_make_basic(MOD_BIT(KC_RALT), KC_Z, RALT(KC_5)); // Press alt gr + B for »
const key_override_t ntz_override_3 = ko_make_basic(MOD_BIT(KC_RALT), KC_B, RALT(KC_DOT));  // Press alt gr + B for »
const key_override_t ntz_override_4 = ko_make_basic(MOD_BIT(KC_RALT), KC_V, RALT(KC_COMM)); // Press alt gr + V for «

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ntz_override_1,
    &ntz_override_3,
    &ntz_override_4,
    NULL // Null terminate the array of overrides!
};