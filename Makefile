# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /home/fqy22/桌面/pointid

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fqy22/桌面/pointid

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/fqy22/桌面/pointid/CMakeFiles /home/fqy22/桌面/pointid/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/fqy22/桌面/pointid/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named ImageShow

# Build rule for target.
ImageShow: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 ImageShow
.PHONY : ImageShow

# fast build rule for target.
ImageShow/fast:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/build
.PHONY : ImageShow/fast

L_sq_se_calculator.o: L_sq_se_calculator.cpp.o

.PHONY : L_sq_se_calculator.o

# target to build an object file
L_sq_se_calculator.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/L_sq_se_calculator.cpp.o
.PHONY : L_sq_se_calculator.cpp.o

L_sq_se_calculator.i: L_sq_se_calculator.cpp.i

.PHONY : L_sq_se_calculator.i

# target to preprocess a source file
L_sq_se_calculator.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/L_sq_se_calculator.cpp.i
.PHONY : L_sq_se_calculator.cpp.i

L_sq_se_calculator.s: L_sq_se_calculator.cpp.s

.PHONY : L_sq_se_calculator.s

# target to generate assembly for a file
L_sq_se_calculator.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/L_sq_se_calculator.cpp.s
.PHONY : L_sq_se_calculator.cpp.s

Mn_generater.o: Mn_generater.cpp.o

.PHONY : Mn_generater.o

# target to build an object file
Mn_generater.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/Mn_generater.cpp.o
.PHONY : Mn_generater.cpp.o

Mn_generater.i: Mn_generater.cpp.i

.PHONY : Mn_generater.i

# target to preprocess a source file
Mn_generater.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/Mn_generater.cpp.i
.PHONY : Mn_generater.cpp.i

Mn_generater.s: Mn_generater.cpp.s

.PHONY : Mn_generater.s

# target to generate assembly for a file
Mn_generater.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/Mn_generater.cpp.s
.PHONY : Mn_generater.cpp.s

base_operation.o: base_operation.cpp.o

.PHONY : base_operation.o

# target to build an object file
base_operation.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/base_operation.cpp.o
.PHONY : base_operation.cpp.o

base_operation.i: base_operation.cpp.i

.PHONY : base_operation.i

# target to preprocess a source file
base_operation.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/base_operation.cpp.i
.PHONY : base_operation.cpp.i

base_operation.s: base_operation.cpp.s

.PHONY : base_operation.s

# target to generate assembly for a file
base_operation.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/base_operation.cpp.s
.PHONY : base_operation.cpp.s

delaunay_ext.o: delaunay_ext.cpp.o

.PHONY : delaunay_ext.o

# target to build an object file
delaunay_ext.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/delaunay_ext.cpp.o
.PHONY : delaunay_ext.cpp.o

delaunay_ext.i: delaunay_ext.cpp.i

.PHONY : delaunay_ext.i

# target to preprocess a source file
delaunay_ext.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/delaunay_ext.cpp.i
.PHONY : delaunay_ext.cpp.i

delaunay_ext.s: delaunay_ext.cpp.s

.PHONY : delaunay_ext.s

# target to generate assembly for a file
delaunay_ext.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/delaunay_ext.cpp.s
.PHONY : delaunay_ext.cpp.s

pointid.o: pointid.cpp.o

.PHONY : pointid.o

# target to build an object file
pointid.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid.cpp.o
.PHONY : pointid.cpp.o

pointid.i: pointid.cpp.i

.PHONY : pointid.i

# target to preprocess a source file
pointid.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid.cpp.i
.PHONY : pointid.cpp.i

pointid.s: pointid.cpp.s

.PHONY : pointid.s

# target to generate assembly for a file
pointid.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid.cpp.s
.PHONY : pointid.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... ImageShow"
	@echo "... L_sq_se_calculator.o"
	@echo "... L_sq_se_calculator.i"
	@echo "... L_sq_se_calculator.s"
	@echo "... Mn_generater.o"
	@echo "... Mn_generater.i"
	@echo "... Mn_generater.s"
	@echo "... base_operation.o"
	@echo "... base_operation.i"
	@echo "... base_operation.s"
	@echo "... delaunay_ext.o"
	@echo "... delaunay_ext.i"
	@echo "... delaunay_ext.s"
	@echo "... pointid.o"
	@echo "... pointid.i"
	@echo "... pointid.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

