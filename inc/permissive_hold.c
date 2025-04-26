
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
    case LSFT_T(KC_SPC):
    case RALT_T(KC_BSPC):
    // case LT(3, KC_ENT):
      // Immediately select the hold action when another key is tapped.
      return true;
    default:
      // Do not select the hold action when another key is tapped.
      return false;
  }
}

// bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record)
// {
//   switch (keycode)
//   {
//     case LT(3, KC_ENT):
//       // Do not force the mod-tap key press to be handled as a modifier
//       // if any other key was pressed while the mod-tap key is held down.
//       return true;
//     default:
//       // Force the mod-tap key press to be handled as a modifier if any
//       // other key was pressed while the mod-tap key is held down.
//       return false;
//   }
// }

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case LT(3, KC_ENT):
    // Immediately select the hold action when another key is pressed.
    return true;
  default:
    // Do not select the hold action when another key is pressed.
    return false;
  }
}
