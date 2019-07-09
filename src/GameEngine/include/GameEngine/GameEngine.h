#ifndef SIIC_GAMEENGINE
#define SIIC_GAMEENGINE

#include <string>
#include <vector>
#include <iostream>

#include <sdl2core/SDL2.h>

#include <sdl2class/Window.h>
#include <GameState/GameState.h>

namespace siic {

class GameState;

class GameEngine {
public:
    void init( std::string title, int width = 640, int height = 480, bool fullscreen = false );
    void cleanup();

    void change_state( siic::GameState * state );
    void push_state( siic::GameEngine * state );
    void pop_state();

    void handle_events();
    void update();
    void render();

    bool is_running() { return this->m_is_running; }
    void quit() { this->m_is_running = false; }

    sdl2class::Window window;
private:
    std::vector< siic::GameState * > m_states;
    bool m_is_running;
};

}
#endif