#ifndef POINT_H
#define POINT_H

#include "boolean.h"
#include "mesinkata.h"
typedef struct {
	int X; /* absis */
	int Y; /* ordinat*/
	int ID; /*penunjuk lokasi di mana player berada, misal Room 1, Room 2, Dapur*/
} POINT;

typedef struct{
	int life;
	int money;
    Kata name;
} PLAYER;

#define Life(P) (P).life
#define Money(P) (P).money
#define Nama(P) (P).name
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define IDP(P) (P).ID

#endif
