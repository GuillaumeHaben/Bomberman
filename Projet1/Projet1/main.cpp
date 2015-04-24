#include <stdio.h>
#include <SDL/SDL.h>
#include "Game.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//The window we'll be rendering to
SDL_Window* window = NULL;

//The surface contained by the window
SDL_Surface* screenSurface = NULL;

//Event system
SDL_Event evn;

void clean_up()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	bool quit = false;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {

		//Create window
		window = SDL_CreateWindow( "Bomberman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ){
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {

			screenSurface = SDL_GetWindowSurface( window );
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			SDL_UpdateWindowSurface( window );

			// Create game
			Game plateau = Game();
			Joueur prncp = plateau.getPrincipal();

			//While user hasn't quit
			while (quit == false)
			{
				SDL_WaitEvent(&evn);
				switch (evn.type)
				{
				case SDL_QUIT: //Quit Window with X
					quit = true;
					break;
				case SDL_KEYDOWN:
					switch (evn.key.keysym.sym)
					{
					case SDLK_ESCAPE: //Quit Window with escape
						quit = true;
						break;
					}
					break;
				}
			}
		}
	}

	return 0;
}