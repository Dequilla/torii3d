#ifndef __TORII_MODEL_H__
#define __TORII_MODEL_H__

#include "math.hpp"

#include <vector>

namespace torii
{

    struct Vertex
    {
        Vec3d position = { .0, .0, .0};
        Vec3d normal = { .0, .0, .0 };
        Vec2d uv = { .0, .0 };
    };

    struct Mesh
    {
        std::vector<Vertex> vertices;
        std::vector<uint64_t> indices;
    };

    inline Mesh temp_create_square()
    {
        Mesh mesh;
        mesh.vertices = {
            Vertex { .position = {-0.5, -0.5, -0.5} },
            Vertex { .position = {-0.5, -0.5,  0.5} },
            Vertex { .position = { 0.5, -0.5, -0.5} },
            Vertex { .position = {-0.5,  0.5, -0.5} },
            Vertex { .position = {-0.5,  0.5,  0.5} },
            Vertex { .position = { 0.5, -0.5,  0.5} },
            Vertex { .position = { 0.5,  0.5, -0.5} },
            Vertex { .position = { 0.5,  0.5,  0.5} }
        };

        mesh.indices = {
            0, 1, 2,
            5, 1, 2,

            1, 4, 0,
            0, 4, 3,

            1, 4, 5,
            5, 4, 7,

            7, 4, 6,
            6, 3, 4,

            7, 5, 6,
            7, 2, 6,

            0, 2, 3,
            3, 2, 6
        };

        return mesh;
    }

}
#endif // __TORII_MODEL_H 