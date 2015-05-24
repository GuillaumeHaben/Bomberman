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
	void Explosion::end();

private:
	int x, y, puissance;
};

#endif;