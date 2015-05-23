#ifndef TIME_H
#define TIME_H

#include <SDL/SDL.h>

class Time{

public :
	// Constructor.
	Time();
	~Time();

	// Setters.
	void start();
	void stop();
	void restart();

	// Getters.
	int getTime();
	bool isOn();
	int getStartDate();
	int getStopDate();

private :
	int startDate, stopDate;
	bool on;
};

#endif