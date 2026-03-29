/* ---------- headers */

#include "cache/cache_files.h"

#include "tag_files/tag_files.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

// hooks

REX_PPC_HOOK(tag_files_open);
REX_PPC_HOOK(tag_files_initialize_from_main);
REX_PPC_HOOK(tag_files_close);

/* ---------- public code */

void tag_files_open(void)
{
    cache_files_initialize();
}

void tag_files_initialize_from_main(void)
{
}

void tag_files_close(void)
{
    cache_files_dispose();
}

/* ---------- private code */
