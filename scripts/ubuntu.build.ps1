$currentScriptDirectory = Split-Path -Parent $MyInvocation.MyCommand.Definition
Set-Location $currentScriptDirectory/..

docker build -t r-type-ubuntu-build -f ./containers/build/Dockerfile.Ubuntu .
docker run -it -v ${PWD}/build/containers/ubuntu:/home/r-type/build r-type-ubuntu-build
