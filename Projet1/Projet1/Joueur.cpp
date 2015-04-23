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

	case UP: if (p_line - 1 < 0) break;
			 else{
				 if (jeu[p_colone][p_line - 1] == MUR) break;
				 else{
					 jeu[p_colone][p_line] = VIDE;
					 jeu[p_colone][p_line - 1] == JOUEUR;
					 return 0;
				 }
			 }

	case DOWN:
		if (p_line + 1 > 20) break;
		else{
			if (jeu[p_colone][p_line + 1] == MUR) break;
			else{
				jeu[p_colone][p_line] = VIDE;
				jeu[p_colone][p_line + 1] == JOUEUR;
				return 0;
			}
		}

	case RIGHT:
		if (p_colone + 1 > 20) break;
		else{
			if (jeu[p_colone + 1 ][p_line] == MUR) break;
			else{
				jeu[p_colone][p_line] = VIDE;
				jeu[p_colone + 1][p_line] == JOUEUR;
				return 0;
			}
		}

	case LEFT:
		if (p_colone + 1 < 0) break;
		else{
			if (jeu[p_colone + 1][p_line] == MUR) break;
			else{
				jeu[p_colone][p_line] = VIDE;
				jeu[p_colone + 1][p_line] == JOUEUR;
				return 0;
			}
		}

	}
	return -1;
}