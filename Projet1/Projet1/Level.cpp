#include "Level.h"

/* Constructor */
Level::Level(Game* plateauVide) {
	plateau = plateauVide;
}

/* To setup the game */
void Level::setUpGame(int niveau) {
	switch (niveau) {
	case 1:
		niveau1();
		break;
	}
}

void Level::niveau1() {
	// Walls
for (int i = 0; i < TAILLE_JEU; i++) {
	plateau->jeu[i][0] = MUR;
	plateau->jeu[i][TAILLE_JEU - 1] = MUR;
}
for (int j = 0; j < TAILLE_JEU; j++) {
	plateau->jeu[0][j] = MUR;
	plateau->jeu[TAILLE_JEU - 1][j] = MUR;
}
for (int i = 4; i <= 6; i++) {
	plateau->jeu[i][4] = MUR;
	plateau->jeu[i][10] = MUR;
}
for (int i = 8; i <= TAILLE_JEU - 5; i++) {
	plateau->jeu[i][4] = MUR;
	plateau->jeu[i][10] = MUR;
}
for (int i = 8; i <= TAILLE_JEU - 7; i++) {
	plateau->jeu[i][6] = MUR;
	plateau->jeu[i][8] = MUR;
}
for (int i = 4; i <= TAILLE_JEU - 3; i++)
	plateau->jeu[i][2] = MUR;
for (int i = 2; i <= TAILLE_JEU - 5; i++)
	plateau->jeu[i][12] = MUR;
for (int j = 5; j <= 9; j++) {
	plateau->jeu[4][j] = MUR;
	plateau->jeu[TAILLE_JEU - 5][j] = MUR;
}
for (int j = 4; j <= TAILLE_JEU - 4; j++)
	plateau->jeu[2][j] = MUR;
for (int j = 4; j <= 8; j++)
	plateau->jeu[TAILLE_JEU - 3][j] = MUR;
plateau->jeu[2][2] = MUR;
plateau->jeu[TAILLE_JEU - 3][12] = MUR;
plateau->jeu[6][7] = MUR;
plateau->jeu[8][7] = MUR;
plateau->jeu[7][TAILLE_JEU - 2] = MUR;
plateau->jeu[TAILLE_JEU - 2][7] = MUR;

// Joueur.
plateau->jeu[1][1] = JOUEUR;

}