cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
project(Zeta
        VERSION 0.1.0
        LANGUAGES C
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(libs)

SET(ZETA_LIBS_LINK
        Anvil
        raylib
)

set(ZETA_LIBS_INCLUDE
        ${CMAKE_SOURCE_DIR}/libs/clay
        ${CMAKE_SOURCE_DIR}/include
        ${Anvil_SOURCE_DIR}/include
        ${raylib_Build_DIR}/src
)

set(ZETA_LIBS_SOURCES

)

set(ZETA_SOURCES
        src/test_deps.c
        src/clay_raylib_renderer.c
        include/clay_raylib_renderer.h
)

list(APPEND ZETA_SOURCES ${ZETA_LIBS_SOURCES})

add_executable(${PROJECT_NAME} ${ZETA_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC ${ZETA_LIBS_INCLUDE})
target_link_libraries(${PROJECT_NAME} PUBLIC ${ZETA_LIBS_LINK})

if (WIN32)
    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Anvil>
            ${CMAKE_BINARY_DIR}
            COMMENT "Copying Anvil to source directory for Windows"
    )

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:raylib>
            ${CMAKE_BINARY_DIR}
            COMMENT "Copying raylib to source directory for Windows"
    )
endif ()