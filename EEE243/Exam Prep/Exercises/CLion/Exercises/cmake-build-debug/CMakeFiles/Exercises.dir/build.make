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
CMAKE_SOURCE_DIR = "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Exercises.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Exercises.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Exercises.dir/flags.make

CMakeFiles/Exercises.dir/main.c.o: CMakeFiles/Exercises.dir/flags.make
CMakeFiles/Exercises.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Exercises.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Exercises.dir/main.c.o   -c "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/main.c"

CMakeFiles/Exercises.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Exercises.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/main.c" > CMakeFiles/Exercises.dir/main.c.i

CMakeFiles/Exercises.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Exercises.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/main.c" -o CMakeFiles/Exercises.dir/main.c.s

CMakeFiles/Exercises.dir/main.c.o.requires:

.PHONY : CMakeFiles/Exercises.dir/main.c.o.requires

CMakeFiles/Exercises.dir/main.c.o.provides: CMakeFiles/Exercises.dir/main.c.o.requires
	$(MAKE) -f CMakeFiles/Exercises.dir/build.make CMakeFiles/Exercises.dir/main.c.o.provides.build
.PHONY : CMakeFiles/Exercises.dir/main.c.o.provides

CMakeFiles/Exercises.dir/main.c.o.provides.build: CMakeFiles/Exercises.dir/main.c.o


# Object files for target Exercises
Exercises_OBJECTS = \
"CMakeFiles/Exercises.dir/main.c.o"

# External object files for target Exercises
Exercises_EXTERNAL_OBJECTS =

Exercises: CMakeFiles/Exercises.dir/main.c.o
Exercises: CMakeFiles/Exercises.dir/build.make
Exercises: CMakeFiles/Exercises.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Exercises"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Exercises.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Exercises.dir/build: Exercises

.PHONY : CMakeFiles/Exercises.dir/build

CMakeFiles/Exercises.dir/requires: CMakeFiles/Exercises.dir/main.c.o.requires

.PHONY : CMakeFiles/Exercises.dir/requires

CMakeFiles/Exercises.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Exercises.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Exercises.dir/clean

CMakeFiles/Exercises.dir/depend:
	cd "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises" "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises" "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/cmake-build-debug" "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/cmake-build-debug" "/mnt/c/Users/jerem_000/OneDrive/School/RMC/Current Classes/EEE243/Exam Prep/Exercises/CLion/Exercises/cmake-build-debug/CMakeFiles/Exercises.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Exercises.dir/depend

