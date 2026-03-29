/* ---------- headers */

#include "rasterizer/rasterizer.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT_CLASS(c_rasterizer, shell_initialize);
REX_PPC_EXTERN_IMPORT_CLASS(c_rasterizer, shell_dispose);
REX_PPC_EXTERN_IMPORT_CLASS(c_rasterizer, initialize_device);
REX_PPC_EXTERN_IMPORT_CLASS(c_rasterizer, release_device);

// hooks

/* ---------- public code */


void c_rasterizer::shell_initialize(bool use_desktop_window, bool null_device)
{
    REX_PPC_INVOKE_CLASS(c_rasterizer, shell_initialize, use_desktop_window, null_device);
}

void c_rasterizer::shell_dispose(void)
{
    REX_PPC_INVOKE_CLASS(c_rasterizer, shell_dispose);
}

bool c_rasterizer::initialize_device(bool use_desktop_window, bool null_device)
{
    REX_PPC_INVOKE_CLASS(c_rasterizer, initialize_device, use_desktop_window, null_device);
}

void c_rasterizer::release_device(void)
{
    REX_PPC_INVOKE_CLASS(c_rasterizer, release_device);
}

/* ---------- private code */
