/* ---------- headers */

#include "memory/thread_local_storage.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

DEFINE_REX_FUNC(get_thread_local_by_offset)
{
	REX_FUNC_PROLOGUE();

	uint32_t ea{};

	// lwz r11,0(r13)        ; r11 = TLS base pointer
	ctx.r11.u64 = REX_LOAD_U32(ctx.r13.u32 + 0);

	// lwzx r3,r11,r3        ; r3 = *(TLS + offset)
	ea = ctx.r11.u32 + ctx.r3.u32;
	ctx.r3.u64 = REX_LOAD_U32(ea);

	// blr
	return;
}

/* ---------- reverse engineering */
