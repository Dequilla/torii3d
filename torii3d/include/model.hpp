#ifndef __TORII_MODEL_H__
#define __TORII_MODEL_H__

#include "math.hpp"

namespace torii
{

    struct Vertex
    {
        Vec3d position;
        Vec3d normal;
        Vec2d uv;
    };

}
#endif // __TORII_MODEL_H 