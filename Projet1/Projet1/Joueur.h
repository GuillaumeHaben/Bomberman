#ifndef JOUEUR_H
#define JOUEUR_H

#include "Personnage.h"

class Joueur : public Personnage{

public:
	Joueur();
	Joueur(int pos_x, int pos_y);
	~Joueur();

	/* Gestion évènements d'un joueur poser bombe, déplacement..*/
};

#endif