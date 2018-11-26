//Driver untuk array.c
#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "array.c"
#include "map.h"
#include "mesinkata.h"

int main(){
  //KAMUS
  TabInt T;
  int i,X;
  //ALGORITMA
  CreateEmptyArr(&T);
  for(i = GetFirstIdx(T); i <= GetLastIdx(T); i++){
    scanf("%d\n",&X);
    Makanan(T,i) = X;
  }
  PrintArr(T);
  scanf("%d",&i);
  DelEli(&T,i);
  return 0;
}
