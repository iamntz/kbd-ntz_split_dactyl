bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case LT(1, KC_SCLN):
  case RALT_T(KC_BSPC):
    // Immediately select the hold action when another key is pressed.
    return true;
  default:
    // Do not select the hold action when another key is pressed.
    return false;
  }
}
