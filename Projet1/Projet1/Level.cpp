#include "Level.h"

/* Constructor */
Level::Level(Game* plateauVide) {
	plateau = plateauVide;
}

/* To setup the game */
void Level::setUpGame(int niveau) {
	switch (niveau) {
	case 1:
		for (int i = 0; i < TAILLE_JEU; i++) {
			plateau->jeu[i][0] = MUR;
			plateau->jeu[i][TAILLE_JEU - 1] = MUR;
		}
		for (int j = 0; j < TAILLE_JEU; j++) {
			plateau->jeu[0][j] = MUR;
			plateau->jeu[TAILLE_JEU - 1][j] = MUR;
		}
		plateau->jeu[1][1] = JOUEUR;

	}
}