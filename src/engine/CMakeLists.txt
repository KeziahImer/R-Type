cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(r-type_engine VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp" "*/**.cpp")
add_library(RNGine STATIC ${SOURCES})

target_include_directories(RNGine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
