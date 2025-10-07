include(FetchContent)

FetchContent_Declare(
        Anvil
        GIT_REPOSITORY https://github.com/szmathias/Anvil.git
        GIT_TAG main
        GIT_SHALLOW TRUE
)

set(ANV_BUILD_EXAMPLES OFF)
set(ANV_BUILD_TESTS OFF)

FetchContent_Declare(
        clay
        GIT_REPOSITORY https://github.com/nicbarker/clay
        GIT_TAG main
        GIT_SHALLOW TRUE
)
set(CLAY_INCLUDE_ALL_EXAMPLES OFF)
set(CLAY_INCLUDE_SDL3_EXAMPLES ON)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL
        GIT_TAG release-3.2.24
)


FetchContent_MakeAvailable(Anvil clay SDL3)