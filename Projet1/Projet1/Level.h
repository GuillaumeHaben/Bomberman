#ifndef LEVEL_H
#define LEVEL_H

#include <stdio.h>
#include <stdlib.h>
#include <Time.h>

#include "Case.h"

extern SDL_Renderer * renderer;

class Level {

public:

	// Constructor.
	Level();
	Level(Case_plateau* * jeu);
	~Level();

	// Setters.
	void setUpGame(int niveau);
	void niveau1();
	void generateurCaisses(int nombreCaisses);
	void dessiner();

private:
	Case_plateau* * jeu;
	SDL_Surface *img[3];
	int niveau;
};

#endif;