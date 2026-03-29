/* ---------- headers */

#include "cache/restricted_memory_regions.h"

#include "rex_macros.h"

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(restricted_region_get_name);
REX_PPC_EXTERN_IMPORT(restricted_memory_set_base_address);
REX_PPC_EXTERN_IMPORT(restricted_memory_get_address);
REX_PPC_EXTERN_IMPORT(restricted_region_valid);
REX_PPC_EXTERN_IMPORT(restricted_region_locked_for_current_thread);
REX_PPC_EXTERN_IMPORT(restricted_region_mirror_locked_for_current_thread);
REX_PPC_EXTERN_IMPORT(restricted_region_aliased_for_current_thread);
REX_PPC_EXTERN_IMPORT(restricted_region_create);
REX_PPC_EXTERN_IMPORT(restricted_region_add_mirror);
REX_PPC_EXTERN_IMPORT(restricted_region_destroy);
REX_PPC_EXTERN_IMPORT(restricted_region_get_total_size);
REX_PPC_EXTERN_IMPORT(restricted_region_get_sector_size);
REX_PPC_EXTERN_IMPORT(restricted_region_get_mirror_count);
REX_PPC_EXTERN_IMPORT(restricted_region_publish_to_mirror);
REX_PPC_EXTERN_IMPORT(restricted_region_reset_mirrors);
REX_PPC_EXTERN_IMPORT(restricted_region_add_member);
REX_PPC_EXTERN_IMPORT(restricted_region_free_member);
REX_PPC_EXTERN_IMPORT(restricted_region_get_member_offset);
REX_PPC_EXTERN_IMPORT(restricted_region_get_member_address);
REX_PPC_EXTERN_IMPORT(restricted_region_clear_membership);
REX_PPC_EXTERN_IMPORT(restricted_region_lock_primary);
REX_PPC_EXTERN_IMPORT(restricted_region_try_and_lock_primary);
REX_PPC_EXTERN_IMPORT(restricted_region_lock_mirror);
REX_PPC_EXTERN_IMPORT(restricted_region_try_and_lock_mirror);
REX_PPC_EXTERN_IMPORT(restricted_region_unlock_primary);
REX_PPC_EXTERN_IMPORT(restricted_region_unlock_mirror);
REX_PPC_EXTERN_IMPORT(restricted_region_validate_address);
REX_PPC_EXTERN_IMPORT(restricted_region_find_address);
REX_PPC_EXTERN_IMPORT(restricted_region_handle_crash_of_current_thread);
REX_PPC_EXTERN_IMPORT(restricted_region_wait_for_available_mirror);
REX_PPC_EXTERN_IMPORT(restricted_region_wait_for_new_write_mirror);
REX_PPC_EXTERN_IMPORT(restricted_region_begin_aliasing);
REX_PPC_EXTERN_IMPORT(restricted_region_end_aliasing);
REX_PPC_EXTERN_IMPORT(restricted_region_add_alias);
REX_PPC_EXTERN_IMPORT(restricted_region_remove_alias);

// hooks

/* ---------- public code */

char const* restricted_region_get_name(long index)
{
    return REX_PPC_INVOKE(restricted_region_get_name, index);
}

void restricted_memory_set_base_address(long index, void* address)
{
    REX_PPC_INVOKE(restricted_memory_set_base_address, index, address);
}

void* restricted_memory_get_address(long index, unsigned long offset)
{
    return REX_PPC_INVOKE(restricted_memory_get_address, index, offset);
}

bool restricted_region_valid(long index)
{
    return REX_PPC_INVOKE(restricted_region_valid, index);
}

bool restricted_region_locked_for_current_thread(long index)
{
    return REX_PPC_INVOKE(restricted_region_locked_for_current_thread, index);
}

bool restricted_region_mirror_locked_for_current_thread(long index)
{
    return REX_PPC_INVOKE(restricted_region_mirror_locked_for_current_thread, index);
}

bool restricted_region_aliased_for_current_thread(long index)
{
    return REX_PPC_INVOKE(restricted_region_aliased_for_current_thread, index);
}

void restricted_region_create(long index, c_restricted_section* primary_section, long critical_section_index, c_restricted_memory_callbacks* callbacks)
{
    REX_PPC_INVOKE(restricted_region_create, primary_section, index, critical_section_index, callbacks);
}

void restricted_region_add_mirror(long index, c_restricted_section* mirror_section)
{
    REX_PPC_INVOKE(restricted_region_add_mirror, index, mirror_section);
}

void restricted_region_destroy(long index)
{
    REX_PPC_INVOKE(restricted_region_destroy, index);
}

unsigned int restricted_region_get_total_size(long index)
{
    return REX_PPC_INVOKE(restricted_region_get_total_size, index);
}

unsigned int restricted_region_get_sector_size(long index)
{
    return REX_PPC_INVOKE(restricted_region_get_sector_size, index);
}

long restricted_region_get_mirror_count(long index)
{
    return REX_PPC_INVOKE(restricted_region_get_mirror_count, index);
}

bool restricted_region_publish_to_mirror(long index)
{
    return REX_PPC_INVOKE(restricted_region_publish_to_mirror, index);
}

void restricted_region_reset_mirrors(long index)
{
    REX_PPC_INVOKE(restricted_region_reset_mirrors, index);
}

long restricted_region_add_member(long index, char const* name, char const* type_name, unsigned int allocation, long alignment_bits, void (*tls_update_callback)(void*), void (*pre_copy_fixup_callback)(void*), void (*post_copy_fixup_callback)(void*))
{
    return REX_PPC_INVOKE(restricted_region_add_member, index, name, type_name, allocation, alignment_bits, tls_update_callback, pre_copy_fixup_callback, post_copy_fixup_callback);
}

void restricted_region_free_member(long index, long member_index)
{
    REX_PPC_INVOKE(restricted_region_free_member, index, member_index);
}

unsigned long restricted_region_get_member_offset(long index, long member_index)
{
    return REX_PPC_INVOKE(restricted_region_get_member_offset, index, member_index);
}

void* restricted_region_get_member_address(long index, long member_index)
{
    return REX_PPC_INVOKE(restricted_region_get_member_address, index, member_index);
}

void restricted_region_clear_membership(long index)
{
    REX_PPC_INVOKE(restricted_region_clear_membership, index);
}

void restricted_region_lock_primary(long index)
{
    REX_PPC_INVOKE(restricted_region_lock_primary, index);
}

bool restricted_region_try_and_lock_primary(long index)
{
    return REX_PPC_INVOKE(restricted_region_try_and_lock_primary, index);
}

bool restricted_region_lock_mirror(long index)
{
    return REX_PPC_INVOKE(restricted_region_lock_mirror, index);
}

bool restricted_region_try_and_lock_mirror(long index)
{
    return REX_PPC_INVOKE(restricted_region_try_and_lock_mirror, index);
}

void restricted_region_unlock_primary(long index)
{
    REX_PPC_INVOKE(restricted_region_unlock_primary, index);
}

void restricted_region_unlock_mirror(long index)
{
    REX_PPC_INVOKE(restricted_region_unlock_mirror, index);
}

bool restricted_region_validate_address(long index, void const* address)
{
    return REX_PPC_INVOKE(restricted_region_validate_address, index, address);
}

long restricted_region_find_address(void const* address)
{
    return REX_PPC_INVOKE(restricted_region_find_address, address);
}

void restricted_region_handle_crash_of_current_thread(void)
{
    REX_PPC_INVOKE(restricted_region_handle_crash_of_current_thread);
}

bool restricted_region_wait_for_available_mirror(long index, unsigned long timeout)
{
    return REX_PPC_INVOKE(restricted_region_wait_for_available_mirror, index, timeout);
}

bool restricted_region_wait_for_new_write_mirror(long index, unsigned long timeout)
{
    return REX_PPC_INVOKE(restricted_region_wait_for_new_write_mirror, index, timeout);
}

void restricted_region_begin_aliasing(long index)
{
    REX_PPC_INVOKE(restricted_region_begin_aliasing, index);
}

void restricted_region_end_aliasing(long index)
{
    REX_PPC_INVOKE(restricted_region_end_aliasing, index);
}

void restricted_region_add_alias(long index)
{
    REX_PPC_INVOKE(restricted_region_add_alias, index);
}

void restricted_region_remove_alias(long index)
{
    REX_PPC_INVOKE(restricted_region_remove_alias, index);
}

/* ---------- private code */
