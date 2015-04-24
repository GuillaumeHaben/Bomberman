#ifndef GAME_H
#define GAME_H

#include "Case.h"
#include "Joueur.h"

class Game {

public:
	Game();
	~Game();

	bool getPause();
	void setPause(bool p);
	Joueur getPrincipal();
	Case_plateau jeu[TAILLE_JEU][TAILLE_JEU];

private:
	bool end, pause;
	Joueur principal;

};
#endif