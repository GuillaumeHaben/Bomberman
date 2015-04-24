#ifndef GAME_H
#define GAME_H

#include "Case.h";
#include "Joueur.h"

class Game {

public:
	Game();
	~Game();

	bool getPause();
	void setPause(bool p);

private:
	bool end, pause;

public:
	Case_plateau jeu[TAILLE_JEU][TAILLE_JEU];
	Joueur principal;

};
#endif