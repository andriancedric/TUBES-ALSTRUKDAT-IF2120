//Driver map.h
//

#include "map.h"
#include "KamusVariabel.h"

char TipeR(Room R, int X, int Y){//Getter Tipe u/ Room
    return R.S[X][Y].tipe;
}

int IsiR(Room R, int X, int Y){//Getter isi u/ Room
    return  R.S[X][Y].isi;
}

void MakeRoom (Room *R,int ID){//Prosedur membuat room
    int M,N;
    int ext_status;
    Room Rt;
    Square **S;
    Rt.ID=ID;//ID
    printf("Masukkan M\n");
    scanf("%d",&M);
    Rt.M=M;//M
    printf("Masukkan N\n");
    scanf("%d",&N);
    Rt.N=N;//N
    S = (Square **) malloc (M*sizeof(Square));
    for (int k = 0; k < M; k++) {
        S[k]=(Square *)malloc(N*sizeof(Square));//Alokasi
    }
       // if( S != NULL) {
            //ext_status = 1;
            for (int i=0; i < M; i++) {
                for (int j = 0; j < N; ++j) {
                    Tipe(S[i][j]) = '.';//Secara default membuat . (tempat kosong)
                    Isi(S[i][j]) = 0;//Isi tempat kosong adalah 0
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

void  EditSquare(Room *R, Square S, int X, int Y){
  (*R).S[X][Y]=S;
}
//Mengedit Square di room

void MakeSquare(Square *S, char tipe, int ID){
  Tipe(*S)=tipe;
  Isi(*S)=ID;
}
//Membuat Square

void UpdatePosition(char *input, Room *R){
  Square Sq;
  MakeSquare(&Sq,'.',0);
  EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
  if (strcmp(input,"GU")==0){
    Absis(PosisiP)--;
    Absis(PosisiP)=(Absis(PosisiP) % M(*R));
  }
  else if (strcmp(input,"GL")==0){
    Ordinat(PosisiP)--;
    Ordinat(PosisiP)=(Ordinat(PosisiP) % N(*R));
  }
  else if (strcmp(input,"GR")==0){
    Ordinat(PosisiP)++;
    Ordinat(PosisiP)=(Ordinat(PosisiP) % N(*R));
  }
  else if (strcmp(input,"GD")==0){
    Absis(PosisiP)++;
    Absis(PosisiP)=(Absis(PosisiP) % M(*R));
  }
  MakeSquare(&Sq,'P',0);
  EditSquare(R,Sq,Absis(PosisiP),Ordinat(PosisiP));
  Draw(*R);
}
//Prosedur untuk update display dan posisi player

//void MakeDoor(Square *S, Room *R, Graph *G, int X, int Y);
//Prosedur khusus untuk membuat pintu
/* 
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
 */