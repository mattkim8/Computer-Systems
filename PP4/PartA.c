/*
Matthew Kim
3/26/18
Computer Systems
Professor Signorile
Candy Land!
Part A - Generic double linked list
Part B - Candy Land single player
Part C - Candy Land 2 players
*/


#include "PartA.h"
#include <assert.h>

//int main(){
//  char * input;
//  int id = 0;
//  int count = 0;
//  input = getCharBlock();
//  STUDENT s = createstudent(input,id);
//  LIST head = createnode(s);
//  for(int count = 0; count < 5; count++){
//    id ++;
//    input = getCharBlock();
//    STUDENT d = createstudent(input,id);
//    LIST f = createnode(d);
//    head = insertnode(head,f);
//  }
//  fortrans(head,printIt);
//  backtrans(head,printIt);
//  deletenode(head);
//  fortrans(head,printIt);
//  seldel(head,2);
//  fortrans(head,printIt);
//  free(head);
//}

LIST createnode(void *item){
  LIST p;
  p = (LIST) malloc(sizeof(node_t));
  p->item = item;
  p->next = NULL;
  p->prev = NULL;
  return p;
}

STUDENT createstudent(char * word, int x){
  STUDENT p;
  p = (STUDENT)malloc(sizeof(student_t));
  p->id = x;
//  p->name = (char *)malloc(sizeof(strlen(word)+1));
  strcpy(p->name,word);
  return p;
}

//void fortrans(LIST head){
//  LIST p;
//  p = (LIST) head;
//  if (p==NULL){
//    puts("NO LINKED LIST");
//    return;
//  }
//  while(p->next != NULL){
//    puts(s->toString(p->item));
//  }
//}

void fortrans(LIST m, void (*printFunction)(void * A)){
  LIST temp;
  int cnt=0;
  temp = m;
  if (temp==NULL){
    puts("NO LINKED LIST");
    return;
  }
  printf("node values are:\n");
  while (temp != NULL){
    printFunction(temp->item);
    temp=temp->next;
    cnt++;
  }
}

void backtrans(LIST m, void (*printFunction)(void * A)){
  LIST temp;
  int cnt=0;
  temp = m;
  if (temp==NULL){
    puts("NO LINKED LIST");
    return;
  }
  printf("node values are:\n");
  while(temp->next !=NULL){
    temp = temp->next;
  }
  while (temp != NULL){
    printFunction(temp->item);
    temp=temp->prev;
    cnt++;
  }
}

LIST insertnode(LIST head, LIST m){
  LIST p;
  if (head==NULL){
    return m;
  }
  p = head;
  while(p->next != NULL){
    p = p->next;
  }
  p->next = m;
  m->prev = p;
  return head;
}

void deletenode(LIST m){
  LIST p;
  if (m==NULL){
    puts("No Node to delete!");
    return;
  }
  p = m;
  while(p->next != NULL){
    p = p->next;
  }
  p = p->prev;
  p->next = NULL;
  puts("Node deleted");
  return;
}

void seldel(LIST m, int x){
  LIST p;
  if (m==NULL){
    puts("No Node to delete!");
    return;
  }
  p = m;
  int count = 1;
  while (p->next != NULL){
    if(count == x){
      p->next = p->next->next;
      p->next->prev = p;
      return;
    }
    p = p->next;
    count ++;
  }
  puts("Node with that id not found!");
  return;
}

void printIt(void * S){
  STUDENT s;
  s = (STUDENT) S;
  puts(s->name);
}

char * getCharBlock(){
  char * line;
  char c;
  int size = 0;
  c = getchar();
  line = (char *)malloc(80);
  while(c != '\n'){
    *(line+size)  = c;
    size ++;
    line = (char*)realloc(line, size + 1);
    c = getchar();
  }
  *(line+size) = '\0';
  return line;
}
