#ifndef __TORII_MATH_H__
#define __TORII_MATH_H__

namespace torii
{

    template<typename Type>
    struct Vec2
    {
        Type x, y;
    };

    struct Vec2d : public Vec2<double> {};

    template<typename Type>
    struct Vec3
    {
        Type x, y, z;
    };

    struct Vec3d : public Vec3<double> {};

}

#endif // __TORII_MATH_H__