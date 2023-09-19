cmake_minimum_required(VERSION 3.21.0)
include(FetchContent)

project(r-type_client VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../"${PROJECT_SOURCE_DIR}")

FetchContent_Declare(
  sfml
  GIT_REPOSITORY "https://github.com/SFML/SFML.git"
  GIT_TAG        2.6.x
)

set(SFML_BUILD_EXAMPLES OFF)
set(SFML_BUILD_DOC OFF)
set(SFML_BUILD_NETWORK OFF)
set(SFML_BUILD_AUDIO ON)
set(SFML_BUILD_GRAPHICS ON)
set(SFML_BUILD_WINDOW ON)

FetchContent_MakeAvailable(sfml)

file(GLOB_RECURSE SOURCES *.cpp)

add_executable(r-type_client ${SOURCES})

target_link_libraries(
    r-type_client
  sfml-graphics
  sfml-window
  sfml-system
  sfml-audio
)
