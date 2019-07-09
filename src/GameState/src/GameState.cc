#include <GameState/GameState.h>

namespace siic {

void GameState::change_state( GameEngine * game, GameState * state ) {
    game->change_state( state );
}

}