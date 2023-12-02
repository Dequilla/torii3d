#include <iostream>

#ifdef _RUN_TESTS
#include "tests/tests.hpp"
#endif

#include "torii.hpp"

#include "settings.hpp"
#if OPENGL_ENABLED == 1
#include <GL/gl.h>
#endif

#include "logger.hpp"

#include "display.hpp"

#include "model.hpp"
#include "platform/OpenGL/mesh_impl_opengl.hpp"

#include "resource/resource.hpp"
#include "resource/text_document.hpp"

int main(int argc, char** argv)
{ 
#ifdef _RUN_TESTS
    tests::run_all_tests();
#else
    torii::init();

    ////////////////////////
    // testing

    torii::Mesh mesh = torii::temp_create_square();

    // testing
    ////////////////////////

    /////////////////////////////////
    // Actual program start
    torii::trace({"Starting torii3d!"}, "system");

    torii::Display display("Test", {0, 0}, {1280, 720}); 
    display.setClearColor({0.f, 0.f, 0.f, 1.f});

    while( display.isOpen() )
    {
        display.initFrame();
        display.clear();

        glBegin(GL_TRIANGLES);
			glColor3f(  1.0f,  0.0f, 0.0f);
			glVertex3f( 0.0f, -1.0f, 0.0f);
			glColor3f(  0.0f,  1.0f, 0.0f);
			glVertex3f(-1.0f,  1.0f, 0.0f);
			glColor3f(  0.0f,  0.0f, 1.0f);
			glVertex3f( 1.0f,  1.0f, 0.0f);
		glEnd();

        torii::Event event;
        while(display.pollEvent(event))
        {
            switch(event.type)
            {
                case torii::EventType::Close:
                    torii::info({"We are leaving boiiisss!"});
                break;
                case torii::EventType::KeyPressed:
                    torii::info({"KeyPressed: ", std::to_string((uint64_t)event.key.code)});
                break;
                case torii::EventType::KeyReleased:
                    torii::info({"KeyReleased: ", std::to_string((uint64_t)event.key.code)});
                break;
                case torii::EventType::MouseMoved:
                    torii::info({event.mouseMoved.position, " - ", event.mouseMoved.abs_position});
                break;
                
            }
        }

        display.presentFrame();
    }

#endif
    
    return 0;
}