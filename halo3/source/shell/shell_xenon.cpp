/* ---------- headers */

#include "shell/shell_xenon.h"

#include "cache/physical_memory_map.h"
#include "cseries/cseries_windows.h"
#include "main/main.h"
#include "shell/shell.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

int main(int argc, const char** argv, const char** envp);

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(shell_platform_initialize);
REX_PPC_EXTERN_IMPORT(utility_drive_initialize);
REX_PPC_EXTERN_IMPORT(file_system_cache_initialize);

// hooks

REX_PPC_HOOK(main);

/* ---------- public code */

bool shell_platform_initialize(void)
{
    return REX_PPC_INVOKE(shell_platform_initialize);
}

void shell_platform_dispose(void)
{
}

void utility_drive_initialize(void)
{
    REX_PPC_INVOKE(utility_drive_initialize);
}

void kernel_initialize(void)
{
}

void file_system_cache_initialize(void)
{
    REX_PPC_INVOKE(file_system_cache_initialize);
}

int main(int argc, const char** argv, const char** envp)
{
    SYSTEM_DEBUG_MEMORY("initial call into main()");

    SYSTEM_DEBUG_MEMORY("before kernel_initialize()");
    kernel_initialize();

    SYSTEM_DEBUG_MEMORY("before ditching persistent buffer");

    SYSTEM_DEBUG_MEMORY("before physical_memory_allocate()");
    physical_memory_initialize();
    SYSTEM_DEBUG_MEMORY("after physical_memory_allocate()");

    file_system_cache_initialize();
    SYSTEM_DEBUG_MEMORY("after file_system_cache_initialize()");

    physical_memory_stage_push(_memory_stage_game_initialize);

    if (shell_initialize(false))
    {
        main_loop();
        shell_dispose();
    }

    physical_memory_stage_pop(_memory_stage_game_initialize);
    physical_memory_dispose();

    system_exit(0);
    return 0;
}

/* ---------- private code */
