#ifndef TIME_H
#define TIME_H

#include <SDL/SDL.h>

class Time{

public :
	// Constructor.
	Time();

	// Setters.
	void start();
	void stop();

	// Getters.
	int getTime();
	bool isOn();

private :
	int startDate;
	int stopDate;
	bool on;

};


#endif