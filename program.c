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

PLAYER play;
JAM time;
Room R;
Stack ST, SH;
Queue WaitQueue;

void utama(){
    Kata inp;

    inp.TabKata[0] = '%';
    Length(&inp);
    while (!compareKata(inp,"EXIT")){
        printf("\n  --------------------------------------------------------\n");
        printf("  %-15s Money: %-6d Life: %-6d Time: %-6d\n",Nama(play),Money(play),Life(play),Time(time));
        printf("    Waiting Cust  ");
        printf("              Food Stack\n");
        printf("       %-16s        %d\n",Top(ST));
        printf("       Order      ");
        printf("              Hand\n");
        printf("       %-16s        %d\n",Top(SH));
        printf("  --------------------------------------------------------\n");
        printf("  Command: ");
        scanf("%s",inp.TabKata);
        Length(&inp);
        if (compareKata(inp,"GD") || compareKata(inp,"GU") || compareKata(inp,"GL") || compareKata(inp,"GR")) UpdatePosition(inp,&R);
        else if (compareKata(inp,"ORDER")){}
        else if (compareKata(inp,"PUT")){}
        else if (compareKata(inp,"TAKE")){}
        else if (compareKata(inp,"CH")){}
        else if (compareKata(inp,"CT")){}
        else if (compareKata(inp,"PLACE")){}
        else if (compareKata(inp,"GIVE")){}
        else if (compareKata(inp,"RECIPE")){}
        else if (compareKata(inp,"SAVE")){}
        else if (compareKata(inp,"LOAD")){}
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

    MakeRoom(&R,1);
    MakeRoom(&R,2);
    MakeRoom(&R,3);
    MakeRoom(&R,4);
    Money(play) = 0;
    Life(play) = 3;
    Nama(play)[0] = ' ';

    while (input!=4){
        if (input==1){
            printf(">>> Nama: ");
            scanf("%s",Nama(play));
        }
        else if (input==2){
            if (Nama(play)[0]==' ') printf("Pilih new game atau load game dahulu\n");
            else{
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
