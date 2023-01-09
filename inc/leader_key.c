LEADER_EXTERNS();

void matrix_scan_user(void)
{
  LEADER_DICTIONARY()
  {
    leader_end();

    SEQ_FIVE_KEYS(KC_B, KC_B, KC_B, KC_B, KC_B)
    {
      reset_keyboard();
    }

    SEQ_THREE_KEYS(KC_ESC, KC_ESC, KC_ESC)
    {
      // toggle_sarcasm_mode();
    }
  }
}
