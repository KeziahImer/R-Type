cmake_minimum_required(VERSION 3.0)

project(
  r-type_client
  VERSION 0.1.0
  DESCRIPTION "R-type client"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY "https://github.com/SFML/SFML.git"
  GIT_TAG        2.6.x
)

FetchContent_MakeAvailable(SFML)

file(GLOB_RECURSE SOURCE_FILES *.cpp)

add_executable(r-type_client ${SOURCE_FILES})

target_link_libraries(r-type_client PRIVATE sfml-graphics sfml-window sfml-system)
