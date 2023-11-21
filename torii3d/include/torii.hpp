#ifndef __TORII_H__
#define __TORII_H__

#include "settings.hpp"

#if OPENGL_ENABLED == 1
#include "platform/OpenGL/impl_opengl.hpp"
#endif // OPENGL_ENABLED

namespace torii
{
    void init();
}

#endif