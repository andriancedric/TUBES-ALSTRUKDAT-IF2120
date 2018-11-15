#include <stdio.h>
#include <stdlib.h>
#include "FP.h"

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
  /* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
  /* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
  /* F.S. Matriks M sesuai dengan definisi di atas terbentuk */
  //ALGORITMA
  NBrsEff(*M) = NB;
  NKolEff(*M) = NK;
}

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
  /* Mengirimkan indeks baris terkecil M */
  return (BrsMin);
}

indeks GetFirstIdxKol (MATRIKS M){
/* Mengirimkan indeks kolom terkecil M */
  return (KolMin);
}
indeks GetLastIdxBrs (MATRIKS M){
  /* Mengirimkan indeks baris terbesar M */
  return (NBrsEff(M));
}
indeks GetLastIdxKol (MATRIKS M){
  /* Mengirimkan indeks kolom terbesar M */
  return (NKolEff(M));
}
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
    return ((i>=GetFirstIdxBrs(M) && i<=GetLastIdxBrs(M)) && (j>=GetFirstIdxKol(M) && j<=GetLastIdxKol(M)));
}

void TulisMATRIKS (MATRIKS M){
  /* I.S. M terdefinisi */
  /* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
     dipisahkan sebuah spasi */
  /* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
  /* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
  1 2 3
  4 5 6
  8 9 10
  */
  //KAMUS
  indeks i,j;
  //ALGORITMA
  for (i = GetFirstIdxBrs(M) ; i <= GetLastIdxBrs(M) ; i++){
    for (j = GetFirstIdxKol(M) ; j <= GetLastIdxKol(M) ; j++){
        printf("%d",Elmt(M,i,j));
        if (j != GetLastIdxKol(M)){
          printf(" ");
        }
    }
    if(i != GetLastIdxBrs(M)){
      printf("\n");
    }
  }
}
