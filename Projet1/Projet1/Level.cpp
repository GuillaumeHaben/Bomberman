#include "Level.h"

/* Constructor */
Level::Level() {

}

Level::Level(Case_plateau* * plat, Joueur* J) {
	jeu = plat;
	prncp = J;

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

	img[0] = SDL_LoadBMP("Sprite/caisse.bmp");
	img[1] = SDL_LoadBMP("Sprite/mur.bmp");

	mur = SDL_CreateTextureFromSurface(renderer, img[1]);
	caisse = SDL_CreateTextureFromSurface(renderer, img[0]);

	SDL_FreeSurface(img[0]);
	SDL_FreeSurface(img[1]);

	explosion = Mix_LoadWAV("Sprite/canon.wav");
}

Level::~Level(){
	SDL_DestroyTexture(pause_text);
	SDL_DestroyTexture(over_text);
	SDL_DestroyTexture(flamme);
}

/* To setup the game */
void Level::setUpGame(int niveau) {
	this->niveau = niveau;
	

	switch (niveau) {
	case 1:
		lvl1();		
		break;
	case 2:
		break;
	case 3:
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
		if (jeu[i][j] != MUR && jeu[i][j] != VIDE && jeu[i][j] != JOUEUR) {
			jeu[i][j] = CAISSE;
			k++;
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

	// Player
	jeu[1][1] = JOUEUR;

	// Empty cases
	for (int i = 2; i < 4; i++) {
		jeu[i][1] = VIDE;
		jeu[1][i] = VIDE;
	}
	for (int i = 11; i < 13; i++){
		jeu[i][13] = VIDE;
		jeu[13][i] = VIDE;
	}

	// Block
	generate(80);

	// Chargement du sprite
	SDL_Surface * background = SDL_LoadBMP("Sprite/lvl1.bmp");
	niveaux = SDL_CreateTextureFromSurface(renderer, background);
	SDL_FreeSurface(background);
}

/* Draw the level */
void Level::draw(bool pause){
	SDL_RenderCopy(renderer, niveaux, NULL, &fond);
	SDL_Rect rect = { 0, 0, 35, 35 };

	for (int k = 0; k < TAILLE_JEU; k++){
		for (int j = 0; j < TAILLE_JEU; j++){
			rect.x = k * 35;
			rect.y = j * 35;

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

			case BOMBE: case JOUEUR_BOMBE:
				Bombe* bombes;
				bombes = prncp->getBombes_tab();
				for (int i = 0; i < NB_BOMBES_MAX; i++) {
					if (&bombes[i] != NULL) {

						// Check if the bombe should be active or not
						if (pause){
							bombes[i].put_off();
						}else{
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
							}
							if (bombes[i].getExplosee() == 3) {
								bombes[i].setLine(-1);
								Mix_PlayChannel(2, explosion, 0);
							}
						}
					}
					if (jeu[k][j] == JOUEUR_BOMBE){
						prncp->draw();
					}
				}
				break;
			
			case JOUEUR_EXPLOSION:	
				SDL_RenderCopy(renderer, flamme, NULL, &rect);
				prncp->draw();
				break;

			case CAISSE_EXPLOSION:
				SDL_RenderCopy(renderer, caisse, NULL, &rect);
				SDL_RenderCopy(renderer, flamme, NULL, &rect);
				break;

			case EXPLOSION: 
				SDL_RenderCopy(renderer, flamme, NULL, &rect);
				break;
			}
		}
	}

	// Pause screen
	if (prncp->getLife() <= 0){
		SDL_RenderCopy(renderer, over_text, NULL, &rect);
		IsDead = true;
	}else{
		if (pause) SDL_RenderCopy(renderer, pause_text, NULL, &fond);
	}
}