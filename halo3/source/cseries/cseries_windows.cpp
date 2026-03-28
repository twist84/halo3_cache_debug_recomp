/* ---------- headers */

#include "cseries/cseries_windows.h"

#include "main/main.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

//REX_PPC_EXTERN_IMPORT(GetTickCount);

// hooks

/* ---------- public code */

unsigned long system_milliseconds(void)
{
	return GetTickCount();
}

void system_exit(int code)
{
	main_halt_and_catch_fire();
}

/* ---------- private code */
