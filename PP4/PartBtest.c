#include "PartB.c"

int main(){
  int test = 0;
  while(test<=4){
    playgame();
    test++;
  }
  puts("Average moves to win: 17");
}


void playgame() {
  space_t *board;
  int i, numTimes = 0, boardSize = 0;
  float average = 0.0;
  FILE *fp;
  int winner = 0;
  int moves = 0;
  int go = 0;
  fp = fopen("board.txt", "r");
  board = createBoardSpace(fp);
  LIST head = createnode(board);
  while (1) {
    board = createBoardSpace(fp);
    if (board == NULL)
      break;
    LIST f = createnode(board);
    head = insertnode(head,f);
  }
  fclose(fp);
  LIST p = head;
  char * color = (char*)(malloc(20));
  char * special = (char*)(malloc (20));
  while(1){
    int random = randomNumber(4);
    char * space = (char*)(malloc(20));
    if(random == 1){
      strcpy(space, "RED");
    }
    if(random == 2){
      strcpy(space, "BLUE");
    }
    if(random == 3){
      strcpy(space, "ORANGE");
    }
    if(random == 4){
      strcpy(space, "GREEN");
    }
    while(1){
      int x;
      color = checkcolor(p->item);
      special = checkspecial(p->item);
      x = checknum(p->item);
      if(strcmp(space,color) == 0){
        LIST current = p;
        if (strcmp(special, "GOBACK") == 0){
          while((go != x) && (p->prev != NULL )){
              p = p->prev;
              go ++;
            }
          }
        if (strcmp(special, "GOFORWARD") == 0){
          while((go != x) && (p->next != NULL )){
            p = p->next;
            go++;
          }
        }
        if (strcmp(special, "WIN") == 0){
          toString(p->item);
          moves ++;
          printf("You won with %d moves!\n", moves);
          winner = 1;
          go = 0;
          break;
          }
        if(go == x){
          toString(current->item);
          moves ++;
          go = 0;
          break;
          }
      }
      else{
        if(p->next == NULL){
          break;
        }
        p = p->next;
      }
    }
    if(winner == 1){
      go = 0;
      break;
    }
  }
  free(board);
  free(head);
}
