# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.23.0/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.23.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix

# Include any dependencies generated for this target.
include CMakeFiles/Parser_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Parser_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Parser_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Parser_test.dir/flags.make

CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o: CMakeFiles/Parser_test.dir/flags.make
CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o: Tests/Parset_test/Parser_test.cpp
CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o: CMakeFiles/Parser_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o -MF CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o.d -o CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o -c /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix/Tests/Parset_test/Parser_test.cpp

CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix/Tests/Parset_test/Parser_test.cpp > CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.i

CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix/Tests/Parset_test/Parser_test.cpp -o CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.s

# Object files for target Parser_test
Parser_test_OBJECTS = \
"CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o"

# External object files for target Parser_test
Parser_test_EXTERNAL_OBJECTS =

Parser_test: CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o
Parser_test: CMakeFiles/Parser_test.dir/build.make
Parser_test: lib/libgtest_main.a
Parser_test: lib/libgtest.a
Parser_test: CMakeFiles/Parser_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Parser_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Parser_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Parser_test.dir/build: Parser_test
.PHONY : CMakeFiles/Parser_test.dir/build

CMakeFiles/Parser_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Parser_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Parser_test.dir/clean

CMakeFiles/Parser_test.dir/depend:
	cd /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix/CMakeFiles/Parser_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Parser_test.dir/depend

