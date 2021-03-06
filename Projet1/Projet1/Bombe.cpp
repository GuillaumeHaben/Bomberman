#include "Bombe.h"
#include <SDL/SDL_mixer.h>

/* Constructor */
Bombe::Bombe(){
	this->init(0, 0);
}

Bombe::Bombe(int pos_x, int pos_y){
	this->init(pos_x, pos_y);
	SDL_Surface* background = IMG_Load("Sprite/bombe_1.png");
	SDL_Surface* background2 = IMG_Load("Sprite/bombe_2.png");
	texture[0] = SDL_CreateTextureFromSurface(renderer, background);
	texture[1] = SDL_CreateTextureFromSurface(renderer, background2);
	SDL_FreeSurface(background);
	SDL_FreeSurface(background2);
}

/* Destructor */
Bombe::~Bombe(){
	explosee = 0;
	//SDL_DestroyTexture(texture[0]);
	//SDL_DestroyTexture(texture[1]);
}

/* Init Bombe */
void Bombe::init(int x, int y){
	b_colone = x;
	b_line = y;
	dest = { x * 35, y * 35, 35, 35 };
	explosee = 0;

	boom = false;
	isEnd = false;
	isInit = false;
	perdreVie = false;

	// Random generation for the power
	puissance = (rand() % 3) + 1;
	explosion = *new Explosion(b_colone, b_line, puissance);
	retardement.start();
}

/* Handle Bombe event */
//0 = pas explos�e | 1 = pr�te � exploser | 2 = explos�e
int Bombe::event(Case_plateau* * jeu){
	if (b_colone != 0 && b_line != 0){
		if (retardement.getTime() >= 4500 && !isEnd) {
			explosee = 3;
			retardement.stop();
			boom = true;
			explosion.end(jeu);
			isEnd = true;
			return explosee;
		}

		if (retardement.getTime() >= 3500 && !isInit) {
			explosee = 2;
			boom = true;
			int i = explosion.init(jeu);
			if (i == 1){
				perdreVie = true;
			}
			isInit = true;
			return explosee;
		}

		if (retardement.getTime() >= 2000) {
			explosee = 1;
			return 1;
		}
	}
	return 0;
}

bool Bombe::getPerdreVie(){
	return perdreVie;
}

void Bombe::setPerdreVie(){
	perdreVie = !perdreVie;
}

/* Stop the Bombe */
void Bombe::put_off(){
	if (retardement.isOn())
		retardement.stop();
}

/* Restart the Bombe */
void Bombe::put_on(){
	if (!retardement.isOn())
		retardement.restart();
}


/* Getters */
int Bombe::getColone(){
	return b_colone;
}

int Bombe::getLine(){
	return b_line;
}

void Bombe::setLine(int i){
	b_line = i;
}

int Bombe::getPuissance(){
	return puissance;
}

Time Bombe::getRetardement(){
	return retardement;
}

bool Bombe::getBoom(){
	return boom;
}

int Bombe::getExplosee(){
	return explosee;
}

void Bombe::setExplosee(int i) {
	this->explosee = i;
}