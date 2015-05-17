#ifndef BOMBE_H
#define BOMBE_H

#include "Case.h"
#include "Time.h"

extern SDL_Event evn;
extern SDL_Renderer* renderer;

class Bombe {

public:
	Bombe();
	Bombe(int pos_x, int pos_y, int power);
	~Bombe();


	// Getter
	int getColone();
	int getLine();
	int getPuissance();
	Time getRetardement();
	bool getExplosee();

	bool event(Case_plateau* * jeu);
	void init(int x, int y, int power);

	SDL_Texture* texture;
	SDL_Rect dest;

private:
	int b_colone, b_line;
	int puissance;
	Time retardement;
	bool explosee;
};

#endif;