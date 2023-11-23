#!/bin/bash
cmake -DCMAKE_BUILD_TYPE=Debug -DBUILD_TESTS=ON -S. -B./build/tests
cd build/tests/
make  