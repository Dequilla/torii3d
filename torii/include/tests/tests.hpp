#pragma once

#include "idyll.hpp"
#include "test_resource_manager.hpp"

namespace tests
{
    void run_all_tests()
    {
        IDYLL_RUN(resource_manager);
    }
}