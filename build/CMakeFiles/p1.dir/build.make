# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jeblas/usb/p1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jeblas/usb/p1/build

# Include any dependencies generated for this target.
include CMakeFiles/p1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/p1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/p1.dir/flags.make

CMakeFiles/p1.dir/src/array.cc.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/src/array.cc.o: ../src/array.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeblas/usb/p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/p1.dir/src/array.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p1.dir/src/array.cc.o -c /home/jeblas/usb/p1/src/array.cc

CMakeFiles/p1.dir/src/array.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1.dir/src/array.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeblas/usb/p1/src/array.cc > CMakeFiles/p1.dir/src/array.cc.i

CMakeFiles/p1.dir/src/array.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1.dir/src/array.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeblas/usb/p1/src/array.cc -o CMakeFiles/p1.dir/src/array.cc.s

CMakeFiles/p1.dir/src/simple_string.cc.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/src/simple_string.cc.o: ../src/simple_string.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeblas/usb/p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/p1.dir/src/simple_string.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p1.dir/src/simple_string.cc.o -c /home/jeblas/usb/p1/src/simple_string.cc

CMakeFiles/p1.dir/src/simple_string.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1.dir/src/simple_string.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeblas/usb/p1/src/simple_string.cc > CMakeFiles/p1.dir/src/simple_string.cc.i

CMakeFiles/p1.dir/src/simple_string.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1.dir/src/simple_string.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeblas/usb/p1/src/simple_string.cc -o CMakeFiles/p1.dir/src/simple_string.cc.s

CMakeFiles/p1.dir/main.cc.o: CMakeFiles/p1.dir/flags.make
CMakeFiles/p1.dir/main.cc.o: ../main.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jeblas/usb/p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/p1.dir/main.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/p1.dir/main.cc.o -c /home/jeblas/usb/p1/main.cc

CMakeFiles/p1.dir/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/p1.dir/main.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jeblas/usb/p1/main.cc > CMakeFiles/p1.dir/main.cc.i

CMakeFiles/p1.dir/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/p1.dir/main.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jeblas/usb/p1/main.cc -o CMakeFiles/p1.dir/main.cc.s

# Object files for target p1
p1_OBJECTS = \
"CMakeFiles/p1.dir/src/array.cc.o" \
"CMakeFiles/p1.dir/src/simple_string.cc.o" \
"CMakeFiles/p1.dir/main.cc.o"

# External object files for target p1
p1_EXTERNAL_OBJECTS =

p1: CMakeFiles/p1.dir/src/array.cc.o
p1: CMakeFiles/p1.dir/src/simple_string.cc.o
p1: CMakeFiles/p1.dir/main.cc.o
p1: CMakeFiles/p1.dir/build.make
p1: CMakeFiles/p1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jeblas/usb/p1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable p1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/p1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/p1.dir/build: p1

.PHONY : CMakeFiles/p1.dir/build

CMakeFiles/p1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/p1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/p1.dir/clean

CMakeFiles/p1.dir/depend:
	cd /home/jeblas/usb/p1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jeblas/usb/p1 /home/jeblas/usb/p1 /home/jeblas/usb/p1/build /home/jeblas/usb/p1/build /home/jeblas/usb/p1/build/CMakeFiles/p1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/p1.dir/depend

