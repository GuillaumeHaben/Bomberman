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

	int** murs;
	int** danger;
	void modifTableaux(Case_plateau** jeu);
	int x_objectif;
	int y_objectif;

	void init_var();
	void init_load();
	int deplacement(int direction, Case_plateau* * jeu, Joueur *player);
	void draw();
	void vers_chemin(Case_plateau** jeu, Joueur* player);
	void recherche_objectif();
	bool die();
	void setDie();

private:
	int nb_bombes, nb_bombes_max;
	int last_deplacement;
	SDL_Texture* texture;
	SDL_Rect dest;
	Bombe bombes_tab[2];
	int* chemin;
	int taille_chemin;
	bool mort;
};

#endif