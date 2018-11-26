#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* State Mesin Kata */
boolean EndKata;
Kata CKata;

void IgnoreBlank(){
    while ((CC== BLANK || CC == '\n' || CC == ';' || CC == ',' || CC !='(' || CC != ')') && CC != MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC ≠ BLANK atau CC = MARK */

void STARTKATA(char* filename){
    START(filename);
    IgnoreBlank();
    if (CC == MARK)
        EndKata = true;
    else{
        EndKata = false;
        SalinKata();
    }
}
/* I.S. : CC sembarang
   F.S. : EndKata = true, dan CC = MARK;
          atau EndKata = false, CKata adalah kata yang sudah diakuisisi,
          CC karakter pertama sesudah karakter terakhir kata */

void ADVKATA(){
    IgnoreBlank();
    if (CC == MARK){
        EndKata = true;}
    else{
        SalinKata();
        IgnoreBlank();
    }
}

/* I.S. : CC adalah karakter pertama kata yang akan diakuisisi
   F.S. : CKata adalah kata terakhir yang sudah diakuisisi,
          CC adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika CC = MARK, EndKata = true.
   Proses : Akuisisi kata menggunakan procedure SalinKata */
void SalinKata(){
    int i;
    //printf("SalinKata entered! \n");
    i =0;
    for(;;){
        CKata.TabKata[i] = CC;
        //printf("%c", CC);
        ADV();
        if ( CC== MARK || CC == ':' || CC == ';'  || CC == '\n' || CC == ',' ){
            break;
        }
        else
            i ++;

    }
    //printKata(CKata);
    //printf("\nCC done \n");
    CKata.Length = i;
/*
    int i;
    i=1;
    while ((CC!=MARK) && ((CC!= BLANK)&&(CC!= '\n'))){
        CKata.TabKata[i] = CC;
        ADV();
        i++;
    }*/
}

void Length(Kata *kata){
    int i;
    for(i = 0; kata->TabKata[i] != '\0'; ++i);
    kata->Length = i;
}

boolean compareKata(Kata kata1, char* teks){
	for(int i = 0; i<=kata1.Length ; i++){
		if (kata1.TabKata[i] != teks[i])
			return false;
	}
	return true;
}

void printKata(Kata kata1){
	for(int i = 0; i<kata1.Length ; i++){
		printf("%c", kata1.TabKata[i]);
	}
	printf("\n");
}

void printID(Kata kata1){
	printf("%d", kata1.ID);

	//printf("\n");
}

void writefromMatriks(FILE* f, List L ){
	address P = First(L);
	While (P != Nil){
		R = Room(P);
		for(int i=1; i<=8; i++) {
			for(int j=1; j<=8; j++)
			    fprintf(f,"%c", TipeR(R,I,J);
			fprintf(f,";\n");
			}
		P = Next(L);
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
	for(int i = 1; i<neff ; i++){
		if(Makanan(T,i) != ValUndef){
			fprintf(f,"%d", Makanan(T,i));
			fprintf(f,",");
			fprintf(f,"%d;\n", i);
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
	while (Top(Sout) != 0){
		Pop(&Sout, &ID);
		fprintf(f,"%d", ID);
	}
	fprintf(f,";\n");
}

/*void writeGraph(FILE* f, Graph G, List L){
	P = First(L);
	int roomcount=0;
	While (P != Nil){
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
	
	address P= First(L);
	int idx=1;
	While (P != Nil){
		Room R = Room(P);
		fprintf(f,"//ROOM ", idx); fprintf("\n");
		for(int i=1; i<=8; i++) {
			for(int j=i; j<=8; j++){
				if(Tipe(SquareXY(R,i,j) == 'P')
					 fprintf(f,"%d,%d;\n",i,j );
				}
		}
		idx ++;
}

void WriteSaveFile(char* filename ,PLAYER player, JAM time, POINT location, List L, Queue WaitQ, TabInt Pesan, StackTray ST, StackHand SH ){
	FILE *f = fopen(filename, "w");
	if (f == NULL)
	{
	    printf("Creating New File!\n");
	    FILE *fp = fopen("filname", "ab+");
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
	fprintf(f,"PlayerName      :       %s;\n",player.name);
	fprintf(f,"Money           :       %s;\n",player.money);
	fprintf(f,"Life            :       %s;\n",player.life);
	fprintf(f,"Time            :       %s;\n",time.SS);
	fprintf(f,"CurrentRoom     :       %s;\n",location.ID);
	fprintf(f,"X               :       %s;\n",location.X);
	fprintf(f,"Y               :       %s;\n",location.Y;
	fprintf(f,"\n");
	fprintf(f,"//Map\n");
	fprintf(f,"\n");
	writeOccupiedSeats(f,R);
	fprintf(f,"\n");
	fprintf(f,"//Graph\n");
	fprintf(f,"\n");
	writeGraph(f,G,L);
	fprintf(f,"//Details\n");
	fprintf(f,"\n");
	fprintf(f,"Waiting Cust\n");
	fprintf(f,"    ");writefromArray(f,WaitQ);fprintf(f,"\n");
	fprintf(f,"Order\n");
	fprintf(f,"    ");writefromTabint(f,Pesan);
	fprintf(f,"Food Stack\n");
	fprintf(f,"    ");writefromStack(f,ST);
	fprintf(f,"Hand\n");
	fprintf(f,"    ");

	fprintf(f,"ENDOFFILE#");
	fclose(f);
}

void ReadSaveFile(char* filename ,PLAYER* player, JAM* time, POINT* location, List L, Queue* Q, TabInt* Pesan, Stack *ST, Stack *SH ){
	STARTKATA(filename);
	IgnoreBlank();
	// Now position at the first Identity entry.

	//IDENTITY PARSER
	
	//printf("0. %s\n", CKata);
	while (!(compareKata(CKata, "//Map")) ){
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
			player.name = CKata;
			}
		else if (compareKata(CKata, "Money           " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			player.money = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "Life            " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			player.life = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "Time            " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			time.SS = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "CurrentRoom     ")){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			location.ID = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "X               " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			location.X = atoi(CKata.TabKata);
			}
		else if (compareKata(CKata, "Y               " )){
			ADV();
			IgnoreBlank();
			ADVKATA();
			//printKata(CKata);
			location.Y = atoi(CKata.TabKata);
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

		Room R = First(*L);
		while(!compareKata(CKata, "//ROOM 2")){
			i = CKata.TabKata[0]-'0';
			IgnoreBlank();
			ADVKATA();
			j = CKata.TabKata[0]-'0';
			IgnoreBlank();
			SquareXY(R,i,j).occupied = true;
			Tipe(SquareXY(R,i,j)) = 'P';
			ADVKATA();
			}

		Room R = Next(R);
		while(!compareKata(CKata, "//ROOM 3")){
			i = CKata.TabKata[0]-'0';
			IgnoreBlank();
			ADVKATA();
			j = CKata.TabKata[0]-'0';
			IgnoreBlank();
			SquareXY(R,i,j).occupied = true;
			Tipe(SquareXY(R,i,j)) = 'P';
			ADVKATA();
			}

		Room R = Next(R);
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
			JumlahOrang(*Q,i) = (CKata.TabKata[0]-'0');
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
		Pesan[i] = CKata.TabKata[0]-'0';
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
			Push(&ST, (CKata.TabKata[0]-'0');
			IgnoreBlank();
			ADVKATA();
		}

		IgnoreBlank();
		//Hand
		ADVKATA();
		//First val
		CreateEmptySt(&SH);
		while (!compareK8ata(CKata, "ENDOFFILE#" )){
			Push(&SH, (CKata.TabKata[0]-'0');
			IgnoreBlank();
			ADVKATA();
		}

	}
	//MAP PARSER -END-

/* Mengakuisisi kata, menyimpan dalam CKata
   I.S. : CC adalah karakter pertama dari kata
   F.S. : CKata berisi kata yang sudah diakuisisi;
          CC = BLANK atau CC = MARK;
          CC adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */
