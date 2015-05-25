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
}

Bombe* Adversaire::getBombes_tab() {
	return bombes_tab;
}

void Adversaire::init_var(){
	nb_bombes = 0;
	nb_bombes_max = NB_BOMBES_MAX;
	dest = { 35*13, 35*13, 35, 35 };
	chemin = (int *)malloc(sizeof(int));
}

void Adversaire::init_load(){
	SDL_Surface* background = IMG_Load("Sprite/advers.png");
	texture = SDL_CreateTextureFromSurface(renderer, background);
	SDL_FreeSurface(background);
}

int Adversaire::deplacement(int direction, Case_plateau* * jeu){
	int i = 0;
	switch (chemin[i]){

	case UP:
		if (p_line - 1 < 0) {
			i++;
			break;
		}
			 else{
				 if (jeu[p_colone][p_line - 1] == MUR || jeu[p_colone][p_line - 1] == CAISSE) break;
				 else{
					 /*if (jeu[p_colone][p_line] == JOUEUR_BOMBE){
						 jeu[p_colone][p_line] = BOMBE;
					 }
					 else jeu[p_colone][p_line] = VIDE;

					 if (jeu[p_colone][p_line - 1] == BOMBE){
						 jeu[p_colone][p_line - 1] = JOUEUR_BOMBE;
					 }
					 else*/ jeu[p_colone][p_line - 1] = ADVERSAIRE;
					 --p_line;
					 dest.x = p_colone * 35;
					 dest.y = p_line * 35;
					 return 0;
				 }
			i++;
			 }

	case DOWN:
		if (p_line + 1 >= TAILLE_JEU) {
			i++;
			break;
		}
		else{
			if (jeu[p_colone][p_line + 1] == MUR || jeu[p_colone][p_line + 1] == CAISSE) break;
			else{
				/*if (jeu[p_colone][p_line] == JOUEUR_BOMBE){
					jeu[p_colone][p_line] = BOMBE;
				}
				else jeu[p_colone][p_line] = VIDE;

				if (jeu[p_colone][p_line + 1] == BOMBE){
					jeu[p_colone][p_line + 1] = JOUEUR_BOMBE;
				}
				else*/ jeu[p_colone][p_line + 1] = ADVERSAIRE;
				++p_line;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				return 0;
			}
			i++;
		}

	case RIGHT:
		if (p_colone + 1 >= TAILLE_JEU) {
			i++;
			break;
		}
		else{
			if (jeu[p_colone + 1][p_line] == MUR || jeu[p_colone + 1][p_line] == CAISSE) break;
			else{
				/*if (jeu[p_colone][p_line] == JOUEUR_BOMBE){
					jeu[p_colone][p_line] = BOMBE;
				}
				else jeu[p_colone][p_line] = VIDE;

				if (jeu[p_colone + 1][p_line] == BOMBE){
					jeu[p_colone + 1][p_line] = JOUEUR_BOMBE;
				}
				else*/ jeu[p_colone + 1][p_line] = ADVERSAIRE;
				++p_colone;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				return 0;
			}
			i++;
		}

	case LEFT:
		if (p_colone - 1 < 0) {
			i++;
			break;
		}
		else{
			if (jeu[p_colone - 1][p_line] == MUR || jeu[p_colone - 1][p_line] == CAISSE) break;
			else{
				/*if (jeu[p_colone][p_line] == JOUEUR_BOMBE){
					jeu[p_colone][p_line] = BOMBE;
				}
				else jeu[p_colone][p_line] = VIDE;

				if (jeu[p_colone - 1][p_line] == BOMBE){
					jeu[p_colone - 1][p_line] = JOUEUR_BOMBE;
				}
				else*/ jeu[p_colone - 1][p_line] = ADVERSAIRE;
				--p_colone;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				return 0;
			}
			i++;
		}
	}
	return -1;
}

void Adversaire::draw(){
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Adversaire::recherche_chemin(Case_plateau* * jeu, Joueur *player) {
	int i = p_colone;
	int j = p_line;
	if (recherche_chemin_recursive(jeu, chemin, 0, i, j, player)){
		deplacement(chemin[0], jeu);
	}
}

bool Adversaire::recherche_chemin_recursive(Case_plateau* * jeu, int* chemin, int taille_chemin, int i, int j, Joueur *player) {
	
	if (taille_chemin > 20){
		return false;
	}
	
	if (jeu[i][j] == JOUEUR) {
		return true;
	}
	else {
		if (jeu[i][j] == MUR || jeu[i][j] == BOMBE) return false;
		else {
			if (player->getLine() < j) {
				if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i, j - 1, player)) {
					chemin[taille_chemin] = UP;
					return true;
				}
				else {
					if (player->getColone() <= i) {
						if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i - 1, j, player)) {
							chemin[taille_chemin] = LEFT;
							return true;
						}
						else {
							if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i + 1, j, player)) {
								chemin[taille_chemin] = RIGHT;
								return true;
							}
						}
					}
					else {
						if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i + 1, j, player)) {
							chemin[taille_chemin] = RIGHT;
							return true;
						}
						else {
							if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i - 1, j, player)) {
								chemin[taille_chemin] = LEFT;
								return true;
							}
						}
					}
				}
			}
			else { //x < i
				if (player->getLine() == j){
					if (player->getColone() > j) {
						if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i + 1, j, player)) {
							chemin[taille_chemin] = RIGHT;
							return true;
						}
						else {
							if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i - 1, j, player)) {
								chemin[taille_chemin] = LEFT;
								return true;
							}
						}
					}

				}
				else{
					if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i, j + 1, player)) {
					chemin[taille_chemin] = DOWN;
					return true;
				}
				else {
					if (player->getColone() > j) {
							if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i + 1, j, player)) {
							chemin[taille_chemin] = RIGHT;
							return true;
						}
						else {
								if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i - 1, j, player)) {
								chemin[taille_chemin] = LEFT;
								return true;
							}
						}
					}
					else {
							if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i - 1, j, player)) {
							chemin[taille_chemin] = LEFT;
							return true;
						}
						else {
								if (recherche_chemin_recursive(jeu, chemin, taille_chemin+1, i + 1, j, player)) {
								chemin[taille_chemin] = RIGHT;
								return true;
							}
						}
					}
				}
			}
		}
	}
	}
	return false;
}