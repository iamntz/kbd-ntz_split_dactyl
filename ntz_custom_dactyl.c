#include "ntz_custom_dactyl.h"
#include "quantum.h"

#include "inc/mod_tap_interrupt.c"
#include "inc/permissive_hold.c"
#include "inc/tapping_term.c"
#include "inc/hold_on_other_key_press.c"
#include "inc/leader_key.c"

bool maybe_deactivate_mod_key_on_alt_gr(uint16_t alternateKeycode, uint8_t mods, uint16_t keycode, keyrecord_t *record)
{
  if (!((mods & MOD_BIT(KC_RALT)) == MOD_BIT(KC_RALT)))
  {
    return true;
  }

  if (record->event.pressed)
  {
    register_code(alternateKeycode);
    unregister_code(keycode);
  }
  else
  {
    unregister_code(alternateKeycode);
  }

  return false;
}

// https://docs.qmk.fm/#/feature_advanced_keycodes?id=alt-escape-for-alt-tab
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
  const uint8_t mods = get_mods() | get_oneshot_mods();

  switch (keycode)
  {
  case KC_LGUI:
    return maybe_deactivate_mod_key_on_alt_gr(KC_LCBR, mods, keycode, record);

  case KC_TAB:
    return maybe_deactivate_mod_key_on_alt_gr(KC_RCBR, mods, keycode, record);
  }

  return true;
}
