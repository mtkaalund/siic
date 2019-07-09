project(GameState CXX)

include_directories(
    ${GameEngine_INCLUDE_DIRS}
)

add_library(${PROJECT_NAME}
    src/GameState.cc
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${GameEngine_INCLUDE_DIRS}
)

target_link_libraries(${PROJECT_NAME}
    GameEngine
)