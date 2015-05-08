#include "Game.h"

Game::Game(){
	pause = 0;
	end = 0;
	 
	principal = Joueur(0, 0);	
	jeu = new Case_plateau *[TAILLE_JEU];

	int dim_allouee;
	for (dim_allouee = 0; dim_allouee < TAILLE_JEU; ++dim_allouee)
	{
		jeu[dim_allouee] = new Case_plateau [TAILLE_JEU];
	}

	for (int i = 0; i < TAILLE_JEU; i++)
		for (int j = 0; j < TAILLE_JEU; j++)
			jeu[i][j] = VIDE;

	fond = { 0, 0, 675, 480 };
}

Game::~Game(){
	
}

void Game::setPause(bool p){
	pause = p;
}

bool Game::getPause(){
	return pause;
}

Joueur Game::getPrincipal(){
	return principal;
}

void Game::draw(SDL_Renderer * renderer){

	SDL_Surface * background = SDL_LoadBMP("sprite/back.bmp");
	SDL_Texture * text = SDL_CreateTextureFromSurface(renderer, background);
	SDL_RenderCopy(renderer, text, NULL, &fond);
	SDL_FreeSurface(background);
}