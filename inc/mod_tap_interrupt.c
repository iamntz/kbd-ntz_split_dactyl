
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
