#include "utility.hpp"

namespace torii
{
    Exception::Exception(const char* msg)
        : m_msg(msg)
    {
    }

    Exception::Exception(const std::string& msg)
        : m_msg(msg)
    {
    }

    const char* Exception::what() const noexcept
    {
        return m_msg.c_str();
    }

}