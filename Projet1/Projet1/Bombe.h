#ifndef BOMBE_H
#define BOMBE_H

#include "Case.h"
#include "Time.h"
#include "Explosion.h"
#include "SDL/SDL_image.h"

//Utile pour la génération aléatoire
#include <cstdlib>

extern SDL_Renderer* renderer;

class Bombe {

public:
	Bombe();
	Bombe(int pos_x, int pos_y);
	~Bombe();

	// Getter
	int getColone();
	int getLine();
	void setLine(int i);
	int getExplosee();
	int getPuissance();
	Time getRetardement();
	bool getBoom();
	void setExplosee(int i);

	int event(Case_plateau* * jeu);
	void init(int x, int y);
	void put_off();
	void put_on();

	SDL_Texture* texture[2];
	SDL_Rect dest;

private:
	int b_colone, b_line;
	int explosee; //0 = pas explosee | 1 = prête à exploser | 2 = explosée | 3 = fin de l'explosion
	int puissance;
	bool boom;
	Time retardement;
	Explosion explosion;
};

#endif;