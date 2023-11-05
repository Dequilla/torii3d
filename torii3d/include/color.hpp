#ifndef __TORII_COLOR_H__
#define __TORII_COLOR_H__

#include <string>

namespace torii
{

    using ColorComponent = float;

    class Color
    {
    public:
        Color() = default;
        Color(ColorComponent all);
        Color(ColorComponent r, ColorComponent g, ColorComponent b, ColorComponent a = 0.f);

        struct 
        {
            ColorComponent r = 0.f;
            ColorComponent g = 0.f;
            ColorComponent b = 0.f;
            ColorComponent a = 0.f;
        };

        operator std::string() const
        {
            return "(" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ", " + std::to_string(a) + ")";
        }
    };
}

#endif