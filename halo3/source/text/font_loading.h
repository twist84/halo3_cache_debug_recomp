#ifndef __FONT_LOADING_H__
#define __FONT_LOADING_H__
#pragma once

/* ---------- headers */

/* ---------- constants */

enum e_font_index
{
	_font_index_none = -1,
	_font_index_fallback = -2,
	k_maximum_font_index_count = 10,
};

/* ---------- definitions */

/* ---------- prototypes */

extern void font_initialize_emergency(void);
extern void font_initialize(void);
extern void font_dispose(void);
extern void font_idle(void);

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __FONT_LOADING_H__
