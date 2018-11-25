#include <stdio.h>
#include "modstack.h"
#include "bintree.h"

//KAMUS UNTUK UANG MAKANAN
int uangmakanan = 0;

//KAMUS UNTUK LIST MAKANAN
char makanan[25][50] = { "empty", "piring", "sendok", "es krim", "pisang", "banana split", "stroberi", "sundae", "nasi", "telur", "nasi telur dadar",
                          "ayam goreng", "nasi ayam goreng", "garpu", "roti", "patty", "burger", "sosis", "hot dog", "spaghetti", "bolognese",
                          "keju","spaghetti bolognese", "carbonara", "spaghetti carbonara"};

/* ************ Prototype ************ */
/* *** Konstruktor/Kreator *** */
void CreateEmptySt (Stack *S) /*Bisa dipanggil saat CH untuk membuang Hand, CT untuk tray*/
{
  //KAMUS
  //ALGORITMA
  TopSt(*S) = 0;
  InfoTopSt(*S) = 0;
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
  int idxmakanan[5];
  Stack STemp;


	//ALGORITMA
  /*VALIDASI STACK DENGAN BINTREE*/

  indeks = 0;
	if (IsFullSt(*ST)){ /*tray penuh*/
		printf("Tray sudah penuh");
	}
	else {
    CreateEmptySt(&STemp);
    CopyStack(*SH,&STemp);
    InverseStack(&STemp); /*Menginvers stack agar dapat divalidasi dengan tree recipe*/

    /*Validasi bahan makanan pada tangan*/
    while(!IsEmptySt(STemp)) {
        Pop(&STemp, &IDTemp);
        idxmakanan[indeks] = IDTemp;
        /*if (Akar(P).ID != IDTemp){
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
    }*/
        indeks++;
    }

    if (idxmakanan[0] == 0 && idxmakanan[1] == 1 && idxmakanan[2] == 2 && idxmakanan[3] == 3  && idxmakanan[4] == 4) {
		  CreateEmptySt(SH);
		  Push(ST, 5); /*BANANA SPLIT*/
	  }
    else if (idxmakanan[0] == 0 && idxmakanan[1] == 1 && idxmakanan[2] == 2 && idxmakanan[3] == 3 && idxmakanan[4] == 6) {
		  CreateEmptySt(SH);
		  Push(ST, 7); /*SUNDAE*/
	  }
    else if (idxmakanan[0] == 0 && idxmakanan[1] == 1 && idxmakanan[2] == 2 && idxmakanan[3] == 8 && idxmakanan[4] == 9){
		  CreateEmptySt(SH);
		  Push(ST, 10); /*NASI TELUR DADAR*/
	  }
    else if (idxmakanan[0] == 0 && idxmakanan[1] == 1 && idxmakanan[2] == 2 && idxmakanan[3] == 8 && idxmakanan[4] == 11){
		  CreateEmptySt(SH);
		  Push(ST, 12); /*NASI AYAM GORENG*/
	  }
    else if (idxmakanan[0] == 0 && idxmakanan[1] == 1 && idxmakanan[2] == 13 && idxmakanan[3] == 14 && idxmakanan[4] == 15){
		  CreateEmptySt(SH);
		  Push(ST, 16); /*BURGER*/
	  }
    else if (idxmakanan[0] == 0 && idxmakanan[1] == 1 && idxmakanan[2] == 13 && idxmakanan[3] == 14 && idxmakanan[4] == 17){
		  CreateEmptySt(SH);
		  Push(ST, 18); /*HOTDOG*/
	  }
    else if (idxmakanan[0] == 0 && idxmakanan[1] == 1 && idxmakanan[2] == 13 && idxmakanan[3] == 19 && idxmakanan[4] == 20 && idxmakanan[5] == 21){
		  CreateEmptySt(SH);
		  Push(ST, 22); /*SPAGHETTI BOLOGNESE*/
	  }
    else if (idxmakanan[0] == 0 && idxmakanan[1] == 12 && idxmakanan[2] == 13 && idxmakanan[3] == 19 && idxmakanan[4] == 23){
		  CreateEmptySt(SH);
		  Push(ST, 24); /*SPAGHETTI */
	  }
    else {
    printf("Bahan makanan tidak sesuai urutan, tidak bisa dipindahkan ke tray");
    }
  }
}

void Take (int ID, Stack *SH) {
  /*I.S. : Ada bahan di sebelah pemain, kondisi tangan tidak penuh*/
	/*F.S. : Bahan berpindah ke tangan*/

    //KAMUS
    //ALGORITMA
    if(IsEmptySt(*SH)){
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
  if (*ID == 5 && *ID == 10) /*BANANA SPLIT dan NASI TELUR DADAR*/
  {
    uangmakanan = uangmakanan + 10000;
  }
  else if (*ID == 7) /* SUNDAE */
  {
    uangmakanan = uangmakanan + 8000;
  }
  else if (*ID == 12 && *ID == 22 && *ID == 24) /* NASI AYAM GORENG, SPAGHETTI BOLOGNESE, dan SPAGHETTI CARBONARA */
  {
    uangmakanan = uangmakanan + 15000;
  }
  else if (*ID == 16 && *ID == 18) /*BURGER dan HOTDOG*/
  {
    uangmakanan = uangmakanan + 12000;
  }
}

/*Simpan variabel money*/
int MoneyTemp(){
  return uangmakanan;
}

void NamaMakanan(Stack S) {
  //KAMUS
  char yeah;
  int indeks;

  //ALGORITMA
  indeks = InfoTopSt(S);
  printf("%s\n", makanan[indeks]);
}
