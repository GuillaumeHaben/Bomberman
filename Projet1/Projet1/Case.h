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
const int  UP = 0;
const int  DOWN = 1;
const int  RIGHT = 2;
const int  LEFT = 3;

const int NB_BOMBES_MAX = 2;

#endif