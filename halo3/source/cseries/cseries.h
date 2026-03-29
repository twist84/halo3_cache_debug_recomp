#ifndef __CSERIES_H__
#define __CSERIES_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

extern void cseries_initialize(void);
extern void cseries_dispose(void);

// debug memory

extern void debug_memory_manager_initialize(void);
extern void debug_memory_free_for_exit(void);
extern void system_debug_memory_internal(char const* place, char const* source_file, long source_line);

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __CSERIES_H__
