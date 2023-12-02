#ifndef __TORII_UTILITY_H__
#define __TORII_UTILITY_H__

#include <string>
#include <iostream>
#include <cstring>
#include <cstdint>
#include <cassert>
#include <exception>

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
    using Handle = uint64_t;

    template<typename Type>
    inline Type* zero_memory(Type* toZero)
    {
        memset(toZero, 0, sizeof(Type));
    }

    class Exception : public std::exception
    {
    protected:
        std::string m_msg;

    public:
        explicit Exception(const char*);
        explicit Exception(const std::string&);

        virtual ~Exception() noexcept {}

        virtual const char* what() const noexcept;        
    };
}

#endif // __TORII_UTILITY_H__