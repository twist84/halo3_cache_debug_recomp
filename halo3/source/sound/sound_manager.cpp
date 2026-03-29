/* ---------- headers */

#include "sound/sound_manager.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(sound_initialize);
REX_PPC_EXTERN_IMPORT(sound_dispose);

// hooks

REX_PPC_HOOK(sound_initialize);
REX_PPC_HOOK(sound_dispose);

/* ---------- public code */

void sound_initialize(void)
{
    REX_PPC_INVOKE(sound_initialize);
}

void sound_dispose(void)
{
    REX_PPC_INVOKE(sound_dispose);
}

/* ---------- private code */
