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
CMAKE_SOURCE_DIR = /home/outisli/Documents/LCTHW/33

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/outisli/Documents/LCTHW/33/build

# Include any dependencies generated for this target.
include CMakeFiles/list_algos_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/list_algos_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/list_algos_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/list_algos_test.dir/flags.make

CMakeFiles/list_algos_test.dir/list.c.o: CMakeFiles/list_algos_test.dir/flags.make
CMakeFiles/list_algos_test.dir/list.c.o: ../list.c
CMakeFiles/list_algos_test.dir/list.c.o: CMakeFiles/list_algos_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/outisli/Documents/LCTHW/33/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/list_algos_test.dir/list.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/list_algos_test.dir/list.c.o -MF CMakeFiles/list_algos_test.dir/list.c.o.d -o CMakeFiles/list_algos_test.dir/list.c.o -c /home/outisli/Documents/LCTHW/33/list.c

CMakeFiles/list_algos_test.dir/list.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/list_algos_test.dir/list.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/outisli/Documents/LCTHW/33/list.c > CMakeFiles/list_algos_test.dir/list.c.i

CMakeFiles/list_algos_test.dir/list.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/list_algos_test.dir/list.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/outisli/Documents/LCTHW/33/list.c -o CMakeFiles/list_algos_test.dir/list.c.s

CMakeFiles/list_algos_test.dir/list_algos.c.o: CMakeFiles/list_algos_test.dir/flags.make
CMakeFiles/list_algos_test.dir/list_algos.c.o: ../list_algos.c
CMakeFiles/list_algos_test.dir/list_algos.c.o: CMakeFiles/list_algos_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/outisli/Documents/LCTHW/33/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/list_algos_test.dir/list_algos.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/list_algos_test.dir/list_algos.c.o -MF CMakeFiles/list_algos_test.dir/list_algos.c.o.d -o CMakeFiles/list_algos_test.dir/list_algos.c.o -c /home/outisli/Documents/LCTHW/33/list_algos.c

CMakeFiles/list_algos_test.dir/list_algos.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/list_algos_test.dir/list_algos.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/outisli/Documents/LCTHW/33/list_algos.c > CMakeFiles/list_algos_test.dir/list_algos.c.i

CMakeFiles/list_algos_test.dir/list_algos.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/list_algos_test.dir/list_algos.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/outisli/Documents/LCTHW/33/list_algos.c -o CMakeFiles/list_algos_test.dir/list_algos.c.s

CMakeFiles/list_algos_test.dir/list_algos_test.c.o: CMakeFiles/list_algos_test.dir/flags.make
CMakeFiles/list_algos_test.dir/list_algos_test.c.o: ../list_algos_test.c
CMakeFiles/list_algos_test.dir/list_algos_test.c.o: CMakeFiles/list_algos_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/outisli/Documents/LCTHW/33/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/list_algos_test.dir/list_algos_test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/list_algos_test.dir/list_algos_test.c.o -MF CMakeFiles/list_algos_test.dir/list_algos_test.c.o.d -o CMakeFiles/list_algos_test.dir/list_algos_test.c.o -c /home/outisli/Documents/LCTHW/33/list_algos_test.c

CMakeFiles/list_algos_test.dir/list_algos_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/list_algos_test.dir/list_algos_test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/outisli/Documents/LCTHW/33/list_algos_test.c > CMakeFiles/list_algos_test.dir/list_algos_test.c.i

CMakeFiles/list_algos_test.dir/list_algos_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/list_algos_test.dir/list_algos_test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/outisli/Documents/LCTHW/33/list_algos_test.c -o CMakeFiles/list_algos_test.dir/list_algos_test.c.s

# Object files for target list_algos_test
list_algos_test_OBJECTS = \
"CMakeFiles/list_algos_test.dir/list.c.o" \
"CMakeFiles/list_algos_test.dir/list_algos.c.o" \
"CMakeFiles/list_algos_test.dir/list_algos_test.c.o"

# External object files for target list_algos_test
list_algos_test_EXTERNAL_OBJECTS =

list_algos_test: CMakeFiles/list_algos_test.dir/list.c.o
list_algos_test: CMakeFiles/list_algos_test.dir/list_algos.c.o
list_algos_test: CMakeFiles/list_algos_test.dir/list_algos_test.c.o
list_algos_test: CMakeFiles/list_algos_test.dir/build.make
list_algos_test: CMakeFiles/list_algos_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/outisli/Documents/LCTHW/33/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable list_algos_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/list_algos_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/list_algos_test.dir/build: list_algos_test
.PHONY : CMakeFiles/list_algos_test.dir/build

CMakeFiles/list_algos_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/list_algos_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/list_algos_test.dir/clean

CMakeFiles/list_algos_test.dir/depend:
	cd /home/outisli/Documents/LCTHW/33/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/outisli/Documents/LCTHW/33 /home/outisli/Documents/LCTHW/33 /home/outisli/Documents/LCTHW/33/build /home/outisli/Documents/LCTHW/33/build /home/outisli/Documents/LCTHW/33/build/CMakeFiles/list_algos_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/list_algos_test.dir/depend

