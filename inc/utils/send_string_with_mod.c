
void ntz_send_string_with_mod(const char *normalString, const char *shiftedString)
{
  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();

  if ((mods | oneshot_mods) & MOD_MASK_SHIFT)
  { // Is shift held?
    // Temporarily delete shift.
    del_oneshot_mods(MOD_MASK_SHIFT);
    unregister_mods(MOD_MASK_SHIFT);
    send_string(shiftedString);
  }
  else
  {
    send_string(normalString);
  }
}