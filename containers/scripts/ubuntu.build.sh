#!/bin/bash

cmake -B /home/r-type/build -DCMAKE_CXX_COMPILER=clang++ -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Release -S /home/r-type/
cmake --build /home/r-type/build --config Release
cd build
cpack