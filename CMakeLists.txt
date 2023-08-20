# Benjamin Michael Taylor (bentaylorhk)
# 2023

cmake_minimum_required(VERSION 3.20)

project(
        chip-8-emulator
        VERSION 1.0
        DESCRIPTION "CPP Emulator for CHIP-8"
)

set(CMAKE_CXX_STANDARD 20)

include(cmake/targets.cmake)

add_subdirectory(src)