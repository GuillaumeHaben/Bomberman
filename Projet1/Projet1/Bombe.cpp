#include "Bombe.h"

/* Constructeur */
Bombe::Bombe(){
	this->init(0, 0, 2);
}

Bombe::Bombe(int pos_x, int pos_y, int power){
	this->init(pos_x, pos_y, power);

	SDL_Surface* background = IMG_Load("Sprite/bombe_1.png");
	SDL_Surface* background2 = IMG_Load("Sprite/bombe_2.png");
	texture[0] = SDL_CreateTextureFromSurface(renderer, background);
	texture[1] = SDL_CreateTextureFromSurface(renderer, background2);
	dest = { 35, 35, 35, 35 };
	SDL_FreeSurface(background);
}

/* Destructeur */
Bombe::~Bombe(){
	
}

/* Intialise la bombe */
void Bombe::init(int x, int y, int power){
	b_colone = x;
	b_line = y;
	puissance = power;
	retardement.start();
	explosee = false;
}

/* Gère les evenements bombes */
bool Bombe::event(Case_plateau* * jeu){
	if (retardement.getTime() >= 3000) {
		explosee = true;
	}
	return explosee;
}

/* Getters */
int Bombe::getColone(){
	return b_colone;
}

int Bombe::getLine(){
	return b_line;
}

int Bombe::getPuissance(){
	return puissance;
}

Time Bombe::getRetardement(){
	return retardement;
}

bool Bombe::getExplosee(){
	return explosee;
}