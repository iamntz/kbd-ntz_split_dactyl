
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case RALT_T(KC_BSPC):
  case LT(3, KC_ENT):
    // Immediately select the hold action when another key is tapped.
    return true;
  default:
    // Do not select the hold action when another key is tapped.
    return false;
  }
}