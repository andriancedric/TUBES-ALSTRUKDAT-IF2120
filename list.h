//ADT List

#ifndef list_H
#define list_H

#include "boolean.h"
#include "map.h"

#define Nil NULL

typedef struct ttElmtlist *tElmtList;
typedef struct ttElmtlist {
  int ID;//ID pintu yang menghubungkan
	Room r;
	tElmtList Next;
} ElmtList;
typedef struct {
	tElmtList First;
} List;//List dari room2 yang terhubung ke suatu ruangan tertentu

//Selektor
#define Room(P) (P)->r

//Konstruktor
tElmtList AlokEList(int ID,Room r){
  tElmtList P;
  P = (ElmtList *) malloc (sizeof(ElmtList));
  ID(P)=ID;
  Room(P)=r;
  Next(P)=Nil;
  return P;
}

void DealokEList(tElmtList P){
  free(P);
}

void CreateList (List *L){
  tElmtList P;
  First(*L)=Nil;
}

//Fungsi/prosedur lain
tElmtList SearchList(List L, int ID){
  tElmtList P;
  P=First(L);
  while (P != Nil && ID(P)!=ID){
    P=Next(P);
  }
  return P;
}

void InsertEList(List *L,int ID,Room r){
  tElmtList P,Pn;
  P=First(*L);
  if (P!=Nil){
    while (Next(P) != Nil){
      P=Next(P);
    }
    Pn=AlokEList(ID,r);
    Next(P)=Pn;
  }
  else{
    Pn=AlokEList(ID,r);
    First(*L)=Pn;
  }
}

#endif
