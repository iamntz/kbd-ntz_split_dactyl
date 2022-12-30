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

#define MATRIX_ROWS 14
#define MATRIX_COLS 6

#undef SOFT_SERIAL_PIN
#define SOFT_SERIAL_PIN D2     // USART TX pin

#define USE_SERIAL

#define MASTER_RIGHT

#define DOUBLE_TAP_SHIFT_TURNS_ON_CAPS_WORD

#define TAPPING_TERM_PER_KEY // get_tapping_term

// #define PERMISSIVE_HOLD
#define PERMISSIVE_HOLD_PER_KEY // get_permissive_hold

// #define IGNORE_MOD_TAP_INTERRUPT 
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY // get_ignore_mod_tap_interrupt

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

#define AUTO_SHIFT_TIMEOUT 200
