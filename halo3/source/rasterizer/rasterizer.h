#ifndef __RASTERIZER_H__
#define __RASTERIZER_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

/* ---------- definitions */

class c_rasterizer
{
public:
    static void shell_initialize(bool use_desktop_window, bool null_device);
    static void shell_dispose(void);

private:
    static bool initialize_device(bool use_desktop_window, bool null_device);
    static void release_device(void);
};
static_assert(sizeof(c_rasterizer) == 1);

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __RASTERIZER_H__
