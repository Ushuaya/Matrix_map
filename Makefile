# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:

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

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/local/Cellar/cmake/3.23.0/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test
.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/Cellar/cmake/3.23.0/bin/ccmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/Cellar/cmake/3.23.0/bin/cmake --regenerate-during-build -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components
.PHONY : list_install_components/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.23.0/bin/cmake -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/local/Cellar/cmake/3.23.0/bin/cmake -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.23.0/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/local/Cellar/cmake/3.23.0/bin/cmake -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.23.0/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/local/Cellar/cmake/3.23.0/bin/cmake -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix/CMakeFiles /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix//CMakeFiles/progress.marks
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/volkseriy/Desktop/prac7sem/Task1/tmp/repos/Task_matrix/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named mtx_rally

# Build rule for target.
mtx_rally: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 mtx_rally
.PHONY : mtx_rally

# fast build rule for target.
mtx_rally/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/build
.PHONY : mtx_rally/fast

#=============================================================================
# Target rules for targets named Matrix_test

# Build rule for target.
Matrix_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Matrix_test
.PHONY : Matrix_test

# fast build rule for target.
Matrix_test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Matrix_test.dir/build.make CMakeFiles/Matrix_test.dir/build
.PHONY : Matrix_test/fast

#=============================================================================
# Target rules for targets named Parser_test

# Build rule for target.
Parser_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Parser_test
.PHONY : Parser_test

# fast build rule for target.
Parser_test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Parser_test.dir/build.make CMakeFiles/Parser_test.dir/build
.PHONY : Parser_test/fast

#=============================================================================
# Target rules for targets named Proxy_test

# Build rule for target.
Proxy_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Proxy_test
.PHONY : Proxy_test

# fast build rule for target.
Proxy_test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Proxy_test.dir/build.make CMakeFiles/Proxy_test.dir/build
.PHONY : Proxy_test/fast

#=============================================================================
# Target rules for targets named Ration_number_test

# Build rule for target.
Ration_number_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Ration_number_test
.PHONY : Ration_number_test

# fast build rule for target.
Ration_number_test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Ration_number_test.dir/build.make CMakeFiles/Ration_number_test.dir/build
.PHONY : Ration_number_test/fast

#=============================================================================
# Target rules for targets named Strint_test

# Build rule for target.
Strint_test: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 Strint_test
.PHONY : Strint_test

# fast build rule for target.
Strint_test/fast:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Strint_test.dir/build.make CMakeFiles/Strint_test.dir/build
.PHONY : Strint_test/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/build.make _deps/googletest-build/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/build.make _deps/googletest-build/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googletest/CMakeFiles/gtest.dir/build.make _deps/googletest-build/googletest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) $(MAKESILENT) -f _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/build.make _deps/googletest-build/googletest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

Tests/Matrix_test/Matrix_test.o: Tests/Matrix_test/Matrix_test.cpp.o
.PHONY : Tests/Matrix_test/Matrix_test.o

# target to build an object file
Tests/Matrix_test/Matrix_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Matrix_test.dir/build.make CMakeFiles/Matrix_test.dir/Tests/Matrix_test/Matrix_test.cpp.o
.PHONY : Tests/Matrix_test/Matrix_test.cpp.o

Tests/Matrix_test/Matrix_test.i: Tests/Matrix_test/Matrix_test.cpp.i
.PHONY : Tests/Matrix_test/Matrix_test.i

# target to preprocess a source file
Tests/Matrix_test/Matrix_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Matrix_test.dir/build.make CMakeFiles/Matrix_test.dir/Tests/Matrix_test/Matrix_test.cpp.i
.PHONY : Tests/Matrix_test/Matrix_test.cpp.i

Tests/Matrix_test/Matrix_test.s: Tests/Matrix_test/Matrix_test.cpp.s
.PHONY : Tests/Matrix_test/Matrix_test.s

# target to generate assembly for a file
Tests/Matrix_test/Matrix_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Matrix_test.dir/build.make CMakeFiles/Matrix_test.dir/Tests/Matrix_test/Matrix_test.cpp.s
.PHONY : Tests/Matrix_test/Matrix_test.cpp.s

Tests/Parset_test/Parser_test.o: Tests/Parset_test/Parser_test.cpp.o
.PHONY : Tests/Parset_test/Parser_test.o

# target to build an object file
Tests/Parset_test/Parser_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Parser_test.dir/build.make CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.o
.PHONY : Tests/Parset_test/Parser_test.cpp.o

Tests/Parset_test/Parser_test.i: Tests/Parset_test/Parser_test.cpp.i
.PHONY : Tests/Parset_test/Parser_test.i

# target to preprocess a source file
Tests/Parset_test/Parser_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Parser_test.dir/build.make CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.i
.PHONY : Tests/Parset_test/Parser_test.cpp.i

Tests/Parset_test/Parser_test.s: Tests/Parset_test/Parser_test.cpp.s
.PHONY : Tests/Parset_test/Parser_test.s

# target to generate assembly for a file
Tests/Parset_test/Parser_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Parser_test.dir/build.make CMakeFiles/Parser_test.dir/Tests/Parset_test/Parser_test.cpp.s
.PHONY : Tests/Parset_test/Parser_test.cpp.s

Tests/Proxy_test/Proxy_test.o: Tests/Proxy_test/Proxy_test.cpp.o
.PHONY : Tests/Proxy_test/Proxy_test.o

# target to build an object file
Tests/Proxy_test/Proxy_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Proxy_test.dir/build.make CMakeFiles/Proxy_test.dir/Tests/Proxy_test/Proxy_test.cpp.o
.PHONY : Tests/Proxy_test/Proxy_test.cpp.o

Tests/Proxy_test/Proxy_test.i: Tests/Proxy_test/Proxy_test.cpp.i
.PHONY : Tests/Proxy_test/Proxy_test.i

# target to preprocess a source file
Tests/Proxy_test/Proxy_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Proxy_test.dir/build.make CMakeFiles/Proxy_test.dir/Tests/Proxy_test/Proxy_test.cpp.i
.PHONY : Tests/Proxy_test/Proxy_test.cpp.i

Tests/Proxy_test/Proxy_test.s: Tests/Proxy_test/Proxy_test.cpp.s
.PHONY : Tests/Proxy_test/Proxy_test.s

# target to generate assembly for a file
Tests/Proxy_test/Proxy_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Proxy_test.dir/build.make CMakeFiles/Proxy_test.dir/Tests/Proxy_test/Proxy_test.cpp.s
.PHONY : Tests/Proxy_test/Proxy_test.cpp.s

Tests/Ration_number_test/Ration_number_test.o: Tests/Ration_number_test/Ration_number_test.cpp.o
.PHONY : Tests/Ration_number_test/Ration_number_test.o

# target to build an object file
Tests/Ration_number_test/Ration_number_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Ration_number_test.dir/build.make CMakeFiles/Ration_number_test.dir/Tests/Ration_number_test/Ration_number_test.cpp.o
.PHONY : Tests/Ration_number_test/Ration_number_test.cpp.o

Tests/Ration_number_test/Ration_number_test.i: Tests/Ration_number_test/Ration_number_test.cpp.i
.PHONY : Tests/Ration_number_test/Ration_number_test.i

# target to preprocess a source file
Tests/Ration_number_test/Ration_number_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Ration_number_test.dir/build.make CMakeFiles/Ration_number_test.dir/Tests/Ration_number_test/Ration_number_test.cpp.i
.PHONY : Tests/Ration_number_test/Ration_number_test.cpp.i

Tests/Ration_number_test/Ration_number_test.s: Tests/Ration_number_test/Ration_number_test.cpp.s
.PHONY : Tests/Ration_number_test/Ration_number_test.s

# target to generate assembly for a file
Tests/Ration_number_test/Ration_number_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Ration_number_test.dir/build.make CMakeFiles/Ration_number_test.dir/Tests/Ration_number_test/Ration_number_test.cpp.s
.PHONY : Tests/Ration_number_test/Ration_number_test.cpp.s

Tests/Strint_test/StrInt_test.o: Tests/Strint_test/StrInt_test.cpp.o
.PHONY : Tests/Strint_test/StrInt_test.o

# target to build an object file
Tests/Strint_test/StrInt_test.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Strint_test.dir/build.make CMakeFiles/Strint_test.dir/Tests/Strint_test/StrInt_test.cpp.o
.PHONY : Tests/Strint_test/StrInt_test.cpp.o

Tests/Strint_test/StrInt_test.i: Tests/Strint_test/StrInt_test.cpp.i
.PHONY : Tests/Strint_test/StrInt_test.i

# target to preprocess a source file
Tests/Strint_test/StrInt_test.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Strint_test.dir/build.make CMakeFiles/Strint_test.dir/Tests/Strint_test/StrInt_test.cpp.i
.PHONY : Tests/Strint_test/StrInt_test.cpp.i

Tests/Strint_test/StrInt_test.s: Tests/Strint_test/StrInt_test.cpp.s
.PHONY : Tests/Strint_test/StrInt_test.s

# target to generate assembly for a file
Tests/Strint_test/StrInt_test.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/Strint_test.dir/build.make CMakeFiles/Strint_test.dir/Tests/Strint_test/StrInt_test.cpp.s
.PHONY : Tests/Strint_test/StrInt_test.cpp.s

src/Exceptions.o: src/Exceptions.cpp.o
.PHONY : src/Exceptions.o

# target to build an object file
src/Exceptions.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Exceptions.cpp.o
.PHONY : src/Exceptions.cpp.o

src/Exceptions.i: src/Exceptions.cpp.i
.PHONY : src/Exceptions.i

# target to preprocess a source file
src/Exceptions.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Exceptions.cpp.i
.PHONY : src/Exceptions.cpp.i

src/Exceptions.s: src/Exceptions.cpp.s
.PHONY : src/Exceptions.s

# target to generate assembly for a file
src/Exceptions.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Exceptions.cpp.s
.PHONY : src/Exceptions.cpp.s

src/Inputer.o: src/Inputer.cpp.o
.PHONY : src/Inputer.o

# target to build an object file
src/Inputer.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Inputer.cpp.o
.PHONY : src/Inputer.cpp.o

src/Inputer.i: src/Inputer.cpp.i
.PHONY : src/Inputer.i

# target to preprocess a source file
src/Inputer.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Inputer.cpp.i
.PHONY : src/Inputer.cpp.i

src/Inputer.s: src/Inputer.cpp.s
.PHONY : src/Inputer.s

# target to generate assembly for a file
src/Inputer.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Inputer.cpp.s
.PHONY : src/Inputer.cpp.s

src/Matrix.o: src/Matrix.cpp.o
.PHONY : src/Matrix.o

# target to build an object file
src/Matrix.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Matrix.cpp.o
.PHONY : src/Matrix.cpp.o

src/Matrix.i: src/Matrix.cpp.i
.PHONY : src/Matrix.i

# target to preprocess a source file
src/Matrix.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Matrix.cpp.i
.PHONY : src/Matrix.cpp.i

src/Matrix.s: src/Matrix.cpp.s
.PHONY : src/Matrix.s

# target to generate assembly for a file
src/Matrix.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Matrix.cpp.s
.PHONY : src/Matrix.cpp.s

src/Matrix_coords.o: src/Matrix_coords.cpp.o
.PHONY : src/Matrix_coords.o

# target to build an object file
src/Matrix_coords.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Matrix_coords.cpp.o
.PHONY : src/Matrix_coords.cpp.o

src/Matrix_coords.i: src/Matrix_coords.cpp.i
.PHONY : src/Matrix_coords.i

# target to preprocess a source file
src/Matrix_coords.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Matrix_coords.cpp.i
.PHONY : src/Matrix_coords.cpp.i

src/Matrix_coords.s: src/Matrix_coords.cpp.s
.PHONY : src/Matrix_coords.s

# target to generate assembly for a file
src/Matrix_coords.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Matrix_coords.cpp.s
.PHONY : src/Matrix_coords.cpp.s

src/Proxy.o: src/Proxy.cpp.o
.PHONY : src/Proxy.o

# target to build an object file
src/Proxy.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Proxy.cpp.o
.PHONY : src/Proxy.cpp.o

src/Proxy.i: src/Proxy.cpp.i
.PHONY : src/Proxy.i

# target to preprocess a source file
src/Proxy.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Proxy.cpp.i
.PHONY : src/Proxy.cpp.i

src/Proxy.s: src/Proxy.cpp.s
.PHONY : src/Proxy.s

# target to generate assembly for a file
src/Proxy.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Proxy.cpp.s
.PHONY : src/Proxy.cpp.s

src/Rational_number.o: src/Rational_number.cpp.o
.PHONY : src/Rational_number.o

# target to build an object file
src/Rational_number.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Rational_number.cpp.o
.PHONY : src/Rational_number.cpp.o

src/Rational_number.i: src/Rational_number.cpp.i
.PHONY : src/Rational_number.i

# target to preprocess a source file
src/Rational_number.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Rational_number.cpp.i
.PHONY : src/Rational_number.cpp.i

src/Rational_number.s: src/Rational_number.cpp.s
.PHONY : src/Rational_number.s

# target to generate assembly for a file
src/Rational_number.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Rational_number.cpp.s
.PHONY : src/Rational_number.cpp.s

src/Strint.o: src/Strint.cpp.o
.PHONY : src/Strint.o

# target to build an object file
src/Strint.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Strint.cpp.o
.PHONY : src/Strint.cpp.o

src/Strint.i: src/Strint.cpp.i
.PHONY : src/Strint.i

# target to preprocess a source file
src/Strint.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Strint.cpp.i
.PHONY : src/Strint.cpp.i

src/Strint.s: src/Strint.cpp.s
.PHONY : src/Strint.s

# target to generate assembly for a file
src/Strint.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Strint.cpp.s
.PHONY : src/Strint.cpp.s

src/Vector.o: src/Vector.cpp.o
.PHONY : src/Vector.o

# target to build an object file
src/Vector.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Vector.cpp.o
.PHONY : src/Vector.cpp.o

src/Vector.i: src/Vector.cpp.i
.PHONY : src/Vector.i

# target to preprocess a source file
src/Vector.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Vector.cpp.i
.PHONY : src/Vector.cpp.i

src/Vector.s: src/Vector.cpp.s
.PHONY : src/Vector.s

# target to generate assembly for a file
src/Vector.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/Vector.cpp.s
.PHONY : src/Vector.cpp.s

src/main.o: src/main.cpp.o
.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i
.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s
.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) $(MAKESILENT) -f CMakeFiles/mtx_rally.dir/build.make CMakeFiles/mtx_rally.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... edit_cache"
	@echo "... install"
	@echo "... install/local"
	@echo "... install/strip"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... test"
	@echo "... Matrix_test"
	@echo "... Parser_test"
	@echo "... Proxy_test"
	@echo "... Ration_number_test"
	@echo "... Strint_test"
	@echo "... gmock"
	@echo "... gmock_main"
	@echo "... gtest"
	@echo "... gtest_main"
	@echo "... mtx_rally"
	@echo "... Tests/Matrix_test/Matrix_test.o"
	@echo "... Tests/Matrix_test/Matrix_test.i"
	@echo "... Tests/Matrix_test/Matrix_test.s"
	@echo "... Tests/Parset_test/Parser_test.o"
	@echo "... Tests/Parset_test/Parser_test.i"
	@echo "... Tests/Parset_test/Parser_test.s"
	@echo "... Tests/Proxy_test/Proxy_test.o"
	@echo "... Tests/Proxy_test/Proxy_test.i"
	@echo "... Tests/Proxy_test/Proxy_test.s"
	@echo "... Tests/Ration_number_test/Ration_number_test.o"
	@echo "... Tests/Ration_number_test/Ration_number_test.i"
	@echo "... Tests/Ration_number_test/Ration_number_test.s"
	@echo "... Tests/Strint_test/StrInt_test.o"
	@echo "... Tests/Strint_test/StrInt_test.i"
	@echo "... Tests/Strint_test/StrInt_test.s"
	@echo "... src/Exceptions.o"
	@echo "... src/Exceptions.i"
	@echo "... src/Exceptions.s"
	@echo "... src/Inputer.o"
	@echo "... src/Inputer.i"
	@echo "... src/Inputer.s"
	@echo "... src/Matrix.o"
	@echo "... src/Matrix.i"
	@echo "... src/Matrix.s"
	@echo "... src/Matrix_coords.o"
	@echo "... src/Matrix_coords.i"
	@echo "... src/Matrix_coords.s"
	@echo "... src/Proxy.o"
	@echo "... src/Proxy.i"
	@echo "... src/Proxy.s"
	@echo "... src/Rational_number.o"
	@echo "... src/Rational_number.i"
	@echo "... src/Rational_number.s"
	@echo "... src/Strint.o"
	@echo "... src/Strint.i"
	@echo "... src/Strint.s"
	@echo "... src/Vector.o"
	@echo "... src/Vector.i"
	@echo "... src/Vector.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

