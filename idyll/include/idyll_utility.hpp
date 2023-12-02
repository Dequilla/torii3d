#pragma once

#include <functional>
#include <optional>

////////////////////////////
// Macros
#define CONCAT(x, y) x##y
#define C(x, y) CONCAT(x, y)
#define IDYLL_TO_STR(x) #x

#define IDYLL_DEFER()\
idyll::Defer C(_idyll_defer, __LINE__);\
C(_idyll_defer, __LINE__).callback = [&]()

namespace idyll
{

    struct Defer
    {
        std::optional<std::function<void(void)>> callback;
        Defer() {}
        virtual ~Defer() { 
            if(callback.has_value())
                callback.value()(); 
        }
    };

}