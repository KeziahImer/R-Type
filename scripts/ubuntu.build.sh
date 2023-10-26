#!/bin/bash

cd "$(dirname "$0")"/..

docker build -t r-type-ubuntu-build . -f ./containers/build/Dockerfile.Ubuntu

docker run -v ./build/containers/ubuntu:/r-type/build r-type-ubuntu-build
