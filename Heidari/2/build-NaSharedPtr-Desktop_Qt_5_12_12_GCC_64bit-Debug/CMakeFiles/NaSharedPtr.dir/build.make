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

# Include any dependencies generated for this target.
include CMakeFiles/NaSharedPtr.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/NaSharedPtr.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/NaSharedPtr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NaSharedPtr.dir/flags.make

CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.o: CMakeFiles/NaSharedPtr.dir/flags.make
CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.o: NaSharedPtr_autogen/mocs_compilation.cpp
CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.o: CMakeFiles/NaSharedPtr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.o -MF CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.o -c /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/NaSharedPtr_autogen/mocs_compilation.cpp

CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/NaSharedPtr_autogen/mocs_compilation.cpp > CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.i

CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/NaSharedPtr_autogen/mocs_compilation.cpp -o CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.s

CMakeFiles/NaSharedPtr.dir/main.cpp.o: CMakeFiles/NaSharedPtr.dir/flags.make
CMakeFiles/NaSharedPtr.dir/main.cpp.o: /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr/main.cpp
CMakeFiles/NaSharedPtr.dir/main.cpp.o: CMakeFiles/NaSharedPtr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NaSharedPtr.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/NaSharedPtr.dir/main.cpp.o -MF CMakeFiles/NaSharedPtr.dir/main.cpp.o.d -o CMakeFiles/NaSharedPtr.dir/main.cpp.o -c /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr/main.cpp

CMakeFiles/NaSharedPtr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaSharedPtr.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr/main.cpp > CMakeFiles/NaSharedPtr.dir/main.cpp.i

CMakeFiles/NaSharedPtr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaSharedPtr.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr/main.cpp -o CMakeFiles/NaSharedPtr.dir/main.cpp.s

CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.o: CMakeFiles/NaSharedPtr.dir/flags.make
CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.o: /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr/intshareptr.cpp
CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.o: CMakeFiles/NaSharedPtr.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.o -MF CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.o.d -o CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.o -c /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr/intshareptr.cpp

CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr/intshareptr.cpp > CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.i

CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr/intshareptr.cpp -o CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.s

# Object files for target NaSharedPtr
NaSharedPtr_OBJECTS = \
"CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/NaSharedPtr.dir/main.cpp.o" \
"CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.o"

# External object files for target NaSharedPtr
NaSharedPtr_EXTERNAL_OBJECTS =

NaSharedPtr: CMakeFiles/NaSharedPtr.dir/NaSharedPtr_autogen/mocs_compilation.cpp.o
NaSharedPtr: CMakeFiles/NaSharedPtr.dir/main.cpp.o
NaSharedPtr: CMakeFiles/NaSharedPtr.dir/intshareptr.cpp.o
NaSharedPtr: CMakeFiles/NaSharedPtr.dir/build.make
NaSharedPtr: /home/nasim/Qt5.12.12/5.12.12/gcc_64/lib/libQt5Core.so.5.12.12
NaSharedPtr: CMakeFiles/NaSharedPtr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable NaSharedPtr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NaSharedPtr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NaSharedPtr.dir/build: NaSharedPtr
.PHONY : CMakeFiles/NaSharedPtr.dir/build

CMakeFiles/NaSharedPtr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NaSharedPtr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NaSharedPtr.dir/clean

CMakeFiles/NaSharedPtr.dir/depend:
	cd /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr /home/nasim/Desktop/2023CppBootCamp/Heidari/2/NaSharedPtr /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug /home/nasim/Desktop/2023CppBootCamp/Heidari/2/build-NaSharedPtr-Desktop_Qt_5_12_12_GCC_64bit-Debug/CMakeFiles/NaSharedPtr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NaSharedPtr.dir/depend

