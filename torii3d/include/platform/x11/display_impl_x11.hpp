#ifndef __TORII_DISPLAY_IMPL_X11_H__
#define __TORII_DISPLAY_IMPL_X11_H__

#include "settings.hpp"

#if X11_ENABLED == 1

#include "platform/display_impl.hpp"

#include "X11/Xlib.h"

namespace torii
{

    class DisplayImplX11 : public DisplayImpl
    {
        Display* m_display;
        Window m_root;
        Atom m_wm_delete_window;
        XSetWindowAttributes m_attrs;

    public:
        void create(std::string title, Vec2<uint64_t> position, Vec2<uint64_t> size) override;
        void close() override;

        bool pollEvent(Event& event) override;
    };

}

#endif // X11_ENABLED

#endif // __TORII_DISPLAY_IMPL_X11_H__