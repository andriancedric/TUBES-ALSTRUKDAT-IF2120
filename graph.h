//ADT Graph

#ifndef graph_H
#define graph_H

#include "boolean.h"
#include "map.h"

#define Nil NULL

typedef struct tadrNode *adrNode;
typedef struct tadrSuccNode *adrSuccNode;
typedef struct tadrNode {
  int NPred;
	int ID;
	adrNode Next;
  adrSuccNode Trail;
} Node;
typedef struct tadrSuccNode {
	adrNode Succ;
  POINT start;
  adrSuccNode Next;
} SuccNode;//List dari room2 yang terhubung ke suatu ruangan tertentu
typedef struct {
  adrNode First;
} Graph;

//Selektor
#define NPred(P) (P)->NPred
#define Trail(P) (P)->Trail
#define Succ(Pt) (Pt)->Succ
#define Start(Pt) (Pt)->start

//Konstruktor
adrNode AlokNode(int ID){
  adrNode P;
  P = (Node *) malloc (sizeof(Node));
  ID(P)=ID;
  NPred(P)=0;
  Trail(P)=Nil;
  Next(P)=Nil;
  return P;
}

adrSuccNode AlokSuccNode(adrNode Pn,int X,int Y){
  adrSuccNode P;
  POINT Pt;
  P = (SuccNode *) malloc (sizeof(SuccNode));
  Absis(Pt)=X;
  Ordinat(Pt)=Y;
  IDP(Pt)=ID(Pn);
  Start(P)=Pt;
  Succ(P)=Pn;
  Next(P)=Nil;
  return P;
}

void DealokNode(adrNode P){
  free(P);
}

void DealokSuccNode(adrNode P){
  free(P);
}

void CreateGraph (Graph *G){
  adrNode P;
  First(*G)=Nil;
}

//Fungsi/prosedur lain
adrNode SearchNode(Graph G, int ID){
  adrNode P;
  P=First(G);
  while (P != Nil && ID(P)!=ID){
    P=Next(P);
  }
  return P;
}

adrSuccNode SearchEdge(Graph G, int prec, int succ){
  adrNode P;
  P=SearchNode(G,prec);
  if (P!=Nil){
    adrSuccNode Psucc;
    Psucc=Trail(P);
    while (Psucc!=Nil && ID(Succ(Psucc))!=succ){
      Psucc=Next(Psucc);
    }
    return Psucc;
  }
  else{
    return Nil;
  }
}

void InsertNode(Graph *G,int ID,adrNode Pn){
  adrNode P;
  P=First(*G);
  if (P!=Nil){
    while (Next(P) != Nil){
      P=Next(P);
    }
    Pn=AlokNode(ID);
    Next(P)=Pn;
  }
  else{
    Pn=AlokNode(ID);
    First(*G)=Pn;
  }
}

void InsertEdge(Graph *G,int prec,int succ,int X,int Y){
  adrNode Pprec,Psucc;
  Pprec=SearchNode(*G,prec);
  Psucc=SearchNode(*G,succ);
  if (Pprec==Nil){
    InsertNode(G,prec,Pprec);
  }
  if (Psucc==Nil){
    InsertNode(G,succ,Psucc);
  }
  if (SearchEdge(*G,prec,succ)==Nil){
    adrSuccNode PSN;
    PSN=Trail(Pprec);
    if (PSN==Nil){
      Trail(Pprec)=AlokSuccNode(Psucc,X,Y);
    }
    else{
      while (Next(PSN)!=Nil){
        PSN=Next(PSN);
      }
      Next(PSN)=AlokSuccNode(Psucc,X,Y);
    }
  }
}

#endif
