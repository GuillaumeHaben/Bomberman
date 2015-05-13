#include "Game.h"

Game::Game(){
	pause = 0;
	end = 0;
	 
	principal = Joueur(1, 1);	
	jeu = new Case_plateau *[TAILLE_JEU];

	int dim_allouee;
	for (dim_allouee = 0; dim_allouee < TAILLE_JEU; ++dim_allouee)
	{
		jeu[dim_allouee] = new Case_plateau [TAILLE_JEU];
	}

	for (int i = 0; i < TAILLE_JEU; i++)
		for (int j = 0; j < TAILLE_JEU; j++)
			jeu[i][j] = INIT;

	fond = { 0, 0, 675, 525 };
	this->init(1);
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

Level Game::getLevel(){
	return l;
}

void Game::draw(){

	SDL_Surface * background = SDL_LoadBMP("sprite/back.bmp");
	SDL_Texture * text = SDL_CreateTextureFromSurface(renderer, background);
	SDL_RenderCopy(renderer, text, NULL, &fond);

	l.dessiner();

	SDL_FreeSurface(background);
}

void Game::init(int i) {
	l = Level(this->jeu);
	l.setUpGame(i);
	l.dessiner();
}