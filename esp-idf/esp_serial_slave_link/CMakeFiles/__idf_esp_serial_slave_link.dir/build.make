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
include esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/depend.make

# Include the progress variables for this target.
include esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/flags.make

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/flags.make
esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl.c

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl.c > CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.i

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl.c -o CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.s

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj.requires:

.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj.requires

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj.provides: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj.requires
	$(MAKE) -f esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/build.make esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj.provides.build
.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj.provides

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj.provides.build: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj


esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/flags.make
esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl_sdio.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl_sdio.c

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl_sdio.c > CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.i

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl_sdio.c -o CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.s

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj.requires:

.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj.requires

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj.provides: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj.requires
	$(MAKE) -f esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/build.make esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj.provides.build
.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj.provides

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj.provides.build: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj


esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/flags.make
esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl_spi.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl_spi.c

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl_spi.c > CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.i

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link/essl_spi.c -o CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.s

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj.requires:

.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj.requires

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj.provides: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj.requires
	$(MAKE) -f esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/build.make esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj.provides.build
.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj.provides

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj.provides.build: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj


# Object files for target __idf_esp_serial_slave_link
__idf_esp_serial_slave_link_OBJECTS = \
"CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj" \
"CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj" \
"CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj"

# External object files for target __idf_esp_serial_slave_link
__idf_esp_serial_slave_link_EXTERNAL_OBJECTS =

esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj
esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj
esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj
esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/build.make
esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking C static library libesp_serial_slave_link.a"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && $(CMAKE_COMMAND) -P CMakeFiles/__idf_esp_serial_slave_link.dir/cmake_clean_target.cmake
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_esp_serial_slave_link.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/build: esp-idf/esp_serial_slave_link/libesp_serial_slave_link.a

.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/build

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/requires: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl.c.obj.requires
esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/requires: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_sdio.c.obj.requires
esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/requires: esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/essl_spi.c.obj.requires

.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/requires

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/clean:
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link && $(CMAKE_COMMAND) -P CMakeFiles/__idf_esp_serial_slave_link.dir/cmake_clean.cmake
.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/clean

esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/depend:
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/f73377/HDD/projects/heatter/lv_port_esp32_copy /media/f73377/HDD/projects/heatter/esp-idf/components/esp_serial_slave_link /media/f73377/HDD/projects/heatter/lv_port_esp32_copy /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/esp_serial_slave_link/CMakeFiles/__idf_esp_serial_slave_link.dir/depend

