#include "Explosion.h"


/* Constructeur */
Explosion::Explosion()
{

}

Explosion::Explosion(int x, int y, int puissance)
{
	this->x = x;
	this->y = y;
	this->puissance = puissance;
}


/* Destructeur */
Explosion::~Explosion()
{
	this->x = 0;
	this->y = 0;
	this->puissance = 0;
}


/* Intialise l'explosion */
void Explosion::init(Case_plateau* * jeu){
	for (int i=1; i <= puissance; i++) {
		switch (jeu[x + i][y]) {
			case CAISSE:
				jeu[x + i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE: case EXPLOSION:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				break;
			case BOMBE:
				jeu[x + i][y] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x + i][y] = JOUEUR_EXPLOSION;
				break;
			default:
				jeu[x + i][y] = VIDE;
				break;
		}
		switch (jeu[x - i][y]) {
			case CAISSE:
				jeu[x + i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE: case EXPLOSION:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				break;
			case BOMBE:
				jeu[x + i][y] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x + i][y] = JOUEUR_EXPLOSION;
				break;
			default:
				jeu[x + i][y] = VIDE;
				break;
		}
		switch (jeu[x][y + i]) {
			case CAISSE:
				jeu[x + i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE: case EXPLOSION:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				break;
			case BOMBE:
				jeu[x + i][y] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x + i][y] = JOUEUR_EXPLOSION;
				break;
			default:
				jeu[x + i][y] = VIDE;
				break;
		}
		switch (jeu[x][y - i]) {
			case CAISSE:
				jeu[x + i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE: case EXPLOSION:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				break;
			case BOMBE:
				jeu[x + i][y] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x + i][y] = JOUEUR_EXPLOSION;
				break;
			default:
				jeu[x + i][y] = VIDE;
				break;
		}
	}

				 if (jeu[x][y - 1] == MUR || jeu[x][y - 1] == CAISSE ||
					 jeu[x][y - 1] == CAISSE_EXPLOSION || jeu[x][y - 1] == BOMBE
					 || jeu[x][y - 1] == BOMBE_EXPLOSION);
				 else{
					 if (jeu[x][y] == JOUEUR_EXPLOSION){
						 jeu[x][y] = EXPLOSION;
					 }
					 else jeu[x][y] = VIDE;

					 if (jeu[x][y - 1] == EXPLOSION){
						 jeu[x][y - 1] = JOUEUR_EXPLOSION;
						 //this->die();
					 }
					 else jeu[x][y - 1] = JOUEUR;

					 --y;
					 //return 0;
				 }

}
/* Fin de l'explosion */
void Explosion::end(){

}