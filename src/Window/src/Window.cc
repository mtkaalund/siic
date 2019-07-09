#include "sdl2class/Window.h"

namespace sdl2class {

Window::Window() {
    this->m_window          = nullptr;
    this->m_renderer        = nullptr;
    this->m_mousefocus      = false;
    this->m_keyboardfocus   = false;
    this->m_fullscreen      = false;
    this->m_minimized       = false;
    this->m_width           = 0;
    this->m_height          = 0;
    this->m_caption.clear();
}

Window::~Window() {
    this->free();
}

bool Window::init( std::string caption, int width, int height, int window_mask, int renderer_mask ) {
    this->m_window = SDL_CreateWindow(
        caption.c_str(),
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        window_mask
    );

    if( this->m_window == nullptr ) {
        return false;
    }

    this->m_renderer = SDL_CreateRenderer(
        this->m_window,
        -1,
        renderer_mask
    );

    if( this->m_renderer == nullptr ) {
        return false;
    }

    this->m_mousefocus      = true;
    this->m_keyboardfocus   = true;
    this->m_width           = width;
    this->m_height          = height;
    this->m_caption         = caption;

    return true;
}

void Window::free() {
    if( this->m_renderer != nullptr ) {
        SDL_DestroyRenderer( this->m_renderer );
        this->m_renderer    = nullptr;
    }

    if( this->m_window != nullptr ) {
        SDL_DestroyWindow( this->m_window );
        this->m_window      = nullptr;
    }

    this->m_mousefocus      = false;
    this->m_keyboardfocus   = false;
    this->m_width           = 0;
    this->m_height          = 0;
    this->m_caption.clear();
}

void Window::handle_event( SDL_Event & event ) {
    if( event.type == SDL_WINDOWEVENT ) {
        switch ( event.window.event ) 
        {
        case SDL_WINDOWEVENT_SIZE_CHANGED:
            this->m_width   = event.window.data1;
            this->m_height  = event.window.data2;
            SDL_RenderPresent( this->m_renderer );
            break;
        case SDL_WINDOWEVENT_EXPOSED:
            SDL_RenderPresent( this->m_renderer );
            break;
        case SDL_WINDOWEVENT_ENTER:
            this->m_mousefocus = true;
            break;
        case SDL_WINDOWEVENT_LEAVE:
            this->m_mousefocus = false;
            break;
        case SDL_WINDOWEVENT_FOCUS_GAINED:
            this->m_keyboardfocus = true;
            break;
        case SDL_WINDOWEVENT_FOCUS_LOST:
            this->m_keyboardfocus = false;
            break;
        case SDL_WINDOWEVENT_MINIMIZED:
            this->m_minimized = true;
            break;
        case SDL_WINDOWEVENT_MAXIMIZED:
            this->m_minimized = false;
            break;
        case SDL_WINDOWEVENT_RESTORED:
            this->m_minimized = false;
            break;
        }
    }
}

void Window::fullscreen_on() {
    this->m_fullscreen = true;
    SDL_SetWindowFullscreen( this->m_window, SDL_TRUE );
}

void Window::fullscreen_off() {
    this->m_fullscreen = false;
    SDL_SetWindowFullscreen( this->m_window, SDL_FALSE );
}

SDL_Renderer * Window::get_renderer() {
    return this->m_renderer;
}

void Window::set_caption( std::string caption ) {
    this->m_caption = caption;
    SDL_SetWindowTitle( this->m_window, this->m_caption.c_str() );
}

std::string Window::get_caption() {
    return this->m_caption;
}

void Window::set_width( int width ) {
    this->m_width = width;
    SDL_SetWindowSize( this->m_window, this->m_width, this->m_height );
}

int Window::get_width() {
    return this->m_width;
}

void Window::set_height( int height ) {
    this->m_height = height;
    SDL_SetWindowSize( this->m_window, this->m_width, this->m_height );
}

bool Window::has_mouse_focus()      { return this->m_mousefocus; }
bool Window::has_keyboard_focus()   { return this->m_keyboardfocus; }
bool Window::is_minimized()         { return this->m_minimized; }
bool Window::is_fullscreen()        { return this->m_fullscreen; }

}