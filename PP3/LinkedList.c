/*
Matthew Kim
3/1/18
Computer Systems
Professor Signorile
Linked List Struct
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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


int chunknum(char *text){
  int i = strlen(text);
  return (i/80) +1;
}

block * createblocks(int num){
  block* fblock = NULL;
  fblock= malloc(sizeof(block));
  fblock->w = (char*)malloc(80);
  fblock->next = NULL;
  block* sub;
  sub = fblock;
  int bcount = num;
  for(int i=0;i<bcount - 1;i++){
    block* temp = NULL;
    temp= malloc(sizeof(block));
    temp->w = (char*)malloc(80);
    temp->next = NULL;
    pushblock(sub, temp);
  }
  return fblock;
}

void pushblock(block* first, block* next){
  block*temp;
  temp = first;
  while (temp->next != NULL)
    temp = temp->next;
  temp->next = next;
}


void fillblocks(char * text, block * first){
  block* temp;
  temp = first;
  int count = 0;
  int mul = 0;
  while(temp!=NULL){
    while(count<80){
      *(temp->w + count) = *(text + (mul*80) + count);
      count++;
    }
  temp = temp->next;
  count = 0;
  mul++;
  }
}

void printIt(block* first){
  block *temp = first;
  while(temp!=NULL){
    char c;
    int index = 0;
    c = *(temp->w + index);
    printf("chunk:");
    while(c != '\0'){
      printf("%c", c);
      index++;
      c = *(temp->w + index);
    }
    printf("\n");
    temp = temp->next;
  }
}
