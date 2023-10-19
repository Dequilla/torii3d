#!/bin/bash

cmake -DCMAKE_BUILD_TYPE=Debug -S. -B./build/debug
cd build/debug/
make

gdb --ex 'b main' -ex 'run' ./torii