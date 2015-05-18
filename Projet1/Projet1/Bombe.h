#ifndef BOMBE_H
#define BOMBE_H

#include "Case.h"
#include "Time.h"
#include "SDL/SDL_image.h"

extern SDL_Renderer* renderer;

class Bombe {

public:
	Bombe();
	Bombe(int pos_x, int pos_y, int power);
	~Bombe();

	// Getter
	int getColone();
	int getLine();
	int getExplosee();
	int getPuissance();
	Time getRetardement();
	void setExplosee(int i);
	void setLine();

	int event(Case_plateau* * jeu);
	void init(int x, int y, int power);

	SDL_Texture* texture[2];
	SDL_Rect dest;

private:
	int b_colone, b_line;
	int explosee; //0 = pas explosee | 1 = prête à exploser | 2 = explosée
	int puissance;
	Time retardement;

};

#endif;