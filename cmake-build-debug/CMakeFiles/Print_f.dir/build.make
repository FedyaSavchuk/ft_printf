# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hspeeder/Desktop/School_42/printf_project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Print_f.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Print_f.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Print_f.dir/flags.make

CMakeFiles/Print_f.dir/ft_printf.c.o: CMakeFiles/Print_f.dir/flags.make
CMakeFiles/Print_f.dir/ft_printf.c.o: ../ft_printf.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Print_f.dir/ft_printf.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Print_f.dir/ft_printf.c.o   -c /Users/hspeeder/Desktop/School_42/printf_project/ft_printf.c

CMakeFiles/Print_f.dir/ft_printf.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Print_f.dir/ft_printf.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hspeeder/Desktop/School_42/printf_project/ft_printf.c > CMakeFiles/Print_f.dir/ft_printf.c.i

CMakeFiles/Print_f.dir/ft_printf.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Print_f.dir/ft_printf.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hspeeder/Desktop/School_42/printf_project/ft_printf.c -o CMakeFiles/Print_f.dir/ft_printf.c.s

CMakeFiles/Print_f.dir/Libft/ft_putchar.c.o: CMakeFiles/Print_f.dir/flags.make
CMakeFiles/Print_f.dir/Libft/ft_putchar.c.o: ../Libft/ft_putchar.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Print_f.dir/Libft/ft_putchar.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Print_f.dir/Libft/ft_putchar.c.o   -c /Users/hspeeder/Desktop/School_42/printf_project/Libft/ft_putchar.c

CMakeFiles/Print_f.dir/Libft/ft_putchar.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Print_f.dir/Libft/ft_putchar.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hspeeder/Desktop/School_42/printf_project/Libft/ft_putchar.c > CMakeFiles/Print_f.dir/Libft/ft_putchar.c.i

CMakeFiles/Print_f.dir/Libft/ft_putchar.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Print_f.dir/Libft/ft_putchar.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hspeeder/Desktop/School_42/printf_project/Libft/ft_putchar.c -o CMakeFiles/Print_f.dir/Libft/ft_putchar.c.s

CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.o: CMakeFiles/Print_f.dir/flags.make
CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.o: ../Libft/ft_putnbr.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.o   -c /Users/hspeeder/Desktop/School_42/printf_project/Libft/ft_putnbr.c

CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hspeeder/Desktop/School_42/printf_project/Libft/ft_putnbr.c > CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.i

CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hspeeder/Desktop/School_42/printf_project/Libft/ft_putnbr.c -o CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.s

CMakeFiles/Print_f.dir/print_di.c.o: CMakeFiles/Print_f.dir/flags.make
CMakeFiles/Print_f.dir/print_di.c.o: ../print_di.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Print_f.dir/print_di.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Print_f.dir/print_di.c.o   -c /Users/hspeeder/Desktop/School_42/printf_project/print_di.c

CMakeFiles/Print_f.dir/print_di.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Print_f.dir/print_di.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hspeeder/Desktop/School_42/printf_project/print_di.c > CMakeFiles/Print_f.dir/print_di.c.i

CMakeFiles/Print_f.dir/print_di.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Print_f.dir/print_di.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hspeeder/Desktop/School_42/printf_project/print_di.c -o CMakeFiles/Print_f.dir/print_di.c.s

CMakeFiles/Print_f.dir/print_u.c.o: CMakeFiles/Print_f.dir/flags.make
CMakeFiles/Print_f.dir/print_u.c.o: ../print_u.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Print_f.dir/print_u.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Print_f.dir/print_u.c.o   -c /Users/hspeeder/Desktop/School_42/printf_project/print_u.c

CMakeFiles/Print_f.dir/print_u.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Print_f.dir/print_u.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/hspeeder/Desktop/School_42/printf_project/print_u.c > CMakeFiles/Print_f.dir/print_u.c.i

CMakeFiles/Print_f.dir/print_u.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Print_f.dir/print_u.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/hspeeder/Desktop/School_42/printf_project/print_u.c -o CMakeFiles/Print_f.dir/print_u.c.s

# Object files for target Print_f
Print_f_OBJECTS = \
"CMakeFiles/Print_f.dir/ft_printf.c.o" \
"CMakeFiles/Print_f.dir/Libft/ft_putchar.c.o" \
"CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.o" \
"CMakeFiles/Print_f.dir/print_di.c.o" \
"CMakeFiles/Print_f.dir/print_u.c.o"

# External object files for target Print_f
Print_f_EXTERNAL_OBJECTS =

Print_f: CMakeFiles/Print_f.dir/ft_printf.c.o
Print_f: CMakeFiles/Print_f.dir/Libft/ft_putchar.c.o
Print_f: CMakeFiles/Print_f.dir/Libft/ft_putnbr.c.o
Print_f: CMakeFiles/Print_f.dir/print_di.c.o
Print_f: CMakeFiles/Print_f.dir/print_u.c.o
Print_f: CMakeFiles/Print_f.dir/build.make
Print_f: CMakeFiles/Print_f.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable Print_f"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Print_f.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Print_f.dir/build: Print_f

.PHONY : CMakeFiles/Print_f.dir/build

CMakeFiles/Print_f.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Print_f.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Print_f.dir/clean

CMakeFiles/Print_f.dir/depend:
	cd /Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hspeeder/Desktop/School_42/printf_project /Users/hspeeder/Desktop/School_42/printf_project /Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug /Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug /Users/hspeeder/Desktop/School_42/printf_project/cmake-build-debug/CMakeFiles/Print_f.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Print_f.dir/depend

