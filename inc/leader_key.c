LEADER_EXTERNS();

void matrix_scan_user(void)
{
  LEADER_DICTIONARY()
  {
    leading = false;
    leader_end();

    SEQ_FIVE_KEYS(KC_B, KC_B, KC_B, KC_B, KC_B)
    {
      reset_keyboard();
      // register_code(QK_BOOT);
    }
  }
}
