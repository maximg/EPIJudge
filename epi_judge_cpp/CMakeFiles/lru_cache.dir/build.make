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
include CMakeFiles/lru_cache.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/lru_cache.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/lru_cache.dir/flags.make

CMakeFiles/lru_cache.dir/lru_cache.cc.o: CMakeFiles/lru_cache.dir/flags.make
CMakeFiles/lru_cache.dir/lru_cache.cc.o: lru_cache.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/lru_cache.dir/lru_cache.cc.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/lru_cache.dir/lru_cache.cc.o -c "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/lru_cache.cc"

CMakeFiles/lru_cache.dir/lru_cache.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lru_cache.dir/lru_cache.cc.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/lru_cache.cc" > CMakeFiles/lru_cache.dir/lru_cache.cc.i

CMakeFiles/lru_cache.dir/lru_cache.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lru_cache.dir/lru_cache.cc.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/lru_cache.cc" -o CMakeFiles/lru_cache.dir/lru_cache.cc.s

CMakeFiles/lru_cache.dir/lru_cache.cc.o.requires:

.PHONY : CMakeFiles/lru_cache.dir/lru_cache.cc.o.requires

CMakeFiles/lru_cache.dir/lru_cache.cc.o.provides: CMakeFiles/lru_cache.dir/lru_cache.cc.o.requires
	$(MAKE) -f CMakeFiles/lru_cache.dir/build.make CMakeFiles/lru_cache.dir/lru_cache.cc.o.provides.build
.PHONY : CMakeFiles/lru_cache.dir/lru_cache.cc.o.provides

CMakeFiles/lru_cache.dir/lru_cache.cc.o.provides.build: CMakeFiles/lru_cache.dir/lru_cache.cc.o


# Object files for target lru_cache
lru_cache_OBJECTS = \
"CMakeFiles/lru_cache.dir/lru_cache.cc.o"

# External object files for target lru_cache
lru_cache_EXTERNAL_OBJECTS =

lru_cache: CMakeFiles/lru_cache.dir/lru_cache.cc.o
lru_cache: CMakeFiles/lru_cache.dir/build.make
lru_cache: CMakeFiles/lru_cache.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable lru_cache"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lru_cache.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/lru_cache.dir/build: lru_cache

.PHONY : CMakeFiles/lru_cache.dir/build

CMakeFiles/lru_cache.dir/requires: CMakeFiles/lru_cache.dir/lru_cache.cc.o.requires

.PHONY : CMakeFiles/lru_cache.dir/requires

CMakeFiles/lru_cache.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/lru_cache.dir/cmake_clean.cmake
.PHONY : CMakeFiles/lru_cache.dir/clean

CMakeFiles/lru_cache.dir/depend:
	cd "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp" "/Users/TsungHsienLee/Google Drive/episolutions/EPIJudge/epi_judge_cpp/CMakeFiles/lru_cache.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/lru_cache.dir/depend

