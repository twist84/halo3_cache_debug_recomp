/* ---------- headers */

#include "cseries/async.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(async_initialize);
REX_PPC_EXTERN_IMPORT(async_usable);
REX_PPC_EXTERN_IMPORT(async_dispose);
REX_PPC_EXTERN_IMPORT(async_idle);

// hooks

/* ---------- public code */

void async_initialize(void)
{
    REX_PPC_INVOKE(async_initialize);
}

bool async_usable(void)
{
    return REX_PPC_INVOKE(async_usable);
}

void async_dispose(void)
{
    REX_PPC_INVOKE(async_dispose);
}

void async_idle(void)
{
    REX_PPC_INVOKE(async_idle);
}

/* ---------- private code */
