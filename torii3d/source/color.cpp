#include "color.hpp"

namespace torii
{

    Color::Color(ColorComponent all)
        : r(all), g(all), b(all), a(all)
    {
    }

    Color::Color(ColorComponent r, ColorComponent g, ColorComponent b, ColorComponent a)
        : r(r), g(g), b(b), a(a)
    {
    }

}