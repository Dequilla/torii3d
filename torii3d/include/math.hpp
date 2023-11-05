#ifndef __TORII_MATH_H__
#define __TORII_MATH_H__

#include <iostream>
#include <string>

namespace torii
{
    template<typename Type>
    struct Vec2
    {
        Type x, y;

        operator std::string() const 
        {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
        }
    };

    struct Vec2d : public Vec2<double> {};

    template<typename Type>
    struct Vec3
    {
        Type x, y, z;

        operator std::string() const 
        {
            return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
        }
    };

    struct Vec3d : public Vec3<double> {};

}

#endif // __TORII_MATH_H__