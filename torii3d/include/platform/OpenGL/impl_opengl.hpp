#ifndef __TORII_IMPL_OPENGL_H__
#define __TORII_IMPL_OPENGL_H__

#include <GL/gl.h>
#include "impl_opengl_definitions.hpp"

namespace torii
{

    void* getGLProcAddress(const unsigned char* funcName);

    void glInitProcs();

}

#endif