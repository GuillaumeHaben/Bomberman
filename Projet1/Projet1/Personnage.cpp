#include "Personnage.h"

/* Constructeur */
Personnage::Personnage(){
	p_colone = 1;
	p_line = 1;
}

Personnage::Personnage(int pos_x, int pos_y){
	p_colone = pos_x;
	p_line = pos_y;
}

/* Destructeur */
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