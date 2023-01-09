bool is_sarcasm_active = false;

void toggle_sarcasm_mode(void)
{
  is_sarcasm_active = !is_sarcasm_active;
}

void sarcasm_mode_off(void)
{
  is_sarcasm_active = false;
}

// random bool
bool randomly_toggle_sarcasm_mode_on_typing(void)
{
  bool rbool = rand() & 1;

  return rbool;
}

bool maybe_type_in_sarcasm_mode(uint16_t keycode, keyrecord_t *record)
{
  if (is_sarcasm_active && record->event.pressed)
  {
    if (randomly_toggle_sarcasm_mode_on_typing())
    {
      register_code(KC_LSFT);
    }
  }

  return true;
}

void maybe_type_in_sarcasm_mode_post(uint16_t keycode, keyrecord_t *record)
{
  if (is_sarcasm_active && record->event.pressed)
  {
    unregister_code(KC_LSFT);
  }
}