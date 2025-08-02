#include "utils/send_string_with_mod.c"

void ntz_home_tap_dance(tap_dance_state_t *state, void *user_data)
{
  switch (state->count)
  {
    case 1:
      SEND_STRING("cd ~/");
      break;

    default:
      SEND_STRING("~/");
      break;
  }
}

void ntz_cd_up_tap_dance(tap_dance_state_t *state, void *user_data)
{
  switch (state->count)
  {
    case 1:
      SEND_STRING("cd ../");
      break;

    case 2:
      SEND_STRING("../");
      break;

    case 3:
      SEND_STRING("../../");
      break;

    case 4:
      SEND_STRING("../../../");
      break;

    default:
      SEND_STRING("../../../../");
      break;
  }
}

void ntz_arrow_tap_dance(tap_dance_state_t *state, void *user_data)
{
  switch (state->count)
  {
    case 1:
      SEND_STRING("=>");
      break;

    case 2:
      SEND_STRING("->");
      break;

    default:
      SEND_STRING("<=>");
      break;
  }
}


void ntz_php_tags_tap_dance(tap_dance_state_t *state, void *user_data)
{
  switch (state->count)
  {
    case 1:
      SEND_STRING("<?=");
      break;

    case 2:
      SEND_STRING("<?php");
      break;

    default:
      SEND_STRING("?>");
      break;
  }
}

tap_dance_action_t tap_dance_actions[] = {
    [NTZ_HOME] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ntz_home_tap_dance, NULL),
    [NTZ_CD_UP] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ntz_cd_up_tap_dance, NULL),
    [NTZ_ARROWS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ntz_arrow_tap_dance, NULL),
    [NTZ_PHP_TAGS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, ntz_php_tags_tap_dance, NULL),
};
