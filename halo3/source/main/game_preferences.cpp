/* ---------- headers */

#include "main/game_preferences.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

static bool global_preferences_available(void);
static void global_preferences_write(void);
static void global_preferences_create_default(void);
//static void global_preferences_make_safe(s_global_preferences* preferences);
static void global_preferences_init(void);

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(global_preferences_initialize);
REX_PPC_EXTERN_IMPORT(global_preferences_dispose);
REX_PPC_EXTERN_IMPORT(global_preferences_update);
REX_PPC_EXTERN_IMPORT(global_preferences_flush);
REX_PPC_EXTERN_IMPORT(global_preferences_clear);

// hooks

/* ---------- public code */

void global_preferences_initialize(void)
{
	REX_PPC_INVOKE(global_preferences_initialize);
}

void global_preferences_dispose(void)
{
	REX_PPC_INVOKE(global_preferences_dispose);
}

void global_preferences_update(void)
{
	REX_PPC_INVOKE(global_preferences_update);
}

void global_preferences_flush(void)
{
	REX_PPC_INVOKE(global_preferences_flush);
}

void global_preferences_clear(void)
{
	REX_PPC_INVOKE(global_preferences_clear);
}

/* ---------- private code */
