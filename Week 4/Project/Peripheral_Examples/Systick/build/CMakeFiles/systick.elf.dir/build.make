# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/build"

# Include any dependencies generated for this target.
include CMakeFiles/systick.elf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/systick.elf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/systick.elf.dir/flags.make

CMakeFiles/systick.elf.dir/main.c.o: CMakeFiles/systick.elf.dir/flags.make
CMakeFiles/systick.elf.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/systick.elf.dir/main.c.o"
	arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/systick.elf.dir/main.c.o   -c "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/main.c"

CMakeFiles/systick.elf.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/systick.elf.dir/main.c.i"
	arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/main.c" > CMakeFiles/systick.elf.dir/main.c.i

CMakeFiles/systick.elf.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/systick.elf.dir/main.c.s"
	arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/main.c" -o CMakeFiles/systick.elf.dir/main.c.s

CMakeFiles/systick.elf.dir/stm32f0xx_it.c.o: CMakeFiles/systick.elf.dir/flags.make
CMakeFiles/systick.elf.dir/stm32f0xx_it.c.o: ../stm32f0xx_it.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/systick.elf.dir/stm32f0xx_it.c.o"
	arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/systick.elf.dir/stm32f0xx_it.c.o   -c "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/stm32f0xx_it.c"

CMakeFiles/systick.elf.dir/stm32f0xx_it.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/systick.elf.dir/stm32f0xx_it.c.i"
	arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/stm32f0xx_it.c" > CMakeFiles/systick.elf.dir/stm32f0xx_it.c.i

CMakeFiles/systick.elf.dir/stm32f0xx_it.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/systick.elf.dir/stm32f0xx_it.c.s"
	arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/stm32f0xx_it.c" -o CMakeFiles/systick.elf.dir/stm32f0xx_it.c.s

CMakeFiles/systick.elf.dir/system_stm32f0xx.c.o: CMakeFiles/systick.elf.dir/flags.make
CMakeFiles/systick.elf.dir/system_stm32f0xx.c.o: ../system_stm32f0xx.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/systick.elf.dir/system_stm32f0xx.c.o"
	arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/systick.elf.dir/system_stm32f0xx.c.o   -c "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/system_stm32f0xx.c"

CMakeFiles/systick.elf.dir/system_stm32f0xx.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/systick.elf.dir/system_stm32f0xx.c.i"
	arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/system_stm32f0xx.c" > CMakeFiles/systick.elf.dir/system_stm32f0xx.c.i

CMakeFiles/systick.elf.dir/system_stm32f0xx.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/systick.elf.dir/system_stm32f0xx.c.s"
	arm-none-eabi-gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/system_stm32f0xx.c" -o CMakeFiles/systick.elf.dir/system_stm32f0xx.c.s

# Object files for target systick.elf
systick_elf_OBJECTS = \
"CMakeFiles/systick.elf.dir/main.c.o" \
"CMakeFiles/systick.elf.dir/stm32f0xx_it.c.o" \
"CMakeFiles/systick.elf.dir/system_stm32f0xx.c.o"

# External object files for target systick.elf
systick_elf_EXTERNAL_OBJECTS =

systick.elf: CMakeFiles/systick.elf.dir/main.c.o
systick.elf: CMakeFiles/systick.elf.dir/stm32f0xx_it.c.o
systick.elf: CMakeFiles/systick.elf.dir/system_stm32f0xx.c.o
systick.elf: CMakeFiles/systick.elf.dir/build.make
systick.elf: CMakeFiles/systick.elf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Linking C executable systick.elf"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/systick.elf.dir/link.txt --verbose=$(VERBOSE)
	arm-none-eabi-size systick.elf
	arm-none-eabi-objcopy -O ihex systick.elf systick.hex
	arm-none-eabi-objcopy -O binary -S systick.elf systick.bin

# Rule to build all files generated by this target.
CMakeFiles/systick.elf.dir/build: systick.elf

.PHONY : CMakeFiles/systick.elf.dir/build

CMakeFiles/systick.elf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/systick.elf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/systick.elf.dir/clean

CMakeFiles/systick.elf.dir/depend:
	cd "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick" "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick" "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/build" "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/build" "/home/mert/dev/stm32/KON309E/Week 4/Project/Peripheral_Examples/Systick/build/CMakeFiles/systick.elf.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/systick.elf.dir/depend

