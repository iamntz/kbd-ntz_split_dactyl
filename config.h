/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

#define MASTER_RIGHT

//===================================================================================================//
// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#tapping-term
// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#permissive-hold
// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#ignore-mod-tap-interrupt
// https://github.com/qmk/qmk_firmware/blob/master/docs/tap_hold.md#hold-on-other-key-press
// https://docs.qmk.fm/#/feature_leader_key

// enabling this globally will make quick tap of shift + semicolon(layer) + letters will trigger the layer instead
// #define HOLD_ON_OTHER_KEY_PRESS
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY // get_hold_on_other_key_press
//===================================================================================================//
