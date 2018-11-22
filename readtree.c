#include "bintree.h"
#include "mesinkar.h"

int main(){
	int idx = 1;
	BinTree P;
	START("readtree.txt");
	BuildTree(&P,&idx);
	printf("\nprint treee\n");
	PrintTree(P,4);
}