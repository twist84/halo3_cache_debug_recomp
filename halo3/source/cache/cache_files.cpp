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

REX_PPC_EXTERN_IMPORT(tag_files_open);
REX_PPC_EXTERN_IMPORT(tag_files_initialize_from_main);
REX_PPC_EXTERN_IMPORT(tag_files_close);

// hooks

/* ---------- public code */

void tag_files_open(void)
{
    REX_PPC_INVOKE(tag_files_open);
}

void tag_files_initialize_from_main(void)
{
    REX_PPC_INVOKE(tag_files_initialize_from_main);
}

void tag_files_close(void)
{
    REX_PPC_INVOKE(tag_files_close);
}

/* ---------- private code */
