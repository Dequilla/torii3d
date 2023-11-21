#include "resource/text_document.hpp"

#include <fstream>

namespace torii
{

    TextDocument* TextDocumentManager::load(const std::string& path)
    {
        m_resources.emplace_back();
        TextDocument* doc = &m_resources.back();
        m_mapResources.emplace(path, doc);

        std::ifstream file(path);
        std::string line;
        while(std::getline(file, line))
        {
            doc->data.append(line).append("\n");
        }

        return doc;
    }

}