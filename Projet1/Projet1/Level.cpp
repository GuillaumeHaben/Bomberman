#include "Level.h"

/* Constructor */
Level::Level() {

}

Level::Level(Case_plateau* * plat, Joueur* J, Adversaire* A) {
	jeu = plat;
	prncp = J;
	ennemi = A;

	fond = { 0, 0, 675, 525 };

	SDL_Surface* background = IMG_Load("Sprite/pause.png");
	pause_text = SDL_CreateTextureFromSurface(renderer, background);
	SDL_FreeSurface(background);

	SDL_Surface* background2 = IMG_Load("Sprite/over.png");
	over_text = SDL_CreateTextureFromSurface(renderer, background2);
	SDL_FreeSurface(background2);

	SDL_Surface* background3 = IMG_Load("Sprite/flamme.png");
	flamme = SDL_CreateTextureFromSurface(renderer, background3);
	SDL_FreeSurface(background3);

	SDL_Surface* background4 = IMG_Load("Sprite/victoire.png");
	vict_text = SDL_CreateTextureFromSurface(renderer, background4);
	SDL_FreeSurface(background4);

	img[0] = SDL_LoadBMP("Sprite/caisse.bmp");
	img[1] = SDL_LoadBMP("Sprite/mur.bmp");

	mur = SDL_CreateTextureFromSurface(renderer, img[1]);
	caisse = SDL_CreateTextureFromSurface(renderer, img[0]);

	SDL_FreeSurface(img[0]);
	SDL_FreeSurface(img[1]);

	explosion = Mix_LoadWAV("Sprite/canon.wav");
}

Level::~Level(){

}

int Level::getLevel(){
	return niveau;
}

/* To setup the game */
void Level::setUpGame(int niveau) {
	this->niveau = niveau;

	switch (niveau) {
	case 1:
		lvl1();		
		break;
	case 2:
		lvl2();
		break;
	case 3:
		lvl3();
		break;
	default:
		lvl1();
		break;
	}
}

/* Init the map with random block */
void Level::generate(int nombreCaisses) {
	srand(time(NULL));
	int k = 0;
	int i = 0;
	int j = 0;
	while (k < nombreCaisses) {
		i = rand() % 15;
		j = rand() % 15;
		if (jeu[i][j] != MUR && jeu[i][j] != VIDE && jeu[i][j] != JOUEUR && jeu[i][j] != ADVERSAIRE) {
			jeu[i][j] = CAISSE;
			k++;
		}
	}

	for (int l = 0; l < TAILLE_JEU; l++) {
		for (int m = 0; m < TAILLE_JEU; m++) {
			if (jeu[l][m] != MUR && jeu[l][m] != CAISSE && jeu[l][m] != JOUEUR && jeu[i][j] != ADVERSAIRE) {
				jeu[l][m] = VIDE;
			}
		}
	}
}

/* Build the first level */
void Level::lvl1() {

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
	jeu[7][2] = VIDE;
	jeu[7][12] = VIDE;

	// Empty cases
	for (int i = 1; i < 4; i++) {
		jeu[i][1] = VIDE;
		jeu[1][i] = VIDE;
	}
	for (int i = 11; i < 14; i++){
		jeu[i][13] = VIDE;
		jeu[13][i] = VIDE;
	} 

	// Block
	generate(100);

	jeu[1][1] = JOUEUR;
	jeu[13][13] = ADVERSAIRE;

	// Chargement du sprite
	SDL_Surface * background = SDL_LoadBMP("Sprite/lvl1.bmp");
	niveaux = SDL_CreateTextureFromSurface(renderer, background);
	SDL_FreeSurface(background);
}

/* Build the second level */
void Level::lvl2() {

	// Walls
	for (int i = 0; i < TAILLE_JEU; i++) {
		jeu[i][0] = MUR;
		jeu[i][TAILLE_JEU - 1] = MUR;
	}
	for (int j = 0; j < TAILLE_JEU; j++) {
		jeu[0][j] = MUR;
		jeu[TAILLE_JEU - 1][j] = MUR;
	}
	for (int i = 2; i < 6; i++) {
		jeu[i][7] = MUR;
	}
	for (int i = 9; i < 13; i++) {
		jeu[i][7] = MUR;
	}
	for (int i = 12; i < 14; i++) {
		jeu[i][12] = MUR;
	}

	for (int j = 1; j < 5; j++) {
		jeu[4][j] = MUR;
	}

	for (int j = 8; j < 13; j++){
		jeu[6][j] = MUR;
	}

	for (int j = 2; j < 7; j++){
		jeu[8][j] = MUR;
	}

	for (int j = 10; j < 14; j++){
		jeu[10][j] = MUR;
	}

	jeu[2][2] = MUR;
	jeu[12][12] = MUR;
	jeu[2][4] = MUR;
	jeu[4][12] = MUR;
	jeu[10][2] = MUR;
	jeu[12][10] = MUR;

	// Empty cases
	for (int i = 1; i < 4; i++) {
		jeu[i][1] = VIDE;
		jeu[1][i] = VIDE;
	}
	for (int i = 11; i < 14; i++){
		jeu[i][13] = VIDE;
		jeu[13][i] = VIDE;
	}

	// Block
	for (int i = 8; i < 10; i++){
		jeu[i][1] = CAISSE;
	}
	for (int i = 5; i < 7; i++){
		jeu[i][13] = CAISSE;
	}
	generate(90);

	// Personnages
	jeu[1][1] = JOUEUR;
	jeu[13][13] = ADVERSAIRE;

	// Chargement du sprite
	SDL_Surface * background = SDL_LoadBMP("Sprite/lvl2.bmp");
	niveaux = SDL_CreateTextureFromSurface(renderer, background);
	SDL_FreeSurface(background);
}

/* Build the third level */
void Level::lvl3() {

	// Walls
	for (int i = 0; i < TAILLE_JEU; i++) {
		jeu[i][0] = MUR;
		jeu[i][TAILLE_JEU - 1] = MUR;
	}
	for (int j = 0; j < TAILLE_JEU; j++) {
		jeu[0][j] = MUR;
		jeu[TAILLE_JEU - 1][j] = MUR;
	}
	
	for (int i = 2; i < 13; i += 2){
		for (int j = 2; j < 13; j += 2){
			jeu[i][j] = MUR;
		}
	}

	// Empty cases
	for (int i = 1; i < 4; i++) {
		jeu[i][1] = VIDE;
		jeu[1][i] = VIDE;
	}
	for (int i = 11; i < 14; i++){
		jeu[i][13] = VIDE;
		jeu[13][i] = VIDE;
	}

	// Block
	for (int i = 8; i < 10; i++){
		jeu[i][1] = CAISSE;
	}
	for (int i = 5; i < 7; i++){
		jeu[i][13] = CAISSE;
	}
	generate(90);

	// Personnages
	jeu[1][1] = JOUEUR;
	jeu[13][13] = ADVERSAIRE;

	// Chargement du sprite
	SDL_Surface * background = SDL_LoadBMP("Sprite/lvl3.bmp");
	niveaux = SDL_CreateTextureFromSurface(renderer, background);
	SDL_FreeSurface(background);
}

/* Draw the level */
void Level::draw(bool pause){
	SDL_RenderCopy(renderer, niveaux, NULL, &fond);
	SDL_Rect rect = { 0, 0, 35, 35 };
	SDL_Rect rect2 = { 0, 0, 25, 25 };

	for (int k = 0; k < TAILLE_JEU; k++){
		for (int j = 0; j < TAILLE_JEU; j++){
			rect.x = k * 35;
			rect.y = j * 35;
			rect2.x = k * 35+5;
			rect2.y = j * 35+5;

			switch (jeu[k][j]){
			case MUR:
				SDL_RenderCopy(renderer, mur, NULL, &rect);
				break;

			case CAISSE:
				SDL_RenderCopy(renderer, caisse, NULL, &rect);
				break;

			case JOUEUR:
				prncp->draw();
				break;

			case BOMBE: case JOUEUR_BOMBE: case BOMBE_EXPLOSION: case ADVERSAIRE_BOMBE:
				Bombe* bombes;
				bombes = prncp->getBombes_tab();
				Bombe* bombes_adv;
				bombes_adv = ennemi->getBombes_tab();
			
				for (int i = 0; i < 2; i++) {
					if (&bombes[i] != NULL) {

						if (pause)
							bombes[i].put_off();
						else{
							bombes[i].put_on();
							bombes[i].event(jeu);
						}

						// Print the Bombe
						if (rect.x == (bombes[i].getColone() * 35) && rect.y == (bombes[i].getLine() * 35)) {
							if (bombes[i].getExplosee() == 0) {
								SDL_RenderCopy(renderer, bombes[i].texture[0], NULL, &rect);
							}
							if (bombes[i].getExplosee() == 1) {
								SDL_RenderCopy(renderer, bombes[i].texture[1], NULL, &rect);
							}
							if (bombes[i].getExplosee() == 2) {
								SDL_RenderCopy(renderer, bombes[i].texture[1], NULL, &rect);
								if (!musique){
									Mix_PlayChannel(2, explosion, 0);
									musique = true;
								}
								if (bombes[i].getPerdreVie()){
									if (i == 0 || i == 1){
										prncp->die();
										bombes[i].setPerdreVie();
									}
								}
							}
							if (bombes[i].getExplosee() == 3) {
								bombes[i].setLine(-1);
								musique = false;
							}
							break;
						}
					}
					if (&bombes_adv[i] != NULL) {

						if (pause)
							bombes_adv[i].put_off();
						else{
							bombes_adv[i].put_on();
							bombes_adv[i].event(jeu);
						}

						// Print the Bombe
						if (rect.x == (bombes_adv[i].getColone() * 35) && rect.y == (bombes_adv[i].getLine() * 35)) {
							if (bombes_adv[i].getExplosee() == 0) {
								SDL_RenderCopy(renderer, bombes_adv[i].texture[0], NULL, &rect);
							}
							if (bombes_adv[i].getExplosee() == 1) {
								SDL_RenderCopy(renderer, bombes_adv[i].texture[1], NULL, &rect);
							}
							if (bombes_adv[i].getExplosee() == 2) {
								SDL_RenderCopy(renderer, bombes_adv[i].texture[1], NULL, &rect);
								if (!musique){
									Mix_PlayChannel(2, explosion, 0);
									musique = true;
								}
							}
							if (bombes_adv[i].getExplosee() == 3) {
								bombes_adv[i].setLine(-1);
								musique = false;
							}
							break;
						}
					}
				}
				if (jeu[k][j] == JOUEUR_BOMBE){
					prncp->draw();
				}
				if (jeu[k][j] == BOMBE_EXPLOSION){
					SDL_RenderCopy(renderer, flamme, NULL, &rect2);
				}
				break;

			case JOUEUR_EXPLOSION:
				SDL_RenderCopy(renderer, flamme, NULL, &rect2);
				prncp->draw();
				break;

			case CAISSE_EXPLOSION:
				SDL_RenderCopy(renderer, caisse, NULL, &rect);
				SDL_RenderCopy(renderer, flamme, NULL, &rect2);
				break;

			case EXPLOSION: case EXPLOSION_EXPLOSION:
				SDL_RenderCopy(renderer, flamme, NULL, &rect2);
				break;

			case ADVERSAIRE:
				ennemi->draw();
				break;

			case ADVERSAIRE_EXPLOSION:
				ennemi->setDie();
				break;
			}
		}
	}

	// Pause screen
	if (prncp->getLife() <= 0){
		SDL_RenderCopy(renderer, over_text, NULL, &fond);
		IsDead = true;
	}
	if (ennemi->die()){
		SDL_RenderCopy(renderer, vict_text, NULL, &fond);
		NextLevel = true;
	}
	else{
		if (pause){
			SDL_RenderCopy(renderer, pause_text, NULL, &fond);
		}
	}
}