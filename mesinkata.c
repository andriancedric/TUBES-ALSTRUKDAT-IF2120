#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while ((CC== BLANK || CC == '\n' || CC == ';' || CC == ',' ) && CC != MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char* filename){
    START(filename);
    //printf("START%c", CC);
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
    //makeKataBlank(&CKata);
    IgnoreBlank();
    if (CC == MARK){
        //printf("CKataMARK : ");
        //printf("%c\n",CC);
        EndKata = true;}
    else{
        SalinKata();
        //printf("CKata : ");
        //printKata(CKata);
        IgnoreBlank();
    }
}

/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
void SalinKata(){
    int i;
    //printf("SalinKata entered! \n");
    i =0;
    for(;;){
        CKata.TabKata[i] = CC;
        //printf("%c", CC);
        ADV();
        if ( CC== MARK || CC == ':' || CC == ';'  || CC == '\n' || CC == ',' ){
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

void Length(Kata *kata){
    int i;
    for(i = 0; kata->TabKata[i] != '\0'; ++i);
      kata->Length = i;
}

int KataInt(Kata kata){
    int temp = 0;
    for(int i=0; i<=kata.Length; i++){
        temp = (temp*10) + (kata.TabKata[i]-'0');
    }
    return temp;
}

void makeKataBlank(Kata *kata){
    int i;
    for(i = 0; i<=100; ++i);
      kata->TabKata[i] = ' ';
}

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

void printKataR(Kata kata1){
  for(int i = 0; i<kata1.Length ; i++){
    printf("%c", kata1.TabKata[i]);
  }
  printf("\n");
}

void printKataMM(Kata kata1){
  for(int i = 0; i<=kata1.Length ; i++){
    printf("%c", kata1.TabKata[i]);
  }
  int spacenum = (15-kata1.Length);
  for(int i = 0; i<=spacenum ; i++){
    printf(" ");
  }
}
void printID(Kata kata1){
	printf("%d", kata1.ID);

	//printf("\n");
}
	//MAP PARSER -END-

/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
