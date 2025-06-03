cmake_minimum_required(VERSION 3.10)
project(OpenCVTest)

# Find OpenCV Package
find_package(OpenCV REQUIRED)

# Include directories from OpenCV
include_directories(${OpenCV_INCLUDE_DIRS})

# Create an executable
add_executable(main main.cpp)

# Link OpenCV libraries
target_link_libraries(main ${OpenCV_LIBS})