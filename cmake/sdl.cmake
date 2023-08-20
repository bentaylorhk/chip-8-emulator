# Benjamin Michael Taylor (bentaylorhk)
# 2023

include(ExternalProject)

ExternalProject_Add(
        SDL2
        GIT_REPOSITORY "https://github.com/libsdl-org/SDL.git"
        GIT_TAG "main"
)