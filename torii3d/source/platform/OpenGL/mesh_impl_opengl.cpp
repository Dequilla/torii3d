#include "platform/OpenGL/mesh_impl_opengl.hpp"

#include <GL/gl.h>

#include "platform/OpenGL/impl_opengl.hpp"

namespace torii
{

    void MeshImplOpenGL::setup(Mesh mesh)
    {
        m_mesh = mesh;

        glGenVertexArrays(1, &m_vao);
        glGenBuffers(1, &m_vbo);
        glGenBuffers(1, &m_ebo);

        glBindVertexArray(m_vao);
        glBindBuffer(GL_ARRAY_BUFFER, m_vbo);
    
        glBufferData(GL_ARRAY_BUFFER, mesh.vertices.size() * sizeof(Vertex), &mesh.vertices[0], GL_STATIC_DRAW);  
    
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ebo);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh.indices.size() * sizeof(uint64_t), &mesh.indices[0], GL_STATIC_DRAW);
        
        // vertex positions
        glEnableVertexAttribArray(0);	
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)0);
        
        // vertex normals
        glEnableVertexAttribArray(1);	
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, normal));
        
        // vertex texture coords
        glEnableVertexAttribArray(2);	
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

        glBindVertexArray(0);
    }

    void MeshImplOpenGL::draw()
    {
          // draw mesh
        glBindVertexArray(m_vao);
        glDrawElements(GL_TRIANGLES, static_cast<unsigned int>(m_mesh.indices.size()), GL_UNSIGNED_INT, 0);
        glBindVertexArray(0);
    }

}