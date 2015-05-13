#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rect.h>
#include "Game.h"

const int SCREEN_WIDTH = 675;
const int SCREEN_HEIGHT = 525;

//The window we'll be rendering to
SDL_Window* window = NULL;

//Event system
SDL_Event evn;
SDL_Renderer* renderer = NULL;

int main( int argc, char* args[] )
{
	bool quit = false;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {

		//Create window
		window = SDL_CreateWindow( "Bomberman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL ){
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		} else {

			renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

			/* ICI CREATION RENDERER*/

			Game plateau;
			Joueur prncp = plateau.getPrincipal();

			plateau.draw();
			prncp.draw();

			SDL_RenderPresent(renderer);

			//While user hasn't quit
			while (quit == false)
			{
				SDL_WaitEvent(&evn);
				switch (evn.type){
				case SDL_QUIT: //Quit Window with X
					quit = true;
					break;
				case SDL_KEYDOWN:
					switch (evn.key.keysym.sym)
					{
					case SDLK_ESCAPE: //Quit Window with escape
						quit = true;
						break;
					default:
						prncp.event(plateau.jeu);
						break;
					}
					break;
				default:
					break;
				}

				// Update Frame
				plateau.draw();
				prncp.draw();
				SDL_RenderPresent(renderer); 
			}

			SDL_DestroyWindow(window);
			SDL_Quit();
		}
	}

	return 0;
}