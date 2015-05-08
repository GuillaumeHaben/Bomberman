#ifndef LEVEL_H
#define LEVEL_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Case.h"
#include "Game.h"

class Level {

public:

	// Constructor.
	Level(Game* plateauVide);

	// Setters.
	void setUpGame(int niveau);
	void niveau1();
	void generateurCaisses(int nombreCaisses);

private:
	Game* plateau;
};

#endif;