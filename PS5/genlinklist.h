
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <ctype.h>

typedef struct node{
   void * item;
   struct node * next;
   struct node * prev;
}node_t;

typedef node_t * NODE;

typedef struct linklist{
  node_t *head;
  node_t *tail;
} linklist_t;

typedef linklist_t * LIST;

LIST makelinklist(void);
node_t * createNode(void *item);
void  insertnode(LIST linklist, void * item);
void forwardTraverse(LIST linklist, void (*print)(void *val));
int isEmpty(LIST linklist);
void toString(void * val);
void add(LIST linkedlist, void * item);
