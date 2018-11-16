
#include <stdio.h>
#include "modstack.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySt (Stack *S) /*Bisa dipanggil saat CH untuk membuang Hand, CT untuk tray*/
{
  //KAMUS
  //ALGORITMA
  if (IsEmpty (*S)){
    printf("Tumpukan kosong, tidak bisa melakukan CH atau CT");
  }
  else { /*Jika tumpukan ada isinya dan melakukan CH atau CT*/
  Top(*S) = Nil;
  }
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySt (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
  //KAMUS
  //ALGORITMA
  return (Top(S) == Nil);
}
boolean IsFullSt (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
  //KAMUS
  //ALGORITMA
  return (Top(S) == MaxEl);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack *S, int ID)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
  //KAMUS
  //ALGORITMA
    Top(*S)++;
    InfoTop(*S) = ID;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack *S, int *ID)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
  //KAMUS
  //ALGORITMA
  *ID = InfoTop(*S);
  Top(*S)--;
}

void Put (Stack *SH, Stack *ST){ /*SH adalah stack hand, ST adalah Stack tray*/
	/*I.S. : Ada tumpukan makanan di tangan, terbentuk karena urutan*/
	/*F.S. : Makanan yang terbentuk dipindah ke tray*/

	//KAMUS
	int IDTemp;

	//ALGORITMA
	if (IsFull(*ST)){ /*tray penuh*/
		printf("Tray sudah penuh");
	} 
	else {
		Pop(SH,&IDTemp);
		Push(ST, IDTemp);
	}
}

void Take (int ID, Stack *SH) { 
  /*I.S. : Ada bahan di sebelah pemain, kondisi tangan tidak penuh*/
	/*F.S. : Bahan berpindah ke tangan*/

    //KAMUS
    //ALGORITMA
    if(!IsEmpty(*SH)){
        Push(SH, ID);
    }
    else{
        printf("Tangan kamu penuh. Kosongi dahulu");
    }
}

void Give (Stack *ST, int *ID) {
  /*I.S : Ada tumpukkan di tray*/
  /*F.S : Makanan pada top of tray akan diberikan kepada pelanggan*/

  //KAMUS
  int IDTemp;

  //ALGORITMA
  Pop(ST, &IDTemp);
  *ID = IDTemp;
}
     
