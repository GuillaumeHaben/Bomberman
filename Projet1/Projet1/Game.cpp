#include "Game.h"

Game::Game(){
	pause = false;
	end = false;
	int i = 1;

	principal = *new Joueur(1, 1);
	secondaire = *new Adversaire(13, 13);
	jeu = new Case_plateau *[TAILLE_JEU];

	int dim_allouee;
	for (dim_allouee = 0; dim_allouee < TAILLE_JEU; ++dim_allouee) {
		jeu[dim_allouee] = new Case_plateau[TAILLE_JEU];
	}

	for (int i = 0; i < TAILLE_JEU; i++)
		for (int j = 0; j < TAILLE_JEU; j++)
			jeu[i][j] = VIDE;

	l = Level(this->jeu, this->getPrincipal(), this->getSecondaire());
	this->init(i);
}

Game::~Game(){

}

void Game::reinit(){
	principal.setColone(1);
	principal.setLine(1);
	principal.init_var();

	secondaire.setColone(13);
	secondaire.setLine(13);
	secondaire.init_var();
	
	int dim_allouee;
	for (dim_allouee = 0; dim_allouee < TAILLE_JEU; ++dim_allouee) {
		jeu[dim_allouee] = new Case_plateau[TAILLE_JEU];
	}

	for (int i = 0; i < TAILLE_JEU; i++)
		for (int j = 0; j < TAILLE_JEU; j++)
			jeu[i][j] = VIDE;
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

Adversaire* Game::getSecondaire(){
	return &secondaire;
}

Level Game::getLevel(){
	return l;
}

void Game::draw(){
	l.draw(pause);
}

void Game::init(int i) {
	reinit();
	l.setUpGame(i);
	draw();
}