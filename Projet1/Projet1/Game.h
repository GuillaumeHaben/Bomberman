#ifndef GAME_H
#define GAME_H

#include "Case.h"
#include "Joueur.h"
#include "Level.h"

extern SDL_Renderer * renderer;

class Game{

public:
	Game();
	~Game();

	bool getPause();
	void setPause();
	void draw();
	void init(int i);
	void reinit();
	Joueur* getPrincipal();
	Level getLevel();

	Case_plateau* * jeu = 0;

private:
	bool end, pause;
	Joueur principal;
	Level l;
};

#endif