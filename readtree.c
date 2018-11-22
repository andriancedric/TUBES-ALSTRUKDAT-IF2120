#include "bintree.h"
#include "mesinkar.h"

int main(){
	BinTree P;
	START("readtree.txt");
	BuildTree(&P);
	printf("\nprint treee\n");
	PrintTree(P,4);
}