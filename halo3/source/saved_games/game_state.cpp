/* ---------- headers */

#include "saved_games/game_state.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(game_state_shell_initialize);
REX_PPC_EXTERN_IMPORT(game_state_shell_dispose);

// hooks

/* ---------- public code */

void game_state_shell_initialize(void)
{
    REX_PPC_INVOKE(game_state_shell_initialize);
}

void game_state_shell_dispose(void)
{
    REX_PPC_INVOKE(game_state_shell_dispose);
}

/* ---------- private code */
