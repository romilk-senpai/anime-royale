cmake_minimum_required(VERSION 3.10)
project(anime-royale C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Default to native build unless Emscripten is specified
if(EMSCRIPTEN)
    set(CMAKE_C_COMPILER emcc)
    # Use the Emscripten toolchain for WebAssembly
    set(CMAKE_TOOLCHAIN_FILE "~/projects/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake")

    # WebAssembly specific flags
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s WASM=1 -s USE_SDL=2 -O3")  # Add any additional flags for WASM
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -s EXPORTED_FUNCTIONS='[\"_main\"]' -s EXTRA_EXPORTED_RUNTIME_METHODS='[\"ccall\", \"cwrap\"]'")
else()
    set(CMAKE_C_COMPILER clang)
    # Native build settings (e.g., for Linux or macOS)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O2")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -L/usr/local/lib")  # Example for native linking
endif()

# rcds
set(RCDS_PATH ${CMAKE_SOURCE_DIR}/librcds)
include_directories(${RCDS_PATH}/include)
link_directories(${RCDS_PATH}/lib)

# Core library
file(GLOB_RECURSE CORE_SOURCES "src/core/*.c")
add_library(core STATIC ${CORE_SOURCES})

file(GLOB_RECURSE GAME_SOURCES "src/game/*.c")

add_executable(anime-royale ${GAME_SOURCES})

target_link_libraries(core rcds)
target_link_libraries(anime-royale core SDL2 SDL2_image m rcds)

target_include_directories(core PUBLIC src/core)
target_include_directories(anime-royale PUBLIC src/game)

if(EMSCRIPTEN)
	# Set the target to be a web environment
    set_target_properties(anime-royale PROPERTIES LINK_FLAGS "-s WASM=1")
endif()

