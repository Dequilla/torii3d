#include "platform/OpenGL/impl_opengl_definitions.hpp"

namespace torii
{

    FPD_GETERROR glGetError;

    FPD_GENVERTEXARRAYS glGenVertexArrays;
    FPD_BINDVERTEXARRAY glBindVertexArray;
    FPD_ENABLEVERTEXATTRIBARRAY glEnableVertexAttribArray;
    FPD_VERTEXATTRIBPOINTER glVertexAttribPointer;

    FPD_GENBUFFERS glGenBuffers;
    FPD_BINDBUFFER glBindBuffer;
    FPD_BUFFERDATA glBufferData;

}