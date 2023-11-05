cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(r-type)

cmake_policy(SET CMP0077 NEW)

set(FETCHCONTENT_QUIET FALSE)
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

set(BOOST_ROOT ${boost_SOURCE_DIR})

add_subdirectory(src/engine)
add_subdirectory(src/game)
add_subdirectory(src/network)
add_subdirectory(src/fake-client)
add_subdirectory(src/client)
add_subdirectory(src/server)

set(CPACK_PACKAGE_NAME "r-type")
set(CPACK_PACKAGE_VENDOR "Alexandre Inc.")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "R-Type Package")

if(WIN32)
    set(CPACK_GENERATOR "NSIS")
    set(CPACK_PACKAGE_INSTALL_DIRECTORY "r-type")
elseif(APPLE)
    set(CPACK_GENERATOR "DragNDrop")
elseif(UNIX)
    set(CPACK_GENERATOR "DEB;RPM")
    set(CPACK_PACKAGE_CONTACT "alexandre.frede.pro@gmail.com")
    set(CPACK_DEBIAN_PACKAGE_DEPENDS)
endif()

include(CPack)