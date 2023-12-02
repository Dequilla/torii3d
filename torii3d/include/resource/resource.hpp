#ifndef __TORII_RESOURCE_H__
#define __TORII_RESOURCE_H__

#include <unordered_map>
#include <vector>
#include <string>
#include <type_traits>
#include <typeindex>

#include "utility.hpp"
#include "logger.hpp"

namespace torii
{
   
    template<typename Type>
    class ResourceManager
    {
    protected:
        std::unordered_map<std::string, Type*> m_resources;

    public:
        Type* get( const std::string& );
        
        virtual Type* load( const std::string& ) = 0;
        virtual Type* load( const std::string&, const std::vector<uint8_t>& ) = 0;
    };
    
    template<typename Type>
    Type* ResourceManager<Type>::get( const std::string& id )
    {
        auto itRes = m_resources.find(id);
        if(itRes == m_resources.end())
        {
            return load(id);
        } 
        else
        {
            return (*itRes).second;
        }
    }
        
}

#endif