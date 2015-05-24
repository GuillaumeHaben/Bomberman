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
	bool mute = false;

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
			Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024);
			Mix_Chunk *fin = Mix_LoadWAV("Sprite/creature.wav");
			Mix_Chunk *musique = Mix_LoadWAV("Sprite/fond.wav");
			Mix_Chunk *menumusique = Mix_LoadWAV("Sprite/tictac.wav");
			Mix_Volume(1, MIX_MAX_VOLUME / 10);
			Mix_PlayChannel(1, menumusique, -1);

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
						case SDLK_m:
							if (!mute){
								Mix_Volume(1, 0);
								Mix_Volume(2, 0);
								mute = true;
							}else{
								mute = false;
								Mix_Volume(1, MIX_MAX_VOLUME / 10);
								Mix_Volume(2, MIX_MAX_VOLUME / 10);
							}
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
						if (IsMenu){
							Mix_HaltChannel(1);
							Mix_PlayChannel(1, musique, -1);
							IsMenu = false;
						}
						if (IsDead){
							Mix_HaltChannel(1);
							Mix_PlayChannel(1, menumusique, -1);
							Mix_PlayChannel(2, fin, 0);
							IsMenu = true;
							IsDead = false;
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
				}
				else plateau.draw();
				SDL_RenderPresent(renderer);
			}

			Mix_CloseAudio();
			SDL_DestroyWindow(window);
			SDL_Quit();
		}
	}

	return 0;
}