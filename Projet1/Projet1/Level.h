#ifndef LEVEL_H
#define LEVEL_H

#include <stdio.h>
#include <stdlib.h>
#include <Time.h>
#include <SDL/SDL_mixer.h>

#include "Case.h"
#include "Joueur.h"
#include "Adversaire.h"

extern SDL_Renderer * renderer;
extern bool IsDead;

class Level {

public:

	Level();
	Level(Case_plateau** jeu, Joueur* J, Adversaire* A);
	~Level();

	void setUpGame(int niveau);
	void lvl1();
	void lvl2();
	void lvl3();
	void generate(int nombreCaisses);
	void draw(bool b);

private:
	int niveau;
	Case_plateau* * jeu;
	Joueur* prncp;
	Adversaire* ennemi;

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