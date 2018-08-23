#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "utils.c"
#include "vector_generator.c"
#include "vector_binary_search.c"
#include "vector_sequential_search.c"
#include "vector_interpolation_search.c"
#define CLK_PER_SEC 100000
#define MAX_VALOR 10000
#define NUM_ELEMENTS 100000

void show_menu(){
    system("clear");
    printf("------------------\n");
    printf("SELECIONE UMA OPÇÃO \n");
    printf("1 - BUSCA SEQUENCIAL \n");
    printf("2 - BUSCA BINARIA \n");
    printf("3 - BUSCA POR INTERPOLACAO \n");
    printf("0 - SAIR \n");
    printf("------------------\n");

}

int* set_vector(int search_option){
    int * vector;
    system("clear");

    if(search_option == 1)
    {
      int vector_option = 0;
      while(vector_option != 1 && vector_option != 2)
      {
        printf("Deseja buscar em um vetor ordenado?\n 1 - SIM \n 2 - NAO\n" );
        clean_stdin();
        scanf("%d", &vector_option);
        if (vector_option == 1)
        {
          return vector = oriented_vector_generator(NUM_ELEMENTS, MAX_VALOR);
        }
        else if (vector_option == 2)
        {
          return vector = aleatory_vector_generator(NUM_ELEMENTS, MAX_VALOR);
        }
        else
        {
          printf("Opção invalida !!\n" );
        }
      }
    }
}

void run_search_choice(int search_option, int wanted_number, int *vector)
{
    make_sequential_search_cases(wanted_number, vector, NUM_ELEMENTS);
}

int main(){
    int wanted_number, search_option=-1;
    while(search_option != 1 && search_option != 2 && search_option != 3){
      system("clear");
      show_menu();
      scanf("%d", &search_option);
    }
    if (search_option == 0) {
      return 0;
    }

    int *vector = set_vector(search_option);
    printf("Insira o número desejado: ");
    clean_stdin();
    scanf("%d", &wanted_number);
    printf("------------------\n");

    run_search_choice( search_option, wanted_number, vector );
    return 0;
}
