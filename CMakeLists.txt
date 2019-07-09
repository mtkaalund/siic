cmake_minimum_required(VERSION 3.5)

project(SIIC CXX)

#add subdirectory as required
#add_subdirectory(sdl2core)
#add_subdirectory(src/ProjectName)

#include_directories(
#	)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Set the executable
add_executable(${PROJECT_NAME} src/main.cc )

#target_link_libraries( ${PROJECT_NAME}
#	)
