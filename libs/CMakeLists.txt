include(FetchContent)

FetchContent_Declare(
        Anvil
        GIT_REPOSITORY https://github.com/szmathias/Anvil.git
        GIT_TAG main
        GIT_SHALLOW TRUE
)
set(ANV_BUILD_EXAMPLES OFF)
set(ANV_BUILD_TESTS OFF)
set(ANV_ENABLE_SANITIZERS OFF)

FetchContent_Declare(
        SDL3
        GIT_REPOSITORY https://github.com/libsdl-org/SDL
        GIT_TAG release-3.2.24
        GIT_SHALLOW TRUE
)
set(SDL_TEST OFF)
set(SDL_EXAMPLES OFF)
set(SDL_HAPTIC OFF)
set(SDL_JOYSTICK OFF)
set(SDL_POWER OFF)
set(SDL_SENSOR OFF)
set(SDL_CAMERA OFF)
set(SDL_HIDAPI OFF)
set(SDL_DIALOG OFF)

FetchContent_Declare(
        SDL3_ttf
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_ttf
        GIT_TAG release-3.2.2
)
set(SDLTTF_SAMPLES OFF)


FETCHCONTENT_DECLARE(
        SDL3_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image
        GIT_TAG release-3.2.4
        GIT_SHALLOW TRUE
)
set(SDLIMAGE_SAMPLES OFF)
set(SDLIMAGE_TESTS OFF)


if(ZETA_BUILD_SHARED_LIBS)
    set(ANV_BUILD_STATIC_LIBS OFF)
    set(SDL_STATIC OFF)
    set(SDLTTF_BUILD_STATIC_LIBS OFF)
    set(SDLIMAGE_BUILD_STATIC_LIBS OFF)

    set(ANV_BUILD_SHARED_LIBS ON)
    set(SDL_SHARED ON)
    set(SDLTTF_BUILD_SHARED_LIBS ON)
    set(SDLIMAGE_BUILD_SHARED_LIBS ON)
else()
    set(ANV_BUILD_SHARED_LIBS OFF)
    set(SDL_SHARED OFF)
    set(SDLTTF_BUILD_SHARED_LIBS OFF)
    set(SDLIMAGE_BUILD_SHARED_LIBS OFF)

    set(ANV_BUILD_STATIC_LIBS ON)
    set(SDL_STATIC ON)
    set(SDLTTF_BUILD_STATIC_LIBS ON)
    set(SDLIMAGE_BUILD_STATIC_LIBS ON)
endif()


FetchContent_MakeAvailable(Anvil SDL3 SDL3_ttf SDL3_image)