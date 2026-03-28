/* ---------- headers */

#define __STATIC_ARRAYS_TEMPLATES__

#include "cseries/cseries_macros.h"
#include "cache/physical_memory_map.h"
#include "memory/static_array.h"

#include "rex_macros.h"

#include <cassert>

/* ---------- constants */

constexpr unsigned long k_physical_memory_page_mask = MASK(16);

/* ---------- definitions */

struct s_physical_memory_stage
{
	rex::be<unsigned long> low_address; // 0x0
	rex::be<unsigned long> high_address; // 0x4
	rex::guest_addr_t next_available_zero_allocation; // 0x8 // char*
	rex::be<unsigned long> allocation_count; // 0xC
	rex::be<unsigned long> fixed_address_allocation_count; // 0xC
};
static_assert(sizeof(s_physical_memory_stage) == 0x14);

struct s_physical_memory_journal_entry
{
	memory_stage stage; // 0x0
	c_static_string<64> name; // 0x4
	rex::be<unsigned long> size; // 0x44
	rex::be<unsigned long> flags; // 0x48
	rex::guest_addr_t file; // 0x4C // char const*
	rex::be<unsigned long> line; // 0x50
	rex::guest_addr_t address; // 0x54 // void*
};
static_assert(sizeof(s_physical_memory_journal_entry) == 0x58);

struct s_physical_memory_globals
{
	rex::guest_addr_t resize_region_listener; // 0x0 // c_physical_memory_contiguous_region_listener*
	rex::be<memory_stage> current_stage; // 0x4
	rex::be<unsigned long> minimum_address; // 0x8
	rex::be<unsigned long> maximum_address; // 0xC
	rex::guest_addr_t no_mans_land; // 0x10 // char*
	c_static_array<s_physical_memory_stage, k_memory_stage_count> memory_stages; // 0x14
	char __dataA0[0x1C]; // 0xA0 // $TODO figure this out
	c_static_array<s_physical_memory_journal_entry, 64> journal_entries; // 0xBC
};
static_assert(sizeof(s_physical_memory_globals) == 0x16BC);

/* ---------- prototypes */

/* ---------- globals */

REX_DATA_REFERENCE_DECLARE(0x846AE5F0, s_physical_memory_globals, physical_memory_globals);

/* ---------- private variables */

/* ---------- ppc */

// exports

REX_PPC_EXTERN_IMPORT(physical_memory_initialize);
REX_PPC_EXTERN_IMPORT(physical_memory_dispose);
REX_PPC_EXTERN_IMPORT(physical_memory_stage_push);
REX_PPC_EXTERN_IMPORT(physical_memory_stage_pop);
REX_PPC_EXTERN_IMPORT(_physical_memory_malloc);
REX_PPC_EXTERN_IMPORT(physical_memory_free);

// hooks

/* ---------- public code */

void physical_memory_initialize(void)
{
	REX_PPC_INVOKE(physical_memory_initialize);
}

void physical_memory_dispose(void)
{
	REX_PPC_INVOKE(physical_memory_dispose);
}

void physical_memory_stage_push(memory_stage stage)
{
	REX_PPC_INVOKE(physical_memory_stage_push, stage);
}

void physical_memory_stage_pop(memory_stage stage)
{
	REX_PPC_INVOKE(physical_memory_stage_pop, stage);
}

unsigned long _physical_memory_malloc(memory_stage stage, char const* name, unsigned long size, unsigned long flags, char const* file, long line) // void*
{
	return REX_PPC_INVOKE(_physical_memory_malloc, stage, name, size, flags, file, line);
}

void physical_memory_free(unsigned long base_address) // void*
{
	REX_PPC_INVOKE(physical_memory_free, base_address);
}

/* ---------- private code */
