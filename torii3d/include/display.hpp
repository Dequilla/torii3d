#ifndef __TORII_WINDOW_H__
#define __TORII_WINDOW_H__

#include <string>

#include "math.hpp"
#include "event.hpp"

#include "platform/display_impl.hpp"

namespace torii
{
    
    class Display
    {
        DisplayImpl* m_displayImpl;

    public:
        Display(const std::string& title, Vec2<uint64_t> position, Vec2<uint64_t> size);
        ~Display();

        bool isOpen();
        void setClearColor(Color color);

        void initFrame();
        void clear();
        void presentFrame();
        bool pollEvent(Event& event);
    };

}

#endif // __TORII_WINDOW_H__