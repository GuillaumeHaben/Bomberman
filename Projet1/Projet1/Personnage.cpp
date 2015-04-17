#include "Personnage.h"

/* Constructeur */
Personnage::Personnage(){
	p_colone = 0;
	p_line = 0;
}

Personnage::Personnage(int pos_x, int pos_y){
	p_colone = pos_x;
	p_line = pos_y;
}

/* Destructeur (on verra ça plus tard c'est pas essentiel pour l'instant ) */
Personnage::~Personnage(){

}

int Personnage::getColone(){
	return p_colone;
}

int Personnage::getLine(){
	return p_line;
}

void Personnage::setColone(int pos_x){
	p_colone = pos_x;
}

void Personnage::setLine(int pos_y){
	p_line = pos_y;
}