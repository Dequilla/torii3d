#ifndef __TORII_UTILITY_H__
#define __TORII_UTILITY_H__

#include <string>
#include <iostream>
#include <cstring>
#include <cstdint>
#include <cassert>

#include "settings.hpp"
#include "logger.hpp"

#ifdef _DEBUG 
inline void torii_assert_impl(bool exp)
{
    assert(exp);
}
#define TORII_ASSERT(x) assert(x)
#else
#define TORII_ASSERT(x)
#endif

namespace torii
{ 
    template<typename Type>
    inline Type* zero_memory(Type* toZero)
    {
        memset(toZero, 0, sizeof(Type));
    }
}

#endif // __TORII_UTILITY_H__