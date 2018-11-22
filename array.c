
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "array.h"


/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int NbElmtArr (TabInt T){
  /* Mengirimkan banyaknya elemen efektif tabel */
  /* Mengirimkan nol jika tabel kosong */
  //KAMUS
  int count,i;
  //ALGORITMA
  count = 0;
  for(i = GetFirstIdx(T); i<= GetLastIdx(T); i++){
    if(Makanan(T,i) != ValUndef){
      count++;
    }
  }
  return count;
}

/* *** Daya tampung container *** */
int MaxNbElArr (TabInt T){
  /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
return (IdxMaxArr-IdxMinArr +1);
}
/* *** Selektor INDEKS *** */
IdxType GetFirstIdx (TabInt T){
  /* Prekondisi : Tabel T tidak kosong */
  /* Mengirimkan indeks elemen T pertama */
return 1;
}

IdxType GetLastIdx (TabInt T){
  /* Prekondisi : Tabel T tidak kosong */
  /* Mengirimkan indeks elemen T terakhir */
return 12;
}



/* ********** TEST KOSONG/PENUH ********** */
/* *** Test tabel kosong *** */
boolean IsEmptyArr (TabInt T){
  /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
  /* *** Test tabel penuh *** */
  return (NbElmtArr(T) == 0);
}

boolean IsFull (TabInt T){
  /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
  if (NbElmtArr(T) == 12){
    return true;
  }
  else {
    return false;
  }
}

void AddEli (TabInt * T, IdxType i){
  /* Menambahkan X sebagai elemen ke-i tabel tanpa mengganggu kontiguitas
     terhadap elemen yang sudah ada */
  /* I.S. Tabel tidak kosong dan tidak penuh */
  /*      i adalah indeks yang valid. */
  /* F.S. X adalah elemen ke-i T yang baru */
  /* Proses : Geser elemen ke-i+1 s.d. terakhir */
  /*          Isi elemen ke-i dengan X */
  //KAMUS
  IdxType j;
  //ALGORITMA
  srand((unsigned)time(NULL));
  Makanan(*T,i) = (rand()%(8-1)) + 1;
  Kesabaran(*T,i) = (rand()%(40-30)) + 30;;
}

void DelEli (TabInt * T, IdxType i){
  /* Menghapus elemen ke-i tabel tanpa mengganggu kontiguitas */
  /* I.S. Tabel tidak kosong, i adalah indeks efektif yang valid */
  /* F.S. X adalah nilai elemen ke-i T sebelum penghapusan */
  /*      Banyaknya elemen tabel berkurang satu */
  /*      Tabel T mungkin menjadi kosong */
  /* Proses : Geser elemen ke-i+1 s.d. elemen terakhir */
  /*          Kurangi elemen efektif tabel */
  //KAMUS
  IdxType j;
  //ALGORITMA
  for (j=i;j<=GetLastIdx(*T)-1;j++){
    Makanan(*T,j) = ValUndef;
    Kesabaran(*T,j) = ValUndef;
    }
}
