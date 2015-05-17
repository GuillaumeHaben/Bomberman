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
	void setPause(bool p);
	void draw();
	Joueur* getPrincipal();
	Level getLevel();
	void init(int i);

	Case_plateau* * jeu = 0;

private:
	bool end, pause;
	Joueur principal;
	Level l;
};

#endif