#include <stdio.h>
#include <time.h>
#include "boolean.h"
#include "map.h"
#include "credit.c"
#include "modstack.c"
#include "mesinkata.c"
#include "mesinkar.c"
#include "jam.h"
#include "queue.c"
#include "array.c"
#include "point.h"
#include "bintree.c"
#include "list.h"

char filename[100];
PLAYER play;
JAM detik;
int IDR,cd;
Room R;
Stack ST, SH;
Queue WaitQueue;
List L;
Graph G;
int idxx = 1;
BinTree P;
TabInt Pesan;
int orang[3] = {0,2,4};
POINT location;

void writefromMatriks(FILE* f, List L ){
	tElmtList P = First(L);
	while (P != Nil){
		R = Room(P);
		for(int i=1; i<=8; i++) {
			for(int j=1; j<=8; j++)
			    fprintf(f,"%c", TipeR(R,i,j));
			fprintf(f,";\n");
			}
		P = Next(P);
		fprintf(f,"\n");
	}
}

void writefromArray(FILE* f, char strArr[20][100], int neff){
	for(int i = 0; i<neff ; i++){
		fprintf(f,"%s", strArr[i]);
		if(i < neff-1)
			fprintf(f,",");
	}
	fprintf(f,";");
}

void writefromTabint(FILE* f, TabInt T){
	int neff = NbElmtArr(T);
	for(int i = 1; i<=12 ; i++){
		if(Makanan(T,i) != ValUndef){
			fprintf(f,"%d", Makanan(T,i));
			//fprintf(f,",");
			//fprintf(f,"%d;\n", i);
		}
	}
	fprintf(f,";");
}

void writefromQueue(FILE* f, Queue Q){
	int neff = NBElmtQ(Q);
	for(int i = 1; i<=neff ; i++){
		fprintf(f,"%d;\n", JumlahOrang(Q,i));
	}
}

void writefromStack(FILE* f, Stack Sin){
	Stack Sout;
	int ID;
	CreateEmptySt(&Sout);
	CopyStack(Sin,&Sout);
	while (TopSt(Sout) != 0){
		Pop(&Sout, &ID);
		fprintf(f,"%d;\n", ID);
	}
	fprintf(f,"\n");
}

/*void writeGraph(FILE* f, Graph G, List L){
	P = First(L);
	int roomcount=0;
	while (P != Nil){
		roomcount++;
	}

	adrSuccNode T;
	for(int i=1; i<=8; i++) {
			for(int j=i; j<=8; j++){
				T= SearchEdge(G,i,j);
			    fprintf(f,"%d,", Absis(T));
			    fprintf(f,"%d,", Ordinat(T));
			    fprintf(f,"%d,", i);
			    fprintf(f,"%d", j);
				}
			fprintf(f,";\n");
			}
}*/

void writeOccupiedSeats(FILE*f, List L){
	
	tElmtList P;
	int idx=1;
    printf("AAA\n");
        P = SearchList(L,1);
		R = Room(P);
    printf("AAA\n");

		fprintf(f,"//ROOM ", idx);fprintf(f,"1"); fprintf(f,"\n");
		for(int i=0; i<=7; i++) {
			for(int j=0; j<=7; j++){
				if(TipeR(R,i,j) == 'P')
					 fprintf(f,"%d,%d;\n",i,j );
				}
		}
        idx++;

        P = SearchList(L,2);
		R = Room(P);
    printf("AAA\n");
		fprintf(f,"//ROOM ", idx);fprintf(f,"2"); fprintf(f,"\n");
		for(int i=0; i<=7; i++) {
			for(int j=0; j<=7; j++){
				if(Tipe(SquareXY(R,i,j)) == 'P')
					 fprintf(f,"%d,%d;\n",i,j );
				}
		}
    printf("AAA\n");
        P = SearchList(L,3);
		R = Room(P);
        idx++;
		fprintf(f,"//ROOM "); fprintf(f,"3"); fprintf(f,"\n");
		for(int i=0; i<=7; i++) {
			for(int j=0; j<=7; j++){
				if(Tipe(SquareXY(R,i,j)) == 'P')
					 fprintf(f,"%d,%d;\n",i,j );
				}
		}
}


void WriteSaveFile(char* filename){
    printf("%s", filename);
	FILE *f = fopen(filename, "w");
	if (f != NULL)
	{
	    printf("\nCreating New File!\n");
	    //exit(1);
	}
	//EXAMPLE
	/*char* simplestr = "Ibu C.I.A.";
	char strmatriks[8][8] = {{'M','.','.','P','.','.','.','.'},
							{'M','.','.','.','.','.','.','.'},
							{'M','.','.','.','.','.','T','.'},
							{'M','.','.','.','.','.','.','.'},
							{'M','.','.','.','.','.','.','.'},
							{'M','.','.','.','.','.','.','.'},
							{'M','.','.','.','.','.','.','.'},
							{'M','.','.','.','.','.','.','.'}};
	char strArr[20][100] = {"Pizza of Obesity", "Mayonaise of promiscuity", "billy jelly"};
    */
	
	fprintf(f,"//Identity\n");
	fprintf(f,"\n");
    printf("\na\n");
	fprintf(f,"PlayerName      :       %s;\n",Nama(play).TabKata);
    printf("\na\n");

	fprintf(f,"Money           :       %d;\n",play.money);
	fprintf(f,"Life            :       %d;\n",play.life);
	fprintf(f,"Time            :       %d;\n",detik.SS);
	fprintf(f,"CurrentRoom     :       %d;\n",ID(&R));
	fprintf(f,"X               :       %d;\n",Absis(PosisiP));
	fprintf(f,"Y               :       %d;\n",Ordinat(PosisiP));
    printf("\nc\n");
	fprintf(f,"\n");
	fprintf(f,"//Map\n");
	fprintf(f,"\n");
	writeOccupiedSeats(f,L);
	fprintf(f,"\n");
	fprintf(f,"//Details\n");
	fprintf(f,"\n");
	fprintf(f,"Waiting Cust\n");
	fprintf(f,"    ");printf("\nb\n");writefromQueue(f,WaitQueue);fprintf(f,"\n");
	fprintf(f,"Order\n");
	fprintf(f,"    ");printf("\nb\n");writefromTabint(f,Pesan);fprintf(f,"\n");
	fprintf(f,"Food Stack\n");
	fprintf(f,"    ");printf("\nb\n");writefromStack(f,ST);fprintf(f,"\n");
	fprintf(f,"Hand\n");writefromStack(f,SH);fprintf(f,"\n");
	fprintf(f,"    ");

	fprintf(f,"ENDOFFILE#");
	fclose(f);
}

void ReadSaveFile(char* filename){
	STARTKATA(filename);
	IgnoreBlank();
	// Now position at the first Identity entry.
    printf("\nb\n");
	//IDENTITY PARSER
	
	//printf("0. %s\n", CKata);
	while (!(compareKata(CKata, "//Map")) ){
        printf("\nb\n");
		//printf("Identity parser entered! \n");
		//printKata(CKata);
		SalinKata();
		IgnoreBlank();
        
		//printf("Next Comparison ");
		//printKata(CKata);
		
		//printf("0. %s! compared with PlayerName      :! \n", CKata);
		if (compareKata(CKata, "PlayerName      " )){
			//printf("PlayerName entered! \n");
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			play.name = CKata;
			}
		else if (compareKata(CKata, "Money           " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			play.money = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "Life            " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			play.life = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "Time            " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			detik.SS = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "CurrentRoom     ")){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			ID(&R) = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "X               " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			Absis(PosisiP) = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "Y               " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			Ordinat(PosisiP) = atoi(CKata.TabKata);
			}
		//printf("End Comparison ");
		//printKata(CKata);
	}
	//IDENTITY PARSER -END-

	IgnoreBlank();
	// Now position at the first map entry. 

	//MAP PARSER
	int i;
	int j;
	//printKata(CKata);
	ADVKATA();
	//while (!compareKata(CKata, "//Details" )){
		//printKata(CKata);
		ADVKATA();
		IgnoreBlank();
		
		//MAP1
		ADVKATA();

        tElmtList P;
        P=SearchList(L,1);
        R=Room(P);
		while(!compareKata(CKata, "//ROOM 2")){
            printf("\nc\n");
			i = CKata.TabKata[0]-'0';
			IgnoreBlank();
			ADVKATA();
			j = CKata.TabKata[0]-'0';
			IgnoreBlank();
			SquareXY(R,i,j).occupied = true;
			Tipe(SquareXY(R,i,j)) = 'P';
			ADVKATA();
			}

        P=SearchList(L,2);
        R=Room(P);
		while(!compareKata(CKata, "//ROOM 3")){
            printf("\nd\n");
			i = CKata.TabKata[0]-'0';
			IgnoreBlank();
			ADVKATA();
			j = CKata.TabKata[0]-'0';
			IgnoreBlank();
			SquareXY(R,i,j).occupied = true;
			Tipe(SquareXY(R,i,j)) = 'P';
			ADVKATA();
			}

        P=SearchList(L,3);
        R=Room(P);
		while(!compareKata(CKata, "//ROOM 4")){
			i = CKata.TabKata[0]-'0';
			IgnoreBlank();
			ADVKATA();
			j = CKata.TabKata[0]-'0';
			IgnoreBlank();
			SquareXY(R,i,j).occupied = true;
			Tipe(SquareXY(R,i,j)) = 'P';
			ADVKATA();
			}
		//ROOM4
		ADVKATA();
		//Details
		IgnoreBlank();
		ADVKATA();
		//WAITING CUST.

		ADVKATA(); // First Value
		i = 1;
		while(!compareKata(CKata, "Order")){
			JumlahOrang(WaitQueue,i) = (CKata.TabKata[0]-'0');
			i++;
			IgnoreBlank();
			ADVKATA();
		}

		//Ckata : order
		IgnoreBlank();
		ADVKATA();

		i=1;
		while (!compareKata(CKata, "Food Stack" )){
		//printKata(CKata);
		//ADVKATA();
		Makanan(Pesan,i) = CKata.TabKata[0]-'0';
		IgnoreBlank();
		ADVKATA();
		//printf("ONE CYCLE\n");
		}

		IgnoreBlank();
		//Foodstack
		ADVKATA();
		//first val
		CreateEmptySt(&ST);
		while (!compareKata(CKata, "Hand" )){
			Push(&ST, (CKata.TabKata[0]-'0'));
			IgnoreBlank();
			ADVKATA();
		}

		IgnoreBlank();
		//Hand
		ADVKATA();
		//First val
		CreateEmptySt(&SH);
		while (!compareKata(CKata, "ENDOFFILE#" )){
			Push(&SH, (CKata.TabKata[0]-'0'));
			IgnoreBlank();
			ADVKATA();
		}

	}

void utama(){
    Kata inp;
    srand((unsigned)time(NULL));
    cd = (rand() % (8 - 4)) + 4;
    int i = (rand() % (3 - 1)) + 1;

    CreateEmptyQ(&WaitQueue,30);
    CreateEmptyArr(&Pesan);
    inp.TabKata[0] = '%';
    Length(&inp);
    while (!compareKata(inp,"EXIT")&&Life(play)>0){
        printf("\n  ------------------------------------------------------\n");
        printf("  %-15s Money: %-6d Life: %-6d Time: %-6d\n",Nama(play),Money(play),Life(play),Time(detik));
        Draw(R);
        printf("  > Waiting Cust       \n  ");
        PrintQ(WaitQueue);
        printf("  > Food Stack         \n  ");NamaMakanan(ST);
        printf("  > Order              \n");
        PrintArr(Pesan);
        printf("  > Hand               \n  ");NamaMakanan(SH);
        printf("  --------------------------------------------------------\n");
        NOMAP:
        printf("  Command: ");
        scanf("%s",inp.TabKata);
        Length(&inp);
        if (compareKata(inp,"GD") || compareKata(inp,"GU") || compareKata(inp,"GL") || compareKata(inp,"GR")) UpdatePosition(inp,&R,L,&G);
        else if (compareKata(inp,"ORDER")){
            Order(R, &Pesan, PosisiP);
        }
        else if (compareKata(inp,"PUT")){
            Put(&SH,&ST);
            }
        else if (compareKata(inp,"TAKE")){
          printf("  Direction (L,R,U,D): ");
          scanf("%s",inp.TabKata);
          Length(&inp);
          int ID=-1;
          if((TipeR(R,Absis(PosisiP),Ordinat(PosisiP)-1)=='M')&&compareKata(inp,"L")){
            ID=IsiR(R,Absis(PosisiP),Ordinat(PosisiP)-1);
          }
          else if((TipeR(R,Absis(PosisiP),Ordinat(PosisiP)+1)=='M')&&compareKata(inp,"R")){
            ID=IsiR(R,Absis(PosisiP),Ordinat(PosisiP)+1);
          }
          else if((TipeR(R,Absis(PosisiP)-1,Ordinat(PosisiP))=='M')&&compareKata(inp,"U")){
            ID=IsiR(R,Absis(PosisiP)-1,Ordinat(PosisiP));
          }
          else if((TipeR(R,Absis(PosisiP)+1,Ordinat(PosisiP))=='M')&&compareKata(inp,"D")){
            ID=IsiR(R,Absis(PosisiP)+1,Ordinat(PosisiP));
          }
          if(ID!=-1){
            Take(ID, &SH);
          }
          else{
            printf("Tidak ada meja di arah itu...\n");
            goto NOMAP;
          }
        }
        else if (compareKata(inp,"CH")){
            CreateEmptySt(&SH);
        }
        else if (compareKata(inp,"CT")){
            CreateEmptySt(&ST);
        }
        else if (compareKata(inp,"PLACE")){
            Place(R,&WaitQueue,PosisiP);
        }
        else if (compareKata(inp,"GIVE")){
          int IDH;
          Give(&ST,&Pesan,&R,&IDH);
        }
        else if (compareKata(inp,"RECIPE")){
            PrintTree(P,4);
            goto NOMAP;
        }
        else if (compareKata(inp,"SAVE")){
			printf("Input the desired savedata filename : ");
			scanf("%s",filename);
			WriteSaveFile(filename);
			printf("Data successfully written. Come again, baby.\n");
		}
        else if (compareKata(inp,"LOAD")){
			printf("Input a file name from which the program will collect initial data. (Including '.txt') : ");
			scanf("%s",filename);
			ReadSaveFile(filename);

			printf("Data successfully loaded! Enjoy your time, baby.\n");
		}
        else{
            printf("Input salah bos.\n");
            goto NOMAP;
        }
        Time(detik)++;
        cd--;
        if (cd == 0){
          AddQ(&WaitQueue,orang[i],30);
          srand((unsigned)time(NULL));
           cd = (rand() % (20 - 10)) + 10;
           i = (rand() % (3 - 1)) + 1;
        }
        if(!IsEmptyQ(WaitQueue)){
          KesabaranMinusQ(&WaitQueue,1,&play);
        }
        if(!IsEmptyArr(Pesan)){
          KesabaranMinusArr(&Pesan,1,&play);
        }
        if (Life(play)==0){
            Credit();
            exit(1);
        }
    }
}

int main(){
    int input;

    //TAMPILAN AWAL SAJA
    printf("-----------------------------------------------------------------\n");
    printf("--------ENGI'S---------------------------------------------------\n");
    printf("-------------------KITCHEN---------------------------------------\n");
    printf("-------------------------------EXPANSION-------------------------\n");
    printf("-----------------------------------------------2018--------------\n");
    printf("-----------------------------------------------------------------\n");
    printf("\n");

    //PILIHAN MENU
    printf("--------- Silakan pilih menu permainan di bawah ini :  ----------\n");
    printf(">> 1. New Game\n");
    printf(">> 2. Start Game\n");
    printf(">> 3. Load Game\n");
    printf(">> 4. Exit\n\n");
    printf(">> Input: ");
    scanf("%d", &input);

    MakeBuilding(&L,&G,&R,&IDR);
    Money(play) = 0;
    Life(play) = 3;
    Nama(play).TabKata[0] = ' ';
    START("readtree.txt");
	BuildTree(&P,&idxx);
    CreateEmptySt(&SH);
    CreateEmptySt(&ST);

    while (input!=4){
        if (input==1){
            printf(">>> Nama: ");
            scanf("%s",&Nama(play));
        }
        else if (input==2){
            if (Nama(play).TabKata[0]== ' ') printf("Pilih new game atau load game dahulu\n");
            else{
              Square Sq;
              MakeSquare(&Sq,'P',0,false,0);
              Absis(PosisiP)=1;
              Ordinat(PosisiP)=1;
              EditSquare(&R,Sq,Absis(PosisiP),Ordinat(PosisiP));
                utama();
                Credit();
                exit(1);
            }
        }
        else if (input==3){
            printf("Input a file name from which the program will collect initial data. (Including '.txt') : ");
			scanf("%s",filename);
            ReadSaveFile(filename);
			printf("Data successfully loaded! Enjoy your time, baby.\n");
        }
        else{
            printf("Input salah");
        }
        printf("\n>> Input: ");
        scanf("%d", &input);
    }
    Credit();

    return 0;
}
