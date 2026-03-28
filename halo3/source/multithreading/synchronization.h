#ifndef __SYNCHRONIZATION_H__
#define __SYNCHRONIZATION_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

extern void initialize_synchronization_objects(void);
extern bool synchronization_objects_initialized(void);
extern void destroy_synchronization_objects(void);

extern void internal_critical_section_enter(long critical_section_id);
extern bool internal_critical_section_try_and_enter(long critical_section_id);
extern void internal_critical_section_leave(long critical_section_id);
extern void internal_mutex_take(long mutex_id);
extern bool internal_mutex_take_timeout(long mutex_id, unsigned long timeout_in_milliseconds);
extern void internal_mutex_release(long mutex_id);
extern void internal_event_wait(long event_id);
extern bool internal_event_wait_timeout(long event_id, unsigned long timeout_in_milliseconds);
extern void internal_event_set(long event_id);
extern void internal_event_reset(long event_id);
extern bool event_has_automatic_reset(long event_id);

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __SYNCHRONIZATION_H__
