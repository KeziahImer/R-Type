cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(r-type_client VERSION 1.0 LANGUAGES CXX)

cmake_policy(SET CMP0077 NEW)

set(FETCHCONTENT_QUIET FALSE)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(BOOST_INCLUDE_LIBRARIES asio)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)

FetchContent_Declare(
  raylib
  GIT_REPOSITORY https://github.com/raysan5/raylib.git
  GIT_TAG 4.5.0
  GIT_PROGRESS TRUE
  GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(raylib)

FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.83.0
  GIT_PROGRESS TRUE
  GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(Boost)

file(GLOB SOURCES "*.cpp" "*/**.cpp")
add_executable(R-type ${SOURCES})

target_link_libraries(R-type PRIVATE RNGine Rtype raylib Boost::asio)
target_include_directories(R-type PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS R-type DESTINATION .)
install(DIRECTORY assets DESTINATION .)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
