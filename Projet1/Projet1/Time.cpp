#include "Time.h"

/* Constructor. */
Time::Time() {
	startDate = 0;
	stopDate = 0;
	on = false;
}

/* Destructeur. */
Time::~Time(){}

/* To start the object Time. */
void Time::start() {
	if (!isOn()) {
		startDate = SDL_GetTicks() - stopDate;
		stopDate = 0;
		on = true;
	}
}

/* To stop the object Time. */
void Time::stop(){
	if (isOn()) {
		stopDate = SDL_GetTicks() - startDate;
		on = false;
	}
}

/* To return the time. */
int Time::getTime() {
	if (isOn()) return SDL_GetTicks() - startDate;
	else return stopDate;
}

/* To know if the object is on.  */
bool Time::isOn() {
	if (on) return true;
	else return false;
}

/* To get startDate. */
int Time::getStartDate() {
	return startDate;
}

/* To get stopDate. */
int Time::getStopDate() {
	return stopDate;
}