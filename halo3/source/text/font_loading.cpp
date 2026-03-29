/* ---------- headers */

#include "text/font_loading.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(font_initialize_emergency);
REX_PPC_EXTERN_IMPORT(font_initialize);
REX_PPC_EXTERN_IMPORT(font_dispose);
REX_PPC_EXTERN_IMPORT(font_idle);

// hooks

/* ---------- public code */

void font_initialize_emergency(void)
{
    REX_PPC_INVOKE(font_initialize_emergency);
}

void font_initialize(void)
{
    REX_PPC_INVOKE(font_initialize);
}

void font_dispose(void)
{
    REX_PPC_INVOKE(font_dispose);
}

void font_idle(void)
{
    REX_PPC_INVOKE(font_idle);
}

/* ---------- private code */
