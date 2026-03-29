/* ---------- headers */

#include "cseries/cseries.h"

#include "multithreading/synchronization.h"
#include "multithreading/threads.h"
#include "profiler/profiler.h"
#include "profiler/profiler_counters.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

//REX_PPC_EXTERN_IMPORT(cseries_initialize);
//REX_PPC_EXTERN_IMPORT(cseries_dispose);

// hooks

//REX_PPC_HOOK(cseries_initialize);
//REX_PPC_HOOK(cseries_dispose);

/* ---------- public code */

void cseries_initialize(void)
{
	initialize_performance_counters();
	initialize_thread_management();
	initialize_synchronization_objects();
	debug_memory_manager_initialize();
	profiler_initialize_system();
}

void cseries_dispose(void)
{
	debug_memory_free_for_exit();
	destroy_thread_management();
	destroy_synchronization_objects();
}

/* ---------- private code */
