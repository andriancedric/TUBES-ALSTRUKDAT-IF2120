#include <stdio.h>
#include <stdlib.h>
#include "FP.h"


/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q){
  /* Mengirim true jika Q kosong: lihat definisi di atas */
  return (Head(Q) == 0 && Tail(Q) == 0);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQ (Queue Q){
  /* Mengirim true jika tabel penampung elemen Q sudah penuh */
  /* yaitu mengandung elemen sebanyak MaxEl */
  //KAMUS
  //ALGORITMA
  return (NBElmtQ(Q) == MaxElQ);
}

int NBElmtQ (Queue Q){
  /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
  //KAMUS
  address i;
  int count;
  //ALGORITMA
  if (IsEmpty(Q)){
    return 0;
  }
  else {
    count = 0;
    for( i = Head(Q); i<=Tail(Q); i++){
      count++;
    }
    return count;
  }
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q){
  /* I.S. sembarang */
  /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
  /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
  /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
  /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
  //Kamus
  //ALGORITMA
  Head(*Q) = 0;
  Tail(*Q) = 0;
}


/* *** Primitif Add/Delete *** */
void AddQ (Queue * Q, int jumlahorang, int wktantri);
{
  /* Proses: Menambahkan X pada Q dengan aturan FIFO */
  /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
  /* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
  //Kamus
  //ALGORITMA
  if (IsEmpty(*Q)) {
    Head(*Q) = 1;
    Tail(*Q) = 1;
    WktAntriHead(*Q) = wktantri;
    JumlahOrangHead(*Q) = jumlahorang;
    WktAntriTail(*Q) = wktantri;
    JumlahOrangTail(*Q) = jumlahorang;
  }
  else if(IsFullQ(Q)){
    printf("Queue Penuh!");
  }
  else {
    Tail(*Q)++;
    WktAntriTail(*Q) = wktantri;
    JumlahOrangTail(*Q) = jumlahorang;
  }
}

void DelQ (Queue * Q, int * jumlahorang, int * wktantri){
  /* Proses: Menghapus X pada Q dengan aturan FIFO */
  /* I.S. Q tidak mungkin kosong */
  /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
          Q mungkin kosong */
  //KAMUS
  //ALGORITMA
  *jumlahorang = JumlahOrangHead(*Q);
  *wktantri = WktAntriHead(*Q);
  if (Head(*Q) == Tail(*Q)){
    Head(*Q) = 0;
    Tail(*Q) = 0;
  }
  else {
    Head(*Q)++;
  }
}
