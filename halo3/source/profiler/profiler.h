#ifndef __PROFILER_H__
#define __PROFILER_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

extern void profiler_initialize_system(void);
extern void profiler_initialize(void);
extern void profiler_dispose(void);
extern void profiler_initialize_for_new_map(void);
extern void profiler_dispose_from_old_map(void);

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __PROFILER_H__
