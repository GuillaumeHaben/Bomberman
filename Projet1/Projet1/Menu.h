#ifndef MENU_H
#define MENU_H

#include "Case.h"

extern SDL_Renderer* renderer;

class Menu {

public:
	Menu();
	~Menu();

	void draw();

private:
	SDL_Texture* texture;
	SDL_Rect dest;
};

#endif