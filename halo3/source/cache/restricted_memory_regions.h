#ifndef __RESTRICTED_MEMORY_REGIONS_H__
#define __RESTRICTED_MEMORY_REGIONS_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

enum e_restricted_memory_region
{
	k_game_state_header_region = 0,
	k_game_state_update_region,
	k_game_state_render_region,
	k_game_state_shared_region,
	k_global_render_data_region,

	k_total_restricted_memory_regions,
};

/* ---------- definitions */

class c_restricted_section;
class c_restricted_memory_callbacks;

/* ---------- prototypes */

extern char const* restricted_region_get_name(long index);
extern void restricted_memory_set_base_address(long index, void* address);
extern void* restricted_memory_get_address(long index, unsigned long offset);
extern bool restricted_region_valid(long index);
extern bool restricted_region_locked_for_current_thread(long index);
extern bool restricted_region_mirror_locked_for_current_thread(long index);
extern bool restricted_region_aliased_for_current_thread(long index);
extern void restricted_region_create(long index, c_restricted_section* primary_section, long critical_section_index, c_restricted_memory_callbacks* callbacks);
extern void restricted_region_add_mirror(long index, c_restricted_section* mirror_section);
extern void restricted_region_destroy(long index);
extern unsigned int restricted_region_get_total_size(long index);
extern unsigned int restricted_region_get_sector_size(long index);
extern long restricted_region_get_mirror_count(long index);
extern bool restricted_region_publish_to_mirror(long index);
extern void restricted_region_reset_mirrors(long index);
extern long restricted_region_add_member(long index, char const* name, char const* type_name, unsigned int allocation, long alignment_bits, void (*tls_update_callback)(void*), void (*pre_copy_fixup_callback)(void*), void (*post_copy_fixup_callback)(void*));
extern void restricted_region_free_member(long index, long member_index);
extern unsigned long restricted_region_get_member_offset(long index, long member_index);
extern void* restricted_region_get_member_address(long index, long member_index);
extern void restricted_region_clear_membership(long index);
extern void restricted_region_lock_primary(long index);
extern bool restricted_region_try_and_lock_primary(long index);
extern bool restricted_region_lock_mirror(long index);
extern bool restricted_region_try_and_lock_mirror(long index);
extern void restricted_region_unlock_primary(long index);
extern void restricted_region_unlock_mirror(long index);
extern bool restricted_region_validate_address(long index, void const* address);
extern long restricted_region_find_address(void const* address);
extern void restricted_region_handle_crash_of_current_thread(void);
extern bool restricted_region_wait_for_available_mirror(long index, unsigned long timeout);
extern bool restricted_region_wait_for_new_write_mirror(long index, unsigned long timeout);
extern void restricted_region_begin_aliasing(long index);
extern void restricted_region_end_aliasing(long index);
extern void restricted_region_add_alias(long index);
extern void restricted_region_remove_alias(long index);

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __RESTRICTED_MEMORY_REGIONS_H__
