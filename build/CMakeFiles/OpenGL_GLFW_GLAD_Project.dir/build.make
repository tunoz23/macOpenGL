# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.25.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tunaozturk/Desktop/projectX

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tunaozturk/Desktop/projectX/build

# Include any dependencies generated for this target.
include CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/flags.make

CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.o: CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/flags.make
CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.o: /Users/tunaozturk/Desktop/projectX/src/main.cpp
CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.o: CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tunaozturk/Desktop/projectX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.o -MF CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.o.d -o CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.o -c /Users/tunaozturk/Desktop/projectX/src/main.cpp

CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/tunaozturk/Desktop/projectX/src/main.cpp > CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.i

CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/tunaozturk/Desktop/projectX/src/main.cpp -o CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.s

CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.o: CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/flags.make
CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.o: /Users/tunaozturk/Desktop/projectX/src/glad.c
CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.o: CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/tunaozturk/Desktop/projectX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.o -MF CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.o.d -o CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.o -c /Users/tunaozturk/Desktop/projectX/src/glad.c

CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/tunaozturk/Desktop/projectX/src/glad.c > CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.i

CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/tunaozturk/Desktop/projectX/src/glad.c -o CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.s

# Object files for target OpenGL_GLFW_GLAD_Project
OpenGL_GLFW_GLAD_Project_OBJECTS = \
"CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.o" \
"CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.o"

# External object files for target OpenGL_GLFW_GLAD_Project
OpenGL_GLFW_GLAD_Project_EXTERNAL_OBJECTS =

OpenGL_GLFW_GLAD_Project: CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/main.cpp.o
OpenGL_GLFW_GLAD_Project: CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/src/glad.c.o
OpenGL_GLFW_GLAD_Project: CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/build.make
OpenGL_GLFW_GLAD_Project: /Library/Developer/CommandLineTools/SDKs/MacOSX14.2.sdk/System/Library/Frameworks/OpenGL.framework/OpenGL.tbd
OpenGL_GLFW_GLAD_Project: /opt/homebrew/lib/libglfw.3.4.dylib
OpenGL_GLFW_GLAD_Project: CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/tunaozturk/Desktop/projectX/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable OpenGL_GLFW_GLAD_Project"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/build: OpenGL_GLFW_GLAD_Project
.PHONY : CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/build

CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/clean

CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/depend:
	cd /Users/tunaozturk/Desktop/projectX/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tunaozturk/Desktop/projectX /Users/tunaozturk/Desktop/projectX /Users/tunaozturk/Desktop/projectX/build /Users/tunaozturk/Desktop/projectX/build /Users/tunaozturk/Desktop/projectX/build/CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGL_GLFW_GLAD_Project.dir/depend

