cmake_minimum_required(VERSION 3.0)

project(
  r-type_server
  VERSION 0.1.0
  DESCRIPTION "R-type Server"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB_RECURSE SOURCE_FILES *.cpp)

add_executable(r-type_server ${SOURCE_FILES})
