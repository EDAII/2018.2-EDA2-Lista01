#include <stdio.h>
#include <stdlib.h>

// BUSCA POR INTERPOLAÇÃO
int vector_interpolation_search(int wanted_number, int *numbers_vector, int vector_size)
{
    int min_index = 0;
    int max_index = vector_size -1;
    int mid;

    while(numbers_vector[min_index] <= wanted_number && numbers_vector[max_index] <= wanted_number )
    {
      if (numbers_vector[max_index] - numbers_vector[min_index] == 0)
      {
        return (min_index + max_index)/2;
      }
      printf("%d\n", mid);
      mid = min_index + ((max_index - min_index)/(numbers_vector[max_index] - numbers_vector[min_index])) * (wanted_number - numbers_vector[min_index]);
      if (numbers_vector[mid] < wanted_number)
      {
        min_index = mid + 1;
      }
      else if (numbers_vector[mid] > wanted_number)
      {
        max_index = mid -1;
      }
      else
        return mid;
    }
    if (numbers_vector[min_index] == wanted_number)
     {
      return min_index;
    }
    else
    {
      return -1;
    }
}


void show_interpolation_search_case(char *text, int wanted_number, int *vector, int vector_size)
{
    clock_t start, end;

    start = clock();
    int result = vector_interpolation_search(wanted_number, vector, vector_size);
    end = clock();

    printf("%s\n", text);
    if (result != -1)
      printf("O número desejado está na posição: %d\n", result);
    else
      printf("Número não encontrado\n");
    printf("Tempo de execução da busca: %lfs\n", (double)(end - start)/CLOCKS_PER_SEC);
    printf("------------------\n");
}

void make_interpolation_search_cases(int wanted_number, int *vector, int vector_size)
{
    system("clear");
    printf("RESULTADOS BUSCA POR INTERPOLACAO\n");
    printf("------------------\n");
    // Caso de busca por valor inserido pelo usuario

    show_binary_search_case("Busca do valor inserido pelo usuário", wanted_number, vector, vector_size);

    // No melhor caso o elemento buscado estara no meio do vector

    int mid =  vector[(vector_size/2)];
    show_binary_search_case("Melhor Caso: valor é o elmento do meio do vetor", mid, vector, vector_size);

    // Pior caso é quando o elemento não esta presente no vetor e é menor que todos seus elementos

    show_binary_search_case("Pior Caso: valor não está no vetor", 9999999, vector, vector_size);
}
