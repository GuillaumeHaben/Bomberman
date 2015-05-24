#ifndef BOMBE_H
#define BOMBE_H

#include "Case.h"
#include "Time.h"
#include "Explosion.h"
#include "SDL/SDL_image.h"

// Usefull for the random generation
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
	int getPuissance();
	Time getRetardement();
	bool getBoom();
	int getExplosee();
	void setExplosee(int i);
	bool getPerdreVie();
	void setPerdreVie();

	int event(Case_plateau* * jeu);
	void init(int x, int y);
	void put_off();
	void put_on();

	SDL_Texture* texture[2];
	SDL_Rect dest;

private:
	int b_colone, b_line;
	// explosee : 0 = posée | 1 = prête à exploser | 2 = explosée | 3 = explosion finie
	int explosee;
	int puissance;
	bool boom, isInit, isEnd, perdreVie;
	Time retardement;
	Explosion explosion;
};

#endif;