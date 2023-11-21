#include "platform/OpenGL/impl_opengl.hpp"

#include "settings.hpp"
#include "utility.hpp"

#if OPENGL_ENABLED == 1

#if X11_ENABLED == 1
#include <GL/glx.h>
#elif WIN_ENABLED == 1
#include <wingdi.h>
#endif

namespace torii
{
    static const GLubyte* to_glubyte(const char* str)
    {
        return reinterpret_cast<const GLubyte*>(str);
    }

    void* getGLProcAddress(const char* funcName)
    {
        void* fptr = nullptr;
        #if defined( X11_ENABLED )
            fptr = reinterpret_cast<void*>( glXGetProcAddress( to_glubyte(funcName) ) );
        #elif defined( WIN_ENABLED )
            return reinterpret_cast<void*>( wglGetProcAddress( to_glubyte(funcName) ) ); 
        #endif

        if(fptr == nullptr)
            warning({ "GL func not supported: ", funcName }, "OpenGL");

        return fptr;
    }

    void glInitProcs()
    {
        trace({"Loading gl functions."}, "OpenGL");

        glGetError = (FPD_GETERROR)getGLProcAddress("glGetError");

        glGenVertexArrays = (FPD_GENVERTEXARRAYS)getGLProcAddress("glGenVertexArrays");
        glBindVertexArray = (FPD_BINDVERTEXARRAY)getGLProcAddress("glBindVertexArray");
        glEnableVertexAttribArray = (FPD_ENABLEVERTEXATTRIBARRAY)getGLProcAddress("glEnableVertexAttribArray");
        glVertexAttribPointer = (FPD_VERTEXATTRIBPOINTER)getGLProcAddress("glVertexAttribPointer");

        glGenBuffers = (FPD_GENBUFFERS)getGLProcAddress("glGenBuffers");
        glBindBuffer = (FPD_BINDBUFFER)getGLProcAddress("glBindBuffer");
        glBufferData = (FPD_BUFFERDATA)getGLProcAddress("glBufferData");
    }


}

#endif