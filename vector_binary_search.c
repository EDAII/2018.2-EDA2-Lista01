#include <stdio.h>
#include <stdlib.h>

// BUSCA BINARIA 
int do_vector_binary_search(int wanted_number, int vector[], int max_index, int min_index )
{
      // Retorno para melhor scenario onde o vetor possui somente um elemento
      if (min_index > max_index)
      {
        return -1;
      }
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
