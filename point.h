#ifndef POINT_H
#define POINT_H

#include "boolean.h"

typedef struct {
	int X; /* absis */
	int Y; /* ordinat*/
	int ID; /*penunjuk lokasi di mana player berada, misal Room 1, Room 2, Dapur*/
} POINT;
/*Definisi pemanggilan Point */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define IDP(P) (P).ID

#endif
