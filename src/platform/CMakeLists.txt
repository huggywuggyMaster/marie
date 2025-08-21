set(PLATFORM_DIR ${CMAKE_SOURCE_DIR}/src/platform/private/)

if (WINDOWS)
    file(GLOB SRC ${PLATFORM_DIR}/win32/*.cpp)
    add_library(platform STATIC 
        ${SRC}
    )
endif()

include_directories(PRIVATE ${CMAKE_SOURCE_DIR}/private)