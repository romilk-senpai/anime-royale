# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/runner/work/anime-royale/anime-royale

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/runner/work/anime-royale/anime-royale/build-wasm

# Include any dependencies generated for this target.
include CMakeFiles/core.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/core.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/core.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/core.dir/flags.make

CMakeFiles/core.dir/src/core/camera.c.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/core/camera.c.o: ../src/core/camera.c
CMakeFiles/core.dir/src/core/camera.c.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/core.dir/src/core/camera.c.o"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/core.dir/src/core/camera.c.o -MF CMakeFiles/core.dir/src/core/camera.c.o.d -o CMakeFiles/core.dir/src/core/camera.c.o -c /home/runner/work/anime-royale/anime-royale/src/core/camera.c

CMakeFiles/core.dir/src/core/camera.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/src/core/camera.c.i"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/runner/work/anime-royale/anime-royale/src/core/camera.c > CMakeFiles/core.dir/src/core/camera.c.i

CMakeFiles/core.dir/src/core/camera.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/src/core/camera.c.s"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/runner/work/anime-royale/anime-royale/src/core/camera.c -o CMakeFiles/core.dir/src/core/camera.c.s

CMakeFiles/core.dir/src/core/game.c.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/core/game.c.o: ../src/core/game.c
CMakeFiles/core.dir/src/core/game.c.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/core.dir/src/core/game.c.o"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/core.dir/src/core/game.c.o -MF CMakeFiles/core.dir/src/core/game.c.o.d -o CMakeFiles/core.dir/src/core/game.c.o -c /home/runner/work/anime-royale/anime-royale/src/core/game.c

CMakeFiles/core.dir/src/core/game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/src/core/game.c.i"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/runner/work/anime-royale/anime-royale/src/core/game.c > CMakeFiles/core.dir/src/core/game.c.i

CMakeFiles/core.dir/src/core/game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/src/core/game.c.s"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/runner/work/anime-royale/anime-royale/src/core/game.c -o CMakeFiles/core.dir/src/core/game.c.s

CMakeFiles/core.dir/src/core/gameobject.c.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/core/gameobject.c.o: ../src/core/gameobject.c
CMakeFiles/core.dir/src/core/gameobject.c.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/core.dir/src/core/gameobject.c.o"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/core.dir/src/core/gameobject.c.o -MF CMakeFiles/core.dir/src/core/gameobject.c.o.d -o CMakeFiles/core.dir/src/core/gameobject.c.o -c /home/runner/work/anime-royale/anime-royale/src/core/gameobject.c

CMakeFiles/core.dir/src/core/gameobject.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/src/core/gameobject.c.i"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/runner/work/anime-royale/anime-royale/src/core/gameobject.c > CMakeFiles/core.dir/src/core/gameobject.c.i

CMakeFiles/core.dir/src/core/gameobject.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/src/core/gameobject.c.s"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/runner/work/anime-royale/anime-royale/src/core/gameobject.c -o CMakeFiles/core.dir/src/core/gameobject.c.s

CMakeFiles/core.dir/src/core/go_min_heap.c.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/core/go_min_heap.c.o: ../src/core/go_min_heap.c
CMakeFiles/core.dir/src/core/go_min_heap.c.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/core.dir/src/core/go_min_heap.c.o"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/core.dir/src/core/go_min_heap.c.o -MF CMakeFiles/core.dir/src/core/go_min_heap.c.o.d -o CMakeFiles/core.dir/src/core/go_min_heap.c.o -c /home/runner/work/anime-royale/anime-royale/src/core/go_min_heap.c

CMakeFiles/core.dir/src/core/go_min_heap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/src/core/go_min_heap.c.i"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/runner/work/anime-royale/anime-royale/src/core/go_min_heap.c > CMakeFiles/core.dir/src/core/go_min_heap.c.i

CMakeFiles/core.dir/src/core/go_min_heap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/src/core/go_min_heap.c.s"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/runner/work/anime-royale/anime-royale/src/core/go_min_heap.c -o CMakeFiles/core.dir/src/core/go_min_heap.c.s

CMakeFiles/core.dir/src/core/go_pool.c.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/core/go_pool.c.o: ../src/core/go_pool.c
CMakeFiles/core.dir/src/core/go_pool.c.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/core.dir/src/core/go_pool.c.o"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/core.dir/src/core/go_pool.c.o -MF CMakeFiles/core.dir/src/core/go_pool.c.o.d -o CMakeFiles/core.dir/src/core/go_pool.c.o -c /home/runner/work/anime-royale/anime-royale/src/core/go_pool.c

CMakeFiles/core.dir/src/core/go_pool.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/src/core/go_pool.c.i"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/runner/work/anime-royale/anime-royale/src/core/go_pool.c > CMakeFiles/core.dir/src/core/go_pool.c.i

CMakeFiles/core.dir/src/core/go_pool.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/src/core/go_pool.c.s"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/runner/work/anime-royale/anime-royale/src/core/go_pool.c -o CMakeFiles/core.dir/src/core/go_pool.c.s

CMakeFiles/core.dir/src/core/input.c.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/core/input.c.o: ../src/core/input.c
CMakeFiles/core.dir/src/core/input.c.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/core.dir/src/core/input.c.o"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/core.dir/src/core/input.c.o -MF CMakeFiles/core.dir/src/core/input.c.o.d -o CMakeFiles/core.dir/src/core/input.c.o -c /home/runner/work/anime-royale/anime-royale/src/core/input.c

CMakeFiles/core.dir/src/core/input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/src/core/input.c.i"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/runner/work/anime-royale/anime-royale/src/core/input.c > CMakeFiles/core.dir/src/core/input.c.i

CMakeFiles/core.dir/src/core/input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/src/core/input.c.s"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/runner/work/anime-royale/anime-royale/src/core/input.c -o CMakeFiles/core.dir/src/core/input.c.s

CMakeFiles/core.dir/src/core/time.c.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/core/time.c.o: ../src/core/time.c
CMakeFiles/core.dir/src/core/time.c.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/core.dir/src/core/time.c.o"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/core.dir/src/core/time.c.o -MF CMakeFiles/core.dir/src/core/time.c.o.d -o CMakeFiles/core.dir/src/core/time.c.o -c /home/runner/work/anime-royale/anime-royale/src/core/time.c

CMakeFiles/core.dir/src/core/time.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/src/core/time.c.i"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/runner/work/anime-royale/anime-royale/src/core/time.c > CMakeFiles/core.dir/src/core/time.c.i

CMakeFiles/core.dir/src/core/time.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/src/core/time.c.s"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/runner/work/anime-royale/anime-royale/src/core/time.c -o CMakeFiles/core.dir/src/core/time.c.s

CMakeFiles/core.dir/src/core/vector2.c.o: CMakeFiles/core.dir/flags.make
CMakeFiles/core.dir/src/core/vector2.c.o: ../src/core/vector2.c
CMakeFiles/core.dir/src/core/vector2.c.o: CMakeFiles/core.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/core.dir/src/core/vector2.c.o"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/core.dir/src/core/vector2.c.o -MF CMakeFiles/core.dir/src/core/vector2.c.o.d -o CMakeFiles/core.dir/src/core/vector2.c.o -c /home/runner/work/anime-royale/anime-royale/src/core/vector2.c

CMakeFiles/core.dir/src/core/vector2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/core.dir/src/core/vector2.c.i"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/runner/work/anime-royale/anime-royale/src/core/vector2.c > CMakeFiles/core.dir/src/core/vector2.c.i

CMakeFiles/core.dir/src/core/vector2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/core.dir/src/core/vector2.c.s"
	emcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/runner/work/anime-royale/anime-royale/src/core/vector2.c -o CMakeFiles/core.dir/src/core/vector2.c.s

# Object files for target core
core_OBJECTS = \
"CMakeFiles/core.dir/src/core/camera.c.o" \
"CMakeFiles/core.dir/src/core/game.c.o" \
"CMakeFiles/core.dir/src/core/gameobject.c.o" \
"CMakeFiles/core.dir/src/core/go_min_heap.c.o" \
"CMakeFiles/core.dir/src/core/go_pool.c.o" \
"CMakeFiles/core.dir/src/core/input.c.o" \
"CMakeFiles/core.dir/src/core/time.c.o" \
"CMakeFiles/core.dir/src/core/vector2.c.o"

# External object files for target core
core_EXTERNAL_OBJECTS =

libcore.a: CMakeFiles/core.dir/src/core/camera.c.o
libcore.a: CMakeFiles/core.dir/src/core/game.c.o
libcore.a: CMakeFiles/core.dir/src/core/gameobject.c.o
libcore.a: CMakeFiles/core.dir/src/core/go_min_heap.c.o
libcore.a: CMakeFiles/core.dir/src/core/go_pool.c.o
libcore.a: CMakeFiles/core.dir/src/core/input.c.o
libcore.a: CMakeFiles/core.dir/src/core/time.c.o
libcore.a: CMakeFiles/core.dir/src/core/vector2.c.o
libcore.a: CMakeFiles/core.dir/build.make
libcore.a: CMakeFiles/core.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking C static library libcore.a"
	$(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/core.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/core.dir/build: libcore.a
.PHONY : CMakeFiles/core.dir/build

CMakeFiles/core.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/core.dir/cmake_clean.cmake
.PHONY : CMakeFiles/core.dir/clean

CMakeFiles/core.dir/depend:
	cd /home/runner/work/anime-royale/anime-royale/build-wasm && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/runner/work/anime-royale/anime-royale /home/runner/work/anime-royale/anime-royale /home/runner/work/anime-royale/anime-royale/build-wasm /home/runner/work/anime-royale/anime-royale/build-wasm /home/runner/work/anime-royale/anime-royale/build-wasm/CMakeFiles/core.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/core.dir/depend

