#include <IntroState/IntroState.h>

namespace siic {

IntroState IntroState::m_introstate; // Because it is a singleton

void IntroState::init( siic::GameEngine * game ) {
    std::clog << "IntroState::init start" << std::endl;
    // Need to set variables

    std::clog << "IntroState::init end" << std::endl;
}

void IntroState::cleanup() {
    std::clog << "IntroState::cleanup start" << std::endl;
    // cleanup
    std::clog << "IntroState::cleanup end" << std::endl;
}

void IntroState::pause() {
    std::clog << "IntroState::pause start" << std::endl;
    // Pause
    std::clog << "IntroState::pause end" << std::endl;
}

void IntroState::unpause() {
    std::clog << "IntroState::unpause start" << std::endl;

    std::clog << "IntroState::unpause end" << std::endl;
}

void IntroState::handle_events( siic::GameEngine * game ) {
    std::clog << "IntroState::handle_events start" << std::endl;

    SDL_Event event;

    if( SDL_PollEvent( & event ) == true ) {
        switch ( event.type )
        {
        case SDL_QUIT:
            game->quit();
            break;
        case SDL_KEYDOWN:
            switch ( event.key.keysym.sym )
            {
            case SDLK_SPACE:
                //game->change_state( siic::MenuState::instance() );
                break;
            case SDLK_ESCAPE:
                game->quit();
                break;
            }
        default:
            std::clog << "IntroState::handle_events event not implemented" << std::endl;
            break;
        }
    }

    std::clog << "IntroState::handle_events end" << std::endl;
}

void IntroState::update( siic::GameEngine * game ) {
    std::clog << "IntroState::update start" << std::endl;

    std::clog << "IntroState::update end" << std::endl;
}

void IntroState::render( siic::GameEngine * game ) {
    std::clog << "IntroState::render start" << std::endl;

    // Setting background color
    SDL_SetRenderDrawColor( game->window.get_renderer(), 0xff, 0xff, 0xff, 0xff );
    // Clearing screen
    SDL_RenderClear( game->window.get_renderer() );

    // Update screen
    SDL_RenderPresent( game->window.get_renderer() );

    std::clog << "IntroState::render end" << std::endl;
}
}