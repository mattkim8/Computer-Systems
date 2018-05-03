#include "genlinklist.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

typedef struct sensor{
  int id;
  int temp;
}sensor_t;

typedef sensor_t * SENS;

pthread_mutex_t listSens;
LIST senslist;


int count,cycle;
int num;
void createlist();
SENS newsensor(int temp, int id);
void calcsens(sensor_t * sensor);
void getTemp(sensor_t * sensor);
double getAvg(LIST linkedlist);
void freeList(LIST linklist);
