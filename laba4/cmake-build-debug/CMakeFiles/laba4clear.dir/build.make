# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Users\Public\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Users\Public\CLion 2019.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Public\CLionProjects\GEOM\laba4clear

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Public\CLionProjects\GEOM\laba4clear\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/laba4clear.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/laba4clear.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laba4clear.dir/flags.make

CMakeFiles/laba4clear.dir/main.cpp.obj: CMakeFiles/laba4clear.dir/flags.make
CMakeFiles/laba4clear.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Public\CLionProjects\GEOM\laba4clear\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/laba4clear.dir/main.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\laba4clear.dir\main.cpp.obj -c C:\Users\Public\CLionProjects\GEOM\laba4clear\main.cpp

CMakeFiles/laba4clear.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/laba4clear.dir/main.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Public\CLionProjects\GEOM\laba4clear\main.cpp > CMakeFiles\laba4clear.dir\main.cpp.i

CMakeFiles/laba4clear.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/laba4clear.dir/main.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Public\CLionProjects\GEOM\laba4clear\main.cpp -o CMakeFiles\laba4clear.dir\main.cpp.s

CMakeFiles/laba4clear.dir/Picture.cpp.obj: CMakeFiles/laba4clear.dir/flags.make
CMakeFiles/laba4clear.dir/Picture.cpp.obj: ../Picture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Public\CLionProjects\GEOM\laba4clear\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/laba4clear.dir/Picture.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\laba4clear.dir\Picture.cpp.obj -c C:\Users\Public\CLionProjects\GEOM\laba4clear\Picture.cpp

CMakeFiles/laba4clear.dir/Picture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/laba4clear.dir/Picture.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Public\CLionProjects\GEOM\laba4clear\Picture.cpp > CMakeFiles\laba4clear.dir\Picture.cpp.i

CMakeFiles/laba4clear.dir/Picture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/laba4clear.dir/Picture.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Public\CLionProjects\GEOM\laba4clear\Picture.cpp -o CMakeFiles\laba4clear.dir\Picture.cpp.s

# Object files for target laba4clear
laba4clear_OBJECTS = \
"CMakeFiles/laba4clear.dir/main.cpp.obj" \
"CMakeFiles/laba4clear.dir/Picture.cpp.obj"

# External object files for target laba4clear
laba4clear_EXTERNAL_OBJECTS =

laba4clear.exe: CMakeFiles/laba4clear.dir/main.cpp.obj
laba4clear.exe: CMakeFiles/laba4clear.dir/Picture.cpp.obj
laba4clear.exe: CMakeFiles/laba4clear.dir/build.make
laba4clear.exe: CMakeFiles/laba4clear.dir/linklibs.rsp
laba4clear.exe: CMakeFiles/laba4clear.dir/objects1.rsp
laba4clear.exe: CMakeFiles/laba4clear.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Public\CLionProjects\GEOM\laba4clear\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable laba4clear.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\laba4clear.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laba4clear.dir/build: laba4clear.exe

.PHONY : CMakeFiles/laba4clear.dir/build

CMakeFiles/laba4clear.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\laba4clear.dir\cmake_clean.cmake
.PHONY : CMakeFiles/laba4clear.dir/clean

CMakeFiles/laba4clear.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Public\CLionProjects\GEOM\laba4clear C:\Users\Public\CLionProjects\GEOM\laba4clear C:\Users\Public\CLionProjects\GEOM\laba4clear\cmake-build-debug C:\Users\Public\CLionProjects\GEOM\laba4clear\cmake-build-debug C:\Users\Public\CLionProjects\GEOM\laba4clear\cmake-build-debug\CMakeFiles\laba4clear.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/laba4clear.dir/depend
