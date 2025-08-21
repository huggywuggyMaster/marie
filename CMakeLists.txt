cmake_minimum_required(VERSION 3.10.0)
project(marie VERSION 0.1.0 LANGUAGES C CXX)

include_directories(src)

if (WIN32)
    set(WINDOWS ON)
    add_compile_definitions(MARIE_PLATFORM_WINDOWS)
    add_executable(marie WIN32 src/main/win32_main.cpp)
endif()

add_subdirectory(${CMAKE_SOURCE_DIR}/src/platform)

target_link_libraries(marie PRIVATE platform)