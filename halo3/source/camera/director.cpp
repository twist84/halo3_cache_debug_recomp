/* ---------- headers */

#include "camera/director.h"

#include "cseries/constants.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

static e_director_mode choose_appropriate_director(long user_index);
static void change_debug_director_if_necessary(long user_index);

/* ---------- globals */

// $TODO factor this out into a something more generic,
//       since this is a debug build we don't need to do it like this
REXCVAR_DEFINE_INT32(director_mode_override, NONE, "Blam/Camera", "")
	.range(NONE, _director_mode_editor);

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(director_update);
REX_PPC_EXTERN_IMPORT(director_set_mode);

REX_PPC_EXTERN_IMPORT(choose_appropriate_director);
REX_PPC_EXTERN_IMPORT(change_debug_director_if_necessary);

// hooks

//REX_PPC_HOOK(director_update);

/* ---------- public code */

void director_update(float dt)
{
	REX_PPC_INVOKE(director_update, dt);
}

void director_set_mode(long user_index, e_director_mode director_mode)
{
	REX_PPC_INVOKE(director_set_mode, user_index, director_mode);
}

/* ---------- private code */

static e_director_mode choose_appropriate_director(long user_index)
{
	return REX_PPC_INVOKE(choose_appropriate_director, user_index);
}

static void change_debug_director_if_necessary(long user_index)
{
	REX_PPC_INVOKE(change_debug_director_if_necessary, user_index);
}
