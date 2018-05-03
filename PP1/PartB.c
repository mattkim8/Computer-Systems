#include <stdio.h>
#include <stdlib.h>

char * getCharBlock();
void printIt(char *ptr, int index);
int findMatch(char *line);


int main(){
 //pointers for the characters you will read
char *line; //some pointer variables
int n,m,x,y; //some integers
printf("Input : \t");
line = getCharBlock();
//m = getLine(line);
//printf("m: %d\n", m);
x = findMatch(line);
printf("x: %d\n",x);
//printIt(line, x);
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
    c = getchar();
  }
  *(line+size) = '\0';
  return line;
}

//this would fill in the "string" of chars for the passed in char pointer. YOU SHOULD
//place a '\0' character at the end of the "string" (as an end of string sentinel)
//this code MUST use pointer arithmetic

int findMatch(char *line){
  int state = 0;
  int i;
  int result;
  for (i = 0;*(line+i) != '\0'; i++ ){
    if(state != 3){
      if (*(line+i) == 'G'){
        state = 1;
        result = i;
      }
    }
    if(state == 1){
      if(*(line+i) == 'C'){
        state = 2;
      }
    }
    if(state == 2){
      if(*(line+i) == 'A'){
        state = 3;
      }
    }
    if(state == 3){
      if(*(line+i)=='G'){
        return result;
      }
      else{};
    }
  }
  return -1;
}

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
printf("\n");
//this is simple, just remember how pointer arithmetic works
//prints a "string", starting from the pointer "index"
//and any more functions for clarification of work done by the program. Remember,
//by designing and implementing //your code well, you simply need to call the functions
//nicely in main to find multiple locations of the pattern in the //text.
}
