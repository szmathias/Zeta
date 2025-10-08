cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project(Zeta
        VERSION 0.1.0
        LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

set(ZETA_BUILD_SHARED_LIBS ON CACHE BOOL "Build shared libraries")

add_subdirectory(libs)

set(ZETA_RESOURCES
        resources/Roboto-Regular.ttf
        resources/sample.png
)

SET(ZETA_LIBS_LINK
        Anvil
        SDL3::SDL3
        SDL3_ttf::SDL3_ttf
        SDL3_image::SDL3_image
)

set(ZETA_LIBS_INCLUDE
        ${CMAKE_SOURCE_DIR}/libs/clay
        ${CMAKE_SOURCE_DIR}/include
        ${Anvil_SOURCE_DIR}/include
        ${SDL3_SOURCE_DIR}/include
        ${SDL3_ttf_SOURCE_DIR}/include
        ${SDL3_image_SOURCE_DIR}/include
)

set(ZETA_LIBS_SOURCES
        src/clay_sdl_renderer.c
)

set(ZETA_SOURCES
        src/test_deps.c
        src/clay_sdl_renderer.c
        include/clay_sdl_renderer.h
)

list(APPEND ZETA_SOURCES ${ZETA_LIBS_SOURCES})

add_executable(${PROJECT_NAME} ${ZETA_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${ZETA_LIBS_INCLUDE})
target_link_libraries(${PROJECT_NAME} PUBLIC ${ZETA_LIBS_LINK})

add_custom_command(TARGET ${PROJECT_NAME} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources
        $<TARGET_FILE_DIR:${PROJECT_NAME}>/resources
        COMMENT "Copying resource files"
)

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Anvil>
            ${CMAKE_BINARY_DIR}
            COMMENT "Copying Anvil to source directory for Windows"
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL3::SDL3>
            ${CMAKE_BINARY_DIR}
            COMMENT "Copying SDL3 to source directory for Windows"
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL3_ttf::SDL3_ttf>
            ${CMAKE_BINARY_DIR}
            COMMENT "Copying SDL3_ttf to source directory for Windows"
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL3_image::SDL3_image>
            ${CMAKE_BINARY_DIR}
            COMMENT "Copying SDL3_image to source directory for Windows"
    )
endif ()