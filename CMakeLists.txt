cmake_minimum_required(VERSION 3.16 FATAL_ERROR)
project(Zeta VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_subdirectory(libs)

add_executable(Zeta src/test_deps.c)

target_include_directories(Zeta PRIVATE ${clay_SOURCE_DIR})

target_link_libraries(Zeta PRIVATE Anvil clay)