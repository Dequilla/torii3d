#!/bin/bash

./build_debug.sh

gdb --ex 'b main' -ex 'run' ./build/debug/torii