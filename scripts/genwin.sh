#!/bin/bash

cd "$(dirname "$0")" && mkdir -p ../build/win && cd ../build/win

cmake \
  -DCMAKE_C_COMPILER=x86_64-w64-mingw32-gcc \
  -DCMAKE_CXX_COMPILER=x86_64-w64-mingw32-g++ \
  -DCMAKE_SYSTEM_NAME=Windows \
  -DCMAKE_SYSTEM_VERSION=10.0 \
  -DCMAKE_PREFIX_PATH=/usr/x86_64-w64-mingw32 \
  -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=../../../out/win \
  ../..

make
