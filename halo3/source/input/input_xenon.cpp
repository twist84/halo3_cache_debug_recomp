/* ---------- headers */

#include "input/input_xenon.h"

#include "input/input.h"
#include "input/input_constants.h"
#include "input/input_xinput.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

struct key_stroke
{
	unsigned char modifier_flags; // 0x0
	char ascii_code; // 0x1
	rex::be<short> key_code; // 0x2
	bool repeating; // 0x4
};
static_assert(sizeof(key_stroke) == 0x6);

struct input_globals_xenon
{
	bool initialized; // 0x0
	bool suppressed_flag; // 0x1
	bool rumble_suppressed_flag; // 0x2
	rex::be<unsigned long> last_milliseconds; // 0x4

	rex::be<unsigned short> __flags; // 0x8

	char __dataA[8]; // 0xA

	bool valid_gamepads[4]; // 0x12
	gamepad_state_be gamepad_states[4]; // 0x16

	char __data106[0x12]; // 106

	gamepad_state_be gamepad_suppressed; // 0x118
	rumble_state_be rumble_states[4]; // 0x154
	rex::be<long> memory_units_last_change_time; // 0x164

	char __data168[6]; // 0x168

	unsigned char keys_frames[NUMBER_OF_KEYS]; // 0x16E
	rex::be<unsigned short> keys_msec[NUMBER_OF_KEYS]; // 0x1D6
	bool keys_latched[NUMBER_OF_KEYS]; // 0x2A6
	rex::be<short> buffered_key_read_index; // 0x30E
	rex::be<short> buffered_key_write_index; // 0x310
	key_stroke buffered_keys[64]; // 0x312
	char __data492[2]; // 0x492
};
static_assert(sizeof(input_globals_xenon) == 0x494);

/* ---------- prototypes */

/* ---------- globals */

static REX_DATA_REFERENCE_DECLARE_ARRAY(0x841E0460, debug_gamepad_data_be, input_debug_gamepads, 4);
static REX_DATA_REFERENCE_DECLARE(0x841E0480, input_globals_xenon, input_globals);

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(input_initialize);
REX_PPC_EXTERN_IMPORT(input_dispose);

// hooks

/* ---------- public code */

bool input_initialize(void)
{
	return REX_PPC_INVOKE(input_initialize);
}

void input_dispose(void)
{
	REX_PPC_INVOKE(input_dispose);
}

/* ---------- private code */
