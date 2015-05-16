#ifndef LEVEL_H
#define LEVEL_H

#include <stdio.h>
#include <stdlib.h>
#include <Time.h>

#include "Case.h"

extern SDL_Renderer * renderer;

class Level {

public:

	Level();
	Level(Case_plateau* * jeu);
	~Level();

	void setUpGame(int niveau);
	void lvl1();
	void lvl2();
	void generate(int nombreCaisses);
	void draw();

private:
	int niveau;
	Case_plateau* * jeu;

	SDL_Surface* img[3];

	SDL_Texture* niveaux;
	SDL_Texture* mur;
	SDL_Texture* caisse;

	SDL_Rect fond;
};

#endif;