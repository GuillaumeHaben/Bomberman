#include "Explosion.h"


/* Constructors */
Explosion::Explosion()
{

}

Explosion::Explosion(int colone, int line, int puissance)
{
	this->e_line = line;
	this->e_colone = colone;
	this->puissance = puissance;
}


/* Destructor */
Explosion::~Explosion()
{
	this->e_line = 0;
	this->e_colone = 0;
	this->puissance = 0;
}


/* Init Explosion */
int Explosion::init(Case_plateau* * jeu){

	bool east = false;
	bool west = false;
	bool north = false;
	bool south = false;
	bool die = false;

	int x = e_colone;
	int y = e_line;

	for (int i = 1; i <= puissance; i++) {
		if (!(x + i >= TAILLE_JEU || east)){
			switch (jeu[x + i][y]) {
			case CAISSE: case CAISSE_EXPLOSION:
				jeu[x + i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE: case INIT:
				jeu[x + i][y] = EXPLOSION;
				break;
			case MUR:
				east = true;
				break;
			case BOMBE: case BOMBE_EXPLOSION:
				jeu[x + i][y] = BOMBE_EXPLOSION;
				break;
			case JOUEUR_BOMBE:
				jeu[x + i][y] = JOUEUR_BOMBE;
				break;
			case JOUEUR: case JOUEUR_EXPLOSION:
				jeu[x + i][y] = JOUEUR_EXPLOSION;
				die = true;
				break;
			case EXPLOSION: case EXPLOSION_EXPLOSION:
				jeu[x + i][y] = EXPLOSION_EXPLOSION;
				break;
			case ADVERSAIRE: case ADVERSAIRE_EXPLOSION:
				jeu[x + 1][y] = ADVERSAIRE_EXPLOSION;
				break;
			}
		}

		if (!(y + i >= TAILLE_JEU || south)) {
			switch (jeu[x][y + i]) {
			case CAISSE: case CAISSE_EXPLOSION:
				jeu[x][y + i] = CAISSE_EXPLOSION;
				break;
			case VIDE: case INIT:
				jeu[x][y + i] = EXPLOSION;
				break;
			case MUR:
				south = true;
				break;
			case BOMBE: case BOMBE_EXPLOSION:
				jeu[x][y + i] = BOMBE_EXPLOSION;
				break;
			case JOUEUR_BOMBE:
				jeu[x][y + i] = JOUEUR_BOMBE;
				break;
			case JOUEUR: case JOUEUR_EXPLOSION:
				jeu[x][y + i] = JOUEUR_EXPLOSION;
				die = true;
				break;
			case EXPLOSION: case EXPLOSION_EXPLOSION:
				jeu[x][y + i] = EXPLOSION_EXPLOSION;
				break;
			case ADVERSAIRE: case ADVERSAIRE_EXPLOSION:
				jeu[x][y + i] = ADVERSAIRE_EXPLOSION;
				break;
			}
		}

		if (!(x - i < 0 || west)) {
			switch (jeu[x - i][y]) {
			case CAISSE: case CAISSE_EXPLOSION:
				jeu[x - i][y] = CAISSE_EXPLOSION;
				break;
			case VIDE: case INIT:
				jeu[x - i][y] = EXPLOSION;
				break;
			case MUR:
				west = true;
				break;
			case BOMBE: case BOMBE_EXPLOSION:
				jeu[x - i][y] = BOMBE_EXPLOSION;
				break;
			case JOUEUR_BOMBE:
				jeu[x - i][y] = JOUEUR_BOMBE;
				break;
			case JOUEUR: case JOUEUR_EXPLOSION:
				jeu[x - i][y] = JOUEUR_EXPLOSION;
				die = true;
				break;
			case EXPLOSION: case EXPLOSION_EXPLOSION:
				jeu[x - i][y] = EXPLOSION_EXPLOSION;
				break;
			case ADVERSAIRE: case ADVERSAIRE_EXPLOSION:
				jeu[x - i][y] = ADVERSAIRE_EXPLOSION;
				break;
			}
		}

		if (!(y - i < 0 || north)){
			switch (jeu[x][y - i]) {
			case CAISSE: case CAISSE_EXPLOSION:
				jeu[x][y - i] = CAISSE_EXPLOSION;
				break;
			case VIDE: case INIT:
				jeu[x][y - i] = EXPLOSION;
				break;
			case MUR:
				north = true;
				break;
			case BOMBE: case BOMBE_EXPLOSION:
				jeu[x][y - i] = BOMBE_EXPLOSION;
				break;
			case JOUEUR_BOMBE:
				jeu[x][y - i] = JOUEUR_BOMBE;
				break;
			case JOUEUR: case JOUEUR_EXPLOSION:
				jeu[x][y - i] = JOUEUR_EXPLOSION;
				die = true;
				break;
			case EXPLOSION: case EXPLOSION_EXPLOSION:
				jeu[x][y - i] = EXPLOSION_EXPLOSION;
				break;
			case ADVERSAIRE: case ADVERSAIRE_EXPLOSION:
				jeu[x][y - i] = ADVERSAIRE_EXPLOSION;
				break;
			}
		}
	}return die;
}


/* End of Explosion */
void Explosion::end(Case_plateau* * jeu){
	bool east = false;
	bool west = false;
	bool north = false;
	bool south = false;

	int x = e_colone;
	int y = e_line;

	for (int i = 1; i <= puissance; i++) {
		if (!(x + i >= TAILLE_JEU || east)) {
			switch (jeu[x + i][y]) {
			case EXPLOSION: case CAISSE_EXPLOSION:
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
			case JOUEUR_BOMBE:
				jeu[x + i][y] = JOUEUR_BOMBE;
				break;
			case ADVERSAIRE_EXPLOSION: 
				jeu[x + i][y] = ADVERSAIRE;
				break;
			default:
				jeu[x + i][y] = VIDE;
				break;
			}
		}

		if (!(y + i >= TAILLE_JEU || south)) {
			switch (jeu[x][y + i]) {
			case EXPLOSION: case CAISSE_EXPLOSION:
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
			case JOUEUR_BOMBE:
				jeu[x][y + i] = JOUEUR_BOMBE;
				break;
			case ADVERSAIRE_EXPLOSION:
				jeu[x][y + i] = ADVERSAIRE;
				break;
			default:
				jeu[x][y + i] = VIDE;
				break;
			}
		}

		if (!(x - i < 0 || west)) {
			switch (jeu[x - i][y]) {
			case EXPLOSION: case CAISSE_EXPLOSION:
				jeu[x - i][y] = VIDE;
				break;
			case BOMBE_EXPLOSION:
				jeu[x - i][y] = BOMBE;
				break;
			case JOUEUR_EXPLOSION:
				jeu[x - i][y] = JOUEUR;
				break;
			case EXPLOSION_EXPLOSION:
				jeu[x - i][y] = EXPLOSION;
				break;
			case MUR:
				west = true;
				break;
			case JOUEUR_BOMBE:
				jeu[x - i][y] = JOUEUR_BOMBE;
				break;
			case ADVERSAIRE_EXPLOSION:
				jeu[x - i][y] = ADVERSAIRE;
				break;
			default:
				jeu[x - i][y] = VIDE;
				break;
			}
		}

		if (!(y - i < 0 || north)){
			switch (jeu[x][y - i]) {
			case EXPLOSION: case CAISSE_EXPLOSION:
				jeu[x][y - i] = VIDE;
				break;
			case BOMBE_EXPLOSION:
				jeu[x][y - i] = BOMBE;
				break;
			case JOUEUR_EXPLOSION:
				jeu[x][y - i] = JOUEUR;
				break;
			case EXPLOSION_EXPLOSION:
				jeu[x][y - i] = EXPLOSION;
				break;
			case MUR:
				north = true;
				break;
			case JOUEUR_BOMBE:
				jeu[x][y - i] = JOUEUR_BOMBE;
				break;
			case ADVERSAIRE_EXPLOSION:
				jeu[x][y - i] = ADVERSAIRE;
				break;
			default:
				jeu[x][y - i] = VIDE;
				break;
			}
		}
	}

	switch (jeu[x][y]) {
	case JOUEUR_BOMBE:
		jeu[x][y] = JOUEUR;
		break;
	case BOMBE_EXPLOSION:
		jeu[x][y] = EXPLOSION;
		break;
	default:
		jeu[x][y] = VIDE;
	}
}
