#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "vector.c"
#define CLK_PER_SEC 100000
#define MAX_VALOR 10000
#define NUM_ELEMENTS 100000

//BUSCA SEQUENCIAL COM SENTINELA
int vector_sequecial_search(int wanted_number, int *numbers_vector, int vector_size){

  int i;
  numbers_vector[vector_size] = wanted_number;

  for(i=0; numbers_vector[i] != wanted_number; i++);

  if(i < vector_size)
    return i;
  else
    return -1;
}

void search_case(char *text, int wanted_number, int *vector, int vector_size){
  clock_t start, end;

  start = clock();
  int result = vector_sequecial_search(wanted_number, vector, vector_size);
  end = clock();

  printf("%s\n", text);
  if (result != -1)
    printf("O número desejado está na posição: %d\n", result);
  else
    printf("Número não encontrado\n");
  printf("Tempo de execução da busca: %lfs\n", (double)(end - start)/CLOCKS_PER_SEC);
  printf("------------------\n");
}

int main(){

  int* vector = vector_generator(NUM_ELEMENTS, MAX_VALOR);
  int wanted_number;

  printf("Insira o número desejado: ");
  scanf("%d", &wanted_number);
  printf("------------------\n");

  search_case("Busca do valor inserido pelo usuário", wanted_number, vector, NUM_ELEMENTS);
  search_case("Melhor Caso: valor é o primeiro digito do vetor", vector[0], vector, NUM_ELEMENTS);
  search_case("Pior Caso: valor não está no vetor", -1, vector, NUM_ELEMENTS);
  return 0;
}
