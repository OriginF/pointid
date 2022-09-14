# cmake needs this line
cmake_minimum_required(VERSION 3.1)

# Define project name
project(ImageShow)

# Find OpenCV, you may need to set OpenCV_DIR variable
# to the absolute path to the directory containing OpenCVConfig.cmake file
# via the command line or GUI
find_package(OpenCV REQUIRED)

# Enable C++11
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(CMAKE_THREAD_LIBS_INIT "-lpthread")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

# Declare the executable target built from your sources
add_executable(ImageShow main.cpp
                        pointid/pointid.cpp 
                        pointid/g_variable.cpp
                        pointid/single_operation/base_operation.cpp 
                        pointid/single_operation/delaunay_ext.cpp 
                        pointid/single_operation/L_sq_se_calculator.cpp 
                        pointid/single_operation/Mn_generater.cpp
                        pointid/single_operation/Mn2cluster_matrix.cpp
                        pointid/high_level_operation/img_preprocess.cpp 
                        pointid/high_level_operation/location_voter.cpp 
                        pointid/high_level_operation/parameter_init.cpp 
                        pointid/high_level_operation/point2cluster.cpp 
                        pointid/high_level_operation/triangulation.cpp 
                        frame_tracking/frame_tracking.cpp)

# Link your application with OpenCV libraries
target_link_libraries(ImageShow PRIVATE ${OpenCV_LIBS})