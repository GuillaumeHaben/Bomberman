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

	bool east = false;
	bool west = false;
	bool north = false;
	bool south = false;

	for (int i=1; i <= puissance; i++) {
		
		if (x + i >= TAILLE_JEU || south) break;
		else {
			switch (jeu[x + i][y]) {
			case CAISSE:
				jeu[x + i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE: case EXPLOSION:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				south = true;
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

		if (y + i >= TAILLE_JEU || east) break;
		else {
			switch (jeu[x][y + i]) {
			case CAISSE:
				jeu[x][y + i] = CAISSE_EXPLOSION;
				break;
			case VIDE: case EXPLOSION:
				jeu[x][y + i] = EXPLOSION;
				break;
			case MUR:
				east = true;
				break;
			case BOMBE:
				jeu[x][y + i] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x][y + i] = JOUEUR_EXPLOSION;
				break;
			default:
				jeu[x][y + i] = VIDE;
				break;
			}
		}

		if (x - i < 0 || north) break;
		else {
			switch (jeu[x - i][y]) {
			case CAISSE:
				jeu[x - i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE: case EXPLOSION:
				jeu[x - i][y] = EXPLOSION;
				break;
			case MUR:
				north = true;
				break;
			case BOMBE:
				jeu[x - i][y] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x - i][y] = JOUEUR_EXPLOSION;
				break;
			default:
				jeu[x - i][y] = VIDE;
				break;
			}
		}

		if (y - i < 0 || west) break;
		else {
			switch (jeu[x][y - i]) {
			case CAISSE:
				jeu[x][y - i] = CAISSE_EXPLOSION;
				break;
			case VIDE: case EXPLOSION:
				jeu[x][y - i] = EXPLOSION;
				break;
			case MUR:
				west = true;
				break;
			case BOMBE:
				jeu[x][y - i] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x][y - i] = JOUEUR_EXPLOSION;
				break;
			default:
				jeu[x][y - i] = VIDE;
				break;
			}
		}
	}
}
/* Fin de l'explosion */
void Explosion::end(){

}