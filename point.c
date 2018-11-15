
#include <stdio.h>
#include <stdlib.h>
#include "FP.h"

/* *** DEFINISI PROTOTIPE PRIMITIF *** */
/* *** Konstruktor membentuk POINT *** */
POINT MakePOINT (float X, float Y){
  /* Membentuk sebuah POINT dari komponen-komponennya */
  //Kamus
  POINT P;
  //ALGORITMA
  Absis(P)=X;
  Ordinat(P)=Y;
  return P;
}


/* *** KELOMPOK Interaksi dengan I/O device, BACA/TULIS  *** */
void TulisPOINT (POINT P){
  /* Nilai P ditulis ke layar dengan format "(X,Y)"
     tanpa spasi, enter, atau karakter lain di depan, belakang,
     atau di antaranya
     Output X dan Y harus dituliskan dalam bilangan riil dengan 2 angka di belakang koma.
  */
  /* I.S. P terdefinisi */
  /* F.S. P tertulis di layar dengan format "(X,Y)" */
  //Kamus
  //ALGORITMA
  printf("(%0.2f,%0.2f)\n",Absis(P),Ordinat(P));
}

boolean EQ (POINT P1, POINT P2){
  /* Mengirimkan true jika P1 = P2 : Absis dan Ordinatnya sama */
  if ((Absis(P1)==Absis(P2)) && (Ordinat(P1)==Ordinat(P2)))
    return true;
  else
    return false;
}

POINT NextX (POINT P){
  /* Mengirim salinan P dengan Absis ditambah satu */
  //KAMUS
  //ALGORITMA
  Absis(P)+=1;
  return P;
}
POINT NextY (POINT P){
  /* Mengirim salinan P dengan Ordinat ditambah satu */
  //ALGORITMA
  Ordinat(P)+=1;
  return P;
}
float Panjang (POINT P1, POINT P2){
  /* Menghitung panjang garis yang dibentuk P1 dan P2 */
  /* Perhatikanlah bahwa di sini spec fungsi kurang baik sebab menyangkut ADT Garis. */
  /* Tuliskan spec fungsi yang lebih tepat. */
  return (sqrt((Absis(P1)-Absis(P2))*(Absis(P1)-Absis(P2)) + (Ordinat(P1)-Ordinat(P2))*(Ordinat(P1)-Ordinat(P2))));
}

void Geser (POINT *P, float deltaX, float deltaY){
  /* I.S. P terdefinisi */
  /* F.S. P digeser, Absisnya sebesar deltaX dan Ordinatnya sebesar deltaY */
  //ALGORITMA
  Absis(*P) = Absis(*P) + deltaX;
  Ordinat(*P) =Ordinat(*P) + deltaY;
  *P = MakePOINT(Absis(*P),Ordinat(*P));
}
