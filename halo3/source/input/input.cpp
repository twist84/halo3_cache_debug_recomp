/* ---------- headers */

#include "input/input.h"

#include "input/controllers.h"
#include "input/input_constants.h"

#include <cassert>

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(input_any_controller_button_down);

// hooks

/* ---------- public code */

bool input_any_controller_button_down(e_gamepad_button button)
{
    return REX_PPC_INVOKE(input_any_controller_button_down, button);
}

/* ---------- private code */
