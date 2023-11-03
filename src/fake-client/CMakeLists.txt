cmake_minimum_required(VERSION 3.5)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(r-type_fake_client VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB SOURCES "*.cpp" "*/**.cpp")
add_executable(FakeClient ${SOURCES})

target_link_libraries(FakeClient PRIVATE Network)
target_include_directories(FakeClient PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
