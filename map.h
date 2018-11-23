/* Ini adalah header untuk menyimpan ADT map dalam permainan */

#include "boolean.h"
#include "point.h"
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
#ifndef map_H
#define map_H

/*Untuk ADT POINT */
POINT PosisiP; //Variabel koordinat posisi player

typedef struct {
	char tipe;
	int isi;/*Nomor meja jika tipe meja, ID Bahan Makanan jika tipe M, Nomor pintu
              bertipe pintu, 0 jika tidak ada apa2*/
	boolean occupied;
	int capacity;
}Square;

typedef struct {
	int ID;
	int M;/*Baris*/
	int N;/*Kolom*/ //Room berukuran M*N
	Square **S;//Matriks benda yg ada dalam kotak
}Room;

#define Nil NULL

//typedef struct adrNode *Node;

#define First(G) (G).First
#define Next(P) (P)->Next
#define ID(P) (P)->ID
#define Square(R) (R).S
#define SSquare(R) (R).*S
#define SquareXY(R,X,Y) (R).S[X][Y]
#define M(R) (R).M
#define N(R) (R).N
#define List(G) (G).L
#define Tipe(S) (S).tipe
#define Isi(S) (S).isi
#define IsOcc(S) (S).occupied
#define CapMeja(S) (S).capacity

#endif
