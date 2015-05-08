#include "Bombe.h"

/* Constructeur */
Bombe::Bombe(){
	b_colone = 0;
	b_line = 0;
	puissance = 1;
	retardement = 5;
	explosee = false;
	appartient = nullptr;
}

Bombe::Bombe(int pos_x, int pos_y, int power, int time, bool boom, Joueur* J){
	b_colone = pos_x;
	b_line = pos_y;
	puissance = power;
	retardement = time;
	explosee = boom;
	appartient = J;
}

/* Destructeur */
Bombe::~Bombe(){

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

/* Setters */
void Bombe::setColone(int pos_x){
	b_colone = pos_x;
}

void Bombe::setLine(int pos_y){
	b_line = pos_y;
}

void Bombe::setPuissance(int power){
	puissance = power;
}

void Bombe::setRetardement(int time){
	retardement = time;
}

void Bombe::setExplosee(bool boom){
	explosee = boom;
}