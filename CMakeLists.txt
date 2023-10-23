cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(r-type)

add_subdirectory(src/engine)
add_subdirectory(src/game)
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