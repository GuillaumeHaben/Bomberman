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
	SDL_FreeSurface(background);
	SDL_FreeSurface(background2);
}

/* Destructeur */
Bombe::~Bombe(){
	explosee = 0;
	//SDL_DestroyTexture(texture[0]);
	//SDL_DestroyTexture(texture[1]);
}

/* Intialise la bombe */
void Bombe::init(int x, int y, int power){
	b_colone = x;
	b_line = y;
	dest = { x * 35, y * 35, 35, 35 };
	explosee = 0;
	puissance = power;
	retardement.start();
}

/* Gère les evenements bombes */
//0 = pas explosée | 1 = prête à exploser | 2 = explosée
int Bombe::event(Case_plateau* * jeu){
	if (explosee == 1 && retardement.getTime() >= 3500) {
		explosee = 2;
		retardement.stop();
		return explosee;
	}
	if (retardement.getTime() >= 2000) {
		explosee = 1;
		return 1;
	}
	return 0;
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

int Bombe::getExplosee(){
	return explosee; //0 = pas explosée | 1 = prête à exploser | 2 = explosée
}

void Bombe::setExplosee(int i) {
	this->explosee = i;
}