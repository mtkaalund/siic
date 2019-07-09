#ifndef SDL2CLASS_WINDOW_H
#define SDL2CLASS_WINDOW_H

#include <string>

#include <sdl2core/SDL2.h>

namespace sdl2class {

class Window {
private:
    SDL_Window      *   m_window;
    SDL_Renderer    *   m_renderer;

    int                 m_width;
    int                 m_height;
    std::string         m_caption;

    bool                m_mousefocus;
    bool                m_keyboardfocus;
    bool                m_fullscreen;
    bool                m_minimized;

public:
    Window();
    ~Window();

    bool init( std::string caption, int width, int height, int window_mask = SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE,  int renderer_mask = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC );
    void free();

    void handle_event( SDL_Event & event );

    void fullscreen_on();
    void fullscreen_off();

    SDL_Renderer * get_renderer();

    void set_caption( std::string caption );
    std::string get_caption();

    void set_width( int width );
    int get_width();

    void set_height( int height );
    int get_height();

    bool has_mouse_focus();
    bool has_keyboard_focus();
    bool is_minimized();
    bool is_fullscreen();
};

}

#endif