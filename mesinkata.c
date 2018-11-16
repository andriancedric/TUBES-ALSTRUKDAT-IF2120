#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include <string.h>

/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while ((CC== BLANK || CC == '\n' || CC == ';' || CC == ',' /*|| CC== ':'*/) && CC != MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char* filename){
    START(filename);
    IgnoreBlank();
    if (CC == MARK)
        EndKata = true;
    else{
        EndKata = false;
        SalinKata();
    }
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;}
    else{
        SalinKata();
        IgnoreBlank();
    }
}

/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

boolean compareKata(Kata kata1, char* teks){
	for(int i = 0; i<=kata1.Length ; i++){
		if (kata1.TabKata[i] != teks[i])
			return false;
	}
	return true;
}

void printKata(Kata kata1){
	for(int i = 0; i<=kata1.Length ; i++){
		printf("%c", kata1.TabKata[i]);
	}
	printf("\n");
}

void SalinKata(){
    int i;
    //printf("SalinKata entered! \n");
    i =0;
    for(;;){
        CKata.TabKata[i] = CC;
        //printf("%c", CC);
        ADV();
        if ( CC== MARK || CC == ':' || CC == ';'  || CC == '\n' || CC == ','){
            break;
        }
        else
            i ++;

    }
    //printKata(CKata);
    //printf("\nCC done \n");
    CKata.Length = i;
/*
    int i;
    i=1;
    while ((CC!=MARK) && ((CC!= BLANK)&&(CC!= '\n'))){
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }*/
}

void ReadSaveFile(char* filename /*,PLAYER player, JAM time, POINT location, MATRIKS map, Queue queue, TabInt list, StackTray fstack, StackHand hstack*/ ){
	STARTKATA(filename);
	IgnoreBlank();
	// Now position at the first Identity entry.

	//IDENTITY PARSER
	
	//printf("0. %s\n", CKata);
	while (!(compareKata(CKata, "//Map")) ){
		//printf("Identity parser entered! \n");
		//printKata(CKata);
		SalinKata();
		IgnoreBlank();
		//printf("Next Comparison ");
		//printKata(CKata);
		
		//printf("0. %s! compared with PlayerName      :! \n", CKata);
		if (compareKata(CKata, "PlayerName      " )){
			//printf("PlayerName entered! \n");
			ADV();
			IgnoreBlank();
			ADVKATA();
			printKata(CKata);
			//player.name = CKata;
			}
		else if (compareKata(CKata, "Money           " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			printKata(CKata);
			//player.money = CKata;
			}
		else if (compareKata(CKata, "Life            " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			printKata(CKata);
			//player.money = CKata;
			}
		else if (compareKata(CKata, "Time            " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			printKata(CKata);
			//time.SS = CKata;
			}
		else if (compareKata(CKata, "CurrentRoom     ")){
			ADV();
			IgnoreBlank();
			ADVKATA();
			printKata(CKata);
			//location.ID = CKata;
			}
		else if (compareKata(CKata, "X               " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			printKata(CKata);
			//location.X = CKata;
			}
		else if (compareKata(CKata, "Y               " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			printKata(CKata);
			//location.Y = CKata;
			}
		//printf("End Comparison ");
		//printKata(CKata);
	}
	//IDENTITY PARSER -END-

	IgnoreBlank();
	// Now position at the first map entry. 

	//MAP PARSER
	int i=1;
	int j=1;
	//printKata(CKata);
	ADVKATA();
	while (!compareKata(CKata, "//Details" )){
		printKata(CKata);
		ADVKATA();
		IgnoreBlank();
		
		//map[i][j] = CC;
		j++;
		if (j>8){
			j=1;
			i++;
		}
	}
	//MAP PARSER -END-

	IgnoreBlank();
	// Now position at the first details entry.//Waiting Cust

	//DETAILS PARSER
	//printf("Entering Details Parser\n");
	IgnoreBlank();
	ADVKATA();
	ADVKATA();
	i=1;
	while (!compareKata(CKata, "Order" )){
		printKata(CKata);
		ADVKATA();
		//queue.T[i]= CKata;
		IgnoreBlank();
		i++;
	}
	IgnoreBlank(); //POS now at first entry of Order
	ADVKATA();
	i=1;
	//printf("End\n");
	while (!compareKata(CKata, "Food Stack" )){
		printKata(CKata);
		//ADVKATA();
		//list.TI[i].makanan= CKata;
		ADVKATA();
		printKata(CKata);
		//list.TI[i].nomormeja= CKata;
		IgnoreBlank();
		i++;
		ADVKATA();
		//printf("ONE CYCLE\n");
	}
	//printf("End\n");
	IgnoreBlank();
	ADVKATA(); //POS now at first entry of FoodStack
	while (!compareKata(CKata, "Hand" )){
		printKata(CKata);
		ADVKATA();
		//Push(&fstack,CKata);
		IgnoreBlank();
	}
	//printf("End\n");
	IgnoreBlank();
	ADVKATA(); //POS now at first entry of Hand
	while (!compareKata(CKata,"ENDOFFILE")){
		printKata(CKata);
		ADVKATA();
		IgnoreBlank();
		//Push(&hstack,CKata);
	}

}
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
