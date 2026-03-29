#ifndef __PROFILER_H__
#define __PROFILER_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

enum e_profiler_pulse_types
{
    k_profiler_pulse_update_thread = 0,
    k_profiler_pulse_game_tick,
    k_profiler_pulse_render_thread,
    k_profiler_pulse_render_frame,

    k_total_profiler_pulse_types,
};

/* ---------- definitions */

/* ---------- prototypes */

extern void profiler_initialize_system(void);
extern void profiler_initialize(void);
extern void profiler_dispose(void);
extern void profiler_initialize_for_new_map(void);
extern void profiler_dispose_from_old_map(void);
extern void profiler_notify_pulse(e_profiler_pulse_types pulse_type);

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __PROFILER_H__
