#include <iostream>

#define X11_ENABLED 1

#include "display.hpp"

#include "model.hpp"

int main(int argc, char** argv)
{
    torii::Display display("Test", {0, 0}, {1280, 720}); 

    while( display.isOpen() )
    {
        torii::Event event;
        while(display.pollEvent(event))
        {
            switch(event.type)
            {
                case torii::EventType::Close:
                    std::cout << "We are leaving boiiisss!" << std::endl;
                break;
                case torii::EventType::KeyPressed:
                    std::cout << "KeyPressed: " << static_cast<unsigned int>(event.key.code) << std::endl;
                break;
                case torii::EventType::KeyReleased:
                    std::cout << "KeyReleased: " << (unsigned int)event.key.code << std::endl;
                break;
                case torii::EventType::MouseMoved:
                    std::cout << "X: " << event.mouseMoved.position.x << ", Y:" << event.mouseMoved.position.y << " - ABS X: " << event.mouseMoved.abs_position.x << ", Y:" << event.mouseMoved.abs_position.y << std::endl;
                break;
                
            }
        }
    }

    return 0;
}