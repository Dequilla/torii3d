#ifndef __TORII_IMPL_OPENGL_DEFINITIONS_H__
#define __TORII_IMPL_OPENGL_DEFINITIONS_H__

#include "settings.hpp"
#if OPENGL_ENABLED == 1
#include <GL/gl.h>

namespace torii
{
    /////////////////////////
    // Error handling
    typedef GLenum(*FPD_GETERROR)();
    extern FPD_GETERROR glGetError;

    /////////////////////////
    // Vertex Arrays
    typedef void(*FPD_GENVERTEXARRAYS)(GLsizei count, GLuint* arrays);
    extern FPD_GENVERTEXARRAYS glGenVertexArrays;

    typedef void(*FPD_BINDVERTEXARRAY)(GLuint array);
    extern FPD_BINDVERTEXARRAY glBindVertexArray;

    typedef void(*FPD_ENABLEVERTEXATTRIBARRAY)(GLuint index);
    extern FPD_ENABLEVERTEXATTRIBARRAY glEnableVertexAttribArray;

    typedef void(*FPD_VERTEXATTRIBPOINTER)(GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride, const void * pointer);
    extern FPD_VERTEXATTRIBPOINTER glVertexAttribPointer;

    /////////////////////////
    // Buffers
    typedef void(*FPD_GENBUFFERS)(GLsizei count, GLuint* buffers);
    extern FPD_GENBUFFERS glGenBuffers;

    typedef void(*FPD_BINDBUFFER)(GLenum target, GLuint buffer);
    extern FPD_BINDBUFFER glBindBuffer;

    typedef void(*FPD_BUFFERDATA)(GLenum target, GLsizeiptr size, const void* data, GLenum usage);
    extern FPD_BUFFERDATA glBufferData;

}

#endif

#endif