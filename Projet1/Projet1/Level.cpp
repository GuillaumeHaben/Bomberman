#include "Level.h"


/* Constructor */
Level::Level() {

	img[0] = SDL_LoadBMP("Sprite/caisse.bmp");
	img[1] = SDL_LoadBMP("Sprite/mur.bmp");
}

Level::Level(Case_plateau* * jeu) {
	this->jeu = jeu;

	img[0] = SDL_LoadBMP("Sprite/caisse.bmp");
	img[1] = SDL_LoadBMP("Sprite/mur.bmp");
}

Level::~Level() {
	for (int i = 0; i < 2; i++){
		SDL_FreeSurface(img[i]);
	}
}

/* To setup the game */
void Level::setUpGame(int niveau) {
	this->niveau = niveau;

	switch (niveau) {
	case 1:
		niveau1();
		break;
	default:
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
		if (jeu[i][j] != MUR && jeu[i][j] != VIDE && jeu[i][j] != JOUEUR) {
			jeu[i][j] = CAISSE;
			k++;
		}
	}
}

void Level::niveau1() {
	// Walls
	for (int i = 0; i < TAILLE_JEU; i++) {
		jeu[i][0] = MUR;
		jeu[i][TAILLE_JEU - 1] = MUR;
	}
	for (int j = 0; j < TAILLE_JEU; j++) {
		jeu[0][j] = MUR;
		jeu[TAILLE_JEU - 1][j] = MUR;
	}
	for (int i = 4; i <= 6; i++) {
		jeu[i][4] = MUR;
		jeu[i][10] = MUR;
	}
	for (int i = 8; i <= TAILLE_JEU - 5; i++) {
		jeu[i][4] = MUR;
		jeu[i][10] = MUR;
	}
	for (int i = 6; i <= TAILLE_JEU - 7; i++) {
		jeu[i][6] = MUR;
		jeu[i][8] = MUR;
	}
	for (int i = 4; i <= TAILLE_JEU - 3; i++)
		jeu[i][2] = MUR;
	for (int i = 2; i <= TAILLE_JEU - 5; i++)
		jeu[i][12] = MUR;
	for (int j = 5; j <= 9; j++) {
		jeu[4][j] = MUR;
		jeu[TAILLE_JEU - 5][j] = MUR;
	}
	for (int j = 4; j <= TAILLE_JEU - 4; j++)
		jeu[2][j] = MUR;
	for (int j = 3; j <= TAILLE_JEU - 5; j++)
		jeu[TAILLE_JEU - 3][j] = MUR;

	jeu[2][2] = MUR;
	jeu[12][12] = MUR;
	jeu[6][7] = MUR;
	jeu[8][7] = MUR;
	jeu[TAILLE_JEU - 2][10] = MUR;
	jeu[1][4] = MUR;

	// Player.
	jeu[1][1] = JOUEUR;

	// Empty cases.
	for (int i = 2; i < 4; i++) {
		jeu[i][1] = VIDE;
		jeu[1][i] = VIDE;
	}
	for (int i = 11; i < 13; i++){
		jeu[i][13] = MUR;
		jeu[13][i] = MUR;
	}

	// CAISSES.
	generateurCaisses(30);

}


void Level::dessiner(){

	SDL_Rect rect = { 0, 0, 35, 35 };
	SDL_Texture* texture;

	for (int i = 0; i < TAILLE_JEU; i++){
		for (int j = 0; j < TAILLE_JEU; j++){
			rect.x = i * 35;
			rect.y = j * 35;

			switch (jeu[i][j]){
			case MUR: 
				texture = SDL_CreateTextureFromSurface(renderer, img[1]);
				SDL_RenderCopy(renderer, texture, NULL, &rect);
			}
		}
	}


}
/* DESSINER : Associer chaque fois les images au case
penser que cette methode sera en continue, tout le temps refresh

l� qu'on fera l'appel au methdoe genre bombe evenement*/