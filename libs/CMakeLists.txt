include(FetchContent)

FetchContent_Declare(
        Anvil
        GIT_REPOSITORY https://github.com/szmathias/Anvil.git
        GIT_TAG main
        GIT_SHALLOW TRUE
)

set(ANV_BUILD_EXAMPLES OFF)
set(ANV_BUILD_TESTS OFF)
set(ANV_BUILD_SHARED_LIBS ON)
set(ANV_ENABLE_SANITIZERS OFF)

FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib
        GIT_TAG 5.5
        GIT_SHALLOW TRUE
)
set(BUILD_EXAMPLES OFF)
set(CUSTOMIZE_BUILD OFF)
set(BUILD_SHARED_LIBS ON)

FetchContent_MakeAvailable(Anvil raylib)