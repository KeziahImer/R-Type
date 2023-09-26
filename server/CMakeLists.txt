cmake_minimum_required(VERSION 3.0)

project(
  r-type_server
  VERSION 0.1.0
  DESCRIPTION "R-type Server"
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(BOOST_INCLUDE_LIBRARIES asio)
set(BOOST_ENABLE_CMAKE ON)

include(FetchContent)

FetchContent_Declare(
  Boost
  GIT_REPOSITORY https://github.com/boostorg/boost.git
  GIT_TAG boost-1.83.0
)
FetchContent_MakeAvailable(Boost)

file(GLOB_RECURSE SOURCE_FILES *.cpp)

add_executable(r-type_server ${SOURCE_FILES})

target_link_libraries(r-type_server PRIVATE Boost::asio)
