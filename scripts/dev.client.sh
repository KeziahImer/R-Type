#!/bin/bash

cd "$(dirname "$0")"

./genunix.gcc.sh

mkdir -p tmpclient

tar -xzvf ../out/client.unix.gcc.tar.gz  -C ./tmpclient

cd tmpclient

./r-type_client

cd ../

rm -rf ./tmpclient
