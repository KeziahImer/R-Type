$scriptDir = Split-Path -Parent $MyInvocation.MyCommand.Definition

Set-Location -Path $scriptDir\..

cmake -B ./build/win/cl -DCMAKE_CXX_COMPILER=cl -DCMAKE_C_COMPILER=cl -DCMAKE_BUILD_TYPE=Release -S ./

cmake --build ./build/win/cl --config Release
