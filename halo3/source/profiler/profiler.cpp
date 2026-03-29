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
REX_PPC_EXTERN_IMPORT(profiler_notify_pulse);

// hooks

/* ---------- public code */

void profiler_initialize_system(void)
{
    //REX_PPC_INVOKE(profiler_initialize_system);
}

void profiler_initialize(void)
{
}

void profiler_dispose(void)
{
}

void profiler_initialize_for_new_map(void)
{
    REX_PPC_INVOKE(profiler_initialize_for_new_map);
}

void profiler_dispose_from_old_map(void)
{
    REX_PPC_INVOKE(profiler_dispose_from_old_map);
}

void profiler_notify_pulse(e_profiler_pulse_types pulse_type)
{
    REX_PPC_INVOKE(profiler_notify_pulse, pulse_type);
}

/* ---------- private code */

/* ---------- reverse engineering */
