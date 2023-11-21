#include "torii.hpp"

namespace torii
{

    void init()
    {
        #if OPENGL_ENABLED == 1
            glInitProcs();
        #endif // OPENGL_ENABLED
    }

}