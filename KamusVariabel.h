/* Ini adalah header untuk menyimpan semua variabel dalam permainan */

#ifndef kamusvar_H
#define kamusvar_H

#include "boolean.h"

/* Definisi variabel untuk Engi's Kitchen Expansion*/

/*Bentukan si player*/
typedef struct{
	int life;
	int money;
    char name[20];
} PLAYER;

#define Life(P) (P).life
#define Money(P) (P).money
#define Nama(P) (P).name

#endif
