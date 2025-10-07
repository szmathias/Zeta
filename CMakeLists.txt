cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(Zeta VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(libs)

add_executable(${PROJECT_NAME} src/test_deps.c)

if(WIN32)

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:Anvil>
            ${CMAKE_BINARY_DIR}
            COMMENT "Copying Anvil.dll to tests directory for Windows")

    add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
            $<TARGET_FILE:SDL3-shared>
            ${CMAKE_BINARY_DIR}
            COMMENT "Copying SDL3.dll to tests directory for Windows")
endif ()


target_include_directories(${PROJECT_NAME} PUBLIC ${clay_SOURCE_DIR} ${Anvil_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PUBLIC Anvil SDL3::SDL3-shared)