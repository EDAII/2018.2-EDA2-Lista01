#include <time.h>
#include <stdlib.h>

// Gerador de vetor de inteiros não ordenado com elementos não ordenados
int *aleatory_vector_generator(int vector_size, int max_value){

  int *vector = malloc(sizeof(int) * vector_size);

  srand(time(NULL));
  for(int i=0; i<vector_size; i++){
    vector[i] = rand() % max_value;
  }

  return vector;
}

// Gerador de vetor de inteiros com elementos ordenados
int *oriented_vector_generator(int vector_size, int max_value){

  int *vector = malloc(sizeof(int) * vector_size);

  srand(time(NULL));
  for(int i=0; i<vector_size; i++){
    vector[i] = i+1;
  }

  return vector;
}
