#include "Joueur.h"

/* Constructeur */
Joueur::Joueur() : Personnage(){
	init_var();
}

/* Appel au super en C++ */
Joueur::Joueur(int pos_x, int pos_y) : Personnage(pos_x, pos_y) {
	init_var();
}

/* Destructeur */
Joueur::~Joueur(){

}

void Joueur::init_var(){
	nb_bombes = 0;
	nb_bombes_max = 2;
}

int Joueur::deplacement(int direction, Case_plateau jeu[TAILLE_JEU][TAILLE_JEU]){

	switch (direction){

		case UP: 

		case DOWN:

		case RIGHT:

		case LEFT:


	}
}