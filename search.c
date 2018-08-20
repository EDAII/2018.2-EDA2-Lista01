#include <stdio.h>

int vector_sequecial_search(int wanted_number, int numbers_vector[]){

  int i, vector_size = (sizeof(numbers_vector)/4);

  numbers_vector[vector_size] = wanted_number;
  for(i=0; numbers_vector[i] != wanted_number; i++);
  if(i < vector_size)
    return i;
  else
    return -1;
}
