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
include esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/depend.make

# Include the progress variables for this target.
include esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/progress.make

# Include the compile flags for this target's objects.
include esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/eri.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_xtensa.dir/eri.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/eri.c

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_xtensa.dir/eri.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/eri.c > CMakeFiles/__idf_xtensa.dir/eri.c.i

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_xtensa.dir/eri.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/eri.c -o CMakeFiles/__idf_xtensa.dir/eri.c.s

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.requires:

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.provides: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.requires
	$(MAKE) -f esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.provides.build
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.provides

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.provides.build: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj


esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xt_trax.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xt_trax.c

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_xtensa.dir/xt_trax.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xt_trax.c > CMakeFiles/__idf_xtensa.dir/xt_trax.c.i

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_xtensa.dir/xt_trax.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xt_trax.c -o CMakeFiles/__idf_xtensa.dir/xt_trax.c.s

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj.requires:

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj.requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj.provides: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj.requires
	$(MAKE) -f esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj.provides.build
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj.provides

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj.provides.build: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj


esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xtensa_intr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj   -c /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xtensa_intr.c

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.i"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xtensa_intr.c > CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.i

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.s"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xtensa_intr.c -o CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.s

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj.requires:

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj.requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj.provides: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj.requires
	$(MAKE) -f esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj.provides.build
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj.provides

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj.provides.build: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj


esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/flags.make
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj: /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xtensa_intr_asm.S
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building ASM object esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && /home/f73377/.espressif/tools/xtensa-esp32-elf/esp-2020r3-8.4.0/xtensa-esp32-elf/bin/xtensa-esp32-elf-gcc $(ASM_DEFINES) $(ASM_INCLUDES) $(ASM_FLAGS) -o CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj -c /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa/xtensa_intr_asm.S

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj.requires:

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj.requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj.provides: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj.requires
	$(MAKE) -f esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj.provides.build
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj.provides

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj.provides.build: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj


# Object files for target __idf_xtensa
__idf_xtensa_OBJECTS = \
"CMakeFiles/__idf_xtensa.dir/eri.c.obj" \
"CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj" \
"CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj" \
"CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj"

# External object files for target __idf_xtensa
__idf_xtensa_EXTERNAL_OBJECTS =

esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build.make
esp-idf/xtensa/libxtensa.a: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/media/f73377/HDD/projects/heatter/lv_port_esp32_copy/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C static library libxtensa.a"
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && $(CMAKE_COMMAND) -P CMakeFiles/__idf_xtensa.dir/cmake_clean_target.cmake
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__idf_xtensa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build: esp-idf/xtensa/libxtensa.a

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/build

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/eri.c.obj.requires
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xt_trax.c.obj.requires
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr.c.obj.requires
esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires: esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/xtensa_intr_asm.S.obj.requires

.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/requires

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/clean:
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa && $(CMAKE_COMMAND) -P CMakeFiles/__idf_xtensa.dir/cmake_clean.cmake
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/clean

esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/depend:
	cd /media/f73377/HDD/projects/heatter/lv_port_esp32_copy && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /media/f73377/HDD/projects/heatter/lv_port_esp32_copy /media/f73377/HDD/projects/heatter/esp-idf/components/xtensa /media/f73377/HDD/projects/heatter/lv_port_esp32_copy /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa /media/f73377/HDD/projects/heatter/lv_port_esp32_copy/esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : esp-idf/xtensa/CMakeFiles/__idf_xtensa.dir/depend

