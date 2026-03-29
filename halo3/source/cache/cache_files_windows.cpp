/* ---------- headers */

#include "cache/cache_files.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(cache_files_initialize);
REX_PPC_EXTERN_IMPORT(cache_files_dispose);
REX_PPC_EXTERN_IMPORT(cache_file_open);
REX_PPC_EXTERN_IMPORT(cache_file_close);

// hooks

/* ---------- public code */

void cache_files_initialize(void)
{
    REX_PPC_INVOKE(cache_files_initialize);
}

void cache_files_dispose(void)
{
    REX_PPC_INVOKE(cache_files_dispose);
}

bool cache_file_open(char const *scenario_name, s_cache_file_header *header)
{
    return REX_PPC_INVOKE(cache_file_open, scenario_name, header);
}

void cache_file_close(void)
{
    REX_PPC_INVOKE(cache_file_close);
}

/* ---------- private code */
