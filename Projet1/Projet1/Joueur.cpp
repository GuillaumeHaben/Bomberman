#include "Joueur.h"

/* Constructeur */
Joueur::Joueur() : Personnage(){
	init_var();

	dest = {0, 0, 640, 480 };
	background = SDL_LoadBMP("perso.bmp");
	
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, background);
	SDL_RenderCopy(renderer, texture, NULL, &dest);
}

/* Appel au super en C++ */
Joueur::Joueur(int pos_x, int pos_y) : Personnage(pos_x, pos_y) {
	init_var();
}

/* Destructeur */
Joueur::~Joueur(){

}

void Joueur::init_var(){
	nb_bombes = 0;
	nb_bombes_max = 2;
}

int Joueur::deplacement(int direction, Case_plateau* * jeu){

	switch (direction){

	case UP: if (p_line - 1 < 0) break;
			 else{
				 if (jeu[p_colone][p_line - 1] == MUR) break;
				 else{
					 jeu[p_colone][p_line] = VIDE;
					 jeu[p_colone][p_line - 1] = JOUEUR;
					 --p_line;
					 return 0;
				 }
			 }

	case DOWN:
		if (p_line + 1 > TAILLE_JEU) break;
		else{
			if (jeu[p_colone][p_line + 1] == MUR) break;
			else{
				jeu[p_colone][p_line] = VIDE;
				jeu[p_colone][p_line + 1] = JOUEUR;
				++p_line;
				return 0;
			}
		}

	case RIGHT:
		if (p_colone + 1 > TAILLE_JEU) break;
		else{
			if (jeu[p_colone + 1 ][p_line] == MUR) break;
			else{
				jeu[p_colone][p_line] = VIDE;
				jeu[p_colone + 1][p_line] = JOUEUR;
				++p_colone;
				return 0;
			}
		}

	case LEFT:
		if (p_colone - 1 < 0) break;
		else{
			if (jeu[p_colone - 1][p_line] == MUR) break;
			else{
				jeu[p_colone][p_line] = VIDE;
				jeu[p_colone - 1][p_line] = JOUEUR;
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
				dest.x = p_colone*32;
				dest.y = p_line * 45;
			}
			break;

		case SDLK_DOWN:
			if (this->deplacement(DOWN, jeu) != -1){
				dest.x = p_colone * 32;
				dest.y = p_line * 45;
			}
			break;

		case SDLK_LEFT:
			if (this->deplacement(LEFT, jeu) != -1){
				dest.x = p_colone * 32;
				dest.y = p_line * 45;
			}
			break;

		case SDLK_RIGHT:
			if (this->deplacement(RIGHT, jeu) != -1){
				dest.x = p_colone * 32;
				dest.y = p_line * 45;

				SDL_RenderClear(renderer);
				SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, background);
				SDL_RenderCopy(renderer, texture, NULL, &dest);
			}
			break;

		default:
			break;
		}
	}
}