#ifndef LEVEL_H
#define LEVEL_H

#include "Case.h"
#include "Game.h"

class Level {

public:

	// Constructor.
	Level(Game* plateauVide);

	// Setters.
	void setUpGame(int niveau);

private:
	Game* plateau;
};

#endif;