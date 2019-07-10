// STL C++ 
#include <iostream>
#include <exception>
// sdl2core headers
#include <sdl2core/SDL2.h>
#include <sdl2core/IMG.h>
// sdl2class headers
//#include <sdl2class/Window.h>
#include <GameEngine/GameEngine.h>
#include <GameState/GameState.h>
#include <IntroState/IntroState.h>

int main( int argc, char * argv[] )
{
	if( argc > 1 ) {
		std::clog << argv[0] << " is started with following arguments: " << std::endl;
		for(int arg = 1; arg < argc; arg++ )
		{
			std::cout << "argv[ " << arg << "] = " << argv[arg] << std::endl;
		}
	}

	try {
		SDL2 sdl2( SDL_INIT_VIDEO | SDL_INIT_TIMER );
		IMG img( IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF | IMG_INIT_WEBP );

		siic::GameEngine game;
		game.init("SIIC Game window");
		
		game.push_state( siic::IntroState::instance() );

		while( game.is_running() == true ) {
			game.handle_events();
			game.update();
			game.render();
		}

		game.cleanup();

	} catch( SDL2Exception &error ) {
		std::cerr << "Catched SDL2 Exception: \n\t" << error.what() << std::endl;
		return 1;
	} catch( IMGException &error ) {
		std::cerr << "Catched IMG Exception: \n\t" << error.what() << std::endl;
		return 2;
	} catch( std::exception &error ) {
		std::cerr << "Catched an exception: \n\t" << error.what() << std::endl;
		return 3;
	}

	return 0; // Everything is fine, normal exit
}
