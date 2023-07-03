#include <stdlib.h>
#include <stdio.h>

void insertion_sort(int array[], int size) {
  for (int i = 0 ; i < size; i++) {
    int key = array[i];

    // Insert Arr[i] into the sorted subarray Arr[1:i - 1]
    int j = i - 1;

    while (j >= 0 && array[j] < key) {
      array[j + 1] = array[j];
      j = j - 1;
    }

    array[j + 1] = key;
  }
}

int main() {
  int array[6] = {31, 41, 59, 26, 41, 58};

  insertion_sort(array, sizeof(array) / sizeof(array[0]));

  for (int i = 0 ; i < 6 ; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}
