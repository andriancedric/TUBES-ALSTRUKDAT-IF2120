//Driver map.h
//

#include "graph.h"
#include "list.h"

char TipeR(Room R, int X, int Y){//Getter Tipe u/ Room
    return R.S[X][Y].tipe;
}

int IsiR(Room R, int X, int Y){//Getter isi u/ Room
    return R.S[X][Y].isi;
}

void MakeRoom (List *L,Graph *G,Room *R,int ID){//Prosedur membuat room
  adrNode Pn;
  Pn=SearchNode(*G,ID);
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
              InsertNode(G,ID,Pn);
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
    printf("                 Room %d\n",ID(&R));
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

/*void Sit (char tipe, int isi, int Jmlorg ){
  //KAMUS
  int i,j,count;
  int jml,wkt;
  //ALGORITMA
  count = Jmlorg;
  for (i=0; i<=7;i++){
    for (j=0; j<=7;j++){
      if((TipeR(*R,i,j) == tipe) && (IsiR(*R,i,j) == isi)){
        IsOcc(SquareXY(*R,i,j)) = true;
        if(count > 0) {
          Tipe(SquareXY(*R,i,j)) = 'C';
          count--;
        }
      }
    }
  }
}

void EditIsiMeja(Room *R, int X, int Y){
  (*R).S[X][Y]=S;
}*/
void EditSquare(Room *R, Square S, int X, int Y){
  (*R).S[X][Y]=S;
}
//Mengedit Square di room

void MakeSquare(Square *S, char tipe, int ID){
  Tipe(*S)=tipe;
  Isi(*S)=ID;
  //IsOcc(*S) = false;
  //CapMeja(*S) = 0;
}
//Membuat Square

void UpdatePosition(char *input, Room *R, List L, Graph *G){
  Square Sq;
  int IDR=0;
  int X;
  X=Isi((*R).S[Absis(PosisiP)][Ordinat(PosisiP)]);
  if (X==0){
    MakeSquare(&Sq,'-',0);
    EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
  }
  else{
    MakeSquare(&Sq,'D',X);
    EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
  }
  if (strcmp(input,"GU")==0){
    if (Absis(PosisiP)>0){
      Absis(PosisiP)--;
    }
  }
  else if (strcmp(input,"GL")==0){
    if (Ordinat(PosisiP)>0){
      Ordinat(PosisiP)--;
    }
  }
  else if (strcmp(input,"GR")==0){
    if (Ordinat(PosisiP)<(N(*R)-1)){
      Ordinat(PosisiP)++;
    }
  }
  else if (strcmp(input,"GD")==0){
    if (Absis(PosisiP)<(M(*R)-1)){
      Absis(PosisiP)++;
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
  MakeSquare(&Sq,'P',IDR);
  EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
  Draw(*R);
}
//Prosedur untuk update display dan posisi player

void MakeDoor(Room *R, Graph *G, List L, int X1, int Y1, int X2, int Y2, int ID){
//Prosedur khusus untuk membuat pintu
  Square Sq;
  tElmtList P;
  P=SearchList(L,ID);
  if (P!=Nil){
    MakeSquare(&Sq,'D',ID);
    EditSquare(R,Sq,X1,Y1);
    MakeSquare(&Sq,'D',ID(R));
    EditSquare(&Room(P),Sq,X2,Y2);
    InsertEdge(G,ID(R),ID,X2,Y2);
    InsertEdge(G,ID,ID(R),X1,Y1);
  }
  else{
  printf("failed");
  }
}

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
