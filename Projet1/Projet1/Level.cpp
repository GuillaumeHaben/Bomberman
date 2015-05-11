#include "Level.h"


/* Constructor */
Level::Level(Game* plateauVide) {
	plateau = plateauVide;

	img[0] = SDL_LoadBMP("Sprite/caisse.bmp");
	img[1] = SDL_LoadBMP("Sprite/mur.bmp");
}

/* To setup the game */
void Level::setUpGame(int niveau) {
	this->niveau = niveau;

	switch (niveau) {
	case 1:
		niveau1();
		break;
	}
}

void Level::generateurCaisses(int nombreCaisses) {
	srand(time(NULL));
	int k = 0;
	int i = 0;
	int j = 0;
	while (k < nombreCaisses) {
		i = rand() % 15;
		j = rand() % 15;
		if (plateau->jeu[i][j] != MUR && plateau->jeu[i][j] != VIDE && plateau->jeu[i][j] != JOUEUR) {
			plateau->jeu[i][j] = CAISSE;
			k++;
		}
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
	for (int i = 6; i <= TAILLE_JEU - 7; i++) {
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
	for (int j = 3; j <= TAILLE_JEU - 5; j++)
		plateau->jeu[TAILLE_JEU - 3][j] = MUR;

	plateau->jeu[2][2] = MUR;
	plateau->jeu[12][12] = MUR;
	plateau->jeu[6][7] = MUR;
	plateau->jeu[8][7] = MUR;
	plateau->jeu[TAILLE_JEU - 2][10] = MUR;
	plateau->jeu[1][4] = MUR;

	// Player.
	plateau->jeu[1][1] = JOUEUR;

	// Empty cases.
	for (int i = 2; i < 4; i++) {
		plateau->jeu[i][1] = VIDE;
		plateau->jeu[1][i] = VIDE;
	}
	for (int i = 11; i < 13; i++){
		plateau->jeu[i][13] = MUR;
		plateau->jeu[13][i] = MUR;
	}

	// CAISSES.
	generateurCaisses(30);

}


void Level::dessiner(){

}
/* DESSINER : Associer chaque fois les images au case
penser que cette methode sera en continue, tout le temps refresh

là qu'on fera l'appel au methdoe genre bombe evenement*/