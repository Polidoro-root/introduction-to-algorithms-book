#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define SIZE 8

int* add_binary_integers(int a[], int b[], int length);

int main() {
  int arrA[SIZE - 1] = {1, 1, 1, 1, 1, 1, 1},
    arrB[SIZE - 1] = {1, 1, 1, 1, 1, 1, 1},
    *arrC,
    decimal;

  arrC = add_binary_integers(arrA, arrB, SIZE);

  printf("\n  ");

  for (int i = 0; i < SIZE - 1; i++) {
    printf("%d ", arrA[i]);
  }

  printf("\n  ");

  for (int i = 0; i < SIZE - 1; i++) {
    printf("%d ", arrB[i]);
  }

  printf("\n");

  for (int i = 0; i < SIZE; i++) {
    printf("%d ", arrC[i]);
  }

  printf("\n");

  for (int i = SIZE; i >= 0; i--) {
    if (arrC[SIZE - i] == 1) {
      int value = (int)pow(2, i) / 2;

      printf("%d ", value);

      decimal += value; 
    }
  }

  printf("\nRESULT: %d\n", decimal);

  free(arrC);

  return 0;
}

int* add_binary_integers(int a[], int b[], int length) {
  int *result = malloc(length * sizeof(int));
  int temp = 0;

  result[length - 1] = 0;

  for(int i = length - 1; i >= 0; i--) {
    int baseIndex = i - 1;
    printf("i: %d | temp: %d | a: %d | b: %d\n", i, temp, a[baseIndex], b[baseIndex]);

    result[i] = temp;

    if (temp == 1) {
      if (a[baseIndex] & b[baseIndex]) {
        result[i] = 1;
        temp = 1;
        continue;
      }

      if (a[baseIndex] | b[baseIndex]) {
        result[i] = 0;
        temp = 1;
        continue;
      }

      result[i] = temp;
      temp = 0;
      continue;
    }

    if (a[baseIndex] & b[baseIndex]) {
      temp = 1;
      result[i] = 0;
      continue;
    }

    if (a[baseIndex] | b[baseIndex]) {
      temp = 0;
      result[i] = 1;
      continue;
    }
  }

  return result;
}
