#!/bin/bash

cd "$(dirname "$0")" && cd ..

cmake -B ./build/unix/clang -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Release -S ./

cmake --build ./build/unix/clang --config Release
