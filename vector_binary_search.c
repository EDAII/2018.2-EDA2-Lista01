#include <stdio.h>
#include <stdlib.h>

// BUSCA BINARIA
int do_vector_binary_search(int wanted_number, int vector[], int max_index, int min_index )
{
      // teste para parametro errado
      if (min_index > max_index)
      {
        return -1;
      }
      // Retorno para scenario onde o vetor possui somente um elemento
     if(min_index == max_index)
     {
        if(vector[min_index] == wanted_number)
            return min_index;
         else
            return -1;
     }
     else
     {
         int mid_index = (min_index + max_index) / 2;
         if (vector[mid_index] > wanted_number)
         {
              return do_vector_binary_search(wanted_number, vector, mid_index - 1, min_index);
         }
         else if (vector[mid_index] < wanted_number)
         {
              return do_vector_binary_search(wanted_number, vector, max_index, mid_index + 1);
         }
         else
         {
              return mid_index;
         }
    }
}



int vector_binary_search(int wanted_number, int *numbers_vector, int vector_size)
{
    return do_vector_binary_search(wanted_number, numbers_vector, vector_size, 0);
}



void show_binary_search_case(char *text, int wanted_number, int *vector, int vector_size)
{
    clock_t start, end;

    start = clock();
    int result = vector_binary_search(wanted_number, vector, vector_size);
    end = clock();

    printf("%s\n", text);
    if (result != -1)
      printf("O número desejado está na posição: %d\n", result);
    else
      printf("Número não encontrado\n");
    printf("Tempo de execução da busca: %lfs\n", (double)(end - start)/CLOCKS_PER_SEC);
    printf("------------------\n");
}

void make_binary_search_cases(int wanted_number, int *vector, int vector_size)
{
    system("clear");

    // Caso de busca por valor inserido pelo usuario

    show_binary_search_case("Busca do valor inserido pelo usuário", wanted_number, vector, vector_size);

    // No melhor caso o elemento buscado estara no meio do vector

    int mid =  vector[(vector_size/2)];
    show_binary_search_case("Melhor Caso: valor é o primeiro digito do vetor", mid, vector, vector_size);

    // Pior caso é quando o elemento não esta presente no vetor e é menor que todos seus elementos

    show_binary_search_case("Pior Caso: valor não está no vetor", -1, vector, vector_size);
}
