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
        "-sMODULARIZE=1"
        "-sEXPORT_NAME='Main'"
        "-sINVOKE_RUN=0"
        "-sEXPORTED_FUNCTIONS=['_main']"
        "-sEXPORTED_RUNTIME_METHODS=['callMain', 'ccall', 'cwrap']"
        "-sFORCE_FILESYSTEM=1"
        "-sUSE_SDL=2"
        "-sALLOW_MEMORY_GROWTH=1"
        "-sASYNCIFY"
        "-sDISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR"
        "--use-port=sdl2_image:formats=png"
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

