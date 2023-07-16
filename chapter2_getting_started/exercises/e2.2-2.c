#include <stdlib.h>
#include <stdio.h>

#define SIZE 5
void selectionsort(int arr[], int size);

int main() {
  int arr[SIZE] = {1, 2, 3, 4, 5};
  
  selectionsort(arr, SIZE);

  for (int i = 0; i < SIZE; i++) printf("%d ", arr[i]);

  printf("\n");

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionsort(int arr[], int size) {
  int min_index;
  int *lowest;

  for (int i = 0; i < size - 1; i++) {
    min_index = i;

    lowest = &arr[min_index];

    for (int j = min_index; j < size; j++) {
      if (arr[j] < *lowest) {
        lowest = &arr[j];    
      }
    }

    swap(&arr[min_index], lowest);

    lowest = NULL;
  }

  free(lowest);
}
