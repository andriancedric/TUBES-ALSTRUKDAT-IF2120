//Driver map.h
//

#include "graph.h"
#include "list.h"
#ifndef map_c
#define map_c

char TipeR(Room R, int X, int Y){//Getter Tipe u/ Room
    return R.S[X][Y].tipe;
}

int IsiR(Room R, int X, int Y){//Getter isi u/ Room
    return R.S[X][Y].isi;
}

void MakeRoom (List *L,Graph *G,Room *R,int ID){//Prosedur membuat room
  adrNode Pn;
  Pn=SearchGNode(*G,ID);
    if (Pn==Nil){
      int M = 8;
      int N = 8;
      //int ext_status;
      Room Rt;
      Square **S;
      Rt.ID=ID;//ID
      Rt.M=8;
      Rt.N=8;
      S = (Square **) malloc (M*sizeof(Square));
      for (int k = 0; k < M; k++) {
          S[k]=(Square *)malloc(N*sizeof(Square));//Alokasi
      }
         // if( S != NULL) {
              //ext_status = 1;
              for (int i=0; i < M; i++) {
                  for (int j = 0; j < N; ++j) {
                      Tipe(S[i][j]) = '-';//Secara default membuat . (tempat kosong)
                      Isi(S[i][j]) = 0;//Isi tempat kosong adalah 0
                  }
              }
              Rt.S=S;
              *R=Rt;
              InsertEList(L,ID,*R);
              InsertGNode(G,ID,Pn);
          /*}
              else {
              ext_status = 0; (ext_status Harusnya buat error msg tapi aku males...)
          }*/
          //return Rt;
        }
      else{
        printf("Telah terdapat room dengan ID: %d\n", ID);
      }
    }

void Draw(Room R){//Prosedur Menggambar peta
    Square S;
    int M=M(R);
    if (ID(&R)==4){
      printf("              Kitchen %d\n",ID(&R));
    }
    else{
      printf("                 Room %d\n",ID(&R));
    }
    for(int i=0;i<M(R);i++){
        printf("                 ");
        for(int j=0;j<N(R);j++){
            S=Square(R)[i][j];
            printf(" ");
            printf("%c",Tipe(S));
        }
        printf("\n");
    }
}

void Sit (Room *R, char tipe, int isi, int Jmlorg ){
  //KAMUS
  int i,j,count;
  int jml,wkt;
  //ALGORITMA
  count = Jmlorg;
  for (i=0; i<=7;i++){
    for (j=0; j<=7;j++){
      if((TipeR(*R,i,j) == 'X') && (IsiR(*R,i,j) == isi) ){
        IsOcc(SquareXY(*R,i,j)) = true;
        if(count > 0) {
          Tipe(SquareXY(*R,i,j)) = 'C';
          count--;
        }
      }
    }
  }
}

void EditSquare(Room *R, Square S, int X, int Y){
  (*R).S[X][Y]=S;
}
//Mengedit Square di room

void MakeSquare(Square *S, char tipe, int ID, boolean Occ, int cap){
  Tipe(*S)=tipe;
  Isi(*S)=ID;
  IsOcc(*S)=Occ;
  CapMeja(*S)=cap;
  //IsOcc(*S) = false;
  //CapMeja(*S) = 0;
}
//Membuat Square

void UpdatePosition(Kata input, Room *R, List L, Graph *G){
  Square Sq;
  int IDR=0;
  int X;
  X=Isi((*R).S[Absis(PosisiP)][Ordinat(PosisiP)]);
  if (X==0){
    MakeSquare(&Sq,'-',0,false,0);
    EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
  }
  else{
    MakeSquare(&Sq,'D',X,false,0);
    EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
  }
  if (compareKata(input,"GU")){
    if (Absis(PosisiP)>0){
      if((TipeR(*R,Absis(PosisiP)-1,Ordinat(PosisiP))=='-')||(TipeR(*R,Absis(PosisiP)-1,Ordinat(PosisiP))=='D')){
        Absis(PosisiP)--;
      }
    }
  }
  else if (compareKata(input,"GL")){
    if (Ordinat(PosisiP)>0){
      if((TipeR(*R,Absis(PosisiP),Ordinat(PosisiP)-1)=='-')||(TipeR(*R,Absis(PosisiP),Ordinat(PosisiP)-1)=='D')){
        printf("%c\n", TipeR(*R,Ordinat(PosisiP)-1,Absis(PosisiP)));
        Ordinat(PosisiP)--;
      }
    }
  }
  else if (compareKata(input,"GR")){
    if (Ordinat(PosisiP)<(N(*R)-1)){
      if((TipeR(*R,Absis(PosisiP),Ordinat(PosisiP)+1)=='-')||(TipeR(*R,Absis(PosisiP),Ordinat(PosisiP)+1)=='D')){
        Ordinat(PosisiP)++;
      }
    }
  }
  else if (compareKata(input,"GD")){
    if (Absis(PosisiP)<(M(*R)-1)){
      if((TipeR(*R,Absis(PosisiP)+1,Ordinat(PosisiP))=='-')||(TipeR(*R,Absis(PosisiP)+1,Ordinat(PosisiP))=='D')){
        Absis(PosisiP)++;
      }
    }
  }
  if (Tipe((*R).S[Absis(PosisiP)][Ordinat(PosisiP)])=='D'){
    tElmtList P;
    adrSuccNode Pn;
    X=Isi((*R).S[Absis(PosisiP)][Ordinat(PosisiP)]);
    Pn=SearchEdge(*G,ID(R),X);
    P=SearchList(L,X);
    *R=Room(P);
    Absis(PosisiP)=Absis(Start(Pn));
    Ordinat(PosisiP)=Ordinat(Start(Pn));
    IDR=Isi((*R).S[Absis(PosisiP)][Ordinat(PosisiP)]);
  }
  MakeSquare(&Sq,'P',IDR, false, 0);
  EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
}
//Prosedur untuk update display dan posisi player

void MakeDoor(Room *R, Graph *G, List L, int X1, int Y1, int X2, int Y2, int ID){
//Prosedur khusus untuk membuat pintu
  Square Sq;
  tElmtList P;
  P=SearchList(L,ID);
  if (P!=Nil){
    MakeSquare(&Sq,'D',ID,false,0);
    EditSquare(R,Sq,X1,Y1);
    MakeSquare(&Sq,'D',ID(R),false,0);
    EditSquare(&Room(P),Sq,X2,Y2);
    InsertEdge(G,ID(R),ID,X2,Y2);
    InsertEdge(G,ID,ID(R),X1,Y1);
  }
  else{
  printf("failed");
  }
}

void MakeBuilding(List *L, Graph *G, Room *R, int *Id){
  Square Sq;
  MakeRoom(L,G,R,1);
    /*Kursi*/
    MakeSquare(&Sq,'X',1,false,4);
    EditSquare(R,Sq,0,1);
    MakeSquare(&Sq,'X',1,false,4);
    EditSquare(R,Sq,1,0);
    MakeSquare(&Sq,'X',1,false,4);
    EditSquare(R,Sq,1,2);
    MakeSquare(&Sq,'X',1,false,4);
    EditSquare(R,Sq,2,1);
    MakeSquare(&Sq,'X',2,false,2);
    EditSquare(R,Sq,1,5);
    MakeSquare(&Sq,'X',2,false,2);
    EditSquare(R,Sq,1,7);
    MakeSquare(&Sq,'X',4,false,4);
    EditSquare(R,Sq,5,6);
    MakeSquare(&Sq,'X',4,false,4);
    EditSquare(R,Sq,7,6);
    MakeSquare(&Sq,'X',4,false,4);
    EditSquare(R,Sq,6,7);
    MakeSquare(&Sq,'X',4,false,4);
    EditSquare(R,Sq,6,5);
    MakeSquare(&Sq,'X',3,false,2);
    EditSquare(R,Sq,6,0);
    MakeSquare(&Sq,'X',3,false,2);
    EditSquare(R,Sq,6,2);
    /*ID*/
    MakeSquare(&Sq,'1',1,false,4);
    EditSquare(R,Sq,1,1);
    MakeSquare(&Sq,'2',2,false,2);
    EditSquare(R,Sq,1,6);
    MakeSquare(&Sq,'3',3,false,2);
    EditSquare(R,Sq,6,1);
    MakeSquare(&Sq,'4',4,false,4);
    EditSquare(R,Sq,6,6);
  MakeRoom(L,G,R,2);
    MakeSquare(&Sq,'X',5,false,4);
    EditSquare(R,Sq,0,1);
    MakeSquare(&Sq,'X',5,false,4);
    EditSquare(R,Sq,1,0);
    MakeSquare(&Sq,'X',5,false,4);
    EditSquare(R,Sq,1,2);
    MakeSquare(&Sq,'X',5,false,4);
    EditSquare(R,Sq,2,1);
    MakeSquare(&Sq,'X',6,false,2);
    EditSquare(R,Sq,1,5);
    MakeSquare(&Sq,'X',6,false,2);
    EditSquare(R,Sq,1,7);
    MakeSquare(&Sq,'X',8,false,4);
    EditSquare(R,Sq,5,6);
    MakeSquare(&Sq,'X',8,false,4);
    EditSquare(R,Sq,7,6);
    MakeSquare(&Sq,'X',8,false,4);
    EditSquare(R,Sq,6,7);
    MakeSquare(&Sq,'X',8,false,4);
    EditSquare(R,Sq,6,5);
    MakeSquare(&Sq,'X',7,false,2);
    EditSquare(R,Sq,6,0);
    MakeSquare(&Sq,'X',7,false,2);
    EditSquare(R,Sq,6,2);
    /*ID*/
    MakeSquare(&Sq,'5',5,false,4);
    EditSquare(R,Sq,1,1);
    MakeSquare(&Sq,'6',6,false,2);
    EditSquare(R,Sq,1,6);
    MakeSquare(&Sq,'7',7,false,2);
    EditSquare(R,Sq,6,1);
    MakeSquare(&Sq,'8',8,false,4);
    EditSquare(R,Sq,6,6);
  MakeRoom(L,G,R,3);
    MakeSquare(&Sq,'X',9,false,4);
    EditSquare(R,Sq,0,1);
    MakeSquare(&Sq,'X',9,false,4);
    EditSquare(R,Sq,1,0);
    MakeSquare(&Sq,'X',9,false,4);
    EditSquare(R,Sq,1,2);
    MakeSquare(&Sq,'X',9,false,4);
    EditSquare(R,Sq,2,1);
    MakeSquare(&Sq,'X',10,false,2);
    EditSquare(R,Sq,1,5);
    MakeSquare(&Sq,'X',10,false,2);
    EditSquare(R,Sq,1,7);
    MakeSquare(&Sq,'X',12,false,4);
    EditSquare(R,Sq,5,6);
    MakeSquare(&Sq,'X',12,false,4);
    EditSquare(R,Sq,7,6);
    MakeSquare(&Sq,'X',12,false,4);
    EditSquare(R,Sq,6,7);
    MakeSquare(&Sq,'X',12,false,4);
    EditSquare(R,Sq,6,5);
    MakeSquare(&Sq,'X',11,false,2);
    EditSquare(R,Sq,6,0);
    MakeSquare(&Sq,'X',11,false,2);
    EditSquare(R,Sq,6,2);
    /*ID*/
    MakeSquare(&Sq,'9',9,false,4);
    EditSquare(R,Sq,1,1);
    MakeSquare(&Sq,'A',10,false,2);
    EditSquare(R,Sq,1,6);
    MakeSquare(&Sq,'B',11,false,2);
    EditSquare(R,Sq,6,1);
    MakeSquare(&Sq,'Q',12,false,4);
    EditSquare(R,Sq,6,6);
    MakeRoom(L,G,R,4);
    MakeSquare(&Sq,'M',1,false,4);
    EditSquare(R,Sq,0,0);
    MakeSquare(&Sq,'M',2,false,4);
    EditSquare(R,Sq,1,0);
    MakeSquare(&Sq,'M',3,false,4);
    EditSquare(R,Sq,2,0);
    MakeSquare(&Sq,'M',4,false,4);
    EditSquare(R,Sq,3,0);
    MakeSquare(&Sq,'M',6,false,2);
    EditSquare(R,Sq,4,0);
    MakeSquare(&Sq,'M',8,false,2);
    EditSquare(R,Sq,5,0);
    MakeSquare(&Sq,'M',9,false,4);
    EditSquare(R,Sq,6,0);
    MakeSquare(&Sq,'M',11,false,4);
    EditSquare(R,Sq,7,2);
    MakeSquare(&Sq,'M',13,false,4);
    EditSquare(R,Sq,7,3);
    MakeSquare(&Sq,'M',14,false,4);
    EditSquare(R,Sq,7,4);
    MakeSquare(&Sq,'M',15,false,2);
    EditSquare(R,Sq,7,5);
    MakeSquare(&Sq,'M',17,false,2);
    EditSquare(R,Sq,7,6);
    MakeSquare(&Sq,'M',19,false,4);
    EditSquare(R,Sq,7,7);
    MakeSquare(&Sq,'M',20,false,4);
    EditSquare(R,Sq,3,3);
    MakeSquare(&Sq,'M',21,false,4);
    EditSquare(R,Sq,3,4);
    MakeSquare(&Sq,'M',23,false,4);
    EditSquare(R,Sq,3,5);
    MakeSquare(&Sq,'T',0,false,4);
    EditSquare(R,Sq,1,7);
  /*Door1*/
  tElmtList P;
  P=SearchList(*L,1);
  *R=Room(P);
  MakeDoor(R,G,*L,4,7,4,0,2);
  MakeDoor(R,G,*L,7,4,0,4,4);
  /*Door2*/
  P=SearchList(*L,2);
  *R=Room(P);
  MakeDoor(R,G,*L,7,4,0,4,3);
  /*Door3*/
  P=SearchList(*L,3);
  *R=Room(P);
  MakeDoor(R,G,*L,4,0,4,7,4);
  /*Door4*/
  P=SearchList(*L,4);
  *R=Room(P);
}

/*int main(){
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
}*/

#endif
