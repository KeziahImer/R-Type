#!/bin/bash

cd "$(dirname "$0")"

echo "Extracting server..."
mkdir -p tmpserver

tar -xzvf ../out/server.unix.gcc.tar.gz  -C ./tmpserver >/dev/null

cd tmpserver

echo "Executing server..."
./r-type_server

cd ../

rm -rf ./tmpserver
