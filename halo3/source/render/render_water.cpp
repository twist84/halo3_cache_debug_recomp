/* ---------- headers */

#include "render/render_water.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

REX_DATA_REFERENCE_DECLARE(0x83E5C634, bool, render_water_wireframe_enabled);

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT_CLASS(c_water_renderer, render_shading);

// hooks

//REX_PPC_HOOK_CLASS(c_water_renderer, render_shading);

/* ---------- public code */

void c_water_renderer::render_shading(void)
{
	REX_PPC_INVOKE_CLASS(c_water_renderer, render_shading);
}

/* ---------- private code */
