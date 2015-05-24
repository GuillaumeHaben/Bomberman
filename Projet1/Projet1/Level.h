#ifndef LEVEL_H
#define LEVEL_H

#include <stdio.h>
#include <stdlib.h>
#include <Time.h>
#include <SDL/SDL_mixer.h>

#include "Case.h"
#include "Joueur.h"

extern SDL_Renderer * renderer;
extern bool IsDead;

class Level {

public:

	Level();
	Level(Case_plateau** jeu, Joueur* J);
	~Level();

	void setUpGame(int niveau);
	void lvl1();
	void lvl2();
	void generate(int nombreCaisses);
	void draw(bool b);

private:
	int niveau;
	Case_plateau* * jeu;
	Joueur* prncp;

	SDL_Surface* img[3];

	SDL_Texture* niveaux;
	SDL_Texture* mur;
	SDL_Texture* flamme;
	SDL_Texture* caisse;
	SDL_Texture* pause_text;
	SDL_Texture* over_text;

	SDL_Rect fond;
	bool musique = false;
	Mix_Chunk *explosion;

};

#endif;