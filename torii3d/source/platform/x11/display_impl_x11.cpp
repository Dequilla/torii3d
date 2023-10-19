#include "platform/x11/display_impl_x11.hpp"

#include <stdexcept>

#include "event.hpp"
#include "utility.hpp"

namespace torii
{
    void DisplayImplX11::create(std::string title, Vec2<uint64_t> position, Vec2<uint64_t> size)
    {
        m_attrs.event_mask = KeyPressMask | KeyReleaseMask | PointerMotionMask;

        m_display = XOpenDisplay(NULL);
        if (NULL == m_display) {  
            std::runtime_error("Failed to initialize display");
        }

        m_root = DefaultRootWindow(m_display);
        if (None == m_root) {
            XCloseDisplay(m_display);
            std::runtime_error("No root window found");
        }

        Window window = XCreateWindow(m_display, m_root, position.x, position.y, size.x, size.y, 0, CopyFromParent, InputOutput, CopyFromParent, CWEventMask, &m_attrs);
        if (None == window) {
            XCloseDisplay(m_display);
            std::runtime_error("Failed to create window");
        }

        m_wm_delete_window = XInternAtom(m_display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(m_display, window, &m_wm_delete_window, 1);

        XMapWindow(m_display, window);
        XFlush(m_display);

        m_isOpen = true;
    }

    void DisplayImplX11::close()
    {
        XDestroyWindow(m_display, m_root);
        XCloseDisplay(m_display);
        m_display = nullptr;

        m_isOpen = false;
    }

    bool DisplayImplX11::pollEvent(Event& event)
    {
        if(!m_display) return false;

        XEvent xevent;
        if(XPending(m_display))
        {
            XNextEvent(m_display, &xevent);
            switch(xevent.type) {
                case ClientMessage:
                    if(xevent.xclient.data.l[0] == m_wm_delete_window) {
                        event.type = EventType::Close;
                        close();
                        return true;
                    }
                break;
                case KeyPress:
                    event.type = EventType::KeyPressed;
                    event.key.code = static_cast<torii::KeyCode>(xevent.xkey.keycode);

                    return true;
                break;
                case KeyRelease:
                    event.type = EventType::KeyReleased;
                    event.key.code = static_cast<torii::KeyCode>(xevent.xkey.keycode);

                    return true;
                break;
                case MotionNotify:
                    event.type = EventType::MouseMoved;
                    event.mouseMoved.position.x = static_cast<int64_t>(xevent.xmotion.x);
                    event.mouseMoved.position.y = static_cast<int64_t>(xevent.xmotion.y);
                    
                    return true;
                break;
            }
        }

        return false;
    }

}