# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.7.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.7.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Fuchsito/wi4771tu.2017

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Fuchsito/wi4771tu.2017/build

# Utility rule file for Final_project_assignment.

# Include the progress variables for this target.
include Final-project/CMakeFiles/Final_project_assignment.dir/progress.make

Final-project/CMakeFiles/Final_project_assignment: Final-project/Final_project
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E copy /Users/Fuchsito/wi4771tu.2017/Final-project/src/Final_project.cxx Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E echo "=== Start Environment " >> Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E echo "PROJECT_NAME = Final-project" >> Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E echo "CMAKE_SYSTEM = Darwin-15.5.0" >> Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E echo "CMAKE_VERSION = 3.7.2" >> Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E echo "CMAKE_CXX_COMPILER_ID = AppleClang" >> Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E echo "CMAKE_CXX_COMPILER_VERSION = 7.3.0.7030031" >> Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E echo "=== End Environment " >> Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E echo "=== Start of output from execution of binary Final_project" >> Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && ./Final_project >> Final_project.log
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && /usr/local/Cellar/cmake/3.7.2/bin/cmake -E echo "=== End of output from execution of binary Final_project" >> Final_project.log

Final_project_assignment: Final-project/CMakeFiles/Final_project_assignment
Final_project_assignment: Final-project/CMakeFiles/Final_project_assignment.dir/build.make

.PHONY : Final_project_assignment

# Rule to build all files generated by this target.
Final-project/CMakeFiles/Final_project_assignment.dir/build: Final_project_assignment

.PHONY : Final-project/CMakeFiles/Final_project_assignment.dir/build

Final-project/CMakeFiles/Final_project_assignment.dir/clean:
	cd /Users/Fuchsito/wi4771tu.2017/build/Final-project && $(CMAKE_COMMAND) -P CMakeFiles/Final_project_assignment.dir/cmake_clean.cmake
.PHONY : Final-project/CMakeFiles/Final_project_assignment.dir/clean

Final-project/CMakeFiles/Final_project_assignment.dir/depend:
	cd /Users/Fuchsito/wi4771tu.2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Fuchsito/wi4771tu.2017 /Users/Fuchsito/wi4771tu.2017/Final-project /Users/Fuchsito/wi4771tu.2017/build /Users/Fuchsito/wi4771tu.2017/build/Final-project /Users/Fuchsito/wi4771tu.2017/build/Final-project/CMakeFiles/Final_project_assignment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Final-project/CMakeFiles/Final_project_assignment.dir/depend
