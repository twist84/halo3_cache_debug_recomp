/* ---------- headers */

#include "cseries/cseries.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(debug_memory_manager_initialize);
REX_PPC_EXTERN_IMPORT(debug_memory_free_for_exit);

// hooks

/* ---------- public code */

void debug_memory_manager_initialize(void)
{
    REX_PPC_INVOKE(debug_memory_manager_initialize);
}

void debug_memory_free_for_exit(void)
{
    REX_PPC_INVOKE(debug_memory_free_for_exit);
}

/* ---------- private code */
