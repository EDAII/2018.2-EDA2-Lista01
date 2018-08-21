#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define CLK_PER_SEC 100000
#define MAX_VALOR 10000
#define NUM_ELEMENTS 100000

int vector_sequecial_search(int wanted_number, int *numbers_vector, int vector_size){
  int i;
  numbers_vector[vector_size] = wanted_number;
  for(i=0; numbers_vector[i] != wanted_number; i++);
  if(i < vector_size)
    return i;
  else
    return -1;
}

int *vector_generator(int number_elements){
  int i;
  int *vector = malloc(sizeof(int) * NUM_ELEMENTS);
  srand(time(NULL));
  for(i=0; i < number_elements; i++){
     // vector[i] = rand()%5;
     // printf("%d\n", vector[i]);
     vector[i] = i+1;
  }
  return vector;
}

int main(){
  char * timer_display;

  int* vector = vector_generator(NUM_ELEMENTS);

  int wanted_number = 5;

  // clock_t time_begin = (clock()/CLK_PER_SEC);
  int result = vector_sequecial_search(wanted_number, vector, NUM_ELEMENTS);
  // clock_t time_end = (clock()/CLK_PER_SEC);


  if (result != -1)
    printf("esta na posição : %d\n tempo de execução : %lf \n", result, (double)(time_end - time_begin));
  else
    printf("nao deu\n");

  return 0;
}
