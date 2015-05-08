
#include "Case.h"
#include "Joueur.h"

extern SDL_Event evn;
extern SDL_Surface* screenSurface;
extern SDL_Window* window;
extern SDL_Renderer * renderer;

class Bombe {

public:
	Bombe();
	Bombe(int pos_x, int pos_y, int power, int time, bool boom, Joueur* J);
	~Bombe();

	// Getter
	int getColone();
	int getLine();
	int getPuissance();
	int getRetardement();
	int getExplosee();
	Joueur* getJoueur();

	//Setter
	void setColone(int pos_x);
	void setLine(int pos_y);
	void setPuissance(int power);
	void setRetardement(int time);
	void setExplosee(bool boom);

	void event(Case_plateau* * jeu);

private:
	int b_colone, b_line;
	int puissance;
	int retardement;
	bool explosee;
	Joueur* appartient;
};