#include "Bombe.h"

/* Constructeur */
Bombe::Bombe(){
	this->init(0, 0, 2, NULL);
}

Bombe::Bombe(int pos_x, int pos_y, int power, Joueur* J){
	this->init(pos_x, pos_y, power, J);

	SDL_Surface* background = SDL_LoadBMP("Sprite/bombe.bmp");
	SDL_SetColorKey(background, SDL_TRUE, SDL_MapRGB(background->format, 0, 0, 255));
	texture = SDL_CreateTextureFromSurface(renderer, background);
	dest = { 35, 35, 35, 35 };
	SDL_FreeSurface(background);
}

/* Destructeur */
Bombe::~Bombe(){

}

/* Intialise la bombe */
void Bombe::init(int x, int y, int power, Joueur* J){
	b_colone = x;
	b_line = y;
	puissance = power;
	retardement.start();
	explosee = false;
	appartient = J;
}

/* G�re les evenements bombes */
void event(Case_plateau* * jeu){

	// CHECK TIMER 
	// keep temps comparer 
	// explossee -> vrai -> lancer methode 
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

int Bombe::getRetardement(){
	return puissance;
}

int Bombe::getExplosee(){
	return explosee;
}

Joueur* Bombe::getJoueur(){
	return appartient;
}