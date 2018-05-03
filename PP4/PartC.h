#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PartB.c"

typedef struct player {
  LIST space;
  char * name;
} player_t;

typedef player_t * PLAYER;


PLAYER createplayer(char * name);
char * checkname(void * S);
void placeplayer(PLAYER p, LIST s);
