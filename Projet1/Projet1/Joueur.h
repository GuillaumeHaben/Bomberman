#ifndef JOUEUR_H
#define JOUEUR_H

#include "Case.h"
#include "Personnage.h"
#include "Bombe.h"

extern SDL_Event evn;
extern SDL_Renderer* renderer;

class Joueur : public Personnage{

public:
	Joueur();
	Joueur(int pos_x, int pos_y);
	~Joueur();

	Bombe* getBombes_tab();
	void dim_Nb_Bombes();

	void init_var();
	void init_load();
	void event(Case_plateau* * jeu);
	void draw();
	int getLife();
	void die();

private:
	int nb_bombes, nb_bombes_max, nb_life;
	SDL_Texture* texture;
	SDL_Rect dest, dest_life;
	Bombe bombes_tab[2];
};

#endif