#include <stdio.h>
#include <stdlib.h>


int vector_sequecial_search(int wanted_number, int *numbers_vector){

  int i, vector_size = (sizeof(numbers_vector));
  printf("size: %d\n", vector_size);
  numbers_vector[vector_size] = wanted_number;
  for(i=0; numbers_vector[i] != wanted_number; i++);
  if(i < vector_size)
    return i;
  else
    return -1;

}

int main(){
  int vetor[] = {1, 2, 3};
  printf("size: %ld\n", sizeof(vetor));
  int numero = 3;
  int resultado = vector_sequecial_search(numero, vetor);
  if (resultado != -1)
    printf("%d\n",resultado);
  else
    printf("nao deu\n");

  return 0;
}
