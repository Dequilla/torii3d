#ifndef __TORII_WORLD_H__
#define __TORII_WORLD_H__

#include <map>
#include <optional>

#include "ecs/entity.hpp"

namespace torii
{

    class World
    {
        Handle m_nextHandleEntity = 0;
        std::map<Handle, Entity> m_entities;

    public:
        World();

        Handle entity();
        Entity* entity(Handle handle);
    };

}

#endif