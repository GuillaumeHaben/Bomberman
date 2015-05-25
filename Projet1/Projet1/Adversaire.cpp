#include "Adversaire.h"
#include "SDL/SDL_image.h"


/* Constructeur */
Adversaire::Adversaire() : Personnage(){
	init_var();
	init_load();
	murs = new int* [TAILLE_JEU];
	danger = new int* [TAILLE_JEU];
	int dim_allouee;
	for (dim_allouee = 0; dim_allouee < TAILLE_JEU; ++dim_allouee) {
		murs[dim_allouee] = new int[TAILLE_JEU];
		danger[dim_allouee] = new int[TAILLE_JEU];
	}
	for (int i = 0; i < TAILLE_JEU; i++)
		for (int j = 0; j < TAILLE_JEU; j++) {
			murs[i][j] = 0;
			danger[i][j] = 0;
		}
}

/* Appel au super en C++ */
Adversaire::Adversaire(int pos_x, int pos_y) : Personnage(pos_x, pos_y) {
	init_var();
	init_load();
}

/* Destructeur */
Adversaire::~Adversaire(){
}

void Adversaire::modifTableaux(Case_plateau** jeu) {
	for (int i = 0; i < TAILLE_JEU; i++) {
		for (int j = 0; j < TAILLE_JEU; j++) {
			if (jeu[i][j] == MUR || jeu[i][j] == CAISSE) {
				murs[i][j] = 1;
			}
			if (jeu[i][j] == ADVERSAIRE_BOMBE) {
				danger[i][j] = 1;
				for (int k = 1; k <= 3; k++) {
					danger[i + k][j] = 1;
					danger[i - k][j] = 1;
					danger[i][j + k] = 1;
					danger[i][j - k] = 1;
				}
			}
		}
	}
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
					jeu[p_colone][p_line] = ADVERSAIRE_BOMBE;
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
					jeu[p_colone][p_line] = ADVERSAIRE_BOMBE;
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
					jeu[p_colone][p_line] = ADVERSAIRE_BOMBE;
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
					jeu[p_colone][p_line] = ADVERSAIRE_BOMBE;
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

void Adversaire::vers_chemin(Case_plateau** jeu, Joueur* player) {
	modifTableaux(jeu);
	recherche_objectif();
	if (this->getLine() > y_objectif)
		deplacement(DOWN, jeu, player);
	if (this->getLine() < y_objectif)
		deplacement(UP, jeu, player);
	if (this->getColone() < x_objectif)
		deplacement(RIGHT, jeu, player);
	if (this->getColone() > x_objectif)
		deplacement(LEFT, jeu, player);
}

void Adversaire::recherche_objectif() {
	x_objectif = this->getColone();
	y_objectif = this->getLine();
	if (danger[this->getColone()][this->getLine()] == 0) {
		do {
			srand(time(NULL));
			int i = rand() % 4;
			switch (i) {
			case 0 :
				x_objectif += 1;
				break;
			case 1 :
				x_objectif -= 1;
				break;
			case 2 :
				y_objectif += 1;
				break;
			case 3 :
				y_objectif -= 1;
				break;
			}
		} while (murs[x_objectif][y_objectif] == 1);
		srand(time(NULL));
	}

}