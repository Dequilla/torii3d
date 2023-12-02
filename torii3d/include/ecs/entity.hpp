#ifndef __TORII_ENTITY_H__
#define __TORII_ENTITY_H__

#include <string>

#include "utility.hpp"
#include "ecs/ecs_utility.hpp"

namespace torii
{

    class Entity 
    {
    protected:
        Handle m_handle;

        friend class World;

    public:
        inline Handle getHandle() { return m_handle; }

        operator std::string() const
        {
            return "Entity(Handle: " + std::to_string(m_handle) + ") ";
        }
    };

}

#endif