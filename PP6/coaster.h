/*

Matthew Kim
PP6
4/27/18
Roller Coaster Problem
coaster.h




*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdbool.h>
#include <unistd.h>

int CarCapacity, Passengers,carcount,state;
int PassengersInCar;
bool isWaiting = false;
pthread_cond_t carunload;
pthread_cond_t carload;
pthread_cond_t fullcar;
pthread_cond_t carfirst;
pthread_mutex_t rollerCoaster;

void takeRide(int* x);
void load();
void unload();
void carThread();

int main(int argc, char *argv[]){

  if (argc != 3){
      puts("Please enter (Number of Passengers) and (Car Capacity).\n");
      exit(0);
  } else {
    Passengers = atoi(argv[1]);
    CarCapacity = atoi(argv[2]);
  }
  PassengersInCar = 0;
  pthread_t rider[Passengers];

  printf("Number of passengers: %d\n", Passengers);
  printf("Capacity of cars: %d\n", CarCapacity);

  carcount = 0;
  state = 0;

  pthread_mutex_init(&rollerCoaster, NULL);
  pthread_cond_init(&carload, NULL);
  pthread_cond_init(&carunload, NULL);
  pthread_cond_init(&fullcar, NULL);
  pthread_cond_init(&carfirst,NULL);

  pthread_t Car;
  pthread_create(&Car,NULL,(void*) carThread,NULL);

  sleep(1);

  for (int i = 1; i != Passengers+1; i++){
    int *x;
    x = (int *)malloc(sizeof(int));
    *x = i;
    pthread_create(&(rider[i]),NULL, (void *) takeRide, x);
  }
  pthread_join(Car, NULL);

  for (int i = 0; i < Passengers; i++){
    pthread_join(rider[Passengers],NULL);
  }
return 0;

}
