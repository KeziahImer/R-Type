$currentScriptDirectory = Split-Path -Parent $MyInvocation.MyCommand.Definition
Set-Location $currentScriptDirectory/..

cmake -B .\build -DCMAKE_CXX_COMPILER=cl -DCMAKE_C_COMPILER=cl -DCMAKE_BUILD_TYPE=Release -S .
cmake --build .\build --config Release
Set-Location .\build
cpack
