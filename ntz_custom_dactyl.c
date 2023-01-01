#include "ntz_custom_dactyl.h"
#include "quantum.h"
#include QMK_KEYBOARD_H

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case LSFT_T(KC_SPC):
    // Do not force the mod-tap key press to be handled as a modifier
    // if any other key was pressed while the mod-tap key is held down.
    return true;
  default:
    // Force the mod-tap key press to be handled as a modifier if any
    // other key was pressed while the mod-tap key is held down.
    return false;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case LT(3, KC_ENT):
    // Immediately select the hold action when another key is tapped.
    return true;
  default:
    // Do not select the hold action when another key is tapped.
    return false;
  }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case RALT_T(KC_BSPC):
    return 300;
  default:
    return TAPPING_TERM;
  }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case RALT_T(KC_BSPC):
    // Immediately select the hold action when another key is pressed.
    return true;
  default:
    // Do not select the hold action when another key is pressed.
    return false;
  }
}

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

// layer_state_t layer_state_set_user(layer_state_t state)
// {
//   unregister_code(KC_LALT);

//   if (get_highest_layer(state) == 5)
//   {
//     register_code(KC_LALT);
//   }

//   return state;
// }