cmake_minimum_required(VERSION 3.13)
project(anime-royale C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

if(EMSCRIPTEN)
    set(CMAKE_C_COMPILER emcc)
endif()

# rcds
if(EMSCRIPTEN)
    set(RCDS_PATH ${CMAKE_SOURCE_DIR}/librcds-wasm)
else()
    set(RCDS_PATH ${CMAKE_SOURCE_DIR}/librcds)
endif()
include_directories(${RCDS_PATH}/include)
link_directories(${RCDS_PATH}/lib)

# Core library
add_subdirectory(core)

file(GLOB_RECURSE GAME_SOURCES "game/*.c")
add_executable(${PROJECT_NAME} ${GAME_SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC game)
target_include_directories(${PROJECT_NAME} PUBLIC core)

if(EMSCRIPTEN)
    add_compile_definitions("__EMSCRIPTEN__")
    target_link_options(${PROJECT_NAME} PRIVATE
        # "--bind"
        "-sWASM=1"
        # "-sMODULARIZE=1"
        # "-sEXPORT_NAME='Main'"
        # "-sINVOKE_RUN=0"
        # "-sEXPORTED_FUNCTIONS=['_main']"
        # "-sEXPORTED_RUNTIME_METHODS=['callMain', 'ccall', 'cwrap']"
        # "-sFORCE_FILESYSTEM=1"
        "--use-port=sdl2"
        "--use-port=sdl2_image:formats=png"
        "--use-port=sdl2_ttf"
        # "-sALLOW_MEMORY_GROWTH=1"
        # "-sASYNCIFY"
        # "-sDISABLE_DEPRECATED_FIND_EVENT_TARGET_BEHAVIOR=1"
        # "-O2"
    )
    target_link_options(${PROJECT_NAME} PRIVATE --preload-file assets)
    target_link_libraries(${PROJECT_NAME} core rcds)
else()
    target_link_libraries(${PROJECT_NAME} core rcds SDL2 SDL2_image SDL2_ttf m)
endif()
