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
include CMakeFiles/path_sum.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/path_sum.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/path_sum.dir/flags.make

CMakeFiles/path_sum.dir/path_sum.cc.o: CMakeFiles/path_sum.dir/flags.make
CMakeFiles/path_sum.dir/path_sum.cc.o: path_sum.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/path_sum.dir/path_sum.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/path_sum.dir/path_sum.cc.o -c "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/path_sum.cc"

CMakeFiles/path_sum.dir/path_sum.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/path_sum.dir/path_sum.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/path_sum.cc" > CMakeFiles/path_sum.dir/path_sum.cc.i

CMakeFiles/path_sum.dir/path_sum.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/path_sum.dir/path_sum.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/path_sum.cc" -o CMakeFiles/path_sum.dir/path_sum.cc.s

CMakeFiles/path_sum.dir/path_sum.cc.o.requires:

.PHONY : CMakeFiles/path_sum.dir/path_sum.cc.o.requires

CMakeFiles/path_sum.dir/path_sum.cc.o.provides: CMakeFiles/path_sum.dir/path_sum.cc.o.requires
	$(MAKE) -f CMakeFiles/path_sum.dir/build.make CMakeFiles/path_sum.dir/path_sum.cc.o.provides.build
.PHONY : CMakeFiles/path_sum.dir/path_sum.cc.o.provides

CMakeFiles/path_sum.dir/path_sum.cc.o.provides.build: CMakeFiles/path_sum.dir/path_sum.cc.o


# Object files for target path_sum
path_sum_OBJECTS = \
"CMakeFiles/path_sum.dir/path_sum.cc.o"

# External object files for target path_sum
path_sum_EXTERNAL_OBJECTS =

path_sum: CMakeFiles/path_sum.dir/path_sum.cc.o
path_sum: CMakeFiles/path_sum.dir/build.make
path_sum: CMakeFiles/path_sum.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable path_sum"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/path_sum.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/path_sum.dir/build: path_sum

.PHONY : CMakeFiles/path_sum.dir/build

CMakeFiles/path_sum.dir/requires: CMakeFiles/path_sum.dir/path_sum.cc.o.requires

.PHONY : CMakeFiles/path_sum.dir/requires

CMakeFiles/path_sum.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/path_sum.dir/cmake_clean.cmake
.PHONY : CMakeFiles/path_sum.dir/clean

CMakeFiles/path_sum.dir/depend:
	cd "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles/path_sum.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/path_sum.dir/depend

