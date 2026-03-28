/* ---------- headers */

#include "multithreading/synchronization.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(initialize_synchronization_objects);
REX_PPC_EXTERN_IMPORT(synchronization_objects_initialized);
REX_PPC_EXTERN_IMPORT(destroy_synchronization_objects);

REX_PPC_EXTERN_IMPORT(internal_critical_section_enter);
REX_PPC_EXTERN_IMPORT(internal_critical_section_try_and_enter);
REX_PPC_EXTERN_IMPORT(internal_critical_section_leave);
REX_PPC_EXTERN_IMPORT(internal_mutex_take);
REX_PPC_EXTERN_IMPORT(internal_mutex_take_timeout);
REX_PPC_EXTERN_IMPORT(internal_mutex_release);
REX_PPC_EXTERN_IMPORT(internal_event_wait);
REX_PPC_EXTERN_IMPORT(internal_event_wait_timeout);
REX_PPC_EXTERN_IMPORT(internal_event_set);
REX_PPC_EXTERN_IMPORT(internal_event_reset);
REX_PPC_EXTERN_IMPORT(event_has_automatic_reset);

// hooks

/* ---------- public code */

void initialize_synchronization_objects(void)
{
    REX_PPC_INVOKE(initialize_synchronization_objects);
}
bool synchronization_objects_initialized(void)
{
    return REX_PPC_INVOKE(synchronization_objects_initialized);
}
void destroy_synchronization_objects(void)
{
    REX_PPC_INVOKE(destroy_synchronization_objects);
}

void internal_critical_section_enter(long critical_section_id)
{
    REX_PPC_INVOKE(internal_critical_section_enter, critical_section_id);
}
bool internal_critical_section_try_and_enter(long critical_section_id)
{
    return REX_PPC_INVOKE(internal_critical_section_try_and_enter, critical_section_id);
}
void internal_critical_section_leave(long critical_section_id)
{
    REX_PPC_INVOKE(internal_critical_section_leave, critical_section_id);
}
void internal_mutex_take(long mutex_id)
{
    REX_PPC_INVOKE(internal_mutex_take, mutex_id);
}
bool internal_mutex_take_timeout(long mutex_id, unsigned long timeout_in_milliseconds)
{
    return REX_PPC_INVOKE(internal_mutex_take_timeout, mutex_id, timeout_in_milliseconds);
}
void internal_mutex_release(long mutex_id)
{
    REX_PPC_INVOKE(internal_mutex_release, mutex_id);
}
void internal_event_wait(long event_id)
{
    REX_PPC_INVOKE(internal_event_wait, event_id);
}
bool internal_event_wait_timeout(long event_id, unsigned long timeout_in_milliseconds)
{
    return REX_PPC_INVOKE(internal_event_wait_timeout, event_id, timeout_in_milliseconds);
}
void internal_event_set(long event_id)
{
    REX_PPC_INVOKE(internal_event_set, event_id);
}
void internal_event_reset(long event_id)
{
    REX_PPC_INVOKE(internal_event_reset, event_id);
}
bool event_has_automatic_reset(long event_id)
{
    return REX_PPC_INVOKE(event_has_automatic_reset, event_id);
}

/* ---------- private code */
