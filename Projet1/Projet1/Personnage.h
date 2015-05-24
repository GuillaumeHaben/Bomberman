#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include "Case.h"

class Personnage {

public:
	Personnage();
	Personnage(int pos_x, int pos_y);
	~Personnage();

	// Getter
	int getColone();
	int getLine();

	//Setter
	void setColone(int pos_x);
	void setLine(int pos_y);

protected:
	int p_colone, p_line;

};

#endif