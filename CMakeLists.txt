cmake_minimum_required(VERSION 3.10)
project(anime-royale C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_COMPILER clang)

# SDL2 installation path (local directory)
set(SDL2_PATH ${CMAKE_SOURCE_DIR}/SDL2-2.30.9)

# Add SDL2 include directories
include_directories(${SDL2_PATH}/include)

# Add SDL2 library directories
link_directories(${SDL2_PATH}/lib)

# Add your source files
file(GLOB_RECURSE SOURCES "src/*.c" "src/**/*.c")

# Add executable
add_executable(anime-royale ${SOURCES})

# Link the SDL2 library
target_link_libraries(anime-royale SDL2)

