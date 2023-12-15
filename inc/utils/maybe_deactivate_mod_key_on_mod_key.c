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
