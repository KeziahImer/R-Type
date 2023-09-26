cmake_minimum_required(VERSION 3.0)

project(
  r-type_client
  VERSION 0.1.0
  DESCRIPTION "R-type client"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)
set(FETCHCONTENT_QUIET FALSE)

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY "https://github.com/SFML/SFML.git"
  GIT_PROGRESS TRUE
  GIT_SHALLOW TRUE
  GIT_TAG        2.6.x
)

FetchContent_MakeAvailable(SFML)

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_PROGRESS TRUE
  GIT_SHALLOW TRUE
  GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(json)

file(GLOB_RECURSE SOURCE_FILES *.cpp)

add_executable(r-type_client ${SOURCE_FILES})

target_link_libraries(r-type_client PRIVATE sfml-graphics sfml-window sfml-system nlohmann_json::nlohmann_json)
