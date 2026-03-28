/* ---------- headers */

#include "profiler/profiler.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(profiler_initialize_system);
REX_PPC_EXTERN_IMPORT(profiler_initialize);
REX_PPC_EXTERN_IMPORT(profiler_dispose);
REX_PPC_EXTERN_IMPORT(profiler_initialize_for_new_map);
REX_PPC_EXTERN_IMPORT(profiler_dispose_from_old_map);

// hooks

/* ---------- public code */

void profiler_initialize_system(void)
{
    REX_PPC_INVOKE(profiler_initialize_system);
}

void profiler_initialize(void)
{
    REX_PPC_INVOKE(profiler_initialize);
}

void profiler_dispose(void)
{
    REX_PPC_INVOKE(profiler_dispose);
}

void profiler_initialize_for_new_map(void)
{
    REX_PPC_INVOKE(profiler_initialize_for_new_map);
}

void profiler_dispose_from_old_map(void)
{
    REX_PPC_INVOKE(profiler_dispose_from_old_map);
}

/* ---------- private code */

/* ---------- reverse engineering */
