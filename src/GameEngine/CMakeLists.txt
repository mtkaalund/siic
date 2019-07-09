project(GameEngine CXX)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${PROJECT_SOURCE_DIR}/../../cmake)

find_package( SDL2 REQUIRED )

include_directories(
    ${Window_SOURCE_DIR}/include
    ${GameState_SOURCE_DIR}/include
    ${sdl2core_sdl2}
    ${SDL2_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME} src/GameEngine.cc)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
    PUBLIC ${Window_SOURCE_DIR}/include
    PUBLIC ${GameState_SOURCE_DIR}/include
    PUBLIC ${sdl2core_sdl2}
    PUBLIC ${SDL2_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    Window
    GameState
    sdl2core::sdl2
    ${SDL2_LIBRARY}
)