#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"

/*Untuk ADT ARRAY -> <makanan,nomormeja,kesabaran>*/
typedef int IdxType;  /* type indeks */
typedef struct{
  int nomormeja;
  int kesabaran;
  char makanan;
} infotypeArr;

typedef struct {
    infotypeArr TI[30];
    int Neff;
} TabInt;
/*Definisi pemanggilan Array */
#define Nomormeja(T,i) (T).TI[(i)].nomormeja
#define Kesabaran(T,i) (T).TI[(i)].kesabaran
#define Makanan(T,i) (T).TI[(i)].makanan  /*coba deh bisa di string atau engga */

#endif