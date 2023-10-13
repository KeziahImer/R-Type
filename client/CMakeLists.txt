cmake_minimum_required(VERSION 3.0)

project(
  r-type_client
  VERSION 0.1.0
  DESCRIPTION "R-type client"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

include_directories(
    ${CMAKE_SOURCE_DIR}/
)

include(FetchContent)

set(SFML_BUILD_SHARED_LIBS TRUE)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY "https://github.com/SFML/SFML.git"
  GIT_PROGRESS TRUE
  GIT_SHALLOW TRUE
  GIT_TAG        2.6.x
)

FetchContent_MakeAvailable(SFML)

set(JSON_BuildTests OFF CACHE INTERNAL "")
set(JSON_Install OFF CACHE INTERNAL "")

FetchContent_Declare(
  json
  GIT_REPOSITORY https://github.com/nlohmann/json.git
  GIT_PROGRESS TRUE
  GIT_SHALLOW TRUE
  GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(json)

include_directories(include)

file(GLOB_RECURSE SOURCE_FILES *.cpp)

add_executable(r-type_client ${SOURCE_FILES})

target_link_libraries(r-type_client PRIVATE sfml-graphics sfml-window sfml-system nlohmann_json::nlohmann_json Boost::asio)

if(WIN32)
  add_custom_command(
      TARGET r-type_client
      POST_BUILD
      COMMAND ${CMAKE_COMMAND} -E copy
          "${SFML_BINARY_DIR}/lib/Release/sfml-window-2.dll"
          "${SFML_BINARY_DIR}/lib/Release/sfml-graphics-2.dll"
          "${SFML_BINARY_DIR}/lib/Release/sfml-system-2.dll"
          "$<TARGET_FILE_DIR:r-type_client>"
  )
endif()
