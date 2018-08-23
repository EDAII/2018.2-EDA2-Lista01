#include <stdio.h>

//BUSCA SEQUENCIAL COM SENTINELA
int vector_sequential_search(int wanted_number, int *numbers_vector, int vector_size)
{
    int i;
    numbers_vector[vector_size] = wanted_number;

    for(i=0; numbers_vector[i] != wanted_number; i++);

    if(i < vector_size)
      return i;
    else
      return -1;
}
