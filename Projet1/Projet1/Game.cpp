#include "Game.h"


Game::Game(){
	pause = 0;
	end = 0;
}


Game::~Game(){

}

void Game::setPause(bool p){
	pause = p;
}

bool Game::getPause(){
	return pause;
}