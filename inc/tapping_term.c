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
