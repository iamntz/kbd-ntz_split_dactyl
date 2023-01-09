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
