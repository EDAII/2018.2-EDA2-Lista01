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
      mid = min_index + ((wanted_number - numbers_vector[min_index]) * (max_index - min_index)) / (numbers_vector[max_index] - numbers_vector[min_index]);
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
