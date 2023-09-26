#!/bin/bash

cd "$(dirname "$0")" && mkdir -p ../build/unix && cd ../build/unix

cmake \
  -DCMAKE_RUNTIME_OUTPUT_DIRECTORY=../../../out/bin \
  ../..

make -j4
