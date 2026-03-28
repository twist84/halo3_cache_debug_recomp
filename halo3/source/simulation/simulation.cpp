/* ---------- headers */

#include "simulation/simulation.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(simulation_stop);

// hooks

/* ---------- public code */

void simulation_stop()
{
	REX_PPC_INVOKE(simulation_stop);
}

/* ---------- private code */
