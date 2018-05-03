#include "PartC.c"

int main() {
  space_t *board;
  int i, numTimes = 0, boardSize = 0;
  float average = 0.0;
  FILE *fp;
  int winner = 0;
  int moves1 = 0;
  int moves2 = 0;
  int state = 1;
  int go = 0;
  fp = fopen("board.txt", "r");
  board = createBoardSpace(fp);
  LIST head = createnode(board);
  char * playername = (char *)malloc(10);
  strcpy(playername, "PLAYER 1");
  PLAYER one = createplayer(playername);
  strcpy(playername, "PLAYER 2");
  PLAYER two = createplayer(playername);
  while (1) {
    board = createBoardSpace(fp);
    if (board == NULL)
      break;
    LIST f = createnode(board);
    head = insertnode(head,f);
  }
  fclose(fp);
  LIST p = head;
  while(1){
    if(state = 1){
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
        char * color = (char*)(malloc(20));
        char * special = (char*)(malloc (20));
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
              moves1 ++;
              printf("Player one won with %d moves!\n", moves1);
              winner = 1;
              break;
            }
            if(go == x){
              puts("Player 1 on\n");
              toString(current->item);
              placeplayer(one, p);
              moves1 ++;
              go = 0;
              state = 2;
              break;
            }
          }
          else{
            p = p->next;
          }
        }
        if(winner == 1){
          break;
        }
      }
      if(state = 2){
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
          char * color = (char*)(malloc(20));
          char * special = (char*)(malloc (20));
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
                moves2 ++;
                printf("Player two won with %d moves!\n", moves2);
                winner = 1;
                break;
              }
              if(go == x){
                puts("Player 2 on\n");
                toString(current->item);
                placeplayer(two, p);
                moves2 ++;
                go = 0;
                state = 1;
                break;
              }
            }
            else{
              p = p->next;
            }
          }
          if(winner == 1){
            break;
          }
        }
    }
  }
