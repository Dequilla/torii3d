#include "platform/x11/display_impl_x11.hpp"

#include <iostream>
#include <stdexcept>


#include "event.hpp"
#include "utility.hpp"

namespace torii
{
    
#if OPENGL_ENABLED == 1
    void DisplayImplX11::create_opengl()
    {
        GLint majorGLX = 0, minorGLX = 0;
	    glXQueryVersion(m_display, &majorGLX, &minorGLX);
	    if (majorGLX <= 1 && minorGLX < 2) {
		    throw std::runtime_error("GLX 1.2 or greater is required.");
	    }
        
        // GLX, create XVisualInfo, this is the minimum visuals we want
	    GLint glxAttribs[] = {
		    GLX_RGBA,
		    GLX_DOUBLEBUFFER,
		    GLX_DEPTH_SIZE,     24,
		    GLX_STENCIL_SIZE,   8,
		    GLX_RED_SIZE,       8,
		    GLX_GREEN_SIZE,     8,
		    GLX_BLUE_SIZE,      8,
		    GLX_SAMPLE_BUFFERS, 0,
		    GLX_SAMPLES,        0,
		    None
	    };
        
       m_visualInfo = glXChooseVisual(m_display, DefaultScreen(m_display), glxAttribs);
	    if (m_visualInfo == 0) {
            this->close();
            throw std::runtime_error("Could not create correct visual window");
	    }
        
        // Open the window
	    m_attrs.border_pixel = BlackPixel(m_display, m_screenId);
	    m_attrs.background_pixel = WhitePixel(m_display, m_screenId);
	    m_attrs.override_redirect = True;
        m_attrs.colormap = XCreateColormap(m_display, RootWindow(m_display, m_screenId), m_visualInfo->visual, AllocNone);
        m_attrs.event_mask = KeyPressMask | KeyReleaseMask | PointerMotionMask;
    }
#endif

    void DisplayImplX11::create(std::string title, Vec2<uint64_t> position, Vec2<uint64_t> size, DisplayRenderAPI api)
    {
        // TODO(edwin): Fortsätt på denna: https://github.com/gamedevtech/X11OpenGLWindow

        m_display = XOpenDisplay(NULL);
        if (NULL == m_display) {  
            std::runtime_error("Failed to initialize display");
        }
        m_screen = DefaultScreenOfDisplay(m_display);
	    m_screenId = DefaultScreen(m_display);

#if OPENGL_ENABLED == 1
        create_opengl();
#endif

        m_window = XCreateWindow(m_display, RootWindow(m_display, m_screenId), position.x, position.y, size.x, size.y, 0, CopyFromParent, InputOutput, CopyFromParent, CWEventMask, &m_attrs);
        if (None == m_window) {
            XCloseDisplay(m_display);
            std::runtime_error("Failed to create window");
        }

#if OPENGL_ENABLED == 1
        // Create GLX OpenGL context
	    m_glContext = glXCreateContext(m_display, m_visualInfo, NULL, GL_TRUE);
	    glXMakeCurrent(m_display, m_window, m_glContext);

        std::cout << "GL Vendor: " << glGetString(GL_VENDOR) << "\n";
	    std::cout << "GL Renderer: " << glGetString(GL_RENDERER) << "\n";
	    std::cout << "GL Version: " << glGetString(GL_VERSION) << "\n";
	    std::cout << "GL Shading Language: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";

	    glClearColor(0.5f, 0.6f, 0.7f, 1.0f);
#endif
	    // Show the window
	    XClearWindow(m_display, m_window);
	    XMapRaised(m_display, m_window);

        m_wm_delete_window = XInternAtom(m_display, "WM_DELETE_WINDOW", False);
        XSetWMProtocols(m_display, m_window, &m_wm_delete_window, 1);

        XMapWindow(m_display, m_window);
        XFlush(m_display);

        m_isOpen = true;
    }

    void DisplayImplX11::close()
    {
        XDestroyWindow(m_display, m_window);
        XCloseDisplay(m_display);
        m_display = nullptr;

        m_isOpen = false;
    }

    void DisplayImplX11::clear()
    {
#if OPENGL_ENABLED == 1
        glClear(GL_COLOR_BUFFER_BIT);
#endif
    }

    void DisplayImplX11::initFrame()
    {
#if OPENGL_ENABLED == 1
	    glXMakeCurrent(m_display, m_window, m_glContext);
#endif
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
                case KeyRelease:
                    event.type = (xevent.xkey.type == KeyPress ? EventType::KeyPressed : EventType::KeyReleased);
                    event.key.code = static_cast<torii::KeyCode>(xevent.xkey.keycode);

                    return true;
                break;
                case MotionNotify:
                    event.type = EventType::MouseMoved;
                    event.mouseMoved.position.x = static_cast<int64_t>(xevent.xmotion.x);
                    event.mouseMoved.position.y = static_cast<int64_t>(xevent.xmotion.y);
                    
                    event.mouseMoved.abs_position.x = static_cast<int64_t>(xevent.xmotion.x_root);
                    event.mouseMoved.abs_position.y = static_cast<int64_t>(xevent.xmotion.y_root);
                    
                    return true;
                break;
            }
        }

        return false;
    }

    void DisplayImplX11::presentFrame()
    {
#if OPENGL_ENABLED == 1
        glXSwapBuffers(m_display, m_window);
#endif
    }

}