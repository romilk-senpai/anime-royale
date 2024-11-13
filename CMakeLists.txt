cmake_minimum_required(VERSION 3.10)
project(anime-royale C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# rcds
set(RCDS_PATH ${CMAKE_SOURCE_DIR}/librcds)
include_directories(${RCDS_PATH}/include)
link_directories(${RCDS_PATH}/lib)

# Core library
file(GLOB_RECURSE CORE_SOURCES "src/core/*.c")
add_library(core STATIC ${CORE_SOURCES})

target_include_directories(core PUBLIC src/core)

file(GLOB_RECURSE GAME_SOURCES "src/game/*.c")

add_executable(anime-royale ${GAME_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC src/game)
target_include_directories(${PROJECT_NAME} PUBLIC src/core)

if(EMSCRIPTEN)
    set(CMAKE_C_COMPILER emcc)
    # include_directories("~/projects/emsdk/upstream/emscripten/system/include/SDL/")
    add_compile_definitions("__EMSCRIPTEN__")
    target_link_options(${PROJECT_NAME} PRIVATE
        "-sWASM=1"
        "-s ASSERTIONS=2"
        "-sUSE_SDL=2"
        "-sUSE_SDL_IMAGE=2"
        "-sALLOW_MEMORY_GROWTH=1"
        "-O2"
    )
    add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy
                ${CMAKE_SOURCE_DIR}/index.html
                ${CMAKE_BINARY_DIR}/index.html
        )
endif()

target_link_libraries(core rcds)
target_link_libraries(${PROJECT_NAME} core SDL2 SDL2_image m rcds)

