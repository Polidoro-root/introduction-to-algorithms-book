#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int array[], int size) {
  for (int i = 0 ; i < size; i++) {
    int key = array[i];

    // Insert Arr[i] into the sorted subarray Arr[1:i - 1]
    int j = i - 1;

    while (j >= 0 && array[j] > key) {
      array[j + 1] = array[j];
      j = j - 1;
    }

    array[j + 1] = key;

  }
}

int main() {
  int array[6] = {5, 2, 4, 6, 1, 3};

  insertion_sort(array, sizeof(array) / sizeof(array[0]));

  for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++) {
    printf("%d ", array[i]);
  }

  puts("\n");

  return 0;
}


