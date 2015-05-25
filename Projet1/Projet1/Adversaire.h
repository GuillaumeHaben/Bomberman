#ifndef ADVERSAIRE_H
#define ADVERSAIRE_H

#include "Case.h"
#include <Time.h>
#include "Personnage.h"
#include "Bombe.h"

extern SDL_Event evn;
extern SDL_Renderer* renderer;

class Adversaire : public Personnage{

public:
	Adversaire();
	Adversaire(int pos_x, int pos_y);
	~Adversaire();

	Bombe* getBombes_tab();
	void dim_Nb_Bombes();

	void init_var();
	void init_load();
	int deplacement(int direction, Case_plateau* * jeu);
	void event(Case_plateau* * jeu);
	void draw();
	int direction();

private:
	int nb_bombes, nb_bombes_max;
	SDL_Texture* texture;
	SDL_Rect dest, dest_life;
	Bombe bombes_tab[2];
};

#endif