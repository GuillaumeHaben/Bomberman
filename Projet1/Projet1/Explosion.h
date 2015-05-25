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
	int Explosion::init(Case_plateau* * jeu);
	void Explosion::end(Case_plateau* * jeu);

	void Explosion::affichage_init(int x, int y, Case_plateau* * jeu, bool* axe, bool* die);
	void Explosion::affichage_end(int x, int y, Case_plateau* * jeu, bool* axe);

private:
	int e_colone, e_line, puissance;
	void explose_direction(int direction, int puissance_i);
};

#endif;