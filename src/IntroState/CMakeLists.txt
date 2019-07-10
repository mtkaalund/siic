project(IntroState CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/../../cmake)

find_package(SDL2 REQUIRED)

include_directories(
    ${GameEngine_INCLUDE_DIRS}
    ${GameState_INCLUDE_DIRS}
    ${sdl2core_sdl2}
)

add_library(${PROJECT_NAME} src/IntroState.cc)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    PUBLIC ${GameEngine_INCLUDE_DIRS}
    PUBLIC ${GameState_INCLUDE_DIRS}
    PUBLIC ${sdl2core_sdl2}
)

target_link_libraries(${PROJECT_NAME}
    GameEngine
    GameState
    sdl2core::sdl2
)