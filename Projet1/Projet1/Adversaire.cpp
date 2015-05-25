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
	p_colone = 13;
	p_line = 13;
	mort = false;
}

void Adversaire::init_load(){
	SDL_Surface* background = IMG_Load("Sprite/advers.png");
	texture = SDL_CreateTextureFromSurface(renderer, background);
	SDL_FreeSurface(background);
}

bool Adversaire::die(){
	return mort;
}

void Adversaire::setDie(){
	mort = true;
}

int Adversaire::deplacement(int direction, Case_plateau* * jeu, Joueur *player){
	switch (direction){

	case UP:
		if (p_line - 1 < 0) {
			break;
		}
		else{
			if (jeu[p_colone][p_line - 1] == MUR || jeu[p_colone][p_line - 1] == CAISSE) {
				if (jeu[p_colone][p_line - 1] == CAISSE) {
					jeu[p_colone][p_line] = BOMBE;
					if (nb_bombes < NB_BOMBES_MAX){
						Bombe nouvelle_bombe(p_colone, p_line);
						if (nb_bombes == 1){
							if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)){
								bombes_tab[nb_bombes] = nouvelle_bombe;
								nb_bombes++;
							}
						}else{
							bombes_tab[nb_bombes] = nouvelle_bombe;
							nb_bombes++;
						}
						
						deplacement(last_deplacement, jeu, player);
					}else{
						if (bombes_tab[0].getBoom()){
							if (!(bombes_tab[1].getLine() == p_line && bombes_tab[1].getColone() == p_colone)) {
								bombes_tab[0].init(p_colone, p_line);
								deplacement(last_deplacement, jeu, player);
							}
						}else{
							if (bombes_tab[1].getBoom()){
								if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)) {
									bombes_tab[1].init(p_colone, p_line);
									deplacement(last_deplacement, jeu, player);
								}	
							}
						}
					}
				}
			}
			else{
				jeu[p_colone][p_line - 1] = ADVERSAIRE;
				--p_line;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				last_deplacement = DOWN;
				return 0;
			}
		}
	break;

	case DOWN:
		if (p_line + 1 >= TAILLE_JEU) {
			break;
		}
		else{
			if (jeu[p_colone][p_line + 1] == MUR || jeu[p_colone][p_line + 1] == CAISSE) {
				if (jeu[p_colone][p_line + 1] == CAISSE) {
					jeu[p_colone][p_line] = BOMBE;
					if (nb_bombes < NB_BOMBES_MAX){
						Bombe nouvelle_bombe(p_colone, p_line);
						if (nb_bombes == 1){
							if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)){
								bombes_tab[nb_bombes] = nouvelle_bombe;
								nb_bombes++;
							}
						}
						else{
							bombes_tab[nb_bombes] = nouvelle_bombe;
							nb_bombes++;
						}
						deplacement(last_deplacement, jeu, player);
					}
					else{
						if (bombes_tab[0].getBoom()){
							if (!(bombes_tab[1].getLine() == p_line && bombes_tab[1].getColone() == p_colone)) {
								bombes_tab[0].init(p_colone, p_line);
								deplacement(last_deplacement, jeu, player);
							}
						}
						else{
							if (bombes_tab[1].getBoom()){
								if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)) {
									bombes_tab[1].init(p_colone, p_line);
									deplacement(last_deplacement, jeu, player);
								}
							}
						}
					}
				}
			}
			else{
				jeu[p_colone][p_line + 1] = ADVERSAIRE;
				++p_line;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				last_deplacement = UP;
				return 0;
			}
		}
		break;

	case RIGHT:
		if (p_colone + 1 >= TAILLE_JEU) {
			break;
		}
		else{
			if (jeu[p_colone + 1][p_line] == MUR || jeu[p_colone + 1][p_line] == CAISSE) {
				if (jeu[p_colone + 1][p_line] == CAISSE) {
					jeu[p_colone][p_line] = BOMBE;
					if (nb_bombes < NB_BOMBES_MAX){
						Bombe nouvelle_bombe(p_colone, p_line);
						if (nb_bombes == 1){
							if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)){
								bombes_tab[nb_bombes] = nouvelle_bombe;
								nb_bombes++;
							}
						}
						else{
							bombes_tab[nb_bombes] = nouvelle_bombe;
							nb_bombes++;
						}
						deplacement(last_deplacement, jeu, player);
					}
					else{
						if (bombes_tab[0].getBoom()){
							if (!(bombes_tab[1].getLine() == p_line && bombes_tab[1].getColone() == p_colone)) {
								bombes_tab[0].init(p_colone, p_line);
								deplacement(last_deplacement, jeu, player);
							}
						}
						else{
							if (bombes_tab[1].getBoom()){
								if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)) {
									bombes_tab[1].init(p_colone, p_line);
									deplacement(last_deplacement, jeu, player);
								}
							}
						}
					}
				}
			}
			else{
				jeu[p_colone + 1][p_line] = ADVERSAIRE;
				++p_colone;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				last_deplacement = LEFT;
				return 0;
			}
		}
		break;

	case LEFT:
		if (p_colone - 1 < 0) {
			break;
		}
		else{
			if (jeu[p_colone - 1][p_line] == MUR || jeu[p_colone - 1][p_line] == CAISSE) {
				if (jeu[p_colone - 1][p_line] == CAISSE) {
					jeu[p_colone][p_line] = BOMBE;
					if (nb_bombes < NB_BOMBES_MAX){
						Bombe nouvelle_bombe(p_colone, p_line);
						if (nb_bombes == 1){
							if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)){
								bombes_tab[nb_bombes] = nouvelle_bombe;
								nb_bombes++;
							}
						}
						else{
							bombes_tab[nb_bombes] = nouvelle_bombe;
							nb_bombes++;
						}
						deplacement(last_deplacement, jeu, player);
					}
					else{
						if (bombes_tab[0].getBoom()){
							if (!(bombes_tab[1].getLine() == p_line && bombes_tab[1].getColone() == p_colone)) {
								bombes_tab[0].init(p_colone, p_line);
								deplacement(last_deplacement, jeu, player);
							}
						}
						else{
							if (bombes_tab[1].getBoom()){
								if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)) {
									bombes_tab[1].init(p_colone, p_line);
									deplacement(last_deplacement, jeu, player);
								}
							}
						}
					}
				}
			}
			else{
				jeu[p_colone - 1][p_line] = ADVERSAIRE;
				--p_colone;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				last_deplacement = RIGHT;
				return 0;
			}
		}
		break;
	}
	return -1;
}

void Adversaire::draw(){
	dest.h = 35;
	dest.w = 35;
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}

void Adversaire::recherche_chemin(Case_plateau* * jeu, Joueur *player, int l) {
	int i = p_colone;
	int j = p_line;
	if (recherche_chemin_recursive(jeu, chemin, 0, i, j, player)){
		deplacement(chemin[l], jeu, player);
	}
}

bool Adversaire::recherche_chemin_recursive(Case_plateau* * jeu, int* chemin, int taille_chemin, int i, int j, Joueur *player) {
	
	if (taille_chemin > 35){
		return false;
	}
	
	if (jeu[i][j] == JOUEUR) {
		return true;
	}
	else {
		if (jeu[i][j] == MUR) {
			return false;
		}
		if (jeu[i][j] == BOMBE) {

		}
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