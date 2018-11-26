#ifndef modstack_H
#define modstack_H

#include "boolean.h"
#include "array.c"

/* Contoh deklarasi variabel bertype stack dengan ciri TOP : */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit*/
typedef struct {
	int T[6]; /* tabel penyimpan elemen */
	int TOP;  /* alamat TOP: elemen puncak */
} Stack;
/* Definisi stack S kosong : S.TOP = Nil */
/* Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl] */
/* Jika S adalah Stack maka akses elemen : */
   /* S.T[(S.TOP)] untuk mengakses elemen TOP */
   /* S.TOP adalah alamat elemen TOP */

/* Definisi akses dengan Selektor : Set dan Get */
#define TopSt(S) (S).TOP
#define InfoTopSt(S) (S).T[(S).TOP]

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySt (Stack *S);
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySt (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFullSt (Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack * S, int ID);
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack * S, int *ID);
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */

void Put (Stack *SH, Stack *ST);
/*SH adalah stack hand, ST adalah Stack tray*/
	/*I.S. : Ada tumpukan makanan di tangan, terbentuk karena urutan*/
	/*F.S. : Makanan yang terbentuk dipindah ke tray*/

void Take (int ID, Stack *SH);
  /*I.S. : Ada bahan di sebelah pemain, kondisi tangan tidak penuh*/
	/*F.S. : Bahan berpindah ke tangan*/

int Give (Stack *ST, TabInt *T, Room *R, int *IDH);
/*I.S : Ada tumpukkan di tray*/
  /*F.S : Makanan pada top of tray akan diberikan kepada pelanggan*/

#endif
