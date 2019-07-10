#ifndef SIIC_INTROSTATE
#define SIIC_INTROSTATE

#include <string>
#include <iostream>

#include <GameState/GameState.h>
#include <GameEngine/GameEngine.h>

#include <sdl2core/SDL2.h>

namespace siic {

class IntroState : public siic::GameState {
public:
    void init( siic::GameEngine * game );
    void cleanup();

    void pause();
    void unpause();

    void handle_events( siic::GameEngine * game );
    void update( siic::GameEngine * game );
    void render( siic::GameEngine * game );

    static IntroState * instance() {
        return &m_introstate;
    }
protected:
    IntroState() {}
private:
    static IntroState m_introstate; // singleton

    // Other variables 
};

}

#endif