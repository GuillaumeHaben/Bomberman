#ifndef JOUEUR_H
#define JOUEUR_H

#include "Personnage.h";
#include "Case.h";

class Joueur : public Personnage{

public:
	Joueur();
	Joueur(int pos_x, int pos_y);
	~Joueur();
	void init_var();

	int deplacement(int direction, Case_plateau jeu[TAILLE_JEU][TAILLE_JEU]);
	int event(Case_plateau jeu[TAILLE_JEU][TAILLE_JEU]);

private:
	int nb_bombes, nb_bombes_max;
};

#endif