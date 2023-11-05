#include "platform/display_impl.hpp"

namespace torii
{
    bool DisplayImpl::isOpen()
    {
        return m_isOpen;
    }

    void DisplayImpl::setClearColor(Color color)
    {
        m_clearColor = color;
    }

}