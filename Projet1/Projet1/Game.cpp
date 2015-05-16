#include "Game.h"

Game::Game(){
	pause = false;
	end = false;
	 
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
	l.draw();
}

void Game::init(int i) {
	l = Level(this->jeu);
	l.setUpGame(i);
	draw();
}