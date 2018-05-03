#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node{
   void * item;
   struct node * next;
   struct node * prev;
}node_t;

typedef node_t * LIST;

typedef struct student {
   int id;
   char name[20];
}student_t;

typedef student_t * STUDENT;

LIST createnode(void *item);
STUDENT createstudent(char * word, int x);
void fortrans(LIST m, void (*printFunction)(void * A));
void backtrans(LIST m, void (*printFunction)(void * A));
LIST insertnode(LIST head, LIST m);
void deletenode(LIST m);
void seldel(LIST m, int x);
char * getCharBlock();
void printIt(void * S);
