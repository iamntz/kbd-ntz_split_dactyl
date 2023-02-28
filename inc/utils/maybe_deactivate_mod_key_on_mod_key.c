bool maybe_deactivate_mod_key_on_mod_key(uint16_t alternateKeycode, uint16_t whenModKeyCodeIsActive, uint16_t realKeyCode, keyrecord_t *record, uint16_t withModifier)
{
  const uint8_t mods = get_mods();

  if (!((mods & MOD_BIT(whenModKeyCodeIsActive)) == MOD_BIT(whenModKeyCodeIsActive)))
  {
    return false;
  }

  if (record->event.pressed)
  {
    register_mods(withModifier);
    register_code(alternateKeycode);
  }
  else
  {
    unregister_mods(withModifier);
    unregister_code(alternateKeycode);
  }

  return true;
}

bool ntz_send_string_with_mod(const char *normalString, const char *shiftedString)
{
  const uint8_t mods = get_mods();
  const uint8_t oneshot_mods = get_oneshot_mods();

  if ((mods | oneshot_mods) & MOD_MASK_SHIFT)
  { // Is shift held?
    // Temporarily delete shift.
    del_oneshot_mods(MOD_MASK_SHIFT);
    unregister_mods(MOD_MASK_SHIFT);
    send_string(shiftedString);
    register_mods(mods); // Restore mods.
    return false;
  }

  send_string(normalString);

  return false;
}