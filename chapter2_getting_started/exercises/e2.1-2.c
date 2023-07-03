#include <stdio.h>

int sum_array(int array[], int size);

int main() {
  int array[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9};
  int result;

  result = sum_array(array, sizeof(array) / sizeof(int));

  printf("result: %d\n", result);

  return 0;
}

int sum_array(int array[], int size) {
  int sum = 0;

  for (int i = 0; i < size; i++) {
    sum += array[i];
  }

  return sum;
}
