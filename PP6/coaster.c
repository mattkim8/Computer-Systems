/*

Matthew Kim
PP6
4/27/18
Roller Coaster Problem
coaster.c


compile with
gcc -pthread -o coaster coaster.c
run with
./coaster NumberofPassengers CarCapacity

*/



#include "coaster.h"

void takeRide(int* p){
  int x = *p;
  pthread_mutex_lock(&rollerCoaster);
  printf("Passenger %d is on line\n",x);
  while((isWaiting = false) || PassengersInCar == CarCapacity){
    pthread_cond_wait(&carload,&rollerCoaster);
  }
  PassengersInCar ++;
  carcount ++;
  printf("Passenger %d is on car\n",x);
  if(carcount == Passengers){
    pthread_cond_broadcast(&fullcar);
    //This is for when the number of passengers doesn't evenly divide into cars
  }
  if(PassengersInCar == CarCapacity ){
    printf("Car Capacity reached\n");
    pthread_cond_broadcast(&fullcar);
    //Car is full, out of condition block
  }
  pthread_cond_wait(&carunload, &rollerCoaster);
  printf("Passenger %d has left the car.\n", x);
  pthread_mutex_unlock(&rollerCoaster);
  pthread_exit(0);
}

void load(){
  pthread_mutex_lock(&rollerCoaster);
  while(PassengersInCar>0){
    pthread_cond_wait(&carunload, &rollerCoaster);
  }
  isWaiting = true;
  pthread_cond_broadcast(&carload);
  if(carcount == Passengers){
    puts("No More Passengers!");
    pthread_mutex_unlock(&rollerCoaster);
    pthread_exit(0);
  }
  printf("Car is waiting for passengers.\n");
  pthread_cond_wait(&fullcar, &rollerCoaster);
  isWaiting = false;
  printf("Enjoy the Ride!\n" );
  pthread_mutex_unlock(&rollerCoaster);
}

void unload(){
  pthread_mutex_lock(&rollerCoaster);
  puts("Ride is Over!");
  PassengersInCar=0;
  pthread_cond_broadcast(&carunload);
  pthread_mutex_unlock(&rollerCoaster);
}

void carThread(){
  while(true){
    load();
    sleep(1);//sleep for the delay between loading and unloading
    unload();

  }
}
