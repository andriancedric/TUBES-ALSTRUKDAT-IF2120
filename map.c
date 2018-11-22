//Driver map.h
//

#include "map.h"
//include "KamusVariabel.h"

char TipeR(Room R, int X, int Y){//Getter Tipe u/ Room
    return R.S[X][Y].tipe;
}

int IsiR(Room R, int X, int Y){//Getter isi u/ Room
    return R.S[X][Y].isi;
}

void MakeRoom (Room *R,int ID){//Prosedur membuat room
    int M = 8;
    int N = 8;
    int ext_status;
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
                    Tipe(SquareXY(*R,i,j)) = '.';//Secara default membuat . (tempat kosong)
                    Isi(SquareXY(*R,i,j)) = 0;//Isi tempat kosong adalah 0
                }
            }
            Rt.S=S;
            *R=Rt;
        /*}
            else {
            ext_status = 0; (ext_status Harusnya buat error msg tapi aku males...)
        }*/
        //return Rt;
    }

void Draw(Room R){//Prosedur Menggambar peta
    Square S;
    int M=M(R);
    for(int i=0;i<M(R);i++){
        for(int j=0;j<N(R);j++){
            S=Square(R)[i][j];
            printf("%c",Tipe(S));
        }
        printf("\n");
    }
}

void Sit (char tipe, int isi, int Jmlorg ){
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
}
void EditSquare(Room *R, Square S, int X, int Y){
  (*R).S[X][Y]=S;
}
//Mengedit Square di room

void MakeSquare(Square *S, char tipe, int ID){
  Tipe(*S)=tipe;
  Isi(*S)=ID;
  IsOcc(*S) = false;
  CapMeja(*S) = 0;
}
//Membuat Square

void UpdatePosition(char *input, Room *R){
  Square Sq;
  MakeSquare(&Sq,'.',0);
  EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
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
  MakeSquare(&Sq,'P',0);
  EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
  Draw(*R);
}
//Prosedur untuk update display dan posisi player

//void MakeDoor(Square *S, Room *R, Graph *G, int X, int Y);
//Prosedur khusus untuk membuat pintu

int main(){
    int ext_status;
    Room R;
    MakeRoom(&R,1);
    Absis(PosisiP)=0;
    Ordinat(PosisiP)=0;
    char input[10];
    UpdatePosition(input,&R);
    scanf("%s",&input);
    while (strcmp(input,"X")!=0){
      UpdatePosition(input,&R);
      scanf("%s",input);
    }
    return 0;
}
