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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/build

# Include any dependencies generated for this target.
include CMakeFiles/allegro-interface.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/allegro-interface.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/allegro-interface.dir/flags.make

CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o: CMakeFiles/allegro-interface.dir/flags.make
CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o: ../allegro_interface.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o"
	/usr/bin/x86_64-linux-gnu-g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o -c /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/allegro_interface.cpp

CMakeFiles/allegro-interface.dir/allegro_interface.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/allegro-interface.dir/allegro_interface.cpp.i"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/allegro_interface.cpp > CMakeFiles/allegro-interface.dir/allegro_interface.cpp.i

CMakeFiles/allegro-interface.dir/allegro_interface.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/allegro-interface.dir/allegro_interface.cpp.s"
	/usr/bin/x86_64-linux-gnu-g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/allegro_interface.cpp -o CMakeFiles/allegro-interface.dir/allegro_interface.cpp.s

CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o.requires:

.PHONY : CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o.requires

CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o.provides: CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o.requires
	$(MAKE) -f CMakeFiles/allegro-interface.dir/build.make CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o.provides.build
.PHONY : CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o.provides

CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o.provides.build: CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o


# Object files for target allegro-interface
allegro__interface_OBJECTS = \
"CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o"

# External object files for target allegro-interface
allegro__interface_EXTERNAL_OBJECTS =

liballegro-interface.a: CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o
liballegro-interface.a: CMakeFiles/allegro-interface.dir/build.make
liballegro-interface.a: CMakeFiles/allegro-interface.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library liballegro-interface.a"
	$(CMAKE_COMMAND) -P CMakeFiles/allegro-interface.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/allegro-interface.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/allegro-interface.dir/build: liballegro-interface.a

.PHONY : CMakeFiles/allegro-interface.dir/build

CMakeFiles/allegro-interface.dir/requires: CMakeFiles/allegro-interface.dir/allegro_interface.cpp.o.requires

.PHONY : CMakeFiles/allegro-interface.dir/requires

CMakeFiles/allegro-interface.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/allegro-interface.dir/cmake_clean.cmake
.PHONY : CMakeFiles/allegro-interface.dir/clean

CMakeFiles/allegro-interface.dir/depend:
	cd /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/build /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/build /home/devluis/Documentos/GitHub/exercicios-faculdade/nevermind/build/CMakeFiles/allegro-interface.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/allegro-interface.dir/depend
