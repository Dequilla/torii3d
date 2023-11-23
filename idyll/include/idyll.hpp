#pragma once

#include <iostream>

#include <map>
#include <vector>
#include <string>
#include <optional>

#include "utility.hpp"

//////////////////////////////
// Macros

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
env.addTest(name, []() -> bool {

#define TEST_END });

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
        
        void addSection(std::string name);
        void addTest(std::string name, TestCallback callback);

        void run();
    };



}