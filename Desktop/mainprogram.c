/* Nama/NIM  : Andrian Cedric/13517065
 * Tanggal   : 25 Oktober 2018
 * Topik 	 : Pra-praktikum 09
 * Nama File : listsirkuler.c
 * Deskripsi : Body dari listsirkuler.h */

#include <stdio.h>
#include <stdlib.h>
#include "credit.c"

//KAMUS
int input;

int main(){
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
    printf(">>> 4. Exit\n");

    printf(">>> Input kamu : ");
    scanf("%d", &input);

    if (input == 4) {
        Credit();
    }

    return 0;
}