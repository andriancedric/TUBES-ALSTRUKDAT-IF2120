#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "map.c"
#include "array.c"
#include "program.c"
#include "point.h"
//KAMUS
void PrintArr(TabInt T);
void PrintQ(Queue Q);
void Order(TabInt * T);
void Place();

//ALGORITMA
void PrintArr(TabInt T){
  //KAMUS
  //ALGORITMA
  for(i = 1; i <= 12; i++ ){
    switch (Makanan(T,i)) {
      case 1: printf("Banana Split_%d\n",i);
              break;
      case 2: printf("Sundae_&d\n",i);
              break;
      case 3: printf("Nasi Telur Dadar_%d\n",i);
              break;
      case 4: printf("Nasi Ayam Goreng_%d\n",i);
              break;
      case 5: printf("Burger_%d\n",i);
              break;
      case 6: printf("Hot Dog_%d\n",i);
              break;
      case 7: printf("Spaghetti Bolognese_%d\n",i);
              break;
      case 8: printf("Spaghetti Carbonara_%d\n",i);
              break;
      case ValUndef : break;
    }
  }
  return 0;
}

void PrintQ(Queue Q){
  //KAMUS
  address i;
  //ALGORITMA
  for (i = Head(*Q); i <= Tail(*Q); i++){
    printf("%d\n",&JumlahOrang(Q,i));
  }
}

void Order(TabInt * T){
  //KAMUS
  //ALGORITMA

  if ((TipeR(R, Absis(play)-1, Ordinat(play) ) == 'X') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == 'C') ||(TipeR(R, Absis(play)-1, Ordinat(play) ) == '1')
     || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '2') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '4') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '5') ||
     (TipeR(R, Absis(play)-1, Ordinat(play) ) == '7') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(play)-1, Ordinat(play))))
    {
        AddEli(*T,Isi(SquareXY(R,Absis(play)-1, Ordinat(play))));
    }
  }
  else if ((TipeR(R, Absis(play)+1, Ordinat(play) ) == 'X') || (TipeR(R, Absis(play)+1, Ordinat(play) ) == 'C') ||(TipeR(R, Absis(play)-1, Ordinat(play) ) == '1')
     || (TipeR(R, Absis(play)+1, Ordinat(play) ) == '2') || (TipeR(R, Absis(play)+1, Ordinat(play) ) == '4') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '5') ||
     (TipeR(R, Absis(play)+1, Ordinat(play) ) == '7') || (TipeR(R, Absis(play)+1, Ordinat(play) ) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(play)+1, Ordinat(play))))
    {
       AddEli(*T,Isi(SquareXY(R,Absis(play)+1, Ordinat(play))));
    }
  }
  else if ((TipeR(R, Absis(play), Ordinat(play)-1 ) == 'X') || (TipeR(R, Absis(play), Ordinat(play)-1 ) == 'C') ||(TipeR(R, Absis(play)-1, Ordinat(play) ) == '1')
     || (TipeR(R, Absis(play), Ordinat(play)-1 ) == '2') || (TipeR(R, Absis(play), Ordinat(play)-1 ) == '4') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '5') ||
     (TipeR(R, Absis(play), Ordinat(play)-1 ) == '7') || (TipeR(R, Absis(play), Ordinat(play)-1 ) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(play), Ordinat(play)-1)))
    {
       AddEli(*T,Isi(SquareXY(R,Absis(play), Ordinat(play)-1)));
    }
  }
  else if ((TipeR(R, Absis(play), Ordinat(play)+1 ) == 'X') || (TipeR(R, Absis(play), Ordinat(play)+1 ) == 'C') ||(TipeR(R, Absis(play)-1, Ordinat(play) ) == '1')
     || (TipeR(R, Absis(play), Ordinat(play)+1 ) == '2') || (TipeR(R, Absis(play), Ordinat(play)+1 ) == '4') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '5') ||
     (TipeR(R, Absis(play), Ordinat(play)+1 ) == '7') || (TipeR(R, Absis(play), Ordinat(play)+1 ) == '8'))
  {
    if (IsOcc(SquareXY(R, Absis(play), Ordinat(play)+1)))
    {
      AddEli(*T,Isi(SquareXY(R,Absis(play), Ordinat(play)+1)));
    }
  }
  else
  {
      printf("ANDA TIDAK BERADA DI SEKITAR MEJA");
  }
}


void Place(){
  /* I.S : player berada di samping meja / kursi*/
  /* F.S : HEAD dari Queue Waiting Customer di delete dan di tanda X di meja berubah menjadi C di map */
  /*       jika jumlah customer melebihi jumlah kursi di meja yg bersangkutan, maka place gagal */
    //KAMUS
    int X,Y;
    //ALGORITMA
    if ((TipeR(R, Absis(play)-1, Ordinat(play) ) == 'X') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == 'C') ||(TipeR(R, Absis(play)-1, Ordinat(play) ) == '1')
       || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '2') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '4') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '5') ||
       (TipeR(R, Absis(play)-1, Ordinat(play) ) == '7') || (TipeR(R, Absis(play)-1, Ordinat(play) ) == '8'))
    {
        if (!IsOcc(SquareXY(R, Absis(play)-1, Ordinat(play))))
        {
            if (CapMeja(SquareXY(R, Absis(play)-1, Ordinat(play))) >= JumlahOrangHead(WaitQueue))
            {
              Sit(Tipe(SquareXY(R,Absis(play)-1,Ordinat(play))), Isi(SquareXY(R,Absis(play)-1,Ordinat(play))), JumlahOrangHead(WaitQueue));
              DelQ(&WaitQueue,&X,&Y);
            }
            else
            { //player berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
              if(SearchQ(WaitQueue,2))
              {
                SortQ(&WaitQueue);
                Sit(Tipe(SquareXY(R,Absis(play)-1,Ordinat(play))), Isi(SquareXY(R,Absis(play)-1,Ordinat(play))), JumlahOrangHead(WaitQueue));
                DelQ(&WaitQueue, &X, &Y);
              }
              else
              {// Tidak ada Pelanggan yang berjumlah 2 orang di WaitQueue
                printf("Kapasitas Meja Tidak Mencukupi !");
              }
            }
        }
        else
        {
            printf("Meja sudah ditempati customer lain");
        }
    }
    else if ((TipeR(R, Absis(play)+1, Ordinat(play) ) == 'X') || (TipeR(R, Absis(play)+1, Ordinat(play) ) == 'C') ||(TipeR(R, Absis(play)+1, Ordinat(play) ) == '1')
            || (TipeR(R, Absis(play)+1, Ordinat(play) ) == '2') || (TipeR(R, Absis(play)+1, Ordinat(play) ) == '4') || (TipeR(R, Absis(play)+1, Ordinat(play) ) == '5') ||
            (TipeR(R, Absis(play)+1, Ordinat(play) ) == '7') || (TipeR(R, Absis(play)+1, Ordinat(play) ) == '8'))
    {
        if (!IsOcc(SquareXY(R, Absis(play)+1, Ordinat(play))))
        {
          if (CapMeja(SquareXY(R, Absis(play)+1, Ordinat(play))) >= JumlahOrangHead(WaitQueue))
          {
            Sit(Tipe(SquareXY(R,Absis(play)+1,Ordinat(play))), Isi(SquareXY(R,Absis(play)+1,Ordinat(play))), JumlahOrangHead(WaitQueue));
            DelQ(&WaitQueue, &X, &Y);
          }
          else
          { //player berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
            if(SearchQ(WaitQueue,2))
            {
              SortQ(&WaitQueue);
              Sit(Tipe(SquareXY(R,Absis(play)+1,Ordinat(play))), Isi(SquareXY(R,Absis(play)+1,Ordinat(play))), JumlahOrangHead(WaitQueue));
              DelQ(&WaitQueue, &X, &Y);
            }
            else
            {// Tidak ada Pelanggan yang berjumlah 2 orang di WaitQueue
              printf("Kapasitas Meja Tidak Mencukupi !");
            }
          }
        }
        else {
            printf("Meja sudah ditempati customer lain");
        }
    }
    else if ((TipeR(R, Absis(play), Ordinat(play)-1 ) == 'X') || (TipeR(R, Absis(play), Ordinat(play)-1 ) == 'C') ||(TipeR(R, Absis(play), Ordinat(play)-1 ) == '1')
            || (TipeR(R, Absis(play), Ordinat(play)-1 ) == '2') || (TipeR(R, Absis(play), Ordinat(play)-1 ) == '4') || (TipeR(R, Absis(play), Ordinat(play)-1 ) == '5') ||
            (TipeR(R, Absis(play), Ordinat(play)-1 ) == '7') || (TipeR(R, Absis(play), Ordinat(play)-1 ) == '8'))
    {
        if (!IsOcc(SquareXY(R, Absis(play), Ordinat(play)-1)))
        {
            if (CapMeja(SquareXY(R, Absis(play), Ordinat(play) - 1)) >= JumlahOrangHead(WaitQueue))
            {
                Sit(Tipe(SquareXY(R, Absis(play), Ordinat(play) -1)), Isi(SquareXY(R, Absis(play), Ordinat(play) -1)), JumlahOrangHead(WaitQueue));
                DelQ(&WaitQueue, &X, &Y);
            }
            else
            { //player berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
                if (SearchQ(WaitQueue, 2))
                {
                    SortQ(&WaitQueue);
                    Sit(Tipe(SquareXY(R, Absis(play), Ordinat(play) -1)), Isi(SquareXY(R, Absis(play), Ordinat(play) -1)), JumlahOrangHead(WaitQueue));
                    DelQ(&WaitQueue, &X, &Y);
                }
                else
                { // Tidak ada Pelanggan yang berjumlah 2 orang di WaitQueue
                    printf("Kapasitas Meja Tidak Mencukupi !");
                }
            }
        }
        else {
            printf("Meja sudah ditempati customer lain");
        }
    }
    else if ((TipeR(R, Absis(play), Ordinat(play)+1 ) == 'X') || (TipeR(R, Absis(play), Ordinat(play)+1 ) == 'C') ||(TipeR(R, Absis(play), Ordinat(play)+1 ) == '1')
            || (TipeR(R, Absis(play), Ordinat(play)+1 ) == '2') || (TipeR(R, Absis(play), Ordinat(play)+1 ) == '4') || (TipeR(R, Absis(play), Ordinat(play)+1 ) == '5') ||
            (TipeR(R, Absis(play), Ordinat(play)+1 ) == '7') || (TipeR(R, Absis(play), Ordinat(play)+1 ) == '8'))
    {
        if (!IsOcc(SquareXY(R, Absis(play), Ordinat(play)+1)))
        {
            if (CapMeja(SquareXY(R, Absis(play), Ordinat(play) + 1)) >= JumlahOrangHead(WaitQueue))
            {
                Sit(Tipe(SquareXY(R, Absis(play), Ordinat(play) + 1)), Isi(SquareXY(R, Absis(play), Ordinat(play) + 1)), JumlahOrangHead(WaitQueue));
                DelQ(&WaitQueue, &X, &Y);
            }
            else
            { //player berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
                if (SearchQ(WaitQueue, 2))
                {
                    SortQ(&WaitQueue);
                    Sit(Tipe(SquareXY(R, Absis(play), Ordinat(play) + 1)), Isi(SquareXY(R, Absis(play), Ordinat(play) + 1)), JumlahOrangHead(WaitQueue));
                    DelQ(&WaitQueue, &X, &Y);
                }
                else
                { // Tidak ada Pelanggan yang berjumlah 2 orang di WaitQueue
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
    KesabaranMinusQ(&WaitQueue,1,&play);
}
