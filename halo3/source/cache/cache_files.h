#ifndef __CACHE_FILES_H__
#define __CACHE_FILES_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

/* ---------- definitions */

struct s_cache_file_header;

/* ---------- prototypes */

// cache files windows

extern void cache_files_initialize(void);
extern void cache_files_dispose(void);
extern bool cache_file_open(char const* scenario_name, s_cache_file_header* header);
extern void cache_file_close(void);

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __CACHE_FILES_H__
