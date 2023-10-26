cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(r-type_game VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp" "*/**.cpp")
add_library(Rtype STATIC ${SOURCES})
target_link_libraries(Rtype PUBLIC RNGine)

target_include_directories(Rtype PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
