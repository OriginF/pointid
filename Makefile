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

frame_tracking/frame_tracking.o: frame_tracking/frame_tracking.cpp.o

.PHONY : frame_tracking/frame_tracking.o

# target to build an object file
frame_tracking/frame_tracking.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/frame_tracking.cpp.o
.PHONY : frame_tracking/frame_tracking.cpp.o

frame_tracking/frame_tracking.i: frame_tracking/frame_tracking.cpp.i

.PHONY : frame_tracking/frame_tracking.i

# target to preprocess a source file
frame_tracking/frame_tracking.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/frame_tracking.cpp.i
.PHONY : frame_tracking/frame_tracking.cpp.i

frame_tracking/frame_tracking.s: frame_tracking/frame_tracking.cpp.s

.PHONY : frame_tracking/frame_tracking.s

# target to generate assembly for a file
frame_tracking/frame_tracking.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/frame_tracking.cpp.s
.PHONY : frame_tracking/frame_tracking.cpp.s

frame_tracking/g_variable.o: frame_tracking/g_variable.cpp.o

.PHONY : frame_tracking/g_variable.o

# target to build an object file
frame_tracking/g_variable.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/g_variable.cpp.o
.PHONY : frame_tracking/g_variable.cpp.o

frame_tracking/g_variable.i: frame_tracking/g_variable.cpp.i

.PHONY : frame_tracking/g_variable.i

# target to preprocess a source file
frame_tracking/g_variable.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/g_variable.cpp.i
.PHONY : frame_tracking/g_variable.cpp.i

frame_tracking/g_variable.s: frame_tracking/g_variable.cpp.s

.PHONY : frame_tracking/g_variable.s

# target to generate assembly for a file
frame_tracking/g_variable.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/g_variable.cpp.s
.PHONY : frame_tracking/g_variable.cpp.s

frame_tracking/tr_parameter_init.o: frame_tracking/tr_parameter_init.cpp.o

.PHONY : frame_tracking/tr_parameter_init.o

# target to build an object file
frame_tracking/tr_parameter_init.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/tr_parameter_init.cpp.o
.PHONY : frame_tracking/tr_parameter_init.cpp.o

frame_tracking/tr_parameter_init.i: frame_tracking/tr_parameter_init.cpp.i

.PHONY : frame_tracking/tr_parameter_init.i

# target to preprocess a source file
frame_tracking/tr_parameter_init.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/tr_parameter_init.cpp.i
.PHONY : frame_tracking/tr_parameter_init.cpp.i

frame_tracking/tr_parameter_init.s: frame_tracking/tr_parameter_init.cpp.s

.PHONY : frame_tracking/tr_parameter_init.s

# target to generate assembly for a file
frame_tracking/tr_parameter_init.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/tr_parameter_init.cpp.s
.PHONY : frame_tracking/tr_parameter_init.cpp.s

frame_tracking/update_tracked.o: frame_tracking/update_tracked.cpp.o

.PHONY : frame_tracking/update_tracked.o

# target to build an object file
frame_tracking/update_tracked.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/update_tracked.cpp.o
.PHONY : frame_tracking/update_tracked.cpp.o

frame_tracking/update_tracked.i: frame_tracking/update_tracked.cpp.i

.PHONY : frame_tracking/update_tracked.i

# target to preprocess a source file
frame_tracking/update_tracked.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/update_tracked.cpp.i
.PHONY : frame_tracking/update_tracked.cpp.i

frame_tracking/update_tracked.s: frame_tracking/update_tracked.cpp.s

.PHONY : frame_tracking/update_tracked.s

# target to generate assembly for a file
frame_tracking/update_tracked.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/frame_tracking/update_tracked.cpp.s
.PHONY : frame_tracking/update_tracked.cpp.s

main.o: main.cpp.o

.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i

.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s

.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/main.cpp.s
.PHONY : main.cpp.s

message_send.o: message_send.cpp.o

.PHONY : message_send.o

# target to build an object file
message_send.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/message_send.cpp.o
.PHONY : message_send.cpp.o

message_send.i: message_send.cpp.i

.PHONY : message_send.i

# target to preprocess a source file
message_send.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/message_send.cpp.i
.PHONY : message_send.cpp.i

message_send.s: message_send.cpp.s

.PHONY : message_send.s

# target to generate assembly for a file
message_send.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/message_send.cpp.s
.PHONY : message_send.cpp.s

pointid/g_variable.o: pointid/g_variable.cpp.o

.PHONY : pointid/g_variable.o

# target to build an object file
pointid/g_variable.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/g_variable.cpp.o
.PHONY : pointid/g_variable.cpp.o

pointid/g_variable.i: pointid/g_variable.cpp.i

.PHONY : pointid/g_variable.i

# target to preprocess a source file
pointid/g_variable.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/g_variable.cpp.i
.PHONY : pointid/g_variable.cpp.i

pointid/g_variable.s: pointid/g_variable.cpp.s

.PHONY : pointid/g_variable.s

# target to generate assembly for a file
pointid/g_variable.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/g_variable.cpp.s
.PHONY : pointid/g_variable.cpp.s

pointid/high_level_operation/img_preprocess.o: pointid/high_level_operation/img_preprocess.cpp.o

.PHONY : pointid/high_level_operation/img_preprocess.o

# target to build an object file
pointid/high_level_operation/img_preprocess.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/img_preprocess.cpp.o
.PHONY : pointid/high_level_operation/img_preprocess.cpp.o

pointid/high_level_operation/img_preprocess.i: pointid/high_level_operation/img_preprocess.cpp.i

.PHONY : pointid/high_level_operation/img_preprocess.i

# target to preprocess a source file
pointid/high_level_operation/img_preprocess.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/img_preprocess.cpp.i
.PHONY : pointid/high_level_operation/img_preprocess.cpp.i

pointid/high_level_operation/img_preprocess.s: pointid/high_level_operation/img_preprocess.cpp.s

.PHONY : pointid/high_level_operation/img_preprocess.s

# target to generate assembly for a file
pointid/high_level_operation/img_preprocess.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/img_preprocess.cpp.s
.PHONY : pointid/high_level_operation/img_preprocess.cpp.s

pointid/high_level_operation/location_voter.o: pointid/high_level_operation/location_voter.cpp.o

.PHONY : pointid/high_level_operation/location_voter.o

# target to build an object file
pointid/high_level_operation/location_voter.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/location_voter.cpp.o
.PHONY : pointid/high_level_operation/location_voter.cpp.o

pointid/high_level_operation/location_voter.i: pointid/high_level_operation/location_voter.cpp.i

.PHONY : pointid/high_level_operation/location_voter.i

# target to preprocess a source file
pointid/high_level_operation/location_voter.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/location_voter.cpp.i
.PHONY : pointid/high_level_operation/location_voter.cpp.i

pointid/high_level_operation/location_voter.s: pointid/high_level_operation/location_voter.cpp.s

.PHONY : pointid/high_level_operation/location_voter.s

# target to generate assembly for a file
pointid/high_level_operation/location_voter.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/location_voter.cpp.s
.PHONY : pointid/high_level_operation/location_voter.cpp.s

pointid/high_level_operation/parameter_init.o: pointid/high_level_operation/parameter_init.cpp.o

.PHONY : pointid/high_level_operation/parameter_init.o

# target to build an object file
pointid/high_level_operation/parameter_init.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/parameter_init.cpp.o
.PHONY : pointid/high_level_operation/parameter_init.cpp.o

pointid/high_level_operation/parameter_init.i: pointid/high_level_operation/parameter_init.cpp.i

.PHONY : pointid/high_level_operation/parameter_init.i

# target to preprocess a source file
pointid/high_level_operation/parameter_init.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/parameter_init.cpp.i
.PHONY : pointid/high_level_operation/parameter_init.cpp.i

pointid/high_level_operation/parameter_init.s: pointid/high_level_operation/parameter_init.cpp.s

.PHONY : pointid/high_level_operation/parameter_init.s

# target to generate assembly for a file
pointid/high_level_operation/parameter_init.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/parameter_init.cpp.s
.PHONY : pointid/high_level_operation/parameter_init.cpp.s

pointid/high_level_operation/point2cluster.o: pointid/high_level_operation/point2cluster.cpp.o

.PHONY : pointid/high_level_operation/point2cluster.o

# target to build an object file
pointid/high_level_operation/point2cluster.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/point2cluster.cpp.o
.PHONY : pointid/high_level_operation/point2cluster.cpp.o

pointid/high_level_operation/point2cluster.i: pointid/high_level_operation/point2cluster.cpp.i

.PHONY : pointid/high_level_operation/point2cluster.i

# target to preprocess a source file
pointid/high_level_operation/point2cluster.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/point2cluster.cpp.i
.PHONY : pointid/high_level_operation/point2cluster.cpp.i

pointid/high_level_operation/point2cluster.s: pointid/high_level_operation/point2cluster.cpp.s

.PHONY : pointid/high_level_operation/point2cluster.s

# target to generate assembly for a file
pointid/high_level_operation/point2cluster.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/point2cluster.cpp.s
.PHONY : pointid/high_level_operation/point2cluster.cpp.s

pointid/high_level_operation/triangulation.o: pointid/high_level_operation/triangulation.cpp.o

.PHONY : pointid/high_level_operation/triangulation.o

# target to build an object file
pointid/high_level_operation/triangulation.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/triangulation.cpp.o
.PHONY : pointid/high_level_operation/triangulation.cpp.o

pointid/high_level_operation/triangulation.i: pointid/high_level_operation/triangulation.cpp.i

.PHONY : pointid/high_level_operation/triangulation.i

# target to preprocess a source file
pointid/high_level_operation/triangulation.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/triangulation.cpp.i
.PHONY : pointid/high_level_operation/triangulation.cpp.i

pointid/high_level_operation/triangulation.s: pointid/high_level_operation/triangulation.cpp.s

.PHONY : pointid/high_level_operation/triangulation.s

# target to generate assembly for a file
pointid/high_level_operation/triangulation.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/high_level_operation/triangulation.cpp.s
.PHONY : pointid/high_level_operation/triangulation.cpp.s

pointid/pointid.o: pointid/pointid.cpp.o

.PHONY : pointid/pointid.o

# target to build an object file
pointid/pointid.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/pointid.cpp.o
.PHONY : pointid/pointid.cpp.o

pointid/pointid.i: pointid/pointid.cpp.i

.PHONY : pointid/pointid.i

# target to preprocess a source file
pointid/pointid.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/pointid.cpp.i
.PHONY : pointid/pointid.cpp.i

pointid/pointid.s: pointid/pointid.cpp.s

.PHONY : pointid/pointid.s

# target to generate assembly for a file
pointid/pointid.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/pointid.cpp.s
.PHONY : pointid/pointid.cpp.s

pointid/single_operation/L_sq_se_calculator.o: pointid/single_operation/L_sq_se_calculator.cpp.o

.PHONY : pointid/single_operation/L_sq_se_calculator.o

# target to build an object file
pointid/single_operation/L_sq_se_calculator.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/L_sq_se_calculator.cpp.o
.PHONY : pointid/single_operation/L_sq_se_calculator.cpp.o

pointid/single_operation/L_sq_se_calculator.i: pointid/single_operation/L_sq_se_calculator.cpp.i

.PHONY : pointid/single_operation/L_sq_se_calculator.i

# target to preprocess a source file
pointid/single_operation/L_sq_se_calculator.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/L_sq_se_calculator.cpp.i
.PHONY : pointid/single_operation/L_sq_se_calculator.cpp.i

pointid/single_operation/L_sq_se_calculator.s: pointid/single_operation/L_sq_se_calculator.cpp.s

.PHONY : pointid/single_operation/L_sq_se_calculator.s

# target to generate assembly for a file
pointid/single_operation/L_sq_se_calculator.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/L_sq_se_calculator.cpp.s
.PHONY : pointid/single_operation/L_sq_se_calculator.cpp.s

pointid/single_operation/Mn2cluster_matrix.o: pointid/single_operation/Mn2cluster_matrix.cpp.o

.PHONY : pointid/single_operation/Mn2cluster_matrix.o

# target to build an object file
pointid/single_operation/Mn2cluster_matrix.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/Mn2cluster_matrix.cpp.o
.PHONY : pointid/single_operation/Mn2cluster_matrix.cpp.o

pointid/single_operation/Mn2cluster_matrix.i: pointid/single_operation/Mn2cluster_matrix.cpp.i

.PHONY : pointid/single_operation/Mn2cluster_matrix.i

# target to preprocess a source file
pointid/single_operation/Mn2cluster_matrix.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/Mn2cluster_matrix.cpp.i
.PHONY : pointid/single_operation/Mn2cluster_matrix.cpp.i

pointid/single_operation/Mn2cluster_matrix.s: pointid/single_operation/Mn2cluster_matrix.cpp.s

.PHONY : pointid/single_operation/Mn2cluster_matrix.s

# target to generate assembly for a file
pointid/single_operation/Mn2cluster_matrix.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/Mn2cluster_matrix.cpp.s
.PHONY : pointid/single_operation/Mn2cluster_matrix.cpp.s

pointid/single_operation/Mn_generater.o: pointid/single_operation/Mn_generater.cpp.o

.PHONY : pointid/single_operation/Mn_generater.o

# target to build an object file
pointid/single_operation/Mn_generater.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/Mn_generater.cpp.o
.PHONY : pointid/single_operation/Mn_generater.cpp.o

pointid/single_operation/Mn_generater.i: pointid/single_operation/Mn_generater.cpp.i

.PHONY : pointid/single_operation/Mn_generater.i

# target to preprocess a source file
pointid/single_operation/Mn_generater.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/Mn_generater.cpp.i
.PHONY : pointid/single_operation/Mn_generater.cpp.i

pointid/single_operation/Mn_generater.s: pointid/single_operation/Mn_generater.cpp.s

.PHONY : pointid/single_operation/Mn_generater.s

# target to generate assembly for a file
pointid/single_operation/Mn_generater.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/Mn_generater.cpp.s
.PHONY : pointid/single_operation/Mn_generater.cpp.s

pointid/single_operation/base_operation.o: pointid/single_operation/base_operation.cpp.o

.PHONY : pointid/single_operation/base_operation.o

# target to build an object file
pointid/single_operation/base_operation.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/base_operation.cpp.o
.PHONY : pointid/single_operation/base_operation.cpp.o

pointid/single_operation/base_operation.i: pointid/single_operation/base_operation.cpp.i

.PHONY : pointid/single_operation/base_operation.i

# target to preprocess a source file
pointid/single_operation/base_operation.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/base_operation.cpp.i
.PHONY : pointid/single_operation/base_operation.cpp.i

pointid/single_operation/base_operation.s: pointid/single_operation/base_operation.cpp.s

.PHONY : pointid/single_operation/base_operation.s

# target to generate assembly for a file
pointid/single_operation/base_operation.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/base_operation.cpp.s
.PHONY : pointid/single_operation/base_operation.cpp.s

pointid/single_operation/delaunay_ext.o: pointid/single_operation/delaunay_ext.cpp.o

.PHONY : pointid/single_operation/delaunay_ext.o

# target to build an object file
pointid/single_operation/delaunay_ext.cpp.o:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/delaunay_ext.cpp.o
.PHONY : pointid/single_operation/delaunay_ext.cpp.o

pointid/single_operation/delaunay_ext.i: pointid/single_operation/delaunay_ext.cpp.i

.PHONY : pointid/single_operation/delaunay_ext.i

# target to preprocess a source file
pointid/single_operation/delaunay_ext.cpp.i:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/delaunay_ext.cpp.i
.PHONY : pointid/single_operation/delaunay_ext.cpp.i

pointid/single_operation/delaunay_ext.s: pointid/single_operation/delaunay_ext.cpp.s

.PHONY : pointid/single_operation/delaunay_ext.s

# target to generate assembly for a file
pointid/single_operation/delaunay_ext.cpp.s:
	$(MAKE) -f CMakeFiles/ImageShow.dir/build.make CMakeFiles/ImageShow.dir/pointid/single_operation/delaunay_ext.cpp.s
.PHONY : pointid/single_operation/delaunay_ext.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... ImageShow"
	@echo "... frame_tracking/frame_tracking.o"
	@echo "... frame_tracking/frame_tracking.i"
	@echo "... frame_tracking/frame_tracking.s"
	@echo "... frame_tracking/g_variable.o"
	@echo "... frame_tracking/g_variable.i"
	@echo "... frame_tracking/g_variable.s"
	@echo "... frame_tracking/tr_parameter_init.o"
	@echo "... frame_tracking/tr_parameter_init.i"
	@echo "... frame_tracking/tr_parameter_init.s"
	@echo "... frame_tracking/update_tracked.o"
	@echo "... frame_tracking/update_tracked.i"
	@echo "... frame_tracking/update_tracked.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
	@echo "... message_send.o"
	@echo "... message_send.i"
	@echo "... message_send.s"
	@echo "... pointid/g_variable.o"
	@echo "... pointid/g_variable.i"
	@echo "... pointid/g_variable.s"
	@echo "... pointid/high_level_operation/img_preprocess.o"
	@echo "... pointid/high_level_operation/img_preprocess.i"
	@echo "... pointid/high_level_operation/img_preprocess.s"
	@echo "... pointid/high_level_operation/location_voter.o"
	@echo "... pointid/high_level_operation/location_voter.i"
	@echo "... pointid/high_level_operation/location_voter.s"
	@echo "... pointid/high_level_operation/parameter_init.o"
	@echo "... pointid/high_level_operation/parameter_init.i"
	@echo "... pointid/high_level_operation/parameter_init.s"
	@echo "... pointid/high_level_operation/point2cluster.o"
	@echo "... pointid/high_level_operation/point2cluster.i"
	@echo "... pointid/high_level_operation/point2cluster.s"
	@echo "... pointid/high_level_operation/triangulation.o"
	@echo "... pointid/high_level_operation/triangulation.i"
	@echo "... pointid/high_level_operation/triangulation.s"
	@echo "... pointid/pointid.o"
	@echo "... pointid/pointid.i"
	@echo "... pointid/pointid.s"
	@echo "... pointid/single_operation/L_sq_se_calculator.o"
	@echo "... pointid/single_operation/L_sq_se_calculator.i"
	@echo "... pointid/single_operation/L_sq_se_calculator.s"
	@echo "... pointid/single_operation/Mn2cluster_matrix.o"
	@echo "... pointid/single_operation/Mn2cluster_matrix.i"
	@echo "... pointid/single_operation/Mn2cluster_matrix.s"
	@echo "... pointid/single_operation/Mn_generater.o"
	@echo "... pointid/single_operation/Mn_generater.i"
	@echo "... pointid/single_operation/Mn_generater.s"
	@echo "... pointid/single_operation/base_operation.o"
	@echo "... pointid/single_operation/base_operation.i"
	@echo "... pointid/single_operation/base_operation.s"
	@echo "... pointid/single_operation/delaunay_ext.o"
	@echo "... pointid/single_operation/delaunay_ext.i"
	@echo "... pointid/single_operation/delaunay_ext.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

