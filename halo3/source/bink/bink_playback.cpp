/* ---------- headers */

#include "bink/bink_playback.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(bink_playback_active);

// hooks

/* ---------- public code */

bool bink_playback_active(void)
{
    return REX_PPC_INVOKE(bink_playback_active);
}

/* ---------- private code */
