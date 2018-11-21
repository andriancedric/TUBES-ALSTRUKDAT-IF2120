#include <stdio.h>
#include <stdlib.h>
#include "queue.c"
#include "map.c"

//KAMUS

void Place(){
  /* I.S : player berada di samping meja / kursi*/
  /* F.S : HEAD dari Queue Waiting Customer di delete dan di tanda X di meja berubah menjadi C di map */
  /*       jika jumlah customer melebihi jumlah kursi di meja yg bersangkutan, maka place gagal */
    //KAMUS
    int X,Y;
    //ALGORITMA
    if ((TipeR(R, Absis(Play)-1, Ordinat(Play) ) == 'X') || (TipeR(R, Absis(Play)-1, Ordinat(Play) ) == 'C') ||(TipeR(R, Absis(Play)-1, Ordinat(Play) ) == '1')
       || (TipeR(R, Absis(Play)-1, Ordinat(Play) ) == '2') || (TipeR(R, Absis(Play)-1, Ordinat(Play) ) == '4') || (TipeR(R, Absis(Play)-1, Ordinat(Play) ) == '5') ||
       (TipeR(R, Absis(Play)-1, Ordinat(Play) ) == '7') || (TipeR(R, Absis(Play)-1, Ordinat(Play) ) == '8'))
    {
        if (!IsOcc(R, Absis(Play)-1, Ordinat(Play)))
        {
            if (CapMeja(R, Absis(Play)-1, Ordinat(Play)) >= JumlahOrangHead(Q) )
            {
              Sit(Tipe(SquareXY(R,Absis(Play)-1,Ordinat(Play))), Isi(SquareXY(R,Absis(Play)-1,Ordinat(Play))), JumlahOrangHead(WaitQueue));
              DelQ(&WaitQueue,&X,&Y);
            }
            else
            { //Player berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
              if(SearchQ(WaitQueue,2))
              {
                SortQ(&WaitQueue);
                Sit(Tipe(SquareXY(R,Absis(Play)-1,Ordinat(Play))), Isi(SquareXY(R,Absis(Play)-1,Ordinat(Play))), JumlahOrangHead(WaitQueue));
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
    else if ((TipeR(R, Absis(Play)+1, Ordinat(Play) ) == 'X') || (TipeR(R, Absis(Play)+1, Ordinat(Play) ) == 'C') ||(TipeR(R, Absis(Play)+1, Ordinat(Play) ) == '1')
            || (TipeR(R, Absis(Play)+1, Ordinat(Play) ) == '2') || (TipeR(R, Absis(Play)+1, Ordinat(Play) ) == '4') || (TipeR(R, Absis(Play)+1, Ordinat(Play) ) == '5') ||
            (TipeR(R, Absis(Play)+1, Ordinat(Play) ) == '7') || (TipeR(R, Absis(Play)+1, Ordinat(Play) ) == '8'))
    {
        if (!IsOcc(R, Absis(Play)+1, Ordinat(Play)))
        {
          if (CapMeja(R, Absis(Play)+1, Ordinat(Play)) >= JumlahOrangHead(Q) )
          {
            Sit(Tipe(SquareXY(R,Absis(Play)+1,Ordinat(Play))), Isi(SquareXY(R,Absis(Play)+1,Ordinat(Play))), JumlahOrangHead(WaitQueue));
            DelQ(&WaitQueue, &X, &Y);
          }
          else
          { //Player berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
            if(SearchQ(WaitQueue,2))
            {
              SortQ(&WaitQueue);
              Sit(Tipe(SquareXY(R,Absis(Play)+1,Ordinat(Play))), Isi(SquareXY(R,Absis(Play)+1,Ordinat(Play))), JumlahOrangHead(WaitQueue));
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
    else if ((TipeR(R, Absis(Play), Ordinat(Play)-1 ) == 'X') || (TipeR(R, Absis(Play), Ordinat(Play)-1 ) == 'C') ||(TipeR(R, Absis(Play), Ordinat(Play)-1 ) == '1')
            || (TipeR(R, Absis(Play), Ordinat(Play)-1 ) == '2') || (TipeR(R, Absis(Play), Ordinat(Play)-1 ) == '4') || (TipeR(R, Absis(Play), Ordinat(Play)-1 ) == '5') ||
            (TipeR(R, Absis(Play), Ordinat(Play)-1 ) == '7') || (TipeR(R, Absis(Play), Ordinat(Play)-1 ) == '8'))
    {
        if (!IsOcc(R, Absis(Play), Ordinat(Play)-1 ))
        {
            if (CapMeja(R, Absis(Play), Ordinat(Play)-1) >= JumlahOrangHead(Q))
            {
                Sit(Tipe(SquareXY(R, Absis(Play), Ordinat(Play) -1)), Isi(SquareXY(R, Absis(Play), Ordinat(Play) -1)), JumlahOrangHead(WaitQueue));
                DelQ(&WaitQueue, &X, &Y);
            }
            else
            { //Player berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
                if (SearchQ(WaitQueue, 2))
                {
                    SortQ(&WaitQueue);
                    Sit(Tipe(SquareXY(R, Absis(Play), Ordinat(Play) -1)), Isi(SquareXY(R, Absis(Play), Ordinat(Play) -1)), JumlahOrangHead(WaitQueue));
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
    else if ((TipeR(R, Absis(Play), Ordinat(Play)+1 ) == 'X') || (TipeR(R, Absis(Play), Ordinat(Play)+1 ) == 'C') ||(TipeR(R, Absis(Play), Ordinat(Play)+1 ) == '1')
            || (TipeR(R, Absis(Play), Ordinat(Play)+1 ) == '2') || (TipeR(R, Absis(Play), Ordinat(Play)+1 ) == '4') || (TipeR(R, Absis(Play), Ordinat(Play)+1 ) == '5') ||
            (TipeR(R, Absis(Play), Ordinat(Play)+1 ) == '7') || (TipeR(R, Absis(Play), Ordinat(Play)+1 ) == '8'))
    {
        if (!IsOcc(R, Absis(Play), Ordinat(Play)+1 ))
        {
            if (CapMeja(R, Absis(Play), Ordinat(Play) - 1) >= JumlahOrangHead(Q))
            {
                Sit(Tipe(SquareXY(R, Absis(Play), Ordinat(Play) + 1)), Isi(SquareXY(R, Absis(Play), Ordinat(Play) + 1)), JumlahOrangHead(WaitQueue));
                DelQ(&WaitQueue, &X, &Y);
            }
            else
            { //Player berada di samping meja yg kapasistasnya 2 sedangkan HeadQ jmlh = 4
                if (SearchQ(WaitQueue, 2))
                {
                    SortQ(&WaitQueue);
                    Sit(Tipe(SquareXY(R, Absis(Play), Ordinat(Play) + 1)), Isi(SquareXY(R, Absis(Play), Ordinat(Play) + 1)), JumlahOrangHead(WaitQueue));
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
}
