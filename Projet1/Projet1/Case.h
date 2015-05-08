#ifndef CASE_H
#define CASE_H

#include <stdio.h>
#include <string.h>
#include <SDL/SDL.h>

enum Case_plateau {
	INIT,
	VIDE,
	MUR,
	BOMBE,
	JOUEUR,
	CAISSE,
	JOUEUR_BOMBE
};

const int TAILLE_JEU = 15;
const int const UP = 0;
const int const DOWN = 1;
const int const RIGHT = 2;
const int const LEFT = 3;

#endif