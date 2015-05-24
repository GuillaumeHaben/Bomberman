#ifndef EXPLOSION_H
#define EXPLOSION_H

#include "Case.h"

class Explosion
{
public:
	//Constructeur et Destructeur
	Explosion::Explosion();
	Explosion(int x, int y, int puissance);
	~Explosion();

	//Méthodes 
	void Explosion::init(Case_plateau* * jeu);
	void Explosion::end(Case_plateau* * jeu);

private:
	int e_colone, e_line, puissance;
	void explose_direction(int direction, int puissance_i);
};

#endif;