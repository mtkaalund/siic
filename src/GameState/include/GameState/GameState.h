#ifndef SIIC_GAMESTATE
#define SIIC_GAMESTATE

#include <GameEngine/GameEngine.h>

namespace siic {

class GameEngine;

class GameState {
public:
    virtual void init( siic::GameEngine * game )              = 0;
    virtual void cleanup()                                    = 0;
    virtual void pause()                                      = 0;
    virtual void unpause()                                    = 0;

    virtual void handle_events( siic::GameEngine * game )     = 0;
    virtual void update( siic::GameEngine * game )            = 0;
    virtual void render( siic::GameEngine * game )            = 0;

    void change_state( GameEngine * game, GameState * state );
protected:
    GameState {};
};

}

#endif