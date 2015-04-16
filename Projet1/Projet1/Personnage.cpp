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
