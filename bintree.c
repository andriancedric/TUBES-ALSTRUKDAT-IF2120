/* ADT Pohon Biner */
/* Implementasi dengan menggunakan pointer */
/* Penamaan type Kata*, type addrNode, dan beberapa fungsi disesuikan 
   karena melibatkan modul list rekursif. */

/* Modul lain yang digunakan : */
#include "bintree.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include <stdlib.h>
/* *** PROTOTYPE *** */
/* *** Konstruktor *** */
void Allocate (addrNode *P)
{
    //Kamus Lokal
    
    //Algoritma
    *P =(addrNode) malloc(sizeof(Node));
}

BinTree Tree(Kata Akar, BinTree L, BinTree R)
/* Menghasilkan sebuah pohon biner dari A, L, dan R, jika alokasi berhasil */
/* Menghasilkan pohon kosong (Nil) jika alokasi gagal */
{
  BinTree P;
  P = AlokNode(Akar);
  if (P != Nil) {
    Left(P) = L;
    Right(P) = R;
  }
  return P;
}

void MakeTree(Kata Akar, BinTree L, BinTree R, BinTree *P)
/* I.S. Akar, L, R terdefinisi. P Sembarang */
/* F.S. Membentuk pohon P dengan Akar(P)=Akar, Left(P)=L, dan Right(P)=R 
    jika alokasi berhasil. P = Nil jika alokasi gagal. */
{
  //Kamus Lokal
  
  //Algoritma
  *P = AlokNode(Akar);
  if (*P!= Nil) {
    Left(*P) = L;
    Right(*P) = R;
  } else {
    *P = Nil;
  }
}


void BuildTree(BinTree *P, int* idx)
// Membentuk sebuah pohon biner P dari pita karakter yang dibaca 
// I.S. Pita berisi "konstanta" pohon dalam bentuk prefix. Memori pasti cukup, alokasi pasti  berhasil. 
// F.S. P dibentuk dari ekspresi dalam  pita 
{
  //Kamus Lokal
  Kata Text; int i;
  //Algoritma
  ADV();
  //IgnoreBlank();
  if (CC==')')
    (*P)=Nil;
  else{
      Allocate(P);
      //Reset Num Array to 0
      Text.Length = 0;
      i=0;
      //Loop to fill Num Array with CC result
      while ((CC !='(')&&(CC!=')'))  {
        Text.TabKata[i] = CC;
        Text.Length ++;
        //printf("'%c'",CC);
        ADV();
        i++;
      }
      //Fill a node with STRING NUM converted to INTEGER with atoi()
      Text.ID = *idx;
      Akar(*P) = Text;
      *idx= *idx +1;
      BuildTree(&Left(*P),idx);
      //idx++;
      BuildTree(&Right(*P),idx);
    }
  ADV();
}


/* Manajemen Memory */
addrNode AlokNode(Kata X)
/* Mengirimkan addrNode hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka addrNode tidak Nil, dan misalnya menghasilkan P, 
  maka Akar(P) = X, Left(P) = Nil, Right(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
{
  //Kamus Lokal
  addrNode P;

  //Algoritma
  P = (addrNode) malloc (sizeof(Node));
  if (P!= Nil) {
    Akar(P) = X;
    Left(P) = Nil;
    Right(P) = Nil;
  }
  return P;
}

void DealokNode(addrNode P)
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian addrNode P */
{

    free(P); // Free requires an address as parameter.
}


/* *** PrediKata-PrediKata Penting *** */
boolean IsTreeEmpty (BinTree P) {
/* Mengirimkan true jika P adalah pohon biner kosong */
  return (P == Nil);
}
boolean IsTreeOneElmt (BinTree P) {
/* Mengirimkan true jika P adalah pohon biner tidak kosong dan hanya memiliki 1 elemen */
  return (P != Nil && Right(P) == Nil && Left(P) == Nil);
}
boolean IsUnerLeft (BinTree P) {
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerleft: hanya mempunyai subpohon kiri */
  return (Left(P) != Nil && Right(P) == Nil);
}
boolean IsUnerRight (BinTree P) {
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon unerright: hanya mempunyai subpohon kanan*/
  return (Left(P) == Nil && Right(P) != Nil);
}
boolean IsBiner (BinTree P) {
/* Mengirimkan true jika pohon biner tidak kosong P adalah pohon biner: mempunyai subpohon kiri dan subpohon kanan*/
  return (Left(P) != Nil && Right(P) != Nil);
}
/* *** Traversal *** */
void PrintPreorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara preorder: akar, pohon kiri, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (A()()) adalah pohon dengan 1 elemen dengan akar A
   (A(B()())(C()())) adalah pohon dengan akar A dan subpohon kiri (B()()) dan subpohon kanan (C()()) */
{
    //Kamus Lokal
    
    //Algoritma
   if (IsTreeEmpty(P)) {
     printf("()");
   } else {
     printf("(");
     printKata(Akar(P));
     //printf("%s",Akar(P));
     PrintPreorder(Left(P));
     PrintPreorder(Right(P));
     printf(")");
   }
}


void PrintInorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara inorder: pohon kiri, akar, dan pohon kanan. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()A()) adalah pohon dengan 1 elemen dengan akar A
   ((()B())A(()C())) adalah pohon dengan akar A dan subpohon kiri (()B()) dan subpohon kanan (()C()) */
{
    //Kamus Lokal
    
    //Algoritma
   if (IsTreeEmpty(P)) {
     printf("()");
   } else {
     printf("(");
     PrintInorder(Left(P));
     printKata(Akar(P));
     PrintInorder(Right(P));
     printf(")");
   }
}

void PrintPostorder(BinTree P)
/* I.S. P terdefinisi */
/* F.S. Semua simpul P sudah dicetak secara postorder: pohon kiri, pohon kanan, dan akar. 
   Setiap pohon ditandai dengan tanda kurung buka dan kurung tutup (). 
   Pohon kosong ditandai dengan ().
   Tidak ada tambahan karakter apa pun di depan, tengah, atau akhir. */
/* Contoh: 
   (()()A) adalah pohon dengan 1 elemen dengan akar A
   ((()()B)(()()C)A) adalah pohon dengan akar A dan subpohon kiri (()()B) dan subpohon kanan (()()C) */
{
    //Kamus Lokal
   if (IsTreeEmpty(P)) {
     printf("()");
   } else {
     printf("(");
     PrintPostorder(Left(P));
     PrintPostorder(Right(P));
     printKata(Akar(P));
     printf(")");
   }
}

void PrintSpasi(int h) 
{
    //Kamus Lokal
    int i;
    //Algoritma
    for (i=1; i<=h; i++) {
        printf(" ");
    }
}

void PrintTreeL (BinTree P, int h, int CLevel);
void PrintTreeL (BinTree P, int h, int CLevel) {
  int i;
  if (IsTreeEmpty(P)) {

  } else {
    for (i = 1; i<=h*(CLevel-1); i++) {
      printf(" ");
    }
    printKataR(Akar(P));
    if (Left(P) != Nil) {
      PrintTreeL(Left(P),h,CLevel+1);
    }
    if (Right(P) != Nil) {
      PrintTreeL(Right(P),h,CLevel+1);
    }
  }
}

void PrintTree(BinTree P, int h)
/* I.S. P terdefinisi, h adalah jarak indentasi (spasi) */
/* F.S. Semua simpul P sudah ditulis dengan indentasi (spasi) */
/* Penulisan akar selalu pada baris baru (diakhiri newline) */
/* Contoh, jika h = 2: 
1) Pohon preorder: (A()()) akan ditulis sbb:
A
2) Pohon preorder: (A(B()())(C()())) akan ditulis sbb:
A
  B
  C
3) Pohon preorder: (A(B(D()())())(C()(E()()))) akan ditulis sbb:
A
  B
    D
  C
    E
*/
{
    //Kamus Lokal
    
    //Algoritma
    PrintTreeL(P,h,1);
}



