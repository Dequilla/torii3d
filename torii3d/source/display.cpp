#include "display.hpp"

#include "platform/x11/display_impl_x11.hpp"

namespace torii
{

    Display::Display(const std::string& title, Vec2<uint64_t> position, Vec2<uint64_t> size)
    {
#if X11_ENABLED == 1
        m_displayImpl = new DisplayImplX11();
#endif

        m_displayImpl->create(title, position, size);
    }

    Display::~Display()
    {
        delete m_displayImpl;
    }

    bool Display::isOpen()
    {
        return m_displayImpl->isOpen();
    }

    bool Display::pollEvent(Event& event)
    {
       return m_displayImpl->pollEvent(event);
    }


}