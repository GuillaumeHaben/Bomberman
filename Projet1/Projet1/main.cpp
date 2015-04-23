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
SDL_Event event;

void clean_up()
{
	//Destroy the window
	SDL_DestroyWindow(window);

	//Quit SDL
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Waiting for user to quit
	bool quit = false;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		//Create window
		window = SDL_CreateWindow( "Bomberman", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else
		{
			//Get window surface
			screenSurface = SDL_GetWindowSurface( window );

			//Fill the surface white
			SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );
			
			//Update the surface
			SDL_UpdateWindowSurface( window );

			//While user hasn't quit
			while (quit == false)
			{
				//While there is an event
				while (SDL_PollEvent(&event))
				{
					//If user has click on the X of the window
					if (event.type == SDL_QUIT)
					{
						//We close the program
						quit = true;
					}
				}
			}

			clean_up();
		}
	}

	return 0;
}