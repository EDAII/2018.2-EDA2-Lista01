#include <time.h>
#include <stdlib.h>

int *vector_generator(int vector_size, int max_value){
  int *vector = malloc(sizeof(int) * vector_size);
  srand(time(NULL));
  for(int i=0; i<vector_size; i++){
    vector[i] = rand() % max_value;
  }

  return vector;
}
