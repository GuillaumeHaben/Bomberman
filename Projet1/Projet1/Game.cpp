#include "Game.h"

Game::Game(){
	pause = false;
	end = false;

	principal = *new Joueur(1, 1);
	jeu = new Case_plateau *[TAILLE_JEU];

	int dim_allouee;
	for (dim_allouee = 0; dim_allouee < TAILLE_JEU; ++dim_allouee) {
		jeu[dim_allouee] = new Case_plateau[TAILLE_JEU];
	}

	for (int i = 0; i < TAILLE_JEU; i++)
		for (int j = 0; j < TAILLE_JEU; j++)
			jeu[i][j] = INIT;

	l = Level(this->jeu, this->getPrincipal());
	this->init(1);
}

Game::~Game(){

}

void Game::reinit(){
	principal.setColone(1);
	principal.setLine(1);
	principal.init_var();

	int dim_allouee;
	for (dim_allouee = 0; dim_allouee < TAILLE_JEU; ++dim_allouee) {
		jeu[dim_allouee] = new Case_plateau[TAILLE_JEU];
	}

	for (int i = 0; i < TAILLE_JEU; i++)
		for (int j = 0; j < TAILLE_JEU; j++)
			jeu[i][j] = INIT;

	this->init(1);
}

void Game::setPause(){
	pause = !pause;
}

bool Game::getPause(){
	return pause;
}

Joueur* Game::getPrincipal(){
	return &principal;
}

Level Game::getLevel(){
	return l;
}

void Game::draw(){
	l.draw(pause);
}

void Game::init(int i) {
	l.setUpGame(i);
	draw();
}