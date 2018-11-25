#include <stdio.h>
#include <time.h>
#include "boolean.h"
#include "map.h"
#include "credit.c"
#include "modstack.c"
#include "mesinkata.c"
#include "mesinkar.c"
#include "jam.h"
#include "queue.c"
#include "array.c"
#include "point.h"
#include "bintree.c"

char* filename;
PLAYER play;
JAM detik;
int IDR,cd;
Room R;
Stack ST, SH;
Queue WaitQueue;
List L;
Graph G;
int idxx = 1;
BinTree P;
TabInt Pesan;
int orang[3] = {0,2,4};
POINT PNT;

void utama(){
    Kata inp;
    srand((unsigned)time(NULL));
    cd = (rand() % (8 - 4)) + 4;
    int i = (rand() % (3 - 1)) + 1;

    CreateEmptyQ(&WaitQueue,30);
    CreateEmptyArr(&Pesan);
    inp.TabKata[0] = '%';
    Length(&inp);
    while (!compareKata(inp,"EXIT")&&Life(play)>0){
        printf("\n  ------------------------------------------------------\n");
        printf("  %-15s Money: %-6d Life: %-6d Time: %-6d\n",Nama(play),Money(play),Life(play),Time(detik));
        Draw(R);
        printf("  > Waiting Cust       \n  ");
        PrintQ(WaitQueue);
        printf("  > Food Stack         \n  ");NamaMakanan(ST);
        printf("  > Order              \n");
        PrintArr(Pesan);
        printf("  > Hand               \n  ");NamaMakanan(SH);
        printf("  --------------------------------------------------------\n");
        NOMAP:
        printf("  Command: ");
        scanf("%s",inp.TabKata);
        Length(&inp);
        if (compareKata(inp,"GD") || compareKata(inp,"GU") || compareKata(inp,"GL") || compareKata(inp,"GR")) UpdatePosition(inp,&R,L,&G);
        else if (compareKata(inp,"ORDER")){
            Order(R, &Pesan, PosisiP);
        }
        else if (compareKata(inp,"PUT")){
            Put(&SH,&ST);
            }
        else if (compareKata(inp,"TAKE")){
          printf("  Direction (L,R,U,D): ");
          scanf("%s",inp.TabKata);
          Length(&inp);
          int ID=-1;
          if((TipeR(R,Absis(PosisiP),Ordinat(PosisiP)-1)=='M')&&compareKata(inp,"L")){
            ID=IsiR(R,Absis(PosisiP),Ordinat(PosisiP)-1);
          }
          else if((TipeR(R,Absis(PosisiP),Ordinat(PosisiP)+1)=='M')&&compareKata(inp,"R")){
            ID=IsiR(R,Absis(PosisiP),Ordinat(PosisiP)+1);
          }
          else if((TipeR(R,Absis(PosisiP)-1,Ordinat(PosisiP))=='M')&&compareKata(inp,"U")){
            ID=IsiR(R,Absis(PosisiP)-1,Ordinat(PosisiP));
          }
          else if((TipeR(R,Absis(PosisiP)+1,Ordinat(PosisiP))=='M')&&compareKata(inp,"D")){
            ID=IsiR(R,Absis(PosisiP)+1,Ordinat(PosisiP));
          }
          if(ID!=-1){
            Take(ID, &SH);
          }
          else{
            printf("Tidak ada meja di arah itu...\n");
            goto NOMAP;
          }
        }
        else if (compareKata(inp,"CH")){
            CreateEmptySt(&SH);
        }
        else if (compareKata(inp,"CT")){
            CreateEmptySt(&ST);
        }
        else if (compareKata(inp,"PLACE")){
            Place(R,&WaitQueue,PosisiP);
        }
        else if (compareKata(inp,"GIVE")){
          int IDH;
          Give(&ST,&Pesan,&R,&IDH);
        }
        else if (compareKata(inp,"RECIPE")){
            PrintTree(P,4);
            goto NOMAP;
        }
        else if (compareKata(inp,"SAVE")){
			printf("Input the desired savedata filename : ");
			scanf("%d",&filename);
			WriteSaveFile(filename, play, detik, location, L, WaitQueue, Pesan, ST, SH);
			printf("Data successfully written. Come again, baby.\n");
		}
        else if (compareKata(inp,"LOAD")){
			printf("Input a file name from which the program will collect initial data. (Including '.txt') : ");
			scanf("%d",&filename);
			ReadSaveFile(filename, &play, &detik, &location, &L, &WaitQueue, &Pesan, &ST, &SH);

			printf("Data successfully loaded! Enjoy your time, baby.\n");
		}
        else{
            printf("Input salah bos.\n");
            goto NOMAP;
        }
        Time(detik)++;
        cd--;
        if (cd == 0){
          AddQ(&WaitQueue,orang[i],30);
          srand((unsigned)time(NULL));
           cd = (rand() % (20 - 10)) + 10;
           i = (rand() % (3 - 1)) + 1;
        }
        if(!IsEmptyQ(WaitQueue)){
          KesabaranMinusQ(&WaitQueue,1,&play);
        }
        if(!IsEmptyArr(Pesan)){
          KesabaranMinusArr(&Pesan,1,&play);
        }
        if (Life(play)==0){
            Credit();
            exit(1);
        }
    }
}

int main(){
    int input;

    //TAMPILAN AWAL SAJA
    printf("-----------------------------------------------------------------\n");
    printf("--------ENGI'S---------------------------------------------------\n");
    printf("-------------------KITCHEN---------------------------------------\n");
    printf("-------------------------------EXPANSION-------------------------\n");
    printf("-----------------------------------------------2018--------------\n");
    printf("-----------------------------------------------------------------\n");
    printf("\n");

    //PILIHAN MENU
    printf("--------- Silakan pilih menu permainan di bawah ini :  ----------\n");
    printf(">> 1. New Game\n");
    printf(">> 2. Start Game\n");
    printf(">> 3. Load Game\n");
    printf(">> 4. Exit\n\n");
    printf(">> Input: ");
    scanf("%d", &input);

    MakeBuilding(&L,&G,&R,&IDR);
    Money(play) = 0;
    Life(play) = 3;
    Nama(play)[0] = ' ';
    START("readtree.txt");
	BuildTree(&P,&idxx);
    CreateEmptySt(&SH);
    CreateEmptySt(&ST);

    while (input!=4){
        if (input==1){
            printf(">>> Nama: ");
            scanf("%s",Nama(play));
        }
        else if (input==2){
            if (Nama(play)[0]==' ') printf("Pilih new game atau load game dahulu\n");
            else{
              Square Sq;
              MakeSquare(&Sq,'P',0,false,0);
              Absis(PosisiP)=1;
              Ordinat(PosisiP)=1;
              EditSquare(&R,Sq,Absis(PosisiP),Ordinat(PosisiP));
                utama();
                Credit();
                exit(1);
            }
        }
        else if (input==3){
            printf("Input a file name from which the program will collect initial data. (Including '.txt') : ");
			scanf("%d",&filename);
            ReadSaveFile(filename, &play, &detik, &location, &L, &WaitQueue, &Pesan, &ST, &SH);
			printf("Data successfully loaded! Enjoy your time, baby.\n");
        }
        else{
            printf("Input salah");
        }
        printf("\n>> Input: ");
        scanf("%d", &input);
    }
    Credit();

    return 0;
}
