#!/bin/bash
cmake -DCMAKE_BUILD_TYPE=Release -S. -B./build/release

cd ./build/release
make