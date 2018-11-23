#include <stdio.h>
#include "boolean.h"
#include "map.c"
#include "credit.c"
#include "modstack.h"
#include "mesinkata.c"
#include "mesinkar.c"
#include "jam.h"
#include "queue.h"
#include "point.h"
#include "bintree.c"

char* filename;
PLAYER play;
JAM time;
Room R;
Stack ST, SH;
Queue WaitQueue;
List L;
Graph G;
int idxx = 1;
BinTree P;


void utama(){
    Kata inp;

    inp.TabKata[0] = '%';
    Length(&inp);
    while (!compareKata(inp,"EXIT")){
        printf("\n  --------------------------------------------------------\n");
        printf("  %-15s Money: %-6d Life: %-6d Time: %-6d\n",Nama(play),Money(play),Life(play),Time(time));
        printf("    Waiting Cust  "); Draw(R);
        printf("Food Stack\n");
        printf("       %-16s        %d\n",Top(ST));
        printf("       Order      ");
        printf("              Hand\n");
        printf("       %-16s        %d\n",Top(SH));
        printf("  --------------------------------------------------------\n");
        printf("  Command: ");
        scanf("%s",inp.TabKata);
        Length(&inp);
        if (compareKata(inp,"GD") || compareKata(inp,"GU") || compareKata(inp,"GL") || compareKata(inp,"GR")) UpdatePosition(inp,&R,L,&G);
        else if (compareKata(inp,"ORDER")){}
        else if (compareKata(inp,"PUT")){}
        else if (compareKata(inp,"TAKE")){}
        else if (compareKata(inp,"CH")){}
        else if (compareKata(inp,"CT")){}
        else if (compareKata(inp,"PLACE")){}
        else if (compareKata(inp,"GIVE")){}
        else if (compareKata(inp,"RECIPE")) PrintTree(P,4);
        else if (compareKata(inp,"SAVE")){
			printf("Input the desired savedata filename : ");
			scanf("%d",&filename);
			WriteSaveFile(char* filename)
			printf("Data successfully written. Come again, baby.\n");
		}
        else if (compareKata(inp,"LOAD")){
			printf("Input a file name from which the program will collect initial data. (Including '.txt') : ");
			scanf("%d",&filename);
			ReadSaveFile(filename ,play, time, location, map, WaitQueue, L, ST, SH );
			printf("Data successfully loaded! Enjoy your time, baby.\n");
		}
        else{
            printf("Input salah bos.\n");
            Time(time)--;
        }
        Time(time)++;
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

    MakeRoom(&L,&G,&R,1);
    MakeRoom(&L,&G,&R,2);
    MakeRoom(&L,&G,&R,3);
    MakeRoom(&L,&G,&R,4);
    Money(play) = 0;
    Life(play) = 3;
    Nama(play)[0] = ' ';
    START("readtree.txt");
	BuildTree(&P,&idxx);

    while (input!=4){
        if (input==1){
            printf(">>> Nama: ");
            scanf("%s",Nama(play));
        }
        else if (input==2){
            if (Nama(play)[0]==' ') printf("Pilih new game atau load game dahulu\n");
            else{
              Square Sq;
              MakeSquare(&Sq,'P',0);
              EditSquare(&R,Sq,Absis(PosisiP),Ordinat(PosisiP));
                utama();
                Credit();
                exit(1);
            }
        }
        else if (input==3){

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
