#ifndef __INPUT_H__
#define __INPUT_H__
#pragma once

/* ---------- headers */

#include "input/input_constants.h"
#include "math/integer_math.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

struct gamepad_state
{
    unsigned char analog_buttons[NUMBER_OF_GAMEPAD_ANALOG_BUTTONS]; // 0x0
    unsigned char analog_button_thresholds[NUMBER_OF_GAMEPAD_ANALOG_BUTTONS]; // 0x2
    unsigned char button_frames[NUMBER_OF_GAMEPAD_BUTTONS]; // 0x4
    unsigned short button_msec[NUMBER_OF_GAMEPAD_BUTTONS]; // 0x14
    point2d sticks[NUMBER_OF_GAMEPAD_STICKS]; // 0x34
};
static_assert(sizeof(gamepad_state) == 0x3C);

struct gamepad_state_be
{
    unsigned char analog_buttons[NUMBER_OF_GAMEPAD_ANALOG_BUTTONS]; // 0x0
    unsigned char analog_button_thresholds[NUMBER_OF_GAMEPAD_ANALOG_BUTTONS]; // 0x2
    unsigned char button_frames[NUMBER_OF_GAMEPAD_BUTTONS]; // 0x4
    rex::be<unsigned short> button_msec[NUMBER_OF_GAMEPAD_BUTTONS]; // 0x14
    point2d_be sticks[NUMBER_OF_GAMEPAD_STICKS]; // 0x34
};
static_assert(sizeof(gamepad_state_be) == 0x3C);

/* ---------- prototypes */

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __INPUT_H__
