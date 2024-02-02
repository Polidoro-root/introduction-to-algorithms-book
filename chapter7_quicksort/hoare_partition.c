#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int hoarepartition(int *, int, int);

int main(int argc, char *argv[]) {
  int arr[] = {13, 19, 9, 5, 12, 8, 7, 4, 11, 2, 6, 21};

  printf("%d\n", hoarepartition(arr, 2, 10));

  return EXIT_SUCCESS;
}

int hoarepartition(int *A, int p, int r) {
  int x = A[p];
  int i = p - 1;
  int j = r + 1;

  while (true) {
    while (A[j] > x) {
      j = j - 1;
    }

    while (A[i] < x) {
      i = i + 1;
    }

    if (i < j) {
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    } else
      return j;

    for (int k = 0; k < 12; k++)
      printf("%d ", A[k]);
    printf("\ni: %d | j: %d\n", i, j);
  }
}
