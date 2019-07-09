#include <GameEngine/GameEngine.h>

namespace siic {

void GameEngine::init( std::string title, int width, int height, bool fullscreen ) {
    this->window.init( title, width, height );

    if( fullscreen == true ) {
        this->window.fullscreen_on();
    }
}

void GameEngine::cleanup() {
    while( this->m_states.empty() == false ) {
        this->m_states.back()->cleanup();
        this->m_states.pop_back();
    }
    // Switch back to window mode so other programs won't get accidentially resized
    if( this->window.is_fullscreen() == true ) {
        this->window.fullscreen_off();
    }
}

void GameEngine::change_state( siic::GameState * state ) {
    while( this->m_states.empty() == false ) {
        this->m_states.back()->cleanup();
        this->m_states.pop_back();
    }

    this->m_states.push_back( state );
    this->m_states.back()->init( this );
}

void GameEngine::push_state( siic::GameState * state ) {
    while( this->m_states.empty() == false ) {
        this->m_states.back()->pause();
    }

    this->m_states.push_back( state );
    this->m_states.back()->init(this);
}

void GameEngine::pop_state() {
    while( this->m_states.empty() == false ) {
        this->m_states.back()->cleanup();
        this->m_states.pop_back();
    }

    if( this->m_states.empty() == false ) {
        this->m_states.back()->unpause();
    }
}

void GameEngine::handle_events() {
    this->m_states.back()->handle_events( this );
}

void GameEngine::update() {
    this->m_states.back()->update(this);
}

void GameEngine::render() {
    this->m_states.back()->render(this);
}


}