// STL C
#include <ctime>
// STL C++
#include <chrono>
#include <string> 
#include <fstream>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <exception>
// sdl2core headers
#include <sdl2core/SDL2.h>
#include <sdl2core/IMG.h>
// sdl2class headers
#include <GameEngine/GameEngine.h>
#include <GameState/GameState.h>
#include <IntroState/IntroState.h>

int main( int argc, char * argv[] )
{
	// arguments variables
	bool debug 			= false;
	bool log_to_file	= false;

	auto old_rdbuf = std::clog.rdbuf();
	// No output from std::clog
	std::clog.setstate(std::ios_base::failbit);

	// Creating a file name for log output
	auto now = std::chrono::system_clock::now();
	auto in_time_t = std::chrono::system_clock::to_time_t(now);

	std::stringstream strstream;
	strstream << std::put_time( std::localtime(&in_time_t), "%d%m%Y-%H%M%S");

	std::string log_name = "SIIC-log-" + strstream.str() + ".log";

	std::ofstream log_out;
	// Finished Creating file name

	if( argc > 1 ) {
		std::clog << argv[0] << " is started with following arguments: " << std::endl;
		for(int index = 1; index < argc; index++ )
		{
			std::clog << "argv[ " << index << " ] = " << argv[ index ] << std::endl;
			std::string arg = argv[ index ];

			if( arg.compare("--debug") == 0 ) {
				debug = true;
			}

			if( arg.compare("--log_to_file") == 0 ) {
				log_to_file = true;
			}

			if( arg.compare("--help") == 0 ) {
				std::cout << argv[0] << " [options]" << std::endl;
				std::cout << std::endl << "[options]" << std::endl;
				std::cout << "--debug\t\t output debug information into terminal" << std::endl;
				std::cout << "--log_to_file\t this need to be used with --debug option" << std::endl;
				std::cout << "\t\t will output to a log file" << std::endl;
				std::cout << "--help\t\t will output this help menu" << std::endl;
				return 0;
			}
		}
	}

	if( debug == true ) {
		// Turn on std::clog output
		std::clog.clear();
	} 

	if( log_to_file == true ) {
		log_out.open( log_name.c_str() );

		std::clog.rdbuf( log_out.rdbuf() );

		std::clog << "File: " << log_name << std::endl;
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

		if( log_to_file == true ) {
			std::clog.rdbuf( old_rdbuf );
			log_out.close();
		}

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
