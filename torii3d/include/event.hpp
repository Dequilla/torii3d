#ifndef __TORII_EVENT_H__
#define __TORII_EVENT_H__

#include <cstdint>

#include "keycodes.hpp"
#include "math.hpp"

namespace torii
{
    struct KeyEvent
    {
        KeyCode code;
        // TODO(edwin): Implement keysyms on x11
    };

    struct MouseMovedEvent
    {
        Vec2<int64_t> position;
    };

    struct MouseScrollEvent
    {

    };

    struct MouseButtonEvent
    {

    };
    
    enum class EventType
    {
        Close,
        Resize,
        LostFocus,
        GainedFocus,
        KeyPressed,
        KeyReleased,
        MouseWheelMoved,
        MouseWheelScrolled,
        MouseButtonPressed,
        MouseMoved
    };

    class Event
    {
    public:
        EventType type;

        union
        {
            KeyEvent key;
            MouseMovedEvent mouseMoved;
            MouseScrollEvent mouseScroll;
            MouseButtonEvent mouseButton;
        };
    };
    
    


}

#endif // __TORII_EVENT_H__
