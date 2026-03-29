/* ---------- headers */

#include "networking/network_utilities.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(network_remote_reporting_initialize);
REX_PPC_EXTERN_IMPORT(network_remote_reporting_dispose);

// hooks

/* ---------- public code */

void network_remote_reporting_initialize(void)
{
    REX_PPC_INVOKE(network_remote_reporting_initialize);
}

void network_remote_reporting_dispose(void)
{
    REX_PPC_INVOKE(network_remote_reporting_dispose);
}

/* ---------- private code */
