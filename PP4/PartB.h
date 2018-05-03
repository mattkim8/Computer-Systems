#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PartA.c"

typedef struct space {
  char *color;
  char *special;
  int x;
} space_t;

typedef space_t * SPACE;

space_t *createBoardSpace(FILE *myFile);
void toString(space_t *b);
int randomNumber(int upperBound);
char * checkcolor(void * S);
char * checkspecial(void * S);
int checknum(void * S);
void playgame() ;
