//Driver map.h
//

#include "map.h"

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

//void  EditSquare(Room *R, Square S, int X, int Y);
//Mengedit square di room R di koordinat X,Y menjadi S

//void MakeSquare(Square *S, char tipe, int ID)
//Membuat Square

//void MakeDoor(Square *S, Room *R, Graph *G, int X, int Y);
//Prosedur khusus untuk membuat pintu

char Tipe(Room R, int X, int Y){//Getter Tipe u/ Room
    return R.S[X][Y].tipe;
}

int Isi(Room R, int X, int Y){//Getter isi u/ Room
    return  R.S[X][Y].isi;
}

int main(){
    int ext_status;
    Room R;
    MakeRoom(&R,1);
    Draw(R);
    return 0;
}