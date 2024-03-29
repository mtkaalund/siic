cmake_minimum_required(VERSION 3.5)

project(SIIC CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

#add subdirectory as required
add_subdirectory(sdl2core)
add_subdirectory(src/Window)
add_subdirectory(src/GameState)
add_subdirectory(src/GameEngine)
add_subdirectory(src/IntroState)
#add_subdirectory(src/ProjectName)

include_directories(
    ${sdl2core_sdl2}
    ${sdl2core_img}
    ${Window}
    ${GameState}
    ${GameEngine}
    ${IntroState}
	)

# Set C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Set the executable
add_executable(${PROJECT_NAME} src/main.cc )

target_link_libraries( ${PROJECT_NAME}
    sdl2core::sdl2
    sdl2core::img
    ${SDL2_LIBRARY}
    ${SDL2_IMAGE_LIBRARIES}
    Window
    GameState
    GameEngine
    IntroState
	)
