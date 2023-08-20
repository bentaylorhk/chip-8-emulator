# Benjamin Michael Taylor (bentaylorhk)
# 2023

#include(${CMAKE_SOURCE_DIR}/cmake/sdl.cmake)

file (GLOB_RECURSE SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)

create_target(
        NAME "emulator"
        SOURCES ${SOURCES}
        INCLUDES ${CMAKE_CURRENT_SOURCE_DIR}
        SYSTEM_INCLUDES ${SDL2_INCLUDE_DIRS}
        PRIVATE_LIBS ${SDL2_LIBRARIES}
        EXECUTABLE
)