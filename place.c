#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "map.c"
#include "array.c"
#include "point.h"
//KAMUS
void PrintArr(TabInt T);
void PrintQ(Queue Q);
void Order(Room R, TabInt * T, POINT P);
void Place(Room R, Queue * Q, POINT P);

//ALGORITMA
void PrintArr(TabInt T){
  //KAMUS
  int i;
  //ALGORITMA
  for(i = 1; i <= 12; i++ ){
    switch (Makanan(T,i)) {
      case 4: printf("Banana Split_%d\n",i);
              break;
      case 6: printf("Sundae_&d\n",i);
              break;
      case 9: printf("Nasi Telur Dadar_%d\n",i);
              break;
      case 11: printf("Nasi Ayam Goreng_%d\n",i);
              break;
      case 15: printf("Burger_%d\n",i);
              break;
      case 17: printf("Hot Dog_%d\n",i);
              break;
      case 21: printf("Spaghetti Bolognese_%d\n",i);
              break;
      case 23: printf("Spaghetti Carbonara_%d\n",i);
              break;
      case ValUndef : break;
    }
  }
}

void PrintQ(Queue Q){
  //KAMUS
  address i;
  //ALGORITMA
  for (i = Head(Q); i <= Tail(Q); i++){
    printf("%d\n",&JumlahOrang(Q,i));
  }
}

void Order(Room R,TabInt * T, POINT P){
  //KAMUS
  //ALGORITMA

  if ((TipeR(R, Absis(P)-1, Ordinat(P) ) == 'X') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == 'C') ||(TipeR(R, Absis(P)-1, Ordinat(P) ) == '1')
     || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '2') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '4') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '5') ||
     (TipeR(R, Absis(P)-1, Ordinat(P) ) == '7') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(P)-1, Ordinat(P))))
    {
        AddEli(T,Isi(SquareXY(R,Absis(P)-1, Ordinat(P))));
    }
  }
  else if ((TipeR(R, Absis(P)+1, Ordinat(P) ) == 'X') || (TipeR(R, Absis(P)+1, Ordinat(P) ) == 'C') ||(TipeR(R, Absis(P)-1, Ordinat(P) ) == '1')
     || (TipeR(R, Absis(P)+1, Ordinat(P) ) == '2') || (TipeR(R, Absis(P)+1, Ordinat(P) ) == '4') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '5') ||
     (TipeR(R, Absis(P)+1, Ordinat(P) ) == '7') || (TipeR(R, Absis(P)+1, Ordinat(P) ) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(P)+1, Ordinat(P))))
    {
       AddEli(T,Isi(SquareXY(R,Absis(P)+1, Ordinat(P))));
    }
  }
  else if ((TipeR(R, Absis(P), Ordinat(P)-1 ) == 'X') || (TipeR(R, Absis(P), Ordinat(P)-1 ) == 'C') ||(TipeR(R, Absis(P)-1, Ordinat(P) ) == '1')
     || (TipeR(R, Absis(P), Ordinat(P)-1 ) == '2') || (TipeR(R, Absis(P), Ordinat(P)-1 ) == '4') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '5') ||
     (TipeR(R, Absis(P), Ordinat(P)-1 ) == '7') || (TipeR(R, Absis(P), Ordinat(P)-1 ) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(P), Ordinat(P)-1)))
    {
       AddEli(T,Isi(SquareXY(R,Absis(P), Ordinat(P)-1)));
    }
  }
  else if ((TipeR(R, Absis(P), Ordinat(P)+1 ) == 'X') || (TipeR(R, Absis(P), Ordinat(P)+1 ) == 'C') ||(TipeR(R, Absis(P)-1, Ordinat(P) ) == '1')
     || (TipeR(R, Absis(P), Ordinat(P)+1 ) == '2') || (TipeR(R, Absis(P), Ordinat(P)+1 ) == '4') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '5') ||
     (TipeR(R, Absis(P), Ordinat(P)+1 ) == '7') || (TipeR(R, Absis(P), Ordinat(P)+1 ) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(P), Ordinat(P)+1)))
    {
      AddEli(T,Isi(SquareXY(R,Absis(P), Ordinat(P)+1)));
    }
  }
  else
  {
      printf("ANDA TIDAK BERADA DI SEKITAR MEJA");
  }
}


void Place(Room R,Queue *Q, POINT P){
  /* I.S : Per berada di samping meja / kursi*/
  /* F.S : HEAD dari Queue Waiting Customer di delete dan di tanda X di meja berubah menjadi C di map */
  /*       jika jumlah customer melebihi jumlah kursi di meja yg bersangkutan, maka place gagal */
    //KAMUS
    int X,Y;
    //ALGORITMA
    if ((TipeR(R, Absis(P)-1, Ordinat(P) ) == 'X') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == 'C') ||(TipeR(R, Absis(P)-1, Ordinat(P) ) == '1')
       || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '2') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '4') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '5') ||
       (TipeR(R, Absis(P)-1, Ordinat(P) ) == '7') || (TipeR(R, Absis(P)-1, Ordinat(P) ) == '8'))
    {
        if (!IsOcc(SquareXY(R, Absis(P)-1, Ordinat(P))))
        {
            if (CapMeja(SquareXY(R, Absis(P)-1, Ordinat(P))) >= JumlahOrangHead(*Q))
            {
              Sit(&R,Tipe(SquareXY(R,Absis(P)-1,Ordinat(P))), Isi(SquareXY(R,Absis(P)-1,Ordinat(P))), JumlahOrangHead(*Q));
              DelQ(Q,&X,&Y);
            }
            else
            { //Per berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
              if(SearchQ(*Q,2))
              {
                SortQ(Q);
                Sit(&R,Tipe(SquareXY(R,Absis(P)-1,Ordinat(P))), Isi(SquareXY(R,Absis(P)-1,Ordinat(P))), JumlahOrangHead(*Q));
                DelQ(Q, &X, &Y);
              }
              else
              {// Tidak ada Pelanggan yang berjumlah 2 orang di *Q
                printf("Kapasitas Meja Tidak Mencukupi !");
              }
            }
        }
        else
        {
            printf("Meja sudah ditempati customer lain");
        }
    }
    else if ((TipeR(R, Absis(P)+1, Ordinat(P) ) == 'X') || (TipeR(R, Absis(P)+1, Ordinat(P) ) == 'C') ||(TipeR(R, Absis(P)+1, Ordinat(P) ) == '1')
            || (TipeR(R, Absis(P)+1, Ordinat(P) ) == '2') || (TipeR(R, Absis(P)+1, Ordinat(P) ) == '4') || (TipeR(R, Absis(P)+1, Ordinat(P) ) == '5') ||
            (TipeR(R, Absis(P)+1, Ordinat(P) ) == '7') || (TipeR(R, Absis(P)+1, Ordinat(P) ) == '8'))
    {
        if (!IsOcc(SquareXY(R, Absis(P)+1, Ordinat(P))))
        {
          if (CapMeja(SquareXY(R, Absis(P)+1, Ordinat(P))) >= JumlahOrangHead(*Q))
          {
            Sit(&R,Tipe(SquareXY(R,Absis(P)+1,Ordinat(P))), Isi(SquareXY(R,Absis(P)+1,Ordinat(P))), JumlahOrangHead(*Q));
            DelQ(Q, &X, &Y);
          }
          else
          { //Per berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
            if(SearchQ(*Q,2))
            {
              SortQ(Q);
              Sit(&R, Tipe(SquareXY(R,Absis(P)+1,Ordinat(P))), Isi(SquareXY(R,Absis(P)+1,Ordinat(P))), JumlahOrangHead(*Q));
              DelQ(Q, &X, &Y);
            }
            else
            {// Tidak ada Pelanggan yang berjumlah 2 orang di *Q
              printf("Kapasitas Meja Tidak Mencukupi !");
            }
          }
        }
        else {
            printf("Meja sudah ditempati customer lain");
        }
    }
    else if ((TipeR(R, Absis(P), Ordinat(P)-1 ) == 'X') || (TipeR(R, Absis(P), Ordinat(P)-1 ) == 'C') ||(TipeR(R, Absis(P), Ordinat(P)-1 ) == '1')
            || (TipeR(R, Absis(P), Ordinat(P)-1 ) == '2') || (TipeR(R, Absis(P), Ordinat(P)-1 ) == '4') || (TipeR(R, Absis(P), Ordinat(P)-1 ) == '5') ||
            (TipeR(R, Absis(P), Ordinat(P)-1 ) == '7') || (TipeR(R, Absis(P), Ordinat(P)-1 ) == '8'))
    {
        if (!IsOcc(SquareXY(R, Absis(P), Ordinat(P)-1)))
        {
            if (CapMeja(SquareXY(R, Absis(P), Ordinat(P) - 1)) >= JumlahOrangHead(*Q))
            {
                Sit(&R, Tipe(SquareXY(R, Absis(P), Ordinat(P) -1)), Isi(SquareXY(R, Absis(P), Ordinat(P) -1)), JumlahOrangHead(*Q));
                DelQ(Q, &X, &Y);
            }
            else
            { //Per berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
                if (SearchQ(*Q, 2))
                {
                    SortQ(Q);
                    Sit(&R,Tipe(SquareXY(R, Absis(P), Ordinat(P) -1)), Isi(SquareXY(R, Absis(P), Ordinat(P) -1)), JumlahOrangHead(*Q));
                    DelQ(Q, &X, &Y);
                }
                else
                { // Tidak ada Pelanggan yang berjumlah 2 orang di *Q
                    printf("Kapasitas Meja Tidak Mencukupi !");
                }
            }
        }
        else {
            printf("Meja sudah ditempati customer lain");
        }
    }
    else if ((TipeR(R, Absis(P), Ordinat(P)+1 ) == 'X') || (TipeR(R, Absis(P), Ordinat(P)+1 ) == 'C') ||(TipeR(R, Absis(P), Ordinat(P)+1 ) == '1')
            || (TipeR(R, Absis(P), Ordinat(P)+1 ) == '2') || (TipeR(R, Absis(P), Ordinat(P)+1 ) == '4') || (TipeR(R, Absis(P), Ordinat(P)+1 ) == '5') ||
            (TipeR(R, Absis(P), Ordinat(P)+1 ) == '7') || (TipeR(R, Absis(P), Ordinat(P)+1 ) == '8'))
    {
        if (!IsOcc(SquareXY(R, Absis(P), Ordinat(P)+1)))
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
                    printf("Kapasitas Meja Tidak Mencukupi !");
                }
            }
        }
        else {
            printf("Meja sudah ditempati customer lain");
        }
    }
    else
    {
      printf("ANDA TIDAK BERADA DI SEKITAR MEJA");
    }
}
