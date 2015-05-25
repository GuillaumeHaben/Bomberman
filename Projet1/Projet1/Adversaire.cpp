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
	done = false;
	last_dep = LEFT;
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
				//recherche_chemin_recursive(jeu, chemin, 0, p_colone, p_line, player);
				//done = false;
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
				//recherche_chemin_recursive(jeu, chemin, 0, p_colone, p_line, player);
				//done = false;
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
				//recherche_chemin_recursive(jeu, chemin, 0, p_colone, p_line, player);
				//done = false;
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
				//recherche_chemin_recursive(jeu, chemin, 0, p_colone, p_line, player);
				//done = false;
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

	if (done){
		recherche_chemin_recursive(jeu, chemin, 0, i, j, player, last_dep);
		deplacement(chemin[0], jeu, player);
		done = true;
	}
	else{
		deplacement(chemin[0], jeu, player);
		done = true;
	}
}


bool Adversaire::recherche_chemin_recursive(Case_plateau* * jeu, int* chemin, int taille_chemin, int i, int j, Joueur *player, int direction) {

	if (taille_chemin > 35)	return false;
	if (i - 1 < 0 || j - 1 < 0) return false;
	if (i + 1 >= TAILLE_JEU || j + 1 >= TAILLE_JEU) return false;

	if (jeu[i][j] == JOUEUR) {
		return true;
	}
	else{

		if (jeu[i][j - 1] != MUR && jeu[i][j - 1] != BOMBE && jeu[i][j - 1] != JOUEUR_BOMBE && direction != DOWN){

			// On essaie gauche
			if (recherche_chemin_recursive(jeu, chemin, taille_chemin + 1, i, j - 1, player, UP)) {
				chemin[taille_chemin] = UP;
				return true;
			}
		}

		if (jeu[i - 1][j] != MUR && jeu[i - 1][j] != BOMBE && jeu[i - 1][j] != JOUEUR_BOMBE && direction != RIGHT){

			// On essaie gauche
			if (recherche_chemin_recursive(jeu, chemin, taille_chemin + 1, i - 1, j, player, LEFT)) {
				chemin[taille_chemin] = LEFT;
				return true;
			}
		}


		if (jeu[i + 1][j] != MUR && jeu[i + 1][j] != BOMBE && jeu[i + 1][j] != JOUEUR_BOMBE && direction != LEFT){

			// On essaie droite
			if (recherche_chemin_recursive(jeu, chemin, taille_chemin + 1, i + 1, j, player, RIGHT)) {
				chemin[taille_chemin] = RIGHT;
				return true;
			}
		}

		if (jeu[i][j + 1] != MUR && jeu[i][j + 1] != BOMBE && jeu[i][j + 1] != JOUEUR_BOMBE && direction != UP){

			// On essaie de descendre
			if (recherche_chemin_recursive(jeu, chemin, taille_chemin + 1, i, j + 1, player, DOWN)) {
				chemin[taille_chemin] = DOWN;
				return true;
			}
		}
	}
	return false;
}