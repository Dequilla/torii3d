#ifndef __TORII_DISPLAY_IMPL_H__
#define __TORII_DISPLAY_IMPL_H__

#include <string>
#include <cstdint>

#include "math.hpp"
#include "event.hpp"

namespace torii
{
    enum class DisplayRenderAPI
    {
        OpenGL
    };

    class DisplayImpl
    {
    protected:
        bool m_isOpen = false;

    public:
        bool isOpen();

        virtual void create(std::string title, Vec2<uint64_t> position, Vec2<uint64_t> size, DisplayRenderAPI api = DisplayRenderAPI::OpenGL) = 0;
        virtual void close() = 0;
        virtual void initFrame() = 0;
        virtual void clear() = 0;  
        virtual bool pollEvent(Event& event) = 0;
        virtual void presentFrame() = 0;
    };

}

#endif // __TORII_DISPLAY_IMPL_H__