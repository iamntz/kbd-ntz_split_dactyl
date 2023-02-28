#include "quantum.h"

const key_override_t ntz_override_1 = ko_make_basic(MOD_BIT(KC_RALT), KC_Z, RALT(KC_5));    // Press alt gr + z for ° (alt gr + 5)
const key_override_t ntz_override_3 = ko_make_basic(MOD_BIT(KC_RALT), KC_B, RALT(KC_DOT));  // Press alt gr + B for »
const key_override_t ntz_override_4 = ko_make_basic(MOD_BIT(KC_RALT), KC_V, RALT(KC_COMM)); // Press alt gr + V for «

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &ntz_override_1,
    &ntz_override_3,
    &ntz_override_4,
    NULL // Null terminate the array of overrides!
};