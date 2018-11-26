#ifndef ARRAY_C
#define ARRAY_C

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "array.h"

void CreateEmptyArr(TabInt * T){
  //KAMUS
  int i;
  //ALGORITMA
  for(i = 1; i<=12; i++){
    Makanan(*T,i) = ValUndef;
    Kesabaran(*T,i) = ValUndef;
  }
}
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

boolean IsFullArr (TabInt T){
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
  TabInt Data;
  int r;
  //ALGORITMA
  Neff(Data) = 8;
  Makanan(Data, 1) = 4;
  Makanan(Data, 2) = 6;
  Makanan(Data, 3) = 9;
  Makanan(Data, 4) = 11;
  Makanan(Data, 5) = 15;
  Makanan(Data, 6) = 17;
  Makanan(Data, 7) = 21;
  Makanan(Data, 8) = 23;

  Kesabaran(Data, 1) = ValUndef;
  Kesabaran(Data, 2) = ValUndef;
  Kesabaran(Data, 3) = ValUndef;
  Kesabaran(Data, 4) = ValUndef;
  Kesabaran(Data, 5) = ValUndef;
  Kesabaran(Data, 6) = ValUndef;
  Kesabaran(Data, 7) = ValUndef;
  Kesabaran(Data, 8) = ValUndef;

  srand((unsigned)time(NULL));
  r = (rand() % (9 - 1)) + 1;
  Makanan(*T,i) = Makanan(Data, r);
  Kesabaran(*T,i) = (rand()%(41-30)) + 30;
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
    Makanan(*T,i) = ValUndef;
    Kesabaran(*T,i) = ValUndef;
}

void KesabaranMinusArr(TabInt *T, int c, PLAYER *play){
  /* Mengirimkan Arr dengan setiap elemen Arr dikurangkan c */
  //KAMUS
  IdxType i;
  //ALGORITMA
  i = GetFirstIdx(*T);
  for(i = GetFirstIdx(*T); i <= GetLastIdx(*T); i++){
    if(Makanan(*T,i) != ValUndef){
      Kesabaran(*T,i) -= c;
      if(Kesabaran(*T,i) == 0){
        DelEli(T,i);
        Life(*play)--;
      }
    }
  }
}

void PrintArr(TabInt T)
{
  //KAMUS
  int i;
  //ALGORITMA
  if(IsEmptyArr(T)){
    printf("   -Order Empty-\n");
  }
  else{
    for (i = 1; i <= 12; i++)
    {
      switch (Makanan(T, i))
      {
      case 4:
        printf("   Banana Split %d\n", i);
        break;
      case 6:
        printf("   Sundae_%d\n", i);
        break;
      case 9:
        printf("   Nasi Telur Dadar %d\n", i);
        break;
      case 11:
        printf("   Nasi Ayam Goreng %d\n", i);
        break;
      case 15:
        printf("   Burger %d\n", i);
        break;
      case 17:
        printf("   Hot Dog %d\n", i);
        break;
      case 21:
        printf("   Spaghetti Bolognese %d\n", i);
        break;
      case 23:
        printf("   Spaghetti Carbonara %d\n", i);
        break;
      case ValUndef:
        break;
      }
    }
  }
}

int IDMakanan(TabInt T,int idMeja){
  /* Mengirimkan idMakanan yang dipesan oleh meja dengan nomor meja idMeja */
  int idMakanan;
  idMakanan=Makanan(T,idMeja);
  if(idMakanan==ValUndef){
    return -1;
  }
  else{
    return idMakanan;
  }
}

void Order(Room R, TabInt *T, POINT P)
{
  //KAMUS
  //ALGORITMA

  if ((TipeR(R, Absis(P) - 1, Ordinat(P)) == 'X') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == 'C') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '1') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '2') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '4') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '5') ||
      (TipeR(R, Absis(P) - 1, Ordinat(P)) == '7') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(P) - 1, Ordinat(P))))
    {
      AddEli(T, Isi(SquareXY(R, Absis(P) - 1, Ordinat(P))));
    }
    else{
      printf("  Tidak ada Customer di Meja ini !");
    }
  }
  else if ((TipeR(R, Absis(P) + 1, Ordinat(P)) == 'X') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == 'C') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '1') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '2') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '4') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '5') ||
           (TipeR(R, Absis(P) + 1, Ordinat(P)) == '7') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(P) + 1, Ordinat(P))))
    {
      AddEli(T, Isi(SquareXY(R, Absis(P) + 1, Ordinat(P))));
    }
    else{
      printf("  Tidak ada Customer di Meja ini !");
    }
  }
  else if ((TipeR(R, Absis(P), Ordinat(P) - 1) == 'X') || (TipeR(R, Absis(P), Ordinat(P) - 1) == 'C') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '1') || (TipeR(R, Absis(P), Ordinat(P) - 1) == '2') || (TipeR(R, Absis(P), Ordinat(P) - 1) == '4') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '5') ||
           (TipeR(R, Absis(P), Ordinat(P) - 1) == '7') || (TipeR(R, Absis(P), Ordinat(P) - 1) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(P), Ordinat(P) - 1)))
    {
      AddEli(T, Isi(SquareXY(R, Absis(P), Ordinat(P) - 1)));
    }
    else{
      printf("  Tidak ada Customer di Meja ini !");
    }
  }
  else if ((TipeR(R, Absis(P), Ordinat(P) + 1) == 'X') || (TipeR(R, Absis(P), Ordinat(P) + 1) == 'C') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '1') || (TipeR(R, Absis(P), Ordinat(P) + 1) == '2') || (TipeR(R, Absis(P), Ordinat(P) + 1) == '4') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '5') ||
           (TipeR(R, Absis(P), Ordinat(P) + 1) == '7') || (TipeR(R, Absis(P), Ordinat(P) + 1) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(P), Ordinat(P) + 1)))
    {
      AddEli(T, Isi(SquareXY(R, Absis(P), Ordinat(P) + 1)));
    }
    else{
      printf("  Tidak ada Customer di Meja ini !");
    }
  }
  else
  {
    printf("  ANDA TIDAK BERADA DI SEKITAR MEJA");
  }
}

#endif
