
#include <stdio.h>
#include "modstack.h"
#include "bintree.h"

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySt (Stack *S) /*Bisa dipanggil saat CH untuk membuang Hand, CT untuk tray*/
{
  //KAMUS
  //ALGORITMA
  if (IsEmptySt(*S)){
    printf("Tumpukan kosong, tidak bisa melakukan CH atau CT");
  }
  else { /*Jika tumpukan ada isinya dan melakukan CH atau CT*/
  Top(*S) = 0;
  }
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySt (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
  //KAMUS
  //ALGORITMA
  return (Top(S) == 0);
}
boolean IsFullSt (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
  //KAMUS
  //ALGORITMA
  return (Top(S) == 5);
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

/* Prosedur-prosedur untuk validasi dalam stack*/
void CopyStack (Stack Sin, Stack *Sout)
{
  //KAMUS
  Stack Stacktemp;
  int Eltemp;
  

  //ALGORITMA
  CreateEmptySt(&Stacktemp);
  CreateEmptySt(Sout);
  while (!IsEmptySt(Sin)){
    Pop(&Sin,&Eltemp);
    Push(&Stacktemp, Eltemp);
  }
  while (!IsEmptySt(Stacktemp)){
    Pop(&Stacktemp, &Eltemp);
    Push(&Sin, Eltemp);
    Push(Sout, Eltemp);
  }
}

void InverseStack(Stack *S){
  //KAMUS 
  Stack STemp;
  int Eltemp;

  //ALGORITMA
  CreateEmptySt(&STemp);
  while (!IsEmptySt(*S)){
    Pop(S, &Eltemp);
    Push(&STemp, Eltemp);
  }
  CopyStack(STemp, S);
}

void Put (Stack *SH, Stack *ST){ /*SH adalah stack hand, ST adalah Stack tray*/
	/*I.S. : Ada tumpukan makanan di tangan, terbentuk karena urutan*/
	/*F.S. : Makanan yang terbentuk dipindah ke tray*/

	//KAMUS
	int IDTemp;
  Stack STemp;
  boolean validasi;
  BinTree P;

	//ALGORITMA
  validasi = true;
	if (IsFullSt(*ST)){ /*tray penuh*/
		printf("Tray sudah penuh");
	} 
	else {
    CreateEmptySt(&STemp);
    CopyStack(*SH,&STemp);
    InverseStack(&STemp); /*Menginvers stack agar dapat divalidasi dengan tree recipe*/

    /*Validasi bahan makanan pada tangan*/
    while(!IsEmptySt(STemp) && (validasi == true)) {
        Pop(&STemp, &IDTemp);
        if (Akar(P) != IDTemp){
          validasi = false;
          printf("Bahan makanan tidak sesuai urutan, tidak bisa dipindahkan ke tray");
        }
        else if (Akar(P) == IDTemp){
            Pop(&STemp, &IDTemp);
            if (Left(P) == IDTemp){
              Akar(P) == Left(P);
            }
            else if(Right(P) == IDTemp){
              Akar(P) == Right(P);
            }   
        }
    }
    if (validasi == true){
		Pop(SH,&IDTemp);
		Push(ST, IDTemp);
	  }
  }
}

void Take (int ID, Stack *SH) { 
  /*I.S. : Ada bahan di sebelah pemain, kondisi tangan tidak penuh*/
	/*F.S. : Bahan berpindah ke tangan*/

    //KAMUS
    //ALGORITMA
    if(!IsEmptySt(*SH)){
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
     
