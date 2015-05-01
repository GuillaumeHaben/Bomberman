#ifndef JOUEUR_H
#define JOUEUR_H

#include "Personnage.h"
#include "Case.h"

extern SDL_Event evn;
extern SDL_Surface *screenSurface;

class Joueur : public Personnage{

public:
	Joueur();
	Joueur(int pos_x, int pos_y);
	~Joueur();
	void init_var();

	int deplacement(int direction, Case_plateau* * jeu);
	void event(Case_plateau* * jeu);

private:
	int nb_bombes, nb_bombes_max;
	SDL_Surface *background;
};

#endif