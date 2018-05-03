#include "PartC.h"
#include <assert.h>


char * checkname(void * S){
  PLAYER s;
  s = (PLAYER) S;
  return s->name;
}

PLAYER createplayer(char * name){
  PLAYER p;
  p = (PLAYER)malloc(sizeof(student_t));
  p->name = (char *)malloc(sizeof(strlen(name)+1));
  strcpy(p->name,name);
  p->space = NULL;
  return p;
}

void placeplayer(PLAYER p, LIST s){
  p->space = s;
}
