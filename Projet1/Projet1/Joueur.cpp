#include "Joueur.h"
#include "SDL/SDL_image.h"


/* Constructeur */
Joueur::Joueur() : Personnage(){
	init_var();
	init_load();
}

/* Appel au super en C++ */
Joueur::Joueur(int pos_x, int pos_y) : Personnage(pos_x, pos_y) {
	init_var();
	init_load();
}

/* Destructeur */
Joueur::~Joueur(){
	SDL_DestroyTexture(texture);
}

Bombe* Joueur::getBombes_tab() {
	return bombes_tab;
}

void Joueur::dim_Nb_Bombes() {
	nb_bombes--;
}

int Joueur::getLife() {
	return nb_life;
}

void Joueur::die() {
	nb_life--;
}

void Joueur::init_var(){
	nb_bombes = 0;
	nb_bombes_max = NB_BOMBES_MAX;
	nb_life = 3;
}

void Joueur::init_load(){
	SDL_Surface* background = IMG_Load("Sprite/test.png");
	texture = SDL_CreateTextureFromSurface(renderer, background);
	dest = { 35, 35, 35, 35 };
	dest_life = { 35, 35, 550, 450 };
	SDL_FreeSurface(background);
}

int Personnage::deplacement(int direction, Case_plateau* * jeu){

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

void Joueur::event(Case_plateau* * jeu){

	if (evn.type == SDL_KEYDOWN){

		switch (evn.key.keysym.sym)
		{
		case SDLK_UP:
			if (this->deplacement(UP, jeu) != -1){
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
			}
			break;

		case SDLK_DOWN:
			if (this->deplacement(DOWN, jeu) != -1){
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
			}
			break;

		case SDLK_LEFT:
			if (this->deplacement(LEFT, jeu) != -1){
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
			}
			break;

		case SDLK_RIGHT:
			if (this->deplacement(RIGHT, jeu) != -1){
				dest.x = p_colone * 35;
				dest.y = p_line * 35;
			}
			break;

		case SDLK_SPACE:
			if (nb_bombes < nb_bombes_max) {
				jeu[p_colone][p_line] = JOUEUR_BOMBE;
				Bombe nouvelle_bombe(p_colone, p_line, 1);
				bombes_tab[nb_bombes] = nouvelle_bombe;
				nb_bombes++;
			}
			break;

		default:
			break;
		}
	}
}

void Joueur::draw(){
	SDL_RenderCopy(renderer, texture, NULL, &dest);

	dest_life = { 545, 450, 35, 35};
	for (int vie = 0; vie < getLife(); vie++){
		SDL_RenderCopy(renderer, texture, NULL, &dest_life);
		dest_life.x = dest_life.x + 40;
	}
}