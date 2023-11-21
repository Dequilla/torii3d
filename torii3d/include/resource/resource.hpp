#ifndef __TORII_RESOURCE_H__
#define __TORII_RESOURCE_H__

#include <unordered_map>
#include <vector>
#include <string>

#include "utility.hpp"

namespace torii
{
    template<typename ResType>
    class ResourceManager
    {
    protected:
        std::unordered_map<std::string, ResType*> m_mapResources;
        std::vector<ResType> m_resources;

    public:
        virtual ResType* load(const std::string& ) = 0;
        virtual ResType* get(const std::string& );
    };

    template<typename ResType>
    ResType* ResourceManager<ResType>::get(const std::string& path )
    {
        auto itResource = m_mapResources.find(path);
        if(itResource == m_mapResources.end())
            return load(path);
        else
            return itResource->second;
    }

}

#endif