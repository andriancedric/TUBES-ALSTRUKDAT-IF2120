//Driver map.h
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
#include "list.h"
#include "array.h"
#include "map.c"
#include "map.h"
#include "mesinkata.h"

int main(){
    int ext_status;
    Room R;
    List L;
    Graph G;
    CreateList(&L);
    CreateGraph(&G);
    MakeRoom(&L,&G,&R,1);
    tElmtList P;
    Square Sq;
    P=SearchList(L,1);
    MakeSquare(&Sq,'M',0);
    EditSquare(&Room(P),Sq,2,2);
    MakeRoom(&L,&G,&R,2);
    P=SearchList(L,2);
    EditSquare(&Room(P),Sq,2,1);
    MakeDoor(&R,&G,L,5,5,5,5,1);
    Absis(PosisiP)=0;
    Ordinat(PosisiP)=0;
    char input[10];
    UpdatePosition("GU",&R,L,&G);
    scanf("%s",&input);
    while (strcmp(input,"X")!=0){
      UpdatePosition(input,&R,L,&G);
      scanf("%s",&input);
    }
    return 0;
}
