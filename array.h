#ifndef ARRAY_H
#define ARRAY_H

#include "boolean.h"
#include "point.h"
#include "map.c"
/*Untuk ADT ARRAY -> <makanan,nomormeja,kesabaran>*/
/*  Kamus Umum */
#define IdxMaxArr 12
/* Indeks maksimum array, sekaligus ukuran maksimum array dalam C */
#define IdxMinArr 1
/* Indeks minimum array */
#define ValUndef -999
/* Indeks tak terdefinisi*/

typedef int IdxType;  /* type indeks */
typedef struct{
  int kesabaran;
  int ID_Makanan;
} Pesanan;

typedef struct {
    Pesanan TI[IdxMaxArr+1];
    int Neff;
} TabInt;
/*Definisi pemanggilan Array */
#define Kesabaran(T,i) (T).TI[(i)].kesabaran
#define Makanan(T,i) (T).TI[(i)].ID_Makanan  /*coba deh bisa di string atau engga */
#define Neff(T) (T).Neff

/* KONSTRUKTOR */
void CreateEmptyArr(TabInt * T);
/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArr (TabInt T);
/* Mengirimkan banyaknya elemen efektif tabel */
/* Mengirimkan nol jika tabel kosong */
/* *** Daya tampung container *** */
int MaxNbElArr (TabInt T);
/* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T pertama */
IdxType GetLastIdx (TabInt T);
/* Prekondisi : Tabel T tidak kosong */
/* Mengirimkan indeks elemen T terakhir */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArr (TabInt T);
/* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
/* *** Test tabel penuh *** */
boolean IsFullArr (TabInt T);
/* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */

/* ********** MENAMBAH ELEMEN ********** */
void AddEli (TabInt * T, IdxType i);
/* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
   terhadap elemen yang sudah ada */
/* I.S. Tabel tidak kosong dan tidak penuh */
/*      i adalah indeks yang valid. */
/* F.S. X adalah elemen ke-i T yang baru */
/* Proses : Geser elemen ke-i+1 s.d. terakhir */
/*          Isi elemen ke-i dengan X */

/* ********** MENGHAPUS ELEMEN ********** */
void DelEli (TabInt * T, IdxType i);
/* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
/* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
/* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
/*      Banyaknya elemen tabel berkurang satu */
/*      Tabel T mungkin menjadi kosong */
/* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
/*          Kurangi elemen efektif tabel */

void KesabaranMinusArr(TabInt *T, int c, PLAYER *play);
void PrintArr(TabInt T);

void Order(Room R, TabInt *T, POINT P);
#endif
