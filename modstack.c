#include <stdio.h>
#include "modstack.h"
#include "bintree.h"

//KAMUS UNTUK UANG MAKANAN
int uangmakanan = 0;

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySt (Stack *S) /*Bisa dipanggil saat CH untuk membuang Hand, CT untuk tray*/
{
  //KAMUS
  //ALGORITMA
  TopSt(*S) = 0;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptySt (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
  //KAMUS
  //ALGORITMA
  return (TopSt(S) == 0);
}
boolean IsFullSt (Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{
  //KAMUS
  //ALGORITMA
  return (TopSt(S) == 6);
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push (Stack *S, int ID)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
  //KAMUS
  //ALGORITMA
    TopSt(*S)++;
    InfoTopSt(*S) = ID;
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop (Stack *S, int *ID)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
{
  //KAMUS
  //ALGORITMA
  *ID = InfoTopSt(*S);
  TopSt(*S)--;
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
	int IDTemp, indeks;
  Stack STemp;
  boolean validasi;
  BinTree P;

	//ALGORITMA
  /*PEMBUATAN BINTREE*/
  indeks = 1;
  START("readtree.txt");
  BuildTree(&P, &indeks);

  /*VALIDASI STACK DENGAN BINTREE*/
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
        if (Akar(P).ID != IDTemp){
          validasi = false;
          printf("Bahan makanan tidak sesuai urutan, tidak bisa dipindahkan ke tray");
        }
        else if (Akar(P).ID == IDTemp){
            if (Left(P) != 0){
              Akar(P) = Akar(Left(P));
            }
            else if(Right(P) != 0){
              Akar(P) = Akar(Right(P));
            }   
        }
    }


    if ((validasi == true) && IDTemp == 3){
		  CreateEmptySt(SH);
		  Push(ST, 4); /*BANANA SPLIT*/
	  }
    else if ((validasi == true) && IDTemp == 5){
		  CreateEmptySt(SH);
		  Push(ST, 6); /*SUNDAE*/
	  }
    else if ((validasi == true) && IDTemp == 8){
		  CreateEmptySt(SH);
		  Push(ST, 9); /*NASI TELUR DADAR*/
	  }
    else if ((validasi == true) && IDTemp == 10){
		  CreateEmptySt(SH);
		  Push(ST, 11); /*NASI AYAM GORENG*/
	  }
    else if ((validasi == true) && IDTemp == 14){
		  CreateEmptySt(SH);
		  Push(ST, 15); /*BURGER*/
	  }
    else if ((validasi == true) && IDTemp == 16){
		  CreateEmptySt(SH);
		  Push(ST, 17); /*HOTDOG*/
	  }
    else if ((validasi == true) && IDTemp == 20){
		  CreateEmptySt(SH);
		  Push(ST, 21); /*SPAGHETTI BOLOGNESE*/
	  }
    else if ((validasi == true) && IDTemp == 22){
		  CreateEmptySt(SH);
		  Push(ST, 23); /*SPAGHETTI */
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

  /*Validasi ID Makanan dengan Harga makanan */
  if (*ID == 4 && *ID == 9) /*BANANA SPLIT dan NASI TELUR DADAR*/
  {
    uangmakanan = uangmakanan + 10000;
  }
  else if (*ID == 6) /* SUNDAE */
  {
    uangmakanan = uangmakanan + 8000;
  }
  else if (*ID == 11 && *ID == 21 && *ID == 23) /* NASI AYAM GORENG, SPAGHETTI BOLOGNESE, dan SPAGHETTI CARBONARA */
  {
    uangmakanan = uangmakanan + 15000;
  }
  else if (*ID == 15 && *ID == 17) /*BURGER dan HOTDOG*/
  {
    uangmakanan = uangmakanan + 12000;
  }
}

/*Simpan variabel money*/   
int MoneyTemp(){
  return uangmakanan;
}

Kata NamaMakanan(Stack S) {
  //KAMUS
  BinTree P;
  int indeks, ID;
  boolean namavalid;

  //ALGORITMA
  namavalid = false;
  indeks = 1;
  START("readtree.txt");
  BuildTree(&P, &indeks);

  while (Akar(P).ID != InfoTopSt(S) && namavalid == false){
    if (Akar(P).ID == InfoTopSt(S)){
       namavalid = true;
       
        return Akar(P);
    }
     else if(Right(P) != 0){
              Akar(P) = Akar(Right(P));
            }
            else if (Left(P) != 0){
              Akar(P) = Akar(Left(P));
            }   
        } 
}
