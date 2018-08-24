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


void show_sequential_search_case(char *text, int wanted_number, int *vector, int vector_size)
{
    clock_t start, end;

    start = clock();
    int result = vector_sequential_search(wanted_number, vector, vector_size);
    end = clock();

    printf("%s\n", text);
    if (result != -1)
      printf("O número desejado está na posição: %d\n", result);
    else
      printf("Número não encontrado\n");
    printf("Tempo de execução da busca: %lfs\n", (double)(end - start)/CLOCKS_PER_SEC);
    printf("------------------\n");
}

void make_sequential_search_cases(int wanted_number, int *vector, int vector_size)
{
    system("clear");
    printf("RESULTADOS BUSCA SEQUENCIAL\n");
    printf("------------------\n");
    show_sequential_search_case("Busca do valor inserido pelo usuário", wanted_number, vector, vector_size);
    show_sequential_search_case("Melhor Caso: valor é o primeiro digito do vetor", vector[0], vector, vector_size);
    show_sequential_search_case("Pior Caso: valor não está no vetor", -1, vector, vector_size);
}
