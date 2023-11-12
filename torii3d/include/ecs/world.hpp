#ifndef __TORII_WORLD_H__
#define __TORII_WORLD_H__

#include <map>
#include <unordered_map>
#include <vector>
#include <typeindex>
#include <optional>

#include "settings.hpp"
#include "utility.hpp"

#include "ecs/entity.hpp"
#include "ecs/component.hpp"

namespace torii
{

    class World
    {
        Handle m_nextHandleEntity = 0;
        std::map<Handle, Entity> m_entities;
        std::unordered_map<std::type_index, std::vector<IComponent*>> m_componentsByType;
        std::map<Handle, IComponent*> m_componentsMap;

    public:
        World();
        ~World();

        ///////////////////
        // Entity
        Handle entity();
        Entity* entity(Handle handle);

        ///////////////////
        // Components
        template<typename Type>
        bool registerComponentType();

        template<typename Type>
        Handle component(Type component);

        template<typename Type>
        Type* component(Handle comp) const;

    };

    template<typename Type>
    bool World::registerComponentType()
    {
        if( m_componentsByType.find(typeid(Type)) == m_componentsByType.end() )
        {
            m_componentsByType.emplace(typeid(Type), std::vector<IComponent*>());
            return true;
        }

        return false;
    }

    template<typename Type>
    Handle World::component(Type componentData)
    {
        auto itVec = m_componentsByType.find(typeid(Type));
        if( itVec == m_componentsByType.end() )
        {
            TORII_ASSERT( registerComponentType<Type>() );
            itVec = m_componentsByType.find(typeid(Type));
        }

        Component<Type>* c = new Component<Type>(componentData);
        itVec->second.push_back(c);

        m_componentsMap.emplace(c->getHandle(), c);

        return c->getHandle();
    }

    template<typename Type>
    Type* World::component(Handle cHandle) const
    {
        auto itC = m_componentsMap.find(cHandle);
        if( itC != m_componentsMap.end() )
        {
            return &static_cast<Component<Type>*>(itC->second)->data;
        }

        return nullptr;
    }

}

#endif