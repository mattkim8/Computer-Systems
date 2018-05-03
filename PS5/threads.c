/*
Matthew Kim
4/7/18
Computer Systems
Professor Signorile
Threading
compile with gcc -pthread -o threads threads.c
*/



#include "threads.h"


int main(int argc, char *argv[]){
  num = atoi(argv[1]);
  pthread_t threads[num];
  int x,i = 0;
  createlist();
  for (i= 0; i<num; i++){
    SENS sens= newsensor(rand()%100+1,i);
    if (pthread_create(&(threads[i]),NULL, (void *) calcsens,sens)){
      perror("thread created");
      exit(1);
    }
  }
  for (i = 0; i < num; i++){
	   pthread_join(threads[i], NULL);
   }
  free(senslist);
}
void createlist(){
  pthread_mutex_init(&listSens,NULL);
  senslist = (LIST) malloc(sizeof(linklist_t));
  count = 0;
  cycle = 0;
}


SENS newsensor(int temp, int id){
  sensor_t *sens = (sensor_t*)malloc(sizeof(sensor_t));
  sens->temp = temp;
  sens->id = id;
  return sens;
}

void calcsens(sensor_t * sensor){
  printf("Sensor on %d\n",sensor->id);
  double avg;
  for(int i = 0; i<10;i++){
    pthread_mutex_lock(&listSens);
    getTemp(sensor);
    count ++;
    sleep(1);

    if (count == num){
      puts("hi");
      cycle++;
      count = 0;
      printf("\nCycle:%d\n", cycle);
      printf("Temps: \n");
      forwardTraverse(senslist,toString);
      puts("hi2");
      avg = getAvg(senslist);
      printf("Average temp: %f\n", avg);
      senslist->head = NULL;
      senslist->tail = NULL;
    }
    pthread_mutex_unlock(&listSens);

  }
  pthread_exit(NULL);

}
void getTemp(sensor_t * sensor){
  int * temp = (int *)malloc(sizeof(int));
  * temp = rand()%100+1;
  add(senslist,temp);
  printf("Sensor id: %d Sensor temp: %d\n",sensor->id, *temp);
}

double getAvg(LIST linkedlist){
  int x = 0;
  double sum = 0;
  NODE current = linkedlist->head;
  while(current != NULL){
    int * temp = (int *)current ->item;
    sum = sum+ (double)* temp;
    current = current->next;
    x++;
  }
  return sum/(double)num;
}
