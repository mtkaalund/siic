project(Window)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/../../cmake)

find_package(SDL2 REQUIRED)

include_directories(
    ${sdl2core_sdl2}
)

add_library(${PROJECT_NAME} src/Window.cc)

target_include_directories( ${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include 
    PUBLIC ${sdl2core_sdl2}
)

target_link_libraries( ${PROJECT_NAME}
    sdl2core::sdl2
    ${SDL2_LIBRARY}
)