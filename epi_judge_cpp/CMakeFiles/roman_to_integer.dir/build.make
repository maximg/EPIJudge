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
include CMakeFiles/roman_to_integer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/roman_to_integer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/roman_to_integer.dir/flags.make

CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o: CMakeFiles/roman_to_integer.dir/flags.make
CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o: roman_to_integer.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o -c "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/roman_to_integer.cc"

CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/roman_to_integer.cc" > CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.i

CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/roman_to_integer.cc" -o CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.s

CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o.requires:

.PHONY : CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o.requires

CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o.provides: CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o.requires
	$(MAKE) -f CMakeFiles/roman_to_integer.dir/build.make CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o.provides.build
.PHONY : CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o.provides

CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o.provides.build: CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o


# Object files for target roman_to_integer
roman_to_integer_OBJECTS = \
"CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o"

# External object files for target roman_to_integer
roman_to_integer_EXTERNAL_OBJECTS =

roman_to_integer: CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o
roman_to_integer: CMakeFiles/roman_to_integer.dir/build.make
roman_to_integer: CMakeFiles/roman_to_integer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable roman_to_integer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/roman_to_integer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/roman_to_integer.dir/build: roman_to_integer

.PHONY : CMakeFiles/roman_to_integer.dir/build

CMakeFiles/roman_to_integer.dir/requires: CMakeFiles/roman_to_integer.dir/roman_to_integer.cc.o.requires

.PHONY : CMakeFiles/roman_to_integer.dir/requires

CMakeFiles/roman_to_integer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/roman_to_integer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/roman_to_integer.dir/clean

CMakeFiles/roman_to_integer.dir/depend:
	cd "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles/roman_to_integer.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/roman_to_integer.dir/depend

