#ifndef __TORII_COMPONENT_H__
#define __TORII_COMPONENT_H__

#include <string>

#include "utility.hpp"
#include "ecs/ecs_utility.hpp"

namespace torii
{
    class IComponent
    {
    protected:
        Handle m_handle;
        inline static Handle m_nextHandle = 0;

    public:
        IComponent() 
            : m_handle(m_nextHandle++) {}

        inline Handle getHandle() { return m_handle; }

        operator std::string() const
        {
            return "Component(Handle: " + std::to_string(m_handle) + ") ";
        }
    };

    template<typename Type>
    class Component : public IComponent
    {
    public:
        Type data;

        Component(Type data);
    };

    template<typename Type>
    Component<Type>::Component(Type data)
        : data(data), IComponent() {}
}

#endif