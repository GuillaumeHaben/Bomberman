#include "Explosion.h"


/* Constructeur */
Explosion::Explosion()
{

}

Explosion::Explosion(int colone, int line, int puissance)
{
	this->e_line = line;
	this->e_colone = colone;
	this->puissance = puissance;
}


/* Destructeur */
Explosion::~Explosion()
{
	this->e_line = 0;
	this->e_colone = 0;
	this->puissance = 0;
}


/* Intialise l'explosion */
void Explosion::init(Case_plateau* * jeu){

	bool east = false;
	bool west = false;
	bool north = false;
	bool south = false;

	int x = e_colone;
	int y = e_line;

	for (int i = 1; i <= puissance; i++) {
		if (x + i >= TAILLE_JEU || east);
		else {
			switch (jeu[x + i][y]) {
			case CAISSE:
				jeu[x + i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				east = true;
				break;
			case BOMBE:
				jeu[x + i][y] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x + i][y] = JOUEUR_EXPLOSION;
				break;
			case EXPLOSION:
				jeu[x + i][y] = EXPLOSION_EXPLOSION;
				break;
			default:
				jeu[x + i][y] = VIDE;
				break;
			}
		}

		if (y + i >= TAILLE_JEU || south);
		else {
			switch (jeu[x][y + i]) {
			case CAISSE:
				jeu[x][y + i] = CAISSE_EXPLOSION;
				break;
			case VIDE:
				jeu[x][y + i] = EXPLOSION;
				break;
			case MUR:
				south = true;
				break;
			case BOMBE:
				jeu[x][y + i] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x][y + i] = JOUEUR_EXPLOSION;
				break;
			case EXPLOSION:
				jeu[x][y + i] = EXPLOSION_EXPLOSION;
				break;
			default:
				jeu[x][y + i] = VIDE;
				break;
			}
		}

		if (x - i < 0 || west);
		else {
			switch (jeu[x - i][y]) {
			case CAISSE:
				jeu[x - i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE:
				jeu[x - i][y] = EXPLOSION;
				break;
			case MUR:
				west = true;
				break;
			case BOMBE:
				jeu[x - i][y] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x - i][y] = JOUEUR_EXPLOSION;
				break;
			case EXPLOSION:
				jeu[x - i][y] = EXPLOSION_EXPLOSION;
				break;
			default:
				jeu[x - i][y] = VIDE;
				break;
			}
		}

		if (y - i < 0 || north);
		else {
			switch (jeu[x][y - i]) {
			case CAISSE:
				jeu[x][y - i] = CAISSE_EXPLOSION;
				break;
			case VIDE:
				jeu[x][y - i] = EXPLOSION;
				break;
			case MUR:
				north = true;
				break;
			case BOMBE:
				jeu[x][y - i] = BOMBE_EXPLOSION;
				break;
			case JOUEUR:
				jeu[x][y - i] = JOUEUR_EXPLOSION;
				break;
			case EXPLOSION:
				jeu[x][y - i] = EXPLOSION_EXPLOSION;
				break;
			default:
				jeu[x][y - i] = VIDE;
				break;
			}
		}
	}
}


/* Fin de l'explosion */
void Explosion::end(Case_plateau* * jeu){
	bool east = false;
	bool west = false;
	bool north = false;
	bool south = false;

	int x = e_colone;
	int y = e_line;

	for (int i = 1; i <= puissance; i++) {

		if (x + i >= TAILLE_JEU || east);
		else {
			switch (jeu[x + i][y]) {
			case CAISSE_EXPLOSION: case EXPLOSION:
				jeu[x + i][y] = VIDE;
				break;
			case BOMBE_EXPLOSION:
				jeu[x + i][y] = BOMBE;
				break;
			case JOUEUR_EXPLOSION:
				jeu[x + i][y] = JOUEUR;
				break;
			case EXPLOSION_EXPLOSION:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				east = true;
				break;
			default:
				jeu[x + i][y] = VIDE;
			}
		}

		if (y + i >= TAILLE_JEU || south);
		else {
			switch (jeu[x][y + i]) {
			case CAISSE_EXPLOSION: case EXPLOSION:
				jeu[x][y + i] = VIDE;
				break;
			case BOMBE_EXPLOSION:
				jeu[x][y + i] = BOMBE;
				break;
			case JOUEUR_EXPLOSION:
				jeu[x][y + i] = JOUEUR;
				break;
			case EXPLOSION_EXPLOSION:
				jeu[x][y + i] = EXPLOSION;
				break;
			case MUR:
				south = true;
				break;
			default:
				jeu[x][y + i] = VIDE;
			}
		}

		if (x - i < 0 || west);
		else {
			switch (jeu[x + i][y]) {
			case CAISSE_EXPLOSION: case EXPLOSION:
				jeu[x + i][y] = VIDE;
				break;
			case BOMBE_EXPLOSION:
				jeu[x + i][y] = BOMBE;
				break;
			case JOUEUR_EXPLOSION:
				jeu[x + i][y] = JOUEUR;
				break;
			case EXPLOSION_EXPLOSION:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				west = true;
				break;
			default:
				jeu[x + i][y] = VIDE;
			}
		}

		if (y - i < 0 || north);
		else {
			switch (jeu[x + i][y]) {
			case CAISSE_EXPLOSION: case EXPLOSION:
				jeu[x + i][y] = VIDE;
				break;
			case BOMBE_EXPLOSION:
				jeu[x + i][y] = BOMBE;
				break;
			case JOUEUR_EXPLOSION:
				jeu[x + i][y] = JOUEUR;
				break;
			case EXPLOSION_EXPLOSION:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				north = true;
				break;
			default:
				jeu[x + i][y] = VIDE;
			}
		}
	}
}
