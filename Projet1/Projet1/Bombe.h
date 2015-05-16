#ifndef BOMBE_H
#define BOMBE_H

#include "Case.h"
#include "Joueur.h"
#include "Time.h"

extern SDL_Event evn;
extern SDL_Renderer* renderer;

class Bombe {

public:
	Bombe();
	Bombe(int pos_x, int pos_y, int power, Joueur* J);
	~Bombe();


	// Getter
	int getColone();
	int getLine();
	int getPuissance();
	int getRetardement();
	int getExplosee();
	Joueur* getJoueur();

	void event(Case_plateau* * jeu);
	void init(int x, int y, int power, Joueur* J);

private:
	int b_colone, b_line;
	int puissance;
	Time retardement;
	bool explosee;
	Joueur* appartient;

	SDL_Texture* texture;
	SDL_Rect dest;
};

#endif;