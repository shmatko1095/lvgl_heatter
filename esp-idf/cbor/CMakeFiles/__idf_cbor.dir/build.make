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
CMAKE_SOURCE_DIR = /media/f73377/HDD/projects/heatter/lv_port_esp32_copy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /media/f73377/HDD/projects/heatter/lv_port_esp32_copy

# Include any dependencies generated for this target.
include esp-idf/cbor/CMakeFiles/__idf_cbor.dir/depend.make

# Include the progress variables for this target.
include esp-idf/cbor/CMakeFiles/__idf_cbor.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborencoder_close_container_checked.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborencoder_close_container_checked.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborencoder_close_container_checked.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborencoder_close_container_checked.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj


esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborencoder.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborencoder.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborencoder.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborencoder.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj


esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborerrorstrings.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborerrorstrings.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborerrorstrings.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborerrorstrings.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj


esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborparser_dup_string.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborparser_dup_string.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborparser_dup_string.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborparser_dup_string.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj


esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborparser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborparser.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborparser.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborparser.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj


esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborpretty_stdio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborpretty_stdio.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborpretty_stdio.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborpretty_stdio.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj


esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborpretty.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborpretty.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborpretty.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborpretty.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj


esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cbortojson.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cbortojson.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cbortojson.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cbortojson.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj


esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborvalidation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborvalidation.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborvalidation.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/cborvalidation.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj


esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/flags.make
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/open_memstream.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) -D__linux__ $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/open_memstream.c

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) -D__linux__ $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/open_memstream.c > CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.i

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) -D__linux__ $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/cbor/tinycbor/src/open_memstream.c -o CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.s

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj.requires:

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj.requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj.provides: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj.requires
	$(MAKE) -f esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj.provides.build
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj.provides

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj.provides.build: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj


# Object files for target __idf_cbor
__idf_cbor_OBJECTS = \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj" \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj" \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj" \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj" \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj" \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj" \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj" \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj" \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj" \
"CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj"

# External object files for target __idf_cbor
__idf_cbor_EXTERNAL_OBJECTS =

esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build.make
esp-idf/cbor/libcbor.a: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking C static library libcbor.a"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && $(CMAKE_COMMAND) -P CMakeFiles/__idf_cbor.dir/cmake_clean_target.cmake
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_cbor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build: esp-idf/cbor/libcbor.a

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/build

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder_close_container_checked.c.obj.requires
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborencoder.c.obj.requires
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborerrorstrings.c.obj.requires
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser_dup_string.c.obj.requires
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborparser.c.obj.requires
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty_stdio.c.obj.requires
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborpretty.c.obj.requires
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cbortojson.c.obj.requires
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/cborvalidation.c.obj.requires
esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires: esp-idf/cbor/CMakeFiles/__idf_cbor.dir/tinycbor/src/open_memstream.c.obj.requires

.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/requires

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/clean:
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor && $(CMAKE_COMMAND) -P CMakeFiles/__idf_cbor.dir/cmake_clean.cmake
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/clean

esp-idf/cbor/CMakeFiles/__idf_cbor.dir/depend:
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/f73377/HDD/projects/heatter/lv_port_esp32_copy /media/f73377/HDD/projects/heatter/esp-idf/components/cbor /media/f73377/HDD/projects/heatter/lv_port_esp32_copy /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/cbor/CMakeFiles/__idf_cbor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/cbor/CMakeFiles/__idf_cbor.dir/depend

