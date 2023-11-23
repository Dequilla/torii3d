#include "idyll.hpp"

namespace idyll
{
    bool Section::run(size_t level)
    {
        const std::string PREFIX(level, '\t');

        std::cout << PREFIX << "[ " << name << " ]" << std::endl;
        bool result = true;

        for(auto& test : tests)
        {
            test.result = test.callback();
            if(!test.result.value_or(false))
                result = false;

            std::cout << PREFIX << '\t' << " => " << test.name << " ... " << (result ? "Succeeded" : "Failed") << std::endl;
        }

        for(auto& section : subsections)
        {
            if(!section.run(level + 1))
                result = false;
        }

        return result;
    }

    void Environment::popSection()
    {
        currentSectionsOrdered.pop_back();
    }

    void Environment::addSection(std::string name)
    {
        Section* currentSection = nullptr;
        if(currentSectionsOrdered.size() > 0)
        {
            std::string currentName = currentSectionsOrdered.back();
            auto itSection = allSections.find(currentName);
            if(itSection != allSections.end())
            {
                currentSection = itSection->second;
            }
        }

        Section* pSection = nullptr;
        if(currentSection == nullptr)
        {
            sections.push_back( Section {.name = name} );
            pSection = &sections.back();
        }
        else if(currentSection != nullptr)
        {
            currentSection->subsections.push_back(Section { .name = name });
            pSection = &currentSection->subsections.back();
        }

        allSections.emplace(name, pSection);
        currentSectionsOrdered.push_back(name);
    }

    void Environment::addTest(std::string name, TestCallback callback)
    {
        std::string currentSection = currentSectionsOrdered.back();
        
        auto itSection = allSections.find(currentSection);
        if(itSection != allSections.end())
        {
            Section* active = itSection->second;
            active->tests.push_back( Test {
                .name = name,
                .callback = callback
            });
        }
    }

    void Environment::run()
    {
        std::cout << "Running tests!" << std::endl;

        for(auto& section : sections)
        {
            bool result = section.run(0);
        }
    }
    
}