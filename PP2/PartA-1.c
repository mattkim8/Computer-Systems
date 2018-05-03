/*
Matthew Kim
2/20/18
Computer Systems
Professor Signorile
Advanced Pattern Matching
*/


#include <stdio.h>
#include <stdlib.h>
#include "PartA.h"

int main(){
char * pat;
int x;
char * txt;
pat = getPattern();
txt = getPattern();
x = findMatch(pat,txt);
printIt(txt,0);
printf(" found %d times\n",x);
free(pat);
}


char * getPattern(){
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


//this would fill in the "string" of chars for the passed in char pointer. YOU SHOULD
//place a '\0' character at the end of the "string" (as an end of string sentinel)
//this code MUST use pointer arithmetic

//Part A
int findMatch(char *pat, char *txt){
  int state = 0;
  int patptr;
  int txtptr;
  int matchcount = 0;
  for (patptr = 0;*(pat+patptr) != '\0'; patptr++ ){
    if (state == 0){
      for (txtptr = 0; *(txt + txtptr) != '\0'; txtptr++){
        if(*(txt + txtptr) == *(pat + patptr + txtptr)){
          state = 1;
        }
        else{
          state = 0;
          break;
        }
      }
    }
    if (state == 1){
      matchcount ++;
      state = 0;
      *(pat + patptr) = *(pat + patptr +1);
    }
  }
  return matchcount;

  }

  typedef struct word{
         char * w;
         int frequency;
         int * lineNumers;  //this is a dynamically allocated list of int representing the line numbers
                            //in which the word appears
         int numberOfLines;
         //this is the number of lines in which the word appears (you need this to realloc space for lineNumers
         struct word *next; //points to next word in the linked list
  }word_t;




//looks for a match, returns -1 for failure or an int which is the index to the
//location where the match starts.
//the return values can be used to determine IF a match was found, and where.

void printIt(char *ptr, int index){
  char *a;
  int i;
  a = ptr;
  for(i=index; *(ptr+i) != '\0'; i++){
    printf("%c",*(a+i));
  }
//this is simple, just remember how pointer arithmetic works
//prints a "string", starting from the pointer "index"
//and any more functions for clarification of work done by the program. Remember,
//by designing and implementing //your code well, you simply need to call the functions
//nicely in main to find multiple locations of the pattern in the //text.
}
