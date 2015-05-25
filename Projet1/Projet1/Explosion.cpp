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
			affichage_init(x + i, y, jeu, &east, &die);
		}

		if (!(y + i >= TAILLE_JEU || south)) {
			affichage_init(x, y + i, jeu, &south, &die);
		}

		if (!(x - i < 0 || west)) {
			affichage_init(x - i, y, jeu, &west, &die);
		}

		if (!(y - i < 0 || north)){
			affichage_init(x, y - i, jeu, &north, &die);
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
			affichage_end(x + i, y, jeu, &east);
		}

		if (!(y + i >= TAILLE_JEU || south)) {
			affichage_end(x, y + i, jeu, &south);
		}

		if (!(x - i < 0 || west)) {
			affichage_end(x - i, y, jeu, &west);
		}

		if (!(y - i < 0 || north)){
			affichage_end(x, y - i, jeu, &north);
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

void Explosion::affichage_init(int x, int y, Case_plateau* * jeu, bool* axe, bool* die) {
	switch (jeu[x][y]) {
	case CAISSE: case CAISSE_EXPLOSION:
		jeu[x][y] = CAISSE_EXPLOSION;
		break;
	case VIDE: case INIT:
		jeu[x][y] = EXPLOSION;
		break;
	case MUR:
		*axe = true;
		break;
	case BOMBE: case BOMBE_EXPLOSION:
		jeu[x][y] = BOMBE_EXPLOSION;
		break;
	case JOUEUR_BOMBE:
		jeu[x][y] = JOUEUR_BOMBE;
		break;
	case JOUEUR: case JOUEUR_EXPLOSION:
		jeu[x][y] = JOUEUR_EXPLOSION;
		*die = true;
		break;
	case EXPLOSION: case EXPLOSION_EXPLOSION:
		jeu[x][y] = EXPLOSION_EXPLOSION;
		break;
	case ADVERSAIRE: case ADVERSAIRE_EXPLOSION:
		jeu[x][y] = ADVERSAIRE_EXPLOSION;
		break;
	default:
		jeu[x][y] = VIDE;
	}
}

void Explosion::affichage_end(int x, int y, Case_plateau* * jeu, bool* axe) {
	switch (jeu[x][y]) {
	case EXPLOSION: case CAISSE_EXPLOSION:
		jeu[x][y] = VIDE;
		break;
	case BOMBE_EXPLOSION:
		jeu[x][y] = BOMBE;
		break;
	case JOUEUR_EXPLOSION:
		jeu[x][y] = JOUEUR;
		break;
	case EXPLOSION_EXPLOSION:
		jeu[x][y] = EXPLOSION;
		break;
	case MUR:
		*axe = true;
		break;
	case JOUEUR_BOMBE:
		jeu[x][y] = JOUEUR_BOMBE;
		break;
	case ADVERSAIRE_EXPLOSION:
		jeu[x][y] = ADVERSAIRE;
		break;
	default:
		jeu[x][y] = VIDE;
		break;
	}
}