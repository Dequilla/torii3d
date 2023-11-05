#ifndef __TORII_UTILITY_H__
#define __TORII_UTILITY_H__

#include <string>
#include <iostream>
#include <cstring>

namespace torii
{ 
    template<typename Type>
    inline Type* zero_memory(Type* toZero)
    {
        memset(toZero, 0, sizeof(Type));
    }
}

#endif // __TORII_UTILITY_H__