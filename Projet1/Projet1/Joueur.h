#ifndef JOUEUR_H
#define JOUEUR_H

#include "Personnage.h"

class Joueur : public Personnage{

public:
	Joueur();
	Joueur(int pos_x, int pos_y);
	~Joueur();

	/* Gestion �v�nements d'un joueur poser bombe, d�placement..*/
};

#endif