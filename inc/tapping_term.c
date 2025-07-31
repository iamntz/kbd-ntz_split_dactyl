#include "utils/send_string_with_mod.c"


void ntz_maybe_reset_mods(tap_dance_state_t *state, void *user_data)
{
  del_oneshot_mods(MOD_MASK_SHIFT);
  unregister_mods(MOD_MASK_SHIFT);
  clear_oneshot_mods();
  clear_mods();
};

void ntz_home_tap_dance(tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
    SEND_STRING("~/");
  }
  else
  {
    SEND_STRING("cd ~/");
  }
}

void ntz_cd_up_tap_dance(tap_dance_state_t *state, void *user_data)
{
  if (state->count > 1)
  {
      SEND_STRING("../");
  }
  else
  {
    SEND_STRING("cd ../");
  }
}

void ntz_arrow_tap_dance(tap_dance_state_t *state, void *user_data)
{
  switch (state->count)
  {
  case 2:
    SEND_STRING("->");
    break;

  case 3:
  case 4:
  case 5:
    SEND_STRING("<=>");
    break;

  case 1:
  default:
    SEND_STRING("=>");
    break;
  }
}


void ntz_php_tags_tap_dance(tap_dance_state_t *state, void *user_data)
{
  switch (state->count)
  {
  case 2:
    SEND_STRING("<?php");
    break;

  case 3:
  case 4:
  case 5:
    SEND_STRING("?>");
    break;

  case 1:
  default:
    SEND_STRING("<?=");
    break;
  }
}

tap_dance_action_t tap_dance_actions[] = {
    [NTZ_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ntz_home_tap_dance, NULL),
    [NTZ_CD_UP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ntz_cd_up_tap_dance, NULL),
    [NTZ_ARROWS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ntz_arrow_tap_dance, NULL),
    [NTZ_PHP_TAGS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ntz_php_tags_tap_dance, NULL),
};
