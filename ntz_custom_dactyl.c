#include "ntz_custom_dactyl.h"
#include "quantum.h"

#include "inc/mod_tap_interrupt.c"
#include "inc/permissive_hold.c"
#include "inc/tapping_term.c"
#include "inc/hold_on_other_key_press.c"
#include "inc/leader_key.c"

bool maybe_deactivate_mod_key_on_mod_key(uint16_t alternateKeycode, uint16_t whenModKeyCodeIsActive, uint16_t realKeyCode, keyrecord_t *record, uint16_t extraMods)
{
  const uint8_t mods = get_mods() | get_oneshot_mods();

  if (!((mods & MOD_BIT(whenModKeyCodeIsActive)) == MOD_BIT(whenModKeyCodeIsActive)))
  {
    return true;
  }

  if (record->event.pressed)
  {
    if (extraMods > 0)
    {
      register_mods(extraMods);
    }

    register_code(alternateKeycode);
    unregister_code(realKeyCode);
  }
  else
  {
    unregister_code(alternateKeycode);

    if (extraMods > 0)
    {
      unregister_mods(extraMods);
    }
  }

  return false;
}

// https://docs.qmk.fm/#/feature_advanced_keycodes?id=alt-escape-for-alt-tab
bool process_record_user(uint16_t keycode, keyrecord_t *record)
{

  switch (keycode)
  {
  case KC_LGUI:
    return maybe_deactivate_mod_key_on_mod_key(KC_LCBR, KC_RALT, keycode, record, 0) &&
        maybe_deactivate_mod_key_on_mod_key(KC_TAB, KC_LCTL, keycode, record, MOD_MASK_SHIFT) &&
        maybe_deactivate_mod_key_on_mod_key(KC_TAB, KC_LALT, keycode, record, MOD_MASK_SHIFT);

  case KC_TAB:
    return maybe_deactivate_mod_key_on_mod_key(KC_RCBR, KC_RALT, keycode, record, 0);
  }

  return true;
}
