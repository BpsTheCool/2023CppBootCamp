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
CMAKE_SOURCE_DIR = /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug

# Utility rule file for NaSharedPtr_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/NaSharedPtr_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NaSharedPtr_autogen.dir/progress.make

CMakeFiles/NaSharedPtr_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target NaSharedPtr"
	/usr/bin/cmake -E cmake_autogen /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/CMakeFiles/NaSharedPtr_autogen.dir/AutogenInfo.json Debug

NaSharedPtr_autogen: CMakeFiles/NaSharedPtr_autogen
NaSharedPtr_autogen: CMakeFiles/NaSharedPtr_autogen.dir/build.make
.PHONY : NaSharedPtr_autogen

# Rule to build all files generated by this target.
CMakeFiles/NaSharedPtr_autogen.dir/build: NaSharedPtr_autogen
.PHONY : CMakeFiles/NaSharedPtr_autogen.dir/build

CMakeFiles/NaSharedPtr_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NaSharedPtr_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NaSharedPtr_autogen.dir/clean

CMakeFiles/NaSharedPtr_autogen.dir/depend:
	cd /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/CMakeFiles/NaSharedPtr_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NaSharedPtr_autogen.dir/depend

