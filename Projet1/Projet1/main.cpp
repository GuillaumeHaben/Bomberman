#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_rect.h>
//#include <SDL/SDL_mixer.h>

#include "Game.h"
#include "Menu.h"

const int SCREEN_WIDTH = 675;
const int SCREEN_HEIGHT = 525;

//The window we'll be rendering to
SDL_Window* window = NULL;

//Event system
SDL_Event evn;
SDL_Renderer* renderer = NULL;

bool IsDead = false;

int main( int argc, char* args[] )
{
	bool quit = false;
	bool IsMenu = true;

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

			Game plateau;
			Joueur* prncp = plateau.getPrincipal();
			Menu menu;

			menu.draw();
			SDL_RenderPresent(renderer);

			//While user hasn't quit
			while (quit == false){
				while (SDL_PollEvent(&evn)){
					switch (evn.type){
					case SDL_QUIT: //Quit Window with X
						quit = true;
						break;
					case SDL_KEYDOWN:
						switch (evn.key.keysym.sym){
						case SDLK_ESCAPE: //Quit Window with escape
							quit = true;
							break;
						case SDLK_p:
							plateau.setPause();
							break;
						default:
							if (!plateau.getPause())
								prncp->event(plateau.jeu);
							break;
						}
						break;
					case SDL_MOUSEBUTTONUP:
						if (plateau.getPause())
							plateau.setPause();
						if (IsMenu)
							IsMenu = false;
						if (IsDead){
							IsMenu = true;
							plateau.reinit();
						}
						break;
					default:
						break;
					}

				}

				// Update Frame
				SDL_RenderClear(renderer);
				if (IsMenu){
					menu.draw();
				}else plateau.draw();
				SDL_RenderPresent(renderer);
			}

			SDL_DestroyWindow(window);
			SDL_Quit();
		}
	}

	return 0;
}