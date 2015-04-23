#ifndef GAME_H
#define GAME_H

#include "Case.h";

class Game {

public:
	Game();
	~Game();

	bool getPause();
	void setPause(bool p);

private:
	bool end, pause;
	Case_plateau jeu[TAILLE_JEU][TAILLE_JEU];

};
#endif