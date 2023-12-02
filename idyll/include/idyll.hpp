#pragma once

#include <iostream>

#include <map>
#include <vector>
#include <string>
#include <optional>

#include "idyll_utility.hpp"

//////////////////////////////
// Macros


#define IDYLL_BOOL_RES idyll_tests_result
#define IDYLL_ASSERT(exp) \
if(!(exp)) { \
IDYLL_BOOL_RES = false; \
}

#define IDYLL_RUN(env) \
idyll_test_environment_##env()

// Environment
#define TEST_ENV(name)\
void idyll_test_environment_##name(){\
idyll::Environment env;\
IDYLL_DEFER() { env.run(); };

#define TEST_ENV_END }

// Section
#define TEST_SECTION(name)\
{\
env.addSection(name);\
IDYLL_DEFER()\
{\
    env.popSection(); \
};

#define TEST_SECTION_END }

// Test
#define TEST(name)\
env.addTest(name, []() -> bool { \
bool IDYLL_BOOL_RES = true; 

#define TEST_END \
return IDYLL_BOOL_RES; \
});

// Macros
//////////////////////////////

namespace idyll
{
    using TestCallback = bool (*)();

    struct Test
    {
        std::string name;
        TestCallback callback;
        std::optional<bool> result = std::nullopt;
    };

    struct Section
    {
        std::string name;
        
        std::vector<Section> subsections;
        std::vector<Test> tests;

        bool run(size_t level);
    };

    struct Environment
    {
        std::vector<std::string> currentSectionsOrdered;
        void popSection();

        std::vector<Section> sections;
        std::map<std::string, Section*> allSections;
        #define STRING(s) #s
        void addSection(std::string name);
        void addTest(std::string name, TestCallback callback);

        void run();
    };

}