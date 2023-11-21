#ifndef __TORII_TEXT_DOCUMENT_RESOURCE_H__
#define __TORII_TEXT_DOCUMENT_RESOURCE_H__

#include "resource/resource.hpp"

#include <string>

namespace torii
{
    class TextDocument
    {
    public:
        std::string data;
    };

    class TextDocumentManager : public ResourceManager<TextDocument>
    {
    public:
        TextDocument* load(const std::string&) override;
    };
    
}

#endif // __TORII_TEXT_DOCUMENT_RESOURCE_H__