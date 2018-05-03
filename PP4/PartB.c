#include "PartB.h"
#include <assert.h>

space_t *createBoardSpace(FILE *myFile) {
  char *color;
  char *special;
  char dummy;
  int tempint;
  space_t *board;

  board = (space_t *)malloc(sizeof(space_t));
  board->color = (char *)malloc(sizeof(char) * 10);
  board->special = (char *)malloc(sizeof(char) * 10);

  fscanf(myFile,"%s%s%d%c", board->color, board->special, &tempint, &dummy);
  if (feof(myFile)){
    return NULL;
  }
  board->x = tempint;
  return board;
}

void toString(space_t *b){
  printf("the board space: %s %s %d\n",b->color, b->special, b->x);
}

char * checkcolor(void * S){
  SPACE s;
  s = (SPACE) S;
  return s->color;
}

char * checkspecial(void * S){
  SPACE s;
  s = (SPACE) S;
  return s->special;
}

int checknum(void * S){
  SPACE s;
  s = (SPACE) S;
  return s->x;
}

int randomNumber(int upperBound){
//this is the simple rn generator that generates a random number between 1 and upperBound
    int j;
    j=1+(rand() % upperBound);
    return j;
}
