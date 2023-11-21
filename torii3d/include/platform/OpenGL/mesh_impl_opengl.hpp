#ifndef __TORII_MESH_IMPL_OPENGL_H__
#define __TORII_MESH_IMPL_OPENGL_H__

#include <vector>

#include "platform/mesh_impl.hpp"
#include "model.hpp"

#include "settings.hpp"
#if OPENGL_ENABLED == 1

#include <GL/gl.h>

namespace torii
{

    class MeshImplOpenGL : public MeshImpl
    {
        GLuint m_vao;
        GLuint m_vbo;
        GLuint m_ebo;
        Mesh m_mesh;

    public:
        void setup(Mesh mesh);

        void draw();

    };

}

#endif

#endif