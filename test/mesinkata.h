/* File: mesinkata.h */
/* Definisi Mesin Kata: Model Akuisisi Versi I */
#include <stdio.h>

#ifndef __MESINKATA_H__
#define __MESINKATA_H__

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

#define NMax 50
#define BLANK ' '

typedef struct {
	char TabKata[100]; /* container penyimpan kata, indeks yang dipakai [1..NMax] */
    int Length;
    int ID;
} Kata;

/* State Mesin Kata */
extern boolean EndKata;
extern Kata CKata;

void IgnoreBlank();
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char* filename);
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA();
/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */

void SalinKata();
/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
boolean compareKata(Kata kata1, char* teks);
void Length(Kata *kata);
void printKata(Kata kata1);
void printID(Kata kata1);
void writefromMatriks(FILE* f, char strmatriks[8][8]);
void writefromArray(FILE* f, char strArr[20][100], int neff);

void ReadSaveFile(char* filename ,PLAYER* player, JAM* time, POINT* location, List L, Queue* Q, TabInt* Pesan, Stack *ST, Stack *SH ){
void WriteSaveFile(char* filename ,PLAYER player, JAM time, POINT location, List L, Queue WaitQ, TabInt Pesan, StackTray ST, StackHand SH );

#endif
