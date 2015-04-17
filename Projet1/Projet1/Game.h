#ifndef GAME_H
#define GAME_H

class Game {

public:
	Game();
	~Game();

	bool getPause();
	void setPause(bool p);

private:
	bool end, pause;

};
#endif