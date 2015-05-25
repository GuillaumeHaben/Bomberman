#ifndef ADVERSAIRE_H
#define ADVERSAIRE_H

#include "Case.h"
#include <Time.h>
#include "Personnage.h"
#include "Bombe.h"
#include "Joueur.h"

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
	int deplacement(int direction, Case_plateau* * jeu, Joueur *player);
	void draw();
	void recherche_chemin(Case_plateau* * jeu, Joueur *player, int i);
	bool recherche_chemin_recursive(Case_plateau* * jeu, int* chemin, int taille_chemin, int pos_x, int pos_y, Joueur *player);
	bool die();
	void setDie();

private:
	int nb_bombes, nb_bombes_max;
	SDL_Texture* texture;
	SDL_Rect dest;
	Bombe bombes_tab[2];
	int* chemin;
	int taille_chemin;
	bool mort;
};

#endif