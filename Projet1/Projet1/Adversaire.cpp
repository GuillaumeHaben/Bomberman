#include "Adversaire.h"
#include "SDL/SDL_image.h"


/* Constructeur */
Adversaire::Adversaire() : Personnage(){
	init_var();
	init_load();
}

/* Appel au super en C++ */
Adversaire::Adversaire(int pos_x, int pos_y) : Personnage(pos_x, pos_y) {
	init_var();
	init_load();
}

/* Destructeur */
Adversaire::~Adversaire(){
	SDL_DestroyTexture(texture);
}

Bombe* Adversaire::getBombes_tab() {
	return bombes_tab;
}

void Adversaire::init_var(){
	nb_bombes = 0;
	nb_bombes_max = NB_BOMBES_MAX;
	dest = { 35*13, 35*13, 35, 35 };
}

void Adversaire::init_load(){
	SDL_Surface* background = IMG_Load("Sprite/advers.png");
	texture = SDL_CreateTextureFromSurface(renderer, background);
	SDL_FreeSurface(background);
}

int Adversaire::deplacement(int direction, Case_plateau* * jeu){

	switch (direction){

	case UP: if (p_line - 1 < 0) break;
			 else{
				 if (jeu[p_colone][p_line - 1] == MUR || jeu[p_colone][p_line - 1] == CAISSE) break;
				 else{
					 if (jeu[p_colone][p_line] == JOUEUR_BOMBE){
						 jeu[p_colone][p_line] = BOMBE;
					 }
					 else jeu[p_colone][p_line] = VIDE;

					 if (jeu[p_colone][p_line - 1] == BOMBE){
						 jeu[p_colone][p_line - 1] = JOUEUR_BOMBE;
					 }
					 else jeu[p_colone][p_line - 1] = JOUEUR;
					 --p_line;
					 return 0;
				 }
			 }

	case DOWN:
		if (p_line + 1 >= TAILLE_JEU) break;
		else{
			if (jeu[p_colone][p_line + 1] == MUR || jeu[p_colone][p_line + 1] == CAISSE) break;
			else{
				if (jeu[p_colone][p_line] == JOUEUR_BOMBE){
					jeu[p_colone][p_line] = BOMBE;
				}
				else jeu[p_colone][p_line] = VIDE;

				if (jeu[p_colone][p_line + 1] == BOMBE){
					jeu[p_colone][p_line + 1] = JOUEUR_BOMBE;
				}
				else jeu[p_colone][p_line + 1] = JOUEUR;
				++p_line;
				return 0;
			}
		}

	case RIGHT:
		if (p_colone + 1 >= TAILLE_JEU) break;
		else{
			if (jeu[p_colone + 1][p_line] == MUR || jeu[p_colone + 1][p_line] == CAISSE) break;
			else{
				if (jeu[p_colone][p_line] == JOUEUR_BOMBE){
					jeu[p_colone][p_line] = BOMBE;
				}
				else jeu[p_colone][p_line] = VIDE;

				if (jeu[p_colone + 1][p_line] == BOMBE){
					jeu[p_colone + 1][p_line] = JOUEUR_BOMBE;
				}
				else jeu[p_colone + 1][p_line] = JOUEUR;
				++p_colone;
				return 0;
			}
		}

	case LEFT:
		if (p_colone - 1 < 0) break;
		else{
			if (jeu[p_colone - 1][p_line] == MUR || jeu[p_colone - 1][p_line] == CAISSE) break;
			else{
				if (jeu[p_colone][p_line] == JOUEUR_BOMBE){
					jeu[p_colone][p_line] = BOMBE;
				}
				else jeu[p_colone][p_line] = VIDE;

				if (jeu[p_colone - 1][p_line] == BOMBE){
					jeu[p_colone - 1][p_line] = JOUEUR_BOMBE;
				}
				else jeu[p_colone - 1][p_line] = JOUEUR;
				--p_colone;
				return 0;
			}
		}

	}
	return -1;
}

void Adversaire::event(Case_plateau* * jeu){

}

void Adversaire::draw(){
	SDL_RenderCopy(renderer, texture, NULL, &dest);
			}

void Adversaire::recherche_chemin(Case_plateau* * jeu, Joueur *player) {
	chemin = (int *) malloc(sizeof(int));
	taille_chemin = 0;
	int i = p_colone;
	int j = p_line;
	recherche_chemin_recursive(jeu, chemin, taille_chemin, i, j, player);
}

bool Adversaire::recherche_chemin_recursive(Case_plateau* * jeu, int* chemin, int taille_chemin, int i, int j, Joueur *player) {
	if (jeu[i][j] == JOUEUR) {
		return true;
	}
	else {
		if (jeu[i][j] == MUR || jeu[i][j] == BOMBE) return false;
		else {
			if (player->getLine() >= j) {
				if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i, j - 1, player)) {
					chemin[taille_chemin] = UP;
					return true;
				}
				else {
					if (player->getColone() <= i) {
						if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i - 1, j, player)) {
							chemin[taille_chemin] = LEFT;
							return true;
						}
						else {
							if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i + 1, j, player)) {
								chemin[taille_chemin] = RIGHT;
								return true;
							}
						}
					}
					else {
						if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i + 1, j, player)) {
							chemin[taille_chemin] = RIGHT;
							return true;
						}
						else {
							if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i - 1, j, player)) {
								chemin[taille_chemin] = LEFT;
								return true;
							}
						}
					}
				}
			}
			else { //x < i
				if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i, j + 1, player)) {
					chemin[taille_chemin] = DOWN;
					return true;
				}
				else {
					if (player->getColone() > j) {
						if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i + 1, j, player)) {
							chemin[taille_chemin] = RIGHT;
							return true;
						}
						else {
							if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i - 1, j, player)) {
								chemin[taille_chemin] = LEFT;
								return true;
							}
						}
					}
					else {
						if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i - 1, j, player)) {
							chemin[taille_chemin] = LEFT;
							return true;
						}
						else {
							if (recherche_chemin_recursive(jeu, chemin, taille_chemin++, i + 1, j, player)) {
								chemin[taille_chemin] = RIGHT;
								return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}