#ifndef __TORII_DISPLAY_IMPL_X11_H__
#define __TORII_DISPLAY_IMPL_X11_H__

#include "settings.hpp"

#if X11_ENABLED == 1
#include "X11/Xlib.h"

#if OPENGL_ENABLED == 1
#include <GL/gl.h>
#include <GL/glx.h>
#endif // OPENGL_ENABLED

#include "platform/display_impl.hpp"

namespace torii
{

    class DisplayImplX11 : public DisplayImpl
    {
        Display* m_display;
        Window m_window;
        Screen* m_screen;
	    int m_screenId;
        Atom m_wm_delete_window;
        XSetWindowAttributes m_attrs;
        XVisualInfo* m_visualInfo;

#if OPENGL_ENABLED == 1
        GLXContext m_glContext;
        void create_opengl();
#endif

    public:
        void create(std::string title, Vec2<uint64_t> position, Vec2<uint64_t> size, DisplayRenderAPI api) override;
        void close() override;
        void initFrame() override;
        void clear() override;
        bool pollEvent(Event& event) override;
        void presentFrame() override;
    };

}

#endif // X11_ENABLED

#endif // __TORII_DISPLAY_IMPL_X11_H__