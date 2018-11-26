#include <stdio.h>
#include "modstack.h"
#include "bintree.h"
#include "map.c"

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
  return (TopSt(S) >= 5);
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
  int idxmakanan[6];
  Stack STemp;


	//ALGORITMA
  /*VALIDASI STACK DENGAN BINTREE*/

  indeks = 1;
	if (IsFullSt(*ST)){ /*tray penuh*/
		printf("Tray sudah penuh");
	}
	else {
    CreateEmptySt(&STemp);
    CopyStack(*SH,&STemp);
    /*Menginvers stack agar dapat divalidasi dengan tree recipe*/

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

    if (idxmakanan[1] == 4 && idxmakanan[2] == 3 && idxmakanan[3] == 2  && idxmakanan[4] == 1) {
		  CreateEmptySt(SH);
		  Push(ST, 5); /*BANANA SPLIT*/
	  }
    else if (idxmakanan[1] == 6 && idxmakanan[2] == 3 && idxmakanan[3] == 2 && idxmakanan[4] == 1) {
		  CreateEmptySt(SH);
		  Push(ST, 7); /*SUNDAE*/
	  }
    else if (idxmakanan[1] == 9 && idxmakanan[2] == 8 && idxmakanan[3] == 2 && idxmakanan[4] == 1){
		  CreateEmptySt(SH);
		  Push(ST, 10); /*NASI TELUR DADAR*/
	  }
    else if (idxmakanan[1] == 11 && idxmakanan[2] == 8 && idxmakanan[3] == 2 && idxmakanan[4] == 1){
		  CreateEmptySt(SH);
		  Push(ST, 12); /*NASI AYAM GORENG*/
	  }
    else if (idxmakanan[1] == 15 && idxmakanan[2] == 14 && idxmakanan[3] == 13 && idxmakanan[4] == 1){
		  CreateEmptySt(SH);
		  Push(ST, 16); /*BURGER*/
	  }
    else if (idxmakanan[1] == 17 && idxmakanan[2] == 14 && idxmakanan[3] == 13 && idxmakanan[4] == 1){
		  CreateEmptySt(SH);
		  Push(ST, 18); /*HOTDOG*/
	  }
    else if (idxmakanan[1] == 21 && idxmakanan[2] == 20 && idxmakanan[3] == 19 && idxmakanan[4] == 13 && idxmakanan[5] == 11){
		  CreateEmptySt(SH);
		  Push(ST, 22); /*SPAGHETTI BOLOGNESE*/
	  }
    else if (idxmakanan[1] == 23 && idxmakanan[2] == 19 && idxmakanan[3] == 13 && idxmakanan[4] == 1){
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
    if(!IsFullSt(*SH)){
        Push(SH, ID);
    }
    else{
        printf("Tangan kamu penuh. Kosongi dahulu");
    }
}

int Give (Stack *ST, TabInt *T, Room *R, int *IDH) {
  /*I.S : Ada tumpukkan di tray*/
  /*F.S : Makanan pada top of tray akan diberikan kepada pelanggan*/

  //KAMUS
  int IDTemp;

  //ALGORITMA
  uangmakanan=0;
  if (!IsEmptySt(*ST)){
    Pop(ST, &IDTemp);
    *IDH = IDTemp;
  }
  else{
    *IDH = ValUndef;
  }
  if (*IDH != ValUndef){
    int IDT=-1;
    int ID=0;
    Kata inp;
    printf("  Direction (L,R,U,D): ");
    scanf("%s",inp.TabKata);
    Length(&inp);
    if((TipeR(*R,Absis(PosisiP),Ordinat(PosisiP)-1)=='C')&&compareKata(inp,"L")){
      IDT=IsiR(*R,Absis(PosisiP),Ordinat(PosisiP)-1);
      ID=Makanan(*T,IDT);
    }
    else if((TipeR(*R,Absis(PosisiP),Ordinat(PosisiP)+1)=='C')&&compareKata(inp,"R")){
      IDT=IsiR(*R,Absis(PosisiP),Ordinat(PosisiP)+1);
      ID=Makanan(*T,IDT);
    }
    else if((TipeR(*R,Absis(PosisiP)-1,Ordinat(PosisiP))=='C')&&compareKata(inp,"U")){
      IDT=IsiR(*R,Absis(PosisiP)-1,Ordinat(PosisiP));
      ID=Makanan(*T,IDT);
    }
    else if((TipeR(*R,Absis(PosisiP)+1,Ordinat(PosisiP))=='C')&&compareKata(inp,"D")){
      IDT=IsiR(*R,Absis(PosisiP)+1,Ordinat(PosisiP));
      ID=Makanan(*T,IDT);
    }
    if(Makanan(*T,IDT)!=ValUndef){
      /*Validasi ID Makanan dengan Harga makanan */
      if (*IDH == 5 || *IDH == 10) /*BANANA SPLIT dan NASI TELUR DADAR*/
      {
        DelEli(T,IDT);
        for(int X=0;X<M(*R);X++){
          for(int Y=0; Y<N(*R); Y++){
            IsOcc(SquareXY(*R,X,Y))=false;
            if (IsiR(*R,X,Y)==IDT&&TipeR(*R,X,Y)=='C'){
              Tipe(SquareXY(*R,X,Y))='X';
            }
          }
        }
        uangmakanan = uangmakanan + 10000;
      }
      else if (*IDH == 7) /* SUNDAE */
      {
        DelEli(T,IDT);
        for(int X=0;X<M(*R);X++){
          for(int Y=0; Y<N(*R); Y++){
            IsOcc(SquareXY(*R,X,Y))=false;
            if (IsiR(*R,X,Y)==IDT&&TipeR(*R,X,Y)=='C'){
              Tipe(SquareXY(*R,X,Y))='X';
            }
          }
        }
        uangmakanan = uangmakanan + 8000;
      }
      else if (*IDH == 12 || *IDH == 22 || *IDH == 24) /* NASI AYAM GORENG, SPAGHETTI BOLOGNESE, dan SPAGHETTI CARBONARA */
      {
        DelEli(T,IDT);
        for(int X=0;X<M(*R);X++){
          for(int Y=0; Y<N(*R); Y++){
            IsOcc(SquareXY(*R,X,Y))=false;
            if (IsiR(*R,X,Y)==IDT&&TipeR(*R,X,Y)=='C'){
              Tipe(SquareXY(*R,X,Y))='X';
            }
          }
        }
        uangmakanan = uangmakanan + 15000;
      }
      else if (*IDH == 16 || *IDH == 18) /*BURGER dan HOTDOG*/
      {
        DelEli(T,IDT);
        for(int X=0;X<M(*R);X++){
          for(int Y=0; Y<N(*R); Y++){
            IsOcc(SquareXY(*R,X,Y))=false;
            if (IsiR(*R,X,Y)==IDT&&TipeR(*R,X,Y)=='C'){
              Tipe(SquareXY(*R,X,Y))='X';
            }
          }
        }
        uangmakanan = uangmakanan + 12000;
      }
    }
    else{
      Push(ST, IDTemp);
      printf("  Tidak ada meja di arah itu...\n");
    }
  }
  else{
    printf("  Stack tray kosong...\n");
  }
  return uangmakanan;
}

/*Simpan variabel money*/
int MoneyTemp(){
  return uangmakanan;
}

void NamaMakanan(Stack S) {
  //KAMUS
  char yeah;
  int indeks;
  Stack temp;
  int hehe;

  //ALGORITMA
  if (IsEmptySt(S)) printf(" -Empty-");
  CopyStack(S,&temp);
  InverseStack(&temp);
  while (!IsEmptySt(temp)){
    indeks = InfoTopSt(temp);
    printf("%s  ", makanan[indeks]);
    Pop(&temp,&hehe);
  }
  printf("\n");
}
