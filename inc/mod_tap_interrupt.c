
bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record)
{
  switch (keycode)
  {
  case KC_LGUI:
  case KC_LCTL:
  case KC_RALT:
  case KC_LALT:
  case RALT_T(KC_BSPC):
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
