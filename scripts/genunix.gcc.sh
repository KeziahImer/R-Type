#!/bin/bash

cd "$(dirname "$0")" && cd ..

cmake -B ./build -DCMAKE_CXX_COMPILER=g++ -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Release -S ./

cmake --build ./build --config Release

echo "Bundling client..."
mkdir -p tmp

cp ./client/assets ./tmp/assets -r
cp ./scenes ./tmp/scenes -r
cp ./build/client/r-type_client ./tmp/r-type_client

mkdir -p out
tar -czvf ./out/client.unix.gcc.tar.gz -C ./tmp/ . >/dev/null

echo "Client bundled"

rm -rf ./tmp