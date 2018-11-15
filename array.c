#include <stdio.h>
#include <stdlib.h>
#include "FP.h"

void MakeEmptyArray (TabInt * T){
  /* I.S. T sembarang */
  /* F.S. Terbentuk tabel T kosong dengan kapasitas IdxMax-IdxMin+1 */
  Neff(*T)=0;
}

int NbElmtArr (TabInt T){
  /* Mengirimkan banyaknya elemen efektif tabel */
  /* Mengirimkan nol jika tabel kosong */

  return (Neff(T));
}

int MaxNbElArr (TabInt T){
  /* Mengirimkan maksimum elemen yang dapat ditampung oleh tabel */
return (30+1);
}

IdxType GetFirstIdxArr (TabInt T){
  /* Prekondisi : Tabel T tidak kosong */
  /* Mengirimkan indeks elemen T pertama */
  return (1);
}

IdxType GetLastIdxArr (TabInt T){
  /* Prekondisi : Tabel T tidak kosong */
  /* Mengirimkan indeks elemen T terakhir */
  return (NbElmtArr(T));
}


boolean IsIdxValid (TabInt T, IdxType i){
  /* Mengirimkan true jika i adalah indeks yang valid utk ukuran tabel */
  /* yaitu antara indeks yang terdefinisi utk container*/
  if ((i>=IdxMin)&&(i<=IdxMax)){
    return true;
  }
  else {
    return false;
  }
}

boolean IsIdxEff (TabInt T, IdxType i){
  /* Mengirimkan true jika i adalah indeks yang terdefinisi utk tabel */
  /* yaitu antara FirstIdx(T)..LastIdx(T) */
  if ((i>=GetFirstIdxArr(T))&&(i<=GetLastIdxArr(T))){
    return true;
  }
  else {
    return false;
  }
}


boolean IsArrEmpty (TabInt T){
  /* Mengirimkan true jika tabel T kosong, mengirimkan false jika tidak */
  return (NbElmtArr(T) == 0);
}

/* *** Test tabel penuh *** */
boolean IsArrFull (TabInt T){
  /* Mengirimkan true jika tabel T penuh, mengirimkan false jika tidak */
  if (NbElmtArr(T) == IdxMax){
    return true;
  }
  else {
    return false;
  }
}


boolean SearchArr (TabInt T, IdxType X){
  /* Search apakah ada elemen tabel T yang bernilai X */
  /* Jika ada, menghasilkan true, jika tidak ada menghasilkan false */
  /* Memakai Skema search DENGAN boolean */
  //KAMUS
  IdxType i;
  boolean found;
  //ALGORITMA
  i = GetFirstIdxArr(T);
  found = false;
  while ((i<=GetLastIdxArr(T)) && (!found)){
    if (Elmt(T,i) == X){
      found = true;
    }
    else {//Elmt(T1,i) != X
      i++;
    }
  }
  if (found){
    return true;
  }
  else {
    return false;
  }
}



void SortKesabaran (TabInt * T){
/* I.S. T boleh kosong */
/* F.S. T elemennya terurut menaik dengan Insertion Sort */
/* Proses : mengurutkan T sehingga elemennya menaik/membesar */
/*          tanpa menggunakan tabel kerja */
  //KAMUS
  IdxType i,pass;
  int Temp;
  //ALGORITMA
  if (NbElmtArr(*T)>1){
    for (pass=GetFirstIdxArr(*T)+1;pass<=NbElmtArr(*T);pass++){
      Temp = kesabaran(*T,pass);
      i=pass-1;
      while ((Temp<kesabaran(*T,i)) &&(i>1)){
        kesabaran(*T,i+1) = kesabaran(*T,i);
        i--;
      }
      if (Temp>=kesabaran(*T,i)){
        kesabaran(*T,i+1) = Temp;
      }
      else {
        kesabaran(*T,i+1) = kesabaran(*T,i);
        kesabaran(*T,i) = Temp;
      }
    }
  }
}
