# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /snap/cmake/340/bin/cmake

# The command to remove a file.
RM = /snap/cmake/340/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/cuckydev/CuckyGameEngine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/cuckydev/CuckyGameEngine

# Include any dependencies generated for this target.
include CMakeFiles/CGE_Sample.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CGE_Sample.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CGE_Sample.dir/flags.make

CMakeFiles/CGE_Sample.dir/Sample.cpp.o: CMakeFiles/CGE_Sample.dir/flags.make
CMakeFiles/CGE_Sample.dir/Sample.cpp.o: Sample.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cuckydev/CuckyGameEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CGE_Sample.dir/Sample.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGE_Sample.dir/Sample.cpp.o -c /home/cuckydev/CuckyGameEngine/Sample.cpp

CMakeFiles/CGE_Sample.dir/Sample.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGE_Sample.dir/Sample.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cuckydev/CuckyGameEngine/Sample.cpp > CMakeFiles/CGE_Sample.dir/Sample.cpp.i

CMakeFiles/CGE_Sample.dir/Sample.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGE_Sample.dir/Sample.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cuckydev/CuckyGameEngine/Sample.cpp -o CMakeFiles/CGE_Sample.dir/Sample.cpp.s

CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.o: CMakeFiles/CGE_Sample.dir/flags.make
CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.o: src/CGE/CuckyGameEngine.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/cuckydev/CuckyGameEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.o -c /home/cuckydev/CuckyGameEngine/src/CGE/CuckyGameEngine.cpp

CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/cuckydev/CuckyGameEngine/src/CGE/CuckyGameEngine.cpp > CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.i

CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/cuckydev/CuckyGameEngine/src/CGE/CuckyGameEngine.cpp -o CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.s

# Object files for target CGE_Sample
CGE_Sample_OBJECTS = \
"CMakeFiles/CGE_Sample.dir/Sample.cpp.o" \
"CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.o"

# External object files for target CGE_Sample
CGE_Sample_EXTERNAL_OBJECTS =

CGE_Sample: CMakeFiles/CGE_Sample.dir/Sample.cpp.o
CGE_Sample: CMakeFiles/CGE_Sample.dir/src/CGE/CuckyGameEngine.cpp.o
CGE_Sample: CMakeFiles/CGE_Sample.dir/build.make
CGE_Sample: CMakeFiles/CGE_Sample.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/cuckydev/CuckyGameEngine/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CGE_Sample"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CGE_Sample.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CGE_Sample.dir/build: CGE_Sample

.PHONY : CMakeFiles/CGE_Sample.dir/build

CMakeFiles/CGE_Sample.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CGE_Sample.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CGE_Sample.dir/clean

CMakeFiles/CGE_Sample.dir/depend:
	cd /home/cuckydev/CuckyGameEngine && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/cuckydev/CuckyGameEngine /home/cuckydev/CuckyGameEngine /home/cuckydev/CuckyGameEngine /home/cuckydev/CuckyGameEngine /home/cuckydev/CuckyGameEngine/CMakeFiles/CGE_Sample.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CGE_Sample.dir/depend

