#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.c"

int main(){
  char * input;
  int num;
  printf("Insert Text Here: \n");
  input = getCharBlock();
  num = chunknum(input);
  block * first = createblocks(num);
  fillblocks(input, first);
  printIt(first);
  printf("\n");
  printf("All done!\n");
  free(input);
  free(first);
}
