cmake_minimum_required(VERSION 3.10)
project(anime-royale C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER clang)

# SDL2
set(SDL2_PATH ${CMAKE_SOURCE_DIR}/SDL2-2.30.9)
include_directories(${SDL2_PATH}/include)
link_directories(${SDL2_PATH}/lib)

# rcds
set(RCDS_PATH ${CMAKE_SOURCE_DIR}/librcds)
include_directories(${RCDS_PATH}/include)
link_directories(${RCDS_PATH}/lib)

# Core library
file(GLOB_RECURSE CORE_SOURCES "src/core/*.c")
add_library(core STATIC ${CORE_SOURCES})

# Add main game source files
file(GLOB_RECURSE GAME_SOURCES "src/game/*.c")

# Add executable
add_executable(anime-royale ${GAME_SOURCES})

target_link_libraries(core rcds)
target_link_libraries(anime-royale core SDL2 m rcds)

target_include_directories(core PUBLIC src/core)
target_include_directories(anime-royale PUBLIC src/game)

