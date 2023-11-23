#pragma once

#include "idyll.hpp"

TEST_ENV(env1)

    TEST_SECTION("Section1")

        TEST("Test1")
            return true;
        TEST_END

        TEST_SECTION("Section2")

            TEST("Inner1")
                return false;
            TEST_END

            TEST("Inner2")
                return false;
            TEST_END

        TEST_SECTION_END

        TEST("Test2")
            return true;
        TEST_END
        
        TEST_SECTION("Section3")

            TEST("LastSectionTest")
                return false;
            TEST_END

        TEST_SECTION_END
    
    TEST_SECTION_END

TEST_ENV_END