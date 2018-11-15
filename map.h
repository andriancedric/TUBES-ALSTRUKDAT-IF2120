/* Ini adalah header untuk menyimpan ADT map dalam permainan */

#include "boolean.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef map_H
#define map_H

/*Untuk ADT POINT */
typedef struct {
 	int X; /* absis */
	int Y; /* ordinat*/
	int ID; /*penunjuk lokasi di mana player berada, misal Room 1, Room 2, Dapur*/
} POINT;
/*Definisi pemanggilan Point */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y
#define Lokasi(P) (P).lokasi

POINT PosisiP; //Variabel koordinat posisi player

typedef struct {
	char tipe;
	int isi;/*Nomor meja jika tipe meja, ID Bahan Makanan jika tipe M, Nomor pintu
              bertipe pintu, 0 jika tidak ada apa2*/
}Square;

typedef struct {
	int ID;
	int M;/*Baris*/
	int N;/*Kolom*/ //Room berukuran M*N
	Square **S;//Matriks benda yg ada dalam kotak
}Room;

typedef struct tElmtlist *addressL;
typedef struct tElmtlist {
  int ID;//ID pintu yang menghubungkan
	Room r;
	addressL next;
} ElmtList;
typedef struct {
	addressL First;
} List;//List dari room2 yang terhubung ke suatu ruangan tertentu


typedef struct tElmtgraph *addressG;
typedef struct tElmtgraph {
  int ID;
	List L;
	addressG next;
} ElmtGraph;
typedef struct {
	addressG GFirst;
} Graph;//List dari list tentang room2 yang terhubung dengan room

#define Room(P) (P).r
#define Next(P) (P).next
#define ID(P) (P).ID
#define Square(R) (R).S
#define SSquare(R) (R).*S
#define SquareXY(R,X,Y) (R).S[X][Y]
#define M(R) (R).M
#define N(R) (R).N
#define List(G) (G).L
#define First(G) (G).First
#define Tipe(S) (S).tipe
#define Isi(S) (S).isi


#endif
