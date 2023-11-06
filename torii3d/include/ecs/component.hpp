#ifndef __TORII_COMPONENT_H__
#define __TORII_COMPONENT_H__

#include <string>

#include "ecs/ecs_utility.hpp"

namespace torii
{
    template<typename Type>
    class Component 
    {
    private:
        Handle m_handle;
    
    public:
        Type data;

        Component(Type data);

        inline Handle getHandle() { return m_handle; }

        operator std::string() const
        {
            return "Component(Handle: " + std::to_string(m_handle) + ") ";
        }
    };

    template<typename Type>
    Component<Type>::Component(Type data)
        : data(data)
    {
    }
}

#endif