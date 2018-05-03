#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PartB.h"

int main(){
  char * input;
  int check;
  int index = 0;
  char * line;
  word_t *root = (word_t *)malloc(sizeof(word_t));
  root = NULL;
  while(1){
   printf("Enter a new line or type stop: \t");
   input = getPattern();
   check = isStop(input);
   if(check == 1){
     break;
   }
   line = (char*)malloc(80);
   for(index = 0; *(input + index) != ' '; index++){
     *(line + index) = *(input + index);
   }
   root = freq(line, root);
   free(line);
 }
   mostfrequent(root);
}



char * getPattern() {
  char * line;
  char c;
  int size = 0;
  c = getchar();
  int x;
  line = (char *)malloc(80);
  while(c != '\n'){
    *(line+size)  = c;
    size ++;
    line = (char*)realloc(line, size + 1);
    x = isStop(line);
    if(x == 1){
      *(line+size) = '\0';
      return line;
    }
    c = getchar();
  }
  return line;
}


word_t* freq(char * text, word_t* root) {
  word_t *temp = NULL;
  word_t *last = NULL;
  if(root == NULL){
    puts("hi3");
    root = newword(text);
    return root;
  }
  temp = root;
  puts("hi2");
  while(temp != NULL){
    puts("hi3");
    if(strcmp(text, temp->w) == 0){
      puts("hi");
      temp->frequency++;
      return root;
    }
    temp = temp->next;
  }
  last = newword(text);
  temp->next = last;
  return temp;
}

word_t* newword(char * text) {
  word_t* wrd = NULL;
  wrd= malloc(sizeof(word_t));
  wrd->w = (char*)malloc(strlen(text)+1);
  strcpy(wrd->w, text);
  wrd->frequency = 1;
  wrd->next = NULL;
  return wrd;
  }


int isStop(char *line) {
  int state = 0;
  int i;
  int result;
  for (i = 0;*(line+i) != '\0'; i++ ){
    if(state != 3){
      if (*(line+i) == 'S'){
        state = 1;
        result = i;
      }
    }
    if(state == 1){
      if(*(line+i) == 'T'){
        state = 2;
      }
    }
    if(state == 2){
      if(*(line+i) == 'O'){
        state = 3;
      }
    }
    if(state == 3){
      if(*(line+i)=='P'){
        return 1;
      }
      else{};
    }
  }
  return -1;
}

void mostfrequent(word_t *root){
  word_t * temp = (word_t *)malloc(sizeof(word_t));
  temp = root;
  int count = 0;
  while(temp != NULL){
    if(temp->frequency >= count){
      count = temp->frequency;
    }
    temp = temp->next;
  }
  temp = root;
  printf("The words and their lines are: \n");
  while(temp != NULL){
    if(temp->frequency == count){
      char c;
      int index = 0;
      c = *(temp->w + index);
      printf("\"");
      while(c != '\0'){
        printf("%c", c);
        index++;
        c = *(temp->w + index);
      }
      int l = temp->frequency;
      printf("\":");
      printf("%d",l );
      printf("\n");
    }
    temp = temp->next;
  }

}
