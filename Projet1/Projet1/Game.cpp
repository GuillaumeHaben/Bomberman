#include "Game.h"

Game::Game(){
	pause = 0;
	end = 0;

	for (int i = 0; i < 29; i++)
		for (int j = 0; j < 29; j++)
			jeu[i][j] = VIDE;

	principal = Joueur(0, 0);
}

Game::~Game(){
	
}

void Game::setPause(bool p){
	pause = p;
}

bool Game::getPause(){
	return pause;
}