cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(r-type_client VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp" "*/**.cpp")
add_executable(R-type ${SOURCES})

target_link_libraries(R-type PRIVATE RNGine Rtype raylib Network)
target_include_directories(R-type PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

install(TARGETS R-type DESTINATION .)
install(DIRECTORY assets DESTINATION .)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR})
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Debug)
file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/assets DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Release)
