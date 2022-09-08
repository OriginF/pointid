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

# Declare the executable target built from your sources
add_executable(ImageShow pointid.cpp 
                        single_operation/base_operation.cpp 
                        single_operation/delaunay_ext.cpp 
                        single_operation/L_sq_se_calculator.cpp 
                        single_operation/Mn_generater.cpp)

# Link your application with OpenCV libraries
target_link_libraries(ImageShow PRIVATE ${OpenCV_LIBS})