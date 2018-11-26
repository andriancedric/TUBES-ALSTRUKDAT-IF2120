#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/* ********* Prototype ********* */
boolean IsEmptyQ (Queue Q){
  /* Mengirim true jika Q kosong: lihat definisi di atas */
  return (Head(Q) == 0 && Tail(Q) == 0);
}
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFullQ (Queue Q){
  /* Mengirim true jika tabel penampung elemen Q sudah penuh */
  /* yaitu mengandung elemen sebanyak MaxEl */
  return (MaxEl(Q) == NBElmtQ(Q));
}

int NBElmtQ (Queue Q){
  /* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */
  //KAMUS
  int i;
  int count;
  //ALGORITMA
  if (IsEmptyQ(Q)){
    return 0;
  }
  else {
    count = 0;
    for (i = Head(Q); i<= Tail(Q); i++){
      count ++;
    }
    return count;
    }
}

/* *** Kreator *** */
void CreateEmptyQ (Queue * Q, int Max){
  /* I.S. sembarang */
  /* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
  /* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
  /* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
  /* Proses : Melakukan alokasi, membuat sebuah Q kosong */
  (*Q).T = (infotypeQ *) malloc ((Max+1) * sizeof(infotypeQ));
  if ((*Q).T != NULL) {
       MaxEl(*Q) = Max;
       Head(*Q) = 0;
       Tail(*Q) = 0;
  } else /* alokasi gagal */ {
       MaxEl(*Q) = 0;
  }
}

void DeAlokasiQ(Queue * Q){
  /* Proses: Mengembalikan memori Q */
  /* I.S. Q pernah dialokasi */
  /* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */
  MaxEl(*Q) = 0;
  free((*Q).T);
}

/* *** Primitif Add/Delete *** */
void AddQ (Queue * Q, int jumlahorang, int wktantri)
{
  /* Proses: Menambahkan X pada Q dengan aturan FIFO */
  /* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
  /* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */
  //Kamus
  int i;
  //ALGORITMA
  if (IsEmptyQ(*Q)) {
    Head(*Q) = 1;
    Tail(*Q) = 1;
    WktAntriHead(*Q) = wktantri;
    JumlahOrangHead(*Q) = jumlahorang;
    WktAntriTail(*Q) = wktantri;
    JumlahOrangTail(*Q) = jumlahorang;
  }
  else if(IsFullQ(*Q)){
    printf("  Queue Penuh!");
  }
  else {
    Tail(*Q)++;
    WktAntri(*Q,Tail(*Q)) = wktantri;
    JumlahOrang(*Q,Tail(*Q)) = jumlahorang;
  }
}



void DelQ (Queue * Q, int * jumlahorang, int * wktantri){
  /* Proses: Menghapus X pada Q dengan aturan FIFO */
  /* I.S. Q tidak mungkin kosong */
  /* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
          Q mungkin kosong */
  //KAMUS
  int i;
  //ALGORITMA
  *jumlahorang = JumlahOrangHead(*Q);
  *wktantri = WktAntriHead(*Q);
  if (Head(*Q) == Tail(*Q)){
    Head(*Q) = 0;
    Tail(*Q) = 0;
  }
  else {
    *jumlahorang = JumlahOrangHead(*Q);
    *wktantri = WktAntriHead(*Q);
    i = Head(*Q);
    while(i<Tail(*Q)){
      WktAntri(*Q,i) = WktAntri(*Q,i+1);
      JumlahOrang(*Q,i) = JumlahOrang(*Q,i+1);
      i++;
    }
    Tail(*Q)--;
  }
}
boolean SearchQ(Queue Q, int X)
{
  //KAMUS
  int i;
  boolean found;
  //ALGORITMA
  found = false;
  i = Head(Q);
  while ((i <= Tail(Q)) && !found)
  {
    if (JumlahOrang(Q, i) == X)
    {
      found = true;
    }
    else
    {
      i++;
    }
  }
  return found;
}
void SortQ(Queue *Q)
{
  //KAMUS
  int i;
  int wtemp, jtemp;
  boolean found;
  //ALGORITMA
  found = false;
  i = Head(*Q);
  while ((i <= Tail(*Q)) && !found)
  {
    if (JumlahOrang(*Q, i) == 2)
    {
      DelQIdx(Q, i, &jtemp, &wtemp);
      found = true;
    }
    else
    {
      i++;
    }
  }
  AddDepanQ(Q, jtemp, wtemp);
}

void AddDepanQ(Queue *Q, int jumlahorang, int wktantri)
{
  /* sama menambahkan antrian baru di depan (PrioQueue) */
  //KAMUS
  int i;
  //ALGORITMA
  if (IsEmptyQ(*Q))
  {
    Head(*Q) = 1;
    Tail(*Q) = 1;
    JumlahOrang(*Q, 1) = jumlahorang;
    WktAntri(*Q, 1) = wktantri;
  }
  else
  {
    Tail(*Q)++;
    i = Tail(*Q);
    while (i > Head(*Q))
    {
      JumlahOrang(*Q, i) = JumlahOrang(*Q, i - 1);
      WktAntri(*Q, i) = WktAntri(*Q, i - 1);
      i--;
    }
    JumlahOrang(*Q, i) = jumlahorang;
    WktAntri(*Q, i) = wktantri;
  }
}
void DelQIdx(Queue *Q, int idx, int *jumlahorang, int *wktantri)
{
  //KAMUS
  int i;
  //ALGORITMA
  *wktantri = WktAntri(*Q, idx);
  *jumlahorang = JumlahOrang(*Q, idx);
  i = idx;
  while (i < Tail(*Q))
  {
    JumlahOrang(*Q, i) = JumlahOrang(*Q, i + 1);
    WktAntri(*Q, i) = WktAntri(*Q, i + 1);
    i++;
  }
  Tail(*Q)--;
}
void KesabaranMinusQ(Queue *Q, int c, PLAYER * play){
  /* Mengirimkan Queue dengan setiap elemen Queue dikurangkan c */
  //KAMUS
  int i;
  int X,Y;
  //ALGORITMA
  i = Head(*Q);
  while(i<=Tail(*Q)){
    WktAntri(*Q,i) = WktAntri(*Q,i) - c;
    if(WktAntri(*Q,i) == 0){
      DelQIdx(Q,i,&X,&Y);
      Life(*play)--;
    }
    i++;
  }
}

void PrintQ(Queue Q)
{
  //KAMUS
  int i;
  //ALGORITMA
  if(IsEmptyQ(Q)){
    printf("   -Queue Empty-\n");
  }
  else{
    for (i = Head(Q); i <= Tail(Q); i++)
    {
      printf("   %d\n", JumlahOrang(Q, i));
    }
  }
}

void Place(Room R, Queue *Q, POINT P)
{
  /* I.S : Per berada di samping meja / kursi*/
  /* F.S : HEAD dari Queue Waiting Customer di delete dan di tanda X di meja berubah menjadi C di map */
  /*       jika jumlah customer melebihi jumlah kursi di meja yg bersangkutan, maka place gagal */
  //KAMUS
  int X, Y;
  //ALGORITMA
  if(!IsEmptyQ(*Q)){
    if ((TipeR(R, Absis(P) - 1, Ordinat(P)) == 'X') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == 'C') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '2') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '3') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '6') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == '7') ||
        (TipeR(R, Absis(P) - 1, Ordinat(P)) == 'A') || (TipeR(R, Absis(P) - 1, Ordinat(P)) == 'B'))
    {
      if (!IsOcc(SquareXY(R, Absis(P) - 1, Ordinat(P))))
      {
        if (CapMeja(SquareXY(R, Absis(P) - 1, Ordinat(P))) >= JumlahOrangHead(*Q))
        {
          Sit(&R, Tipe(SquareXY(R, Absis(P) - 1, Ordinat(P))), Isi(SquareXY(R, Absis(P) - 1, Ordinat(P))), JumlahOrangHead(*Q));
          DelQ(Q, &X, &Y);
        }
        else
        { //Per berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
          if (SearchQ(*Q, 2))
          {
            SortQ(Q);
            Sit(&R, Tipe(SquareXY(R, Absis(P) - 1, Ordinat(P))), Isi(SquareXY(R, Absis(P) - 1, Ordinat(P))), JumlahOrangHead(*Q));
            DelQ(Q, &X, &Y);
          }
          else
          { // Tidak ada Pelanggan yang berjumlah 2 orang di *Q
            printf("  Kapasitas Meja Tidak Mencukupi !");
          }
        }
      }
      else
      {
        printf("  Meja sudah ditempati customer lain");
      }
    }
    else if ((TipeR(R, Absis(P) + 1, Ordinat(P)) == 'X') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == 'C') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '2') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '3') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '6') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '7') ||
             (TipeR(R, Absis(P) + 1, Ordinat(P)) == 'A') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == 'B'))
    {
      if (!IsOcc(SquareXY(R, Absis(P) + 1, Ordinat(P))))
      {
        if (CapMeja(SquareXY(R, Absis(P) + 1, Ordinat(P))) >= JumlahOrangHead(*Q))
        {
          Sit(&R, Tipe(SquareXY(R, Absis(P) + 1, Ordinat(P))), Isi(SquareXY(R, Absis(P) + 1, Ordinat(P))), JumlahOrangHead(*Q));
          DelQ(Q, &X, &Y);
        }
        else
        { //Per berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
          if (SearchQ(*Q, 2))
          {
            SortQ(Q);
            Sit(&R, Tipe(SquareXY(R, Absis(P) + 1, Ordinat(P))), Isi(SquareXY(R, Absis(P) + 1, Ordinat(P))), JumlahOrangHead(*Q));
            DelQ(Q, &X, &Y);
          }
          else
          { // Tidak ada Pelanggan yang berjumlah 2 orang di *Q
            printf("  Kapasitas Meja Tidak Mencukupi !");
          }
        }
      }
      else
      {
        printf("  Meja sudah ditempati customer lain");
      }
    }
    else if ((TipeR(R, Absis(P), Ordinat(P) - 1) == 'X') || (TipeR(R, Absis(P), Ordinat(P) - 1) == 'C') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '2') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '3') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '6') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '7') ||
             (TipeR(R, Absis(P) + 1, Ordinat(P)) == 'A') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == 'B'))
    {
      if (!IsOcc(SquareXY(R, Absis(P), Ordinat(P) - 1)))
      {
        if (CapMeja(SquareXY(R, Absis(P), Ordinat(P) - 1)) >= JumlahOrangHead(*Q))
        {
          Sit(&R, Tipe(SquareXY(R, Absis(P), Ordinat(P) - 1)), Isi(SquareXY(R, Absis(P), Ordinat(P) - 1)), JumlahOrangHead(*Q));
          DelQ(Q, &X, &Y);
        }
        else
        { //Per berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
          if (SearchQ(*Q, 2))
          {
            SortQ(Q);
            Sit(&R, Tipe(SquareXY(R, Absis(P), Ordinat(P) - 1)), Isi(SquareXY(R, Absis(P), Ordinat(P) - 1)), JumlahOrangHead(*Q));
            DelQ(Q, &X, &Y);
          }
          else
          { // Tidak ada Pelanggan yang berjumlah 2 orang di *Q
            printf("  Kapasitas Meja Tidak Mencukupi !");
          }
        }
      }
      else
      {
        printf("  Meja sudah ditempati customer lain");
      }
    }
    else if ((TipeR(R, Absis(P), Ordinat(P) + 1) == 'X') || (TipeR(R, Absis(P), Ordinat(P) + 1) == 'C') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '2') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '3') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '6') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == '7') ||
             (TipeR(R, Absis(P) + 1, Ordinat(P)) == 'A') || (TipeR(R, Absis(P) + 1, Ordinat(P)) == 'B'))
    {
      if (!IsOcc(SquareXY(R, Absis(P), Ordinat(P) + 1)))
      {
        if (CapMeja(SquareXY(R, Absis(P), Ordinat(P) + 1)) >= JumlahOrangHead(*Q))
        {
          Sit(&R, Tipe(SquareXY(R, Absis(P), Ordinat(P) + 1)), Isi(SquareXY(R, Absis(P), Ordinat(P) + 1)), JumlahOrangHead(*Q));
          DelQ(Q, &X, &Y);
        }
        else
        { //Per berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
          if (SearchQ(*Q, 2))
          {
            SortQ(Q);
            Sit(&R, Tipe(SquareXY(R, Absis(P), Ordinat(P) + 1)), Isi(SquareXY(R, Absis(P), Ordinat(P) + 1)), JumlahOrangHead(*Q));
            DelQ(Q, &X, &Y);
          }
          else
          { // Tidak ada Pelanggan yang berjumlah 2 orang di *Q
            printf("  Kapasitas Meja Tidak Mencukupi !");
          }
        }
      }
      else
      {
        printf("  Meja sudah ditempati customer lain");
      }
    }
    else
    {
      printf("  ANDA TIDAK BERADA DI SEKITAR MEJA");
    }
  }
  else {
      printf("  QUEUE KOSONG !");
  }
}
