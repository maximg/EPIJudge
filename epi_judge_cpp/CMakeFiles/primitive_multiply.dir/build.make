# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.10.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.10.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp"

# Include any dependencies generated for this target.
include CMakeFiles/primitive_multiply.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/primitive_multiply.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/primitive_multiply.dir/flags.make

CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o: CMakeFiles/primitive_multiply.dir/flags.make
CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o: primitive_multiply.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o -c "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/primitive_multiply.cc"

CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/primitive_multiply.cc" > CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.i

CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/primitive_multiply.cc" -o CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.s

CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o.requires:

.PHONY : CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o.requires

CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o.provides: CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o.requires
	$(MAKE) -f CMakeFiles/primitive_multiply.dir/build.make CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o.provides.build
.PHONY : CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o.provides

CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o.provides.build: CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o


# Object files for target primitive_multiply
primitive_multiply_OBJECTS = \
"CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o"

# External object files for target primitive_multiply
primitive_multiply_EXTERNAL_OBJECTS =

primitive_multiply: CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o
primitive_multiply: CMakeFiles/primitive_multiply.dir/build.make
primitive_multiply: CMakeFiles/primitive_multiply.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable primitive_multiply"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/primitive_multiply.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/primitive_multiply.dir/build: primitive_multiply

.PHONY : CMakeFiles/primitive_multiply.dir/build

CMakeFiles/primitive_multiply.dir/requires: CMakeFiles/primitive_multiply.dir/primitive_multiply.cc.o.requires

.PHONY : CMakeFiles/primitive_multiply.dir/requires

CMakeFiles/primitive_multiply.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/primitive_multiply.dir/cmake_clean.cmake
.PHONY : CMakeFiles/primitive_multiply.dir/clean

CMakeFiles/primitive_multiply.dir/depend:
	cd "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles/primitive_multiply.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/primitive_multiply.dir/depend

