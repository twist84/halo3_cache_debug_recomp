/* ---------- headers */

#include "profiler/profiler_counters.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

struct s_profile_globals
{
    rex::be<long long> frequency; // 0x0
    bool calibrated; // 0x8
};
static_assert(sizeof(s_profile_globals) == 0x10);

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

REX_DATA_REFERENCE_DECLARE(0x84C648A8, s_profile_globals, profile_globals);

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(initialize_performance_counters);

// hooks

//REX_PPC_HOOK(initialize_performance_counters);

/* ---------- public code */

void initialize_performance_counters(void)
{
    REX_PPC_INVOKE(initialize_performance_counters);
}

/* ---------- private code */
