#!/bin/bash

cd "$(dirname "$0")" && cd ..

cmake -B ./build/unix/gcc -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Release -S ./

cmake --build ./build/unix/gcc --config Release
