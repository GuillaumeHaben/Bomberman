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

int Adversaire::getLife() {
	return nb_life;
}

void Adversaire::die() {
	nb_life--;
}

void Adversaire::init_var(){
	nb_bombes = 0;
	nb_bombes_max = NB_BOMBES_MAX;
	nb_life = 3;
	dest = { 35, 35, 35, 35 };
	dest_life = { 35, 35, 550, 450 };
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

	switch (direction()) {
	case UP:
		if (this->deplacement(UP, jeu) != -1){
			dest.x = p_colone * 35;
			dest.y = p_line * 35;
		}
		break;

	case DOWN:
		if (this->deplacement(DOWN, jeu) != -1){
			dest.x = p_colone * 35;
			dest.y = p_line * 35;
		}
		break;

	case LEFT:
		if (this->deplacement(LEFT, jeu) != -1){
			dest.x = p_colone * 35;
			dest.y = p_line * 35;
		}
		break;

	case RIGHT:
		if (this->deplacement(RIGHT, jeu) != -1){
			dest.x = p_colone * 35;
			dest.y = p_line * 35;
		}
		break;

	case 4:
		jeu[p_colone][p_line] = JOUEUR_BOMBE;
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
		}
		else{
			if (bombes_tab[0].getBoom()){
				if (!(bombes_tab[1].getLine() == p_line && bombes_tab[1].getColone() == p_colone))
					bombes_tab[0].init(p_colone, p_line);
			}
			else{
				if (bombes_tab[1].getBoom()){
					if (!(bombes_tab[0].getLine() == p_line && bombes_tab[0].getColone() == p_colone))
						bombes_tab[1].init(p_colone, p_line);
				}
			}
		}
		break;
	}
}

int Adversaire::direction(){
	
	int i = 0;
		i = rand() % 5;
	return i;
}



void Adversaire::draw(){
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}