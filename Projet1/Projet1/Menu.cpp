#include "Menu.h"
#include <SDL/SDL_image.h>

Menu::Menu(){
	SDL_Surface* background = SDL_LoadBMP("Sprite/menu.bmp");
	texture = SDL_CreateTextureFromSurface(renderer, background);
	dest = { 0, 0, 675, 525 };
	SDL_FreeSurface(background);
}


Menu::~Menu(){
	SDL_DestroyTexture(texture);
}

void Menu::clic(int x, int y){
	// TO-DO
}

void Menu::draw(){
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}