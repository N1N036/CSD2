# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild"

# Utility rule file for port_audio-populate.

# Include the progress variables for this target.
include CMakeFiles/port_audio-populate.dir/progress.make

CMakeFiles/port_audio-populate: CMakeFiles/port_audio-populate-complete


CMakeFiles/port_audio-populate-complete: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-install
CMakeFiles/port_audio-populate-complete: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-mkdir
CMakeFiles/port_audio-populate-complete: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-download
CMakeFiles/port_audio-populate-complete: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-update
CMakeFiles/port_audio-populate-complete: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-patch
CMakeFiles/port_audio-populate-complete: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-configure
CMakeFiles/port_audio-populate-complete: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-build
CMakeFiles/port_audio-populate-complete: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-install
CMakeFiles/port_audio-populate-complete: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Completed 'port_audio-populate'"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E make_directory "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/CMakeFiles"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E touch "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/CMakeFiles/port_audio-populate-complete"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E touch "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-done"

port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-install: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "No install step for 'port_audio-populate'"
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-build" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E echo_append
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-build" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E touch "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-install"

port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Creating directories for 'port_audio-populate'"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E make_directory "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-src"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E make_directory "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-build"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E make_directory "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E make_directory "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/tmp"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E make_directory "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E make_directory "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E make_directory "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E touch "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-mkdir"

port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-download: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-gitinfo.txt
port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-download: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (git clone) for 'port_audio-populate'"
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -P "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/tmp/port_audio-populate-gitclone.cmake"
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E touch "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-download"

port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-update: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Performing update step for 'port_audio-populate'"
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-src" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -P "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/tmp/port_audio-populate-gitupdate.cmake"

port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-patch: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "No patch step for 'port_audio-populate'"
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E echo_append
	"C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E touch "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-patch"

port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-configure: port_audio-populate-prefix/tmp/port_audio-populate-cfgcmd.txt
port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-configure: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-update
port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-configure: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "No configure step for 'port_audio-populate'"
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-build" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E echo_append
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-build" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E touch "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-configure"

port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-build: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "No build step for 'port_audio-populate'"
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-build" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E echo_append
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-build" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E touch "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-build"

port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-test: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir="H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "No test step for 'port_audio-populate'"
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-build" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E echo_append
	cd /d "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-build" && "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E touch "H:/Desktop/Music Projects/School/Jaar 2/RayTracedIR/RayTracedIR/Wouter/portaudiotest/cmake-build-debug/_deps/port_audio-subbuild/port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-test"

port_audio-populate: CMakeFiles/port_audio-populate
port_audio-populate: CMakeFiles/port_audio-populate-complete
port_audio-populate: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-install
port_audio-populate: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-mkdir
port_audio-populate: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-download
port_audio-populate: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-update
port_audio-populate: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-patch
port_audio-populate: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-configure
port_audio-populate: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-build
port_audio-populate: port_audio-populate-prefix/src/port_audio-populate-stamp/port_audio-populate-test
port_audio-populate: CMakeFiles/port_audio-populate.dir/build.make

.PHONY : port_audio-populate

# Rule to build all files generated by this target.
CMakeFiles/port_audio-populate.dir/build: port_audio-populate

.PHONY : CMakeFiles/port_audio-populate.dir/build

CMakeFiles/port_audio-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\port_audio-populate.dir\cmake_clean.cmake
.PHONY : CMakeFiles/port_audio-populate.dir/clean

CMakeFiles/port_audio-populate.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild" "H:\Desktop\Music Projects\School\Jaar 2\RayTracedIR\RayTracedIR\Wouter\portaudiotest\cmake-build-debug\_deps\port_audio-subbuild\CMakeFiles\port_audio-populate.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/port_audio-populate.dir/depend
