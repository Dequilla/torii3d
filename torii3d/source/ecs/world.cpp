#include "ecs/world.hpp"

namespace torii
{
    World::World()
    {
    }

    World::~World()
    {
        for(auto component : m_componentsMap)
        {
            delete component.second;
        }
    }

    Handle World::entity()
    {
        auto newEntity = m_entities.emplace(m_nextHandleEntity++, Entity()).first;
        newEntity->second.m_handle = newEntity->first;
        return newEntity->first;
    }

    Entity* World::entity(Handle handle)
    {
        return &m_entities.at(handle);
    }

}