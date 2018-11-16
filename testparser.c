#include "mesinkar.h"
#include "mesinkata.h"
//#include "KamusVariabel.h"
#include <stdio.h>

/*
PLAYER player;
JAM time;
POINT location;
MATRIKS map; 
Queue queue;
TabInt list;
StackTray fstack;
StackHand hstack;*/

//ReadSaveFile("saveData.txt",player,time,location,map,queue,list,fstack,hstack);
int main(){

	ReadSaveFile("saveData.txt");
	WriteSaveFile("writefile2.txt");
	return 0;
	}