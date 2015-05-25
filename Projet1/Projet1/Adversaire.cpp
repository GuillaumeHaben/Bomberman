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
		if (p_line - 1 < 0 || jeu[p_colone][p_line - 1] == BOMBE || jeu[p_colone][p_line - 1] == BOMBE_EXPLOSION) {
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
						jeu[p_colone][p_line] = ADVERSAIRE;
					}else{
						if (bombes_tab[0].getBoom()){
							if (!(bombes_tab[1].getLine() == p_line && bombes_tab[1].getColone() == p_colone)) {
								bombes_tab[0].init(p_colone, p_line);
								deplacement(last_deplacement, jeu, player);
								jeu[p_colone][p_line] = ADVERSAIRE;
							}
						}else{
							if (bombes_tab[1].getBoom()){
								if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)) {
									bombes_tab[1].init(p_colone, p_line);
									deplacement(last_deplacement, jeu, player);
									jeu[p_colone][p_line] = ADVERSAIRE;
								}	
							}
						}
					}
				}
			}
			else{
				p_line--;
				jeu[p_colone][p_line] = ADVERSAIRE;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				last_deplacement = DOWN;
				return 0;
			}
		}
	break;

	case DOWN:
		if (p_line + 1 >= TAILLE_JEU || jeu[p_colone][p_line + 1] == BOMBE || jeu[p_colone][p_line + 1] == BOMBE_EXPLOSION) {
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
						jeu[p_colone][p_line] = ADVERSAIRE;
					}
					else{
						if (bombes_tab[0].getBoom()){
							if (!(bombes_tab[1].getLine() == p_line && bombes_tab[1].getColone() == p_colone)) {
								bombes_tab[0].init(p_colone, p_line);
								deplacement(last_deplacement, jeu, player);
								jeu[p_colone][p_line] = ADVERSAIRE;
							}
						}
						else{
							if (bombes_tab[1].getBoom()){
								if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)) {
									bombes_tab[1].init(p_colone, p_line);
									deplacement(last_deplacement, jeu, player);
									jeu[p_colone][p_line] = ADVERSAIRE;
								}
							}
						}
					}
				}
			}
			else{
				p_line++;
				jeu[p_colone][p_line] = ADVERSAIRE;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				last_deplacement = UP;
				return 0;
			}
		}
		break;

	case RIGHT:
		if (p_colone + 1 >= TAILLE_JEU || jeu[p_colone + 1][p_line] == BOMBE || jeu[p_colone + 1][p_line] == BOMBE_EXPLOSION) {
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
						jeu[p_colone][p_line] = ADVERSAIRE;
					}
					else{
						if (bombes_tab[0].getBoom()){
							if (!(bombes_tab[1].getLine() == p_line && bombes_tab[1].getColone() == p_colone)) {
								bombes_tab[0].init(p_colone, p_line);
								deplacement(last_deplacement, jeu, player);
								jeu[p_colone][p_line] = ADVERSAIRE;
							}
						}
						else{
							if (bombes_tab[1].getBoom()){
								if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)) {
									bombes_tab[1].init(p_colone, p_line);
									deplacement(last_deplacement, jeu, player);
									jeu[p_colone][p_line] = ADVERSAIRE;
								}
							}
						}
					}
				}
			}
			else{
				p_colone++;
				jeu[p_colone][p_line] = ADVERSAIRE;
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
				last_deplacement = LEFT;
				return 0;
			}
		}
		break;

	case LEFT:
		if (p_colone - 1 < 0 || jeu[p_colone - 1][p_line] == BOMBE || jeu[p_colone - 1][p_line] == BOMBE_EXPLOSION) {
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
						jeu[p_colone][p_line] = ADVERSAIRE;

					}
					else{
						if (bombes_tab[0].getBoom()){
							if (!(bombes_tab[1].getLine() == p_line && bombes_tab[1].getColone() == p_colone)) {
								bombes_tab[0].init(p_colone, p_line);
								deplacement(last_deplacement, jeu, player);
								jeu[p_colone][p_line] = ADVERSAIRE;
							}
						}
						else{
							if (bombes_tab[1].getBoom()){
								if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone)) {
									bombes_tab[1].init(p_colone, p_line);
									deplacement(last_deplacement, jeu, player);
									jeu[p_colone][p_line] = ADVERSAIRE;
								}
							}
						}
					}
				}
			}
			else{
				p_colone--;
				jeu[p_colone][p_line] = ADVERSAIRE;
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


		if (recherche_chemin_recursive(jeu, chemin, 0, i, j, player, last_dep)){
			deplacement(chemin[0], jeu, player);
		}
		else{
			int a = last_dep;
			if (a == 0 || a == 2){
				a++;
			}
			else{
				if (a == 1){
					a = 0;
				}
				else a = 2;

				deplacement(a, jeu, player);
			}
		}
}


bool Adversaire::recherche_chemin_recursive(Case_plateau* * jeu, int* chemin, int taille_chemin, int i, int j, Joueur *player, int direction) {

	if (taille_chemin > 50)	return false;
	if (i - 1 < 0 || j - 1 < 0) return false;
	if (i + 1 >= TAILLE_JEU || j + 1 >= TAILLE_JEU) return false;
	int x = player->getColone();
	int y = player->getLine();

	if (jeu[i][j] == jeu[x][y]) {
		return true;
	}
	else{

		if (jeu[i][j - 1] != MUR && jeu[i][j - 1] != BOMBE && jeu[i][j - 1] != JOUEUR_BOMBE && jeu[i][j - 1] != EXPLOSION && jeu[i][j - 1] != EXPLOSION_EXPLOSION 
			&& jeu[i][j - 1] != JOUEUR_EXPLOSION && jeu[i][j - 1] != BOMBE_EXPLOSION  && direction != DOWN){

			// On essaie haut
			if (recherche_chemin_recursive(jeu, chemin, taille_chemin + 1, i, j - 1, player, UP)) {
				chemin[taille_chemin] = UP;
				return true;
			}
		}

		if (jeu[i - 1][j] != MUR && jeu[i - 1][j] != BOMBE && jeu[i - 1][j] != JOUEUR_BOMBE && jeu[i - 1][j] != EXPLOSION && jeu[i - 1][j] != EXPLOSION_EXPLOSION
			&& jeu[i - 1][j] != JOUEUR_EXPLOSION && jeu[i - 1][j] != BOMBE_EXPLOSION  && direction != RIGHT){

			// On essaie gauche
			if (recherche_chemin_recursive(jeu, chemin, taille_chemin + 1, i - 1, j, player, LEFT)) {
				chemin[taille_chemin] = LEFT;
				return true;
			}
		}


		if (jeu[i + 1][j] != MUR && jeu[i + 1][j] != BOMBE && jeu[i + 1][j] != JOUEUR_BOMBE && jeu[i + 1][j] != EXPLOSION && jeu[i + 1][j] != EXPLOSION_EXPLOSION
			&& jeu[i + 1][j] != JOUEUR_EXPLOSION && jeu[i + 1][j] != BOMBE_EXPLOSION  && direction != LEFT){

			// On essaie droite
			if (recherche_chemin_recursive(jeu, chemin, taille_chemin + 1, i + 1, j, player, RIGHT)) {
				chemin[taille_chemin] = RIGHT;
				return true;
			}
		}

		if (jeu[i][j + 1] != MUR && jeu[i][j + 1] != BOMBE && jeu[i][j + 1] != JOUEUR_BOMBE && jeu[i][j + 1] != EXPLOSION && jeu[i][j + 1] != EXPLOSION_EXPLOSION
			&& jeu[i][j + 1] != JOUEUR_EXPLOSION && jeu[i][j + 1] != BOMBE_EXPLOSION && direction != UP){

			// On essaie de descendre
			if (recherche_chemin_recursive(jeu, chemin, taille_chemin + 1, i, j + 1, player, DOWN)) {
				chemin[taille_chemin] = DOWN;
				return true;
			}
		}
	}
	return false;
}