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
CMAKE_SOURCE_DIR = "/home/akuma/lab/lab1/test 1"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/akuma/lab/lab1/test 1/build"

# Include any dependencies generated for this target.
include CMakeFiles/functions.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/functions.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/functions.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/functions.dir/flags.make

# Object files for target functions
functions_OBJECTS =

# External object files for target functions
functions_EXTERNAL_OBJECTS =

libfunctions.a: CMakeFiles/functions.dir/build.make
libfunctions.a: CMakeFiles/functions.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/akuma/lab/lab1/test 1/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libfunctions.a"
	$(CMAKE_COMMAND) -P CMakeFiles/functions.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/functions.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/functions.dir/build: libfunctions.a
.PHONY : CMakeFiles/functions.dir/build

CMakeFiles/functions.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/functions.dir/cmake_clean.cmake
.PHONY : CMakeFiles/functions.dir/clean

CMakeFiles/functions.dir/depend:
	cd "/home/akuma/lab/lab1/test 1/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/akuma/lab/lab1/test 1" "/home/akuma/lab/lab1/test 1" "/home/akuma/lab/lab1/test 1/build" "/home/akuma/lab/lab1/test 1/build" "/home/akuma/lab/lab1/test 1/build/CMakeFiles/functions.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/functions.dir/depend

