# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/a/Desktop/clion-2020.1/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/a/Desktop/clion-2020.1/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/a/CLionProjects/vaseis 2 ergasia 3"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/sort.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sort.dir/flags.make

CMakeFiles/sort.dir/examples/sort_main.c.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/examples/sort_main.c.o: ../examples/sort_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sort.dir/examples/sort_main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.dir/examples/sort_main.c.o   -c "/home/a/CLionProjects/vaseis 2 ergasia 3/examples/sort_main.c"

CMakeFiles/sort.dir/examples/sort_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.dir/examples/sort_main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/a/CLionProjects/vaseis 2 ergasia 3/examples/sort_main.c" > CMakeFiles/sort.dir/examples/sort_main.c.i

CMakeFiles/sort.dir/examples/sort_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.dir/examples/sort_main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/a/CLionProjects/vaseis 2 ergasia 3/examples/sort_main.c" -o CMakeFiles/sort.dir/examples/sort_main.c.s

CMakeFiles/sort.dir/src/record.c.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/src/record.c.o: ../src/record.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/sort.dir/src/record.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.dir/src/record.c.o   -c "/home/a/CLionProjects/vaseis 2 ergasia 3/src/record.c"

CMakeFiles/sort.dir/src/record.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.dir/src/record.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/a/CLionProjects/vaseis 2 ergasia 3/src/record.c" > CMakeFiles/sort.dir/src/record.c.i

CMakeFiles/sort.dir/src/record.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.dir/src/record.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/a/CLionProjects/vaseis 2 ergasia 3/src/record.c" -o CMakeFiles/sort.dir/src/record.c.s

CMakeFiles/sort.dir/src/chunk.c.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/src/chunk.c.o: ../src/chunk.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/sort.dir/src/chunk.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.dir/src/chunk.c.o   -c "/home/a/CLionProjects/vaseis 2 ergasia 3/src/chunk.c"

CMakeFiles/sort.dir/src/chunk.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.dir/src/chunk.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/a/CLionProjects/vaseis 2 ergasia 3/src/chunk.c" > CMakeFiles/sort.dir/src/chunk.c.i

CMakeFiles/sort.dir/src/chunk.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.dir/src/chunk.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/a/CLionProjects/vaseis 2 ergasia 3/src/chunk.c" -o CMakeFiles/sort.dir/src/chunk.c.s

CMakeFiles/sort.dir/src/merge.c.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/src/merge.c.o: ../src/merge.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/sort.dir/src/merge.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.dir/src/merge.c.o   -c "/home/a/CLionProjects/vaseis 2 ergasia 3/src/merge.c"

CMakeFiles/sort.dir/src/merge.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.dir/src/merge.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/a/CLionProjects/vaseis 2 ergasia 3/src/merge.c" > CMakeFiles/sort.dir/src/merge.c.i

CMakeFiles/sort.dir/src/merge.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.dir/src/merge.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/a/CLionProjects/vaseis 2 ergasia 3/src/merge.c" -o CMakeFiles/sort.dir/src/merge.c.s

CMakeFiles/sort.dir/src/sort.c.o: CMakeFiles/sort.dir/flags.make
CMakeFiles/sort.dir/src/sort.c.o: ../src/sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/sort.dir/src/sort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/sort.dir/src/sort.c.o   -c "/home/a/CLionProjects/vaseis 2 ergasia 3/src/sort.c"

CMakeFiles/sort.dir/src/sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sort.dir/src/sort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/a/CLionProjects/vaseis 2 ergasia 3/src/sort.c" > CMakeFiles/sort.dir/src/sort.c.i

CMakeFiles/sort.dir/src/sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sort.dir/src/sort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/a/CLionProjects/vaseis 2 ergasia 3/src/sort.c" -o CMakeFiles/sort.dir/src/sort.c.s

# Object files for target sort
sort_OBJECTS = \
"CMakeFiles/sort.dir/examples/sort_main.c.o" \
"CMakeFiles/sort.dir/src/record.c.o" \
"CMakeFiles/sort.dir/src/chunk.c.o" \
"CMakeFiles/sort.dir/src/merge.c.o" \
"CMakeFiles/sort.dir/src/sort.c.o"

# External object files for target sort
sort_EXTERNAL_OBJECTS =

sort: CMakeFiles/sort.dir/examples/sort_main.c.o
sort: CMakeFiles/sort.dir/src/record.c.o
sort: CMakeFiles/sort.dir/src/chunk.c.o
sort: CMakeFiles/sort.dir/src/merge.c.o
sort: CMakeFiles/sort.dir/src/sort.c.o
sort: CMakeFiles/sort.dir/build.make
sort: CMakeFiles/sort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable sort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sort.dir/build: sort

.PHONY : CMakeFiles/sort.dir/build

CMakeFiles/sort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sort.dir/clean

CMakeFiles/sort.dir/depend:
	cd "/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/a/CLionProjects/vaseis 2 ergasia 3" "/home/a/CLionProjects/vaseis 2 ergasia 3" "/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug" "/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug" "/home/a/CLionProjects/vaseis 2 ergasia 3/cmake-build-debug/CMakeFiles/sort.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/sort.dir/depend
