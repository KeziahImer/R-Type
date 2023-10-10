#!/bin/bash

cd "$(dirname "$0")"

./genunix.gcc.sh

echo "Extracting client..."
mkdir -p tmpclient

tar -xzvf ../out/client.unix.gcc.tar.gz  -C ./tmpclient >/dev/null

cd tmpclient

echo "Executing client..."
./r-type_client

cd ../

rm -rf ./tmpclient
