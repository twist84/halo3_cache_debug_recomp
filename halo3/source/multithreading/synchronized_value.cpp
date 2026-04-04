/* ---------- headers */

#include "multithreading/synchronized_value.h"

#include <Windows.h>

/* ---------- constants */

/* ---------- definitions */

/* ---------- prototypes */

/* ---------- globals */

/* ---------- private variables */

/* ---------- public code */

c_interlocked_long::c_interlocked_long() :
    m_value(0)
{
}

c_interlocked_long::c_interlocked_long(long starting_value) :
    m_value(starting_value)
{
}

c_interlocked_long::~c_interlocked_long()
{
}

c_interlocked_long::operator long() const
{
    return m_value;
}

c_interlocked_long &c_interlocked_long::operator+=(long value)
{
    add(value);
    return *this;
}

c_interlocked_long &c_interlocked_long::operator-=(long value)
{
    add(-value);
    return *this;
}

c_interlocked_long &c_interlocked_long::operator&=(long value)
{
    and_(value);
    return *this;
}

c_interlocked_long &c_interlocked_long::operator|=(long value)
{
    or_(value);
    return *this;
}

c_interlocked_long& c_interlocked_long::operator=(c_interlocked_long const& value)
{
    set(value);
    return *this;
}

c_interlocked_long &c_interlocked_long::operator=(long value)
{
    set(value);
    return *this;
}

c_interlocked_long &c_interlocked_long::operator=(bool value)
{
    set(value);
    return *this;
}

long c_interlocked_long::peek() const
{
    return m_value;
}

c_synchronized_long::c_synchronized_long() :
    m_value(0)
{
}

c_synchronized_long::c_synchronized_long(long starting_value) :
    m_value(starting_value)
{
}

c_synchronized_long::~c_synchronized_long()
{
}

c_synchronized_long::operator long() const
{
    return peek();
}

c_synchronized_long &c_synchronized_long::operator+=(long value)
{
    add(value);
    return *this;
}

c_synchronized_long &c_synchronized_long::operator-=(long value)
{
    add(-value);
    return *this;
}

c_synchronized_long &c_synchronized_long::operator&=(long value)
{
    and_(value);
    return *this;
}

c_synchronized_long &c_synchronized_long::operator|=(long value)
{
    or_(value);
    return *this;
}

c_synchronized_long& c_synchronized_long::operator=(c_synchronized_long const& value)
{
    set(value);
    return *this;
}

c_synchronized_long &c_synchronized_long::operator=(long value)
{
    set(value);
    return *this;
}

c_synchronized_long &c_synchronized_long::operator=(bool value)
{
    set(value);
    return *this;
}

long c_interlocked_long::set(long value)
{
    long result = _InterlockedExchange(&m_value, value);
    return result;
}

long c_interlocked_long::set_if_equal(long value, long comperand)
{
    long result = _InterlockedCompareExchange(&m_value, value, comperand);
    return result;
}

long c_interlocked_long::add(long value)
{
    long result = _InterlockedExchangeAdd(&m_value, value);
    return result;
}

long c_interlocked_long::increment() volatile
{
    long result = _InterlockedIncrement(&m_value);
    return result;
}

long c_interlocked_long::decrement() volatile
{
    long result = _InterlockedDecrement(&m_value);
    return result;
}

long c_interlocked_long::and_(long value)
{
    long before = _InterlockedAnd(&m_value, value);
    long result = before & value;
    return result;
}

long c_interlocked_long::or_(long value)
{
    long before = _InterlockedOr(&m_value, value);
    long result = before | value;
    return result;
}

long c_interlocked_long::xor_(long value)
{
    long before = _InterlockedXor(&m_value, value);
    long result = before ^ value;
    return result;
}

long c_interlocked_long::set_bit(long index, bool setting)
{
    long result;
    if (setting)
    {
        long value = static_cast<long>(FLAG(index));
        long before = _InterlockedOr(&m_value, value);
        result = before | value;
    }
    else
    {
        long value = static_cast<long>(~FLAG(index));
        long before = _InterlockedAnd(&m_value, value);
        result = before & value;
    }
    return result;
}

bool c_interlocked_long::test_bit(long index) const
{
    long current_value = m_value;
    bool result = TEST_BIT(current_value, index);
    return result;
}

long c_synchronized_long::set(long value)
{
    long result = _InterlockedExchange(&m_value, value);
    return result;
}

long c_synchronized_long::set_if_equal(long value, long comperand)
{
    long result = _InterlockedCompareExchange(&m_value, value, comperand);
    return result;
}

long c_synchronized_long::peek() const
{
    long result = m_value;
    return result;
}

long c_synchronized_long::add(long value)
{
    long result = _InterlockedExchangeAdd(&m_value, value);
    return result;
}

long c_synchronized_long::increment()
{
    long result = _InterlockedIncrement(&m_value);
    return result;
}

long c_synchronized_long::decrement()
{
    long result = _InterlockedDecrement(&m_value);
    return result;
}

long c_synchronized_long::and_(long value)
{
    long before = _InterlockedAnd(&m_value, value);
    long result = before & value;
    return result;
}

long c_synchronized_long::or_(long value)
{
    long before = _InterlockedOr(&m_value, value);
    long result = before | value;
    return result;
}

long c_synchronized_long::xor_(long value)
{
    long before = _InterlockedXor(&m_value, value);
    long result = before ^ value;
    return result;
}

long c_synchronized_long::set_bit(long index, bool setting)
{
    long result;
    if (setting)
    {
        long value = static_cast<long>(FLAG(index));
        long before = _InterlockedOr(&m_value, value);
        result = before | value;
    }
    else
    {
        long value = static_cast<long>(~FLAG(index));
        long before = _InterlockedAnd(&m_value, value);
        result = before & value;
    }
    return result;
}

bool c_synchronized_long::test_bit(long index) const
{
    long current_value = m_value;
    bool result = TEST_BIT(current_value, index);
    return result;
}

/* ---------- private code */
