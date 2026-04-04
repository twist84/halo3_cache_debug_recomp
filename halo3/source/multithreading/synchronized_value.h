#ifndef __SYNCHRONIZED_VALUE_H__
#define __SYNCHRONIZED_VALUE_H__
#pragma once

/* ---------- headers */

#include "cseries/cseries_macros.h"

/* ---------- constants */

/* ---------- definitions */

class c_interlocked_long
{
private:
	long volatile m_value; // 0x0
public:
	c_interlocked_long(long starting_value);
	c_interlocked_long();
	~c_interlocked_long();
	operator long() const;
	long set(long value);
	long set_if_equal(long value, long comperand);
	long peek() const;
	long add(long value);
	long increment() volatile;
	long decrement() volatile;
	long and_(long value);
	long or_(long value);
	long xor_(long value);
	long set_bit(long index, bool setting);
	bool test_bit(long index) const;
	c_interlocked_long& operator+=(long value);
	c_interlocked_long& operator-=(long value);
	c_interlocked_long& operator&=(long value);
	c_interlocked_long& operator|=(long value);
	c_interlocked_long& operator=(c_interlocked_long const& value);
	c_interlocked_long& operator=(bool value);
	c_interlocked_long& operator=(long value);
};
static_assert(sizeof(c_interlocked_long) == 0x4);

class c_synchronized_long
{
private:
	long volatile m_value; // 0x0
public:
	c_synchronized_long(long starting_value);
	c_synchronized_long();
	~c_synchronized_long();
	operator long() const;
	long set(long value);
	long set_if_equal(long value, long comperand);
	long peek() const;
	long add(long value);
	long increment();
	long decrement();
	long and_(long value);
	long or_(long value);
	long xor_(long value);
	long set_bit(long index, bool setting);
	bool test_bit(long index) const;
	c_synchronized_long& operator+=(long value);
	c_synchronized_long& operator-=(long value);
	c_synchronized_long& operator&=(long value);
	c_synchronized_long& operator|=(long value);
	c_synchronized_long& operator=(c_synchronized_long const& value);
	c_synchronized_long& operator=(bool value);
	c_synchronized_long& operator=(long value);
};
static_assert(sizeof(c_synchronized_long) == 0x4);

/* ---------- prototypes */

/* ---------- globals */

/* ---------- public code */

/* ---------- private code */

#endif // __SYNCHRONIZED_VALUE_H__
