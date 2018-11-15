#include <stdio.h>
#include "KamusVariabel.h"
#include "modstack.h"
#include "boolean.h"
#include "map.c"
#include "credit.c"

PLAYER play;
JAM time;
Room R;
StackTray ST;

void utama(){
    char inp[6];

    printf("--------------------------------------------------------------\n");
    printf("%15s Money: %6d Life: %d Time: %4d\n",Nama(play),Money(play),Life(play),Time(time));
    printf("Waiting Cust   ");
    Draw(R);
    printf("Food Stack\n");
    printf("%15s        %d\n",TopTray(ST));
    printf("--------------------------------------------------------------\n");
    printf("Order          ");
    printf("Hand\n");
    printf("Command: ");
    scanf("%s",inp);
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
    printf(">>> 1. New Game\n");
    printf(">>> 2. Start Game\n");
    printf(">>> 3. Load Game\n");
    printf(">>> 4. Exit\n\n");
    printf(">>> Input: ");
    scanf("%d", &input);

    MakeRoom(&R,1);
    MakeRoom(&R,2);
    MakeRoom(&R,3);
    MakeRoom(&R,4);
    Money(play) = 0;

    while (input!=4){
        if (input==1){
            printf("Nama: ");
            scanf("%s",Nama(play));
        }
        else if (input==2){
            utama();
        }
        else if (input==3){
            
        }
        else{
            printf("Input salah");
        }
    }
    Credit();

    return 0;
}