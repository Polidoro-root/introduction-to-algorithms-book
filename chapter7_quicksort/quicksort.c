#include <stdlib.h>

/*
 * worst: O(n²)
 * average: O(n lg n)
 */
void quicksort(int *, int, int); // divide, conquer and combine

int partition(int *, int, int);

int randomizedpartition(int *, int, int);

void randomizedquicksort(int *, int, int);

int randomrange(int min, int max) { return min + rand() % (max + 1 - min); }

int main(int argc, char *argv[]) { return EXIT_SUCCESS; }

void quicksort(int *A, int p, int r) {
  if (p < r) {
    // partition the subarray around pivot, which ends up in A[q]
    int q = partition(A, p, r);

    quicksort(A, p, q - 1); // recursively sort the low side
    quicksort(A, q + 1, r); // recursively sort the low side
  }
}

int partition(int *A, int p, int r) {
  int x = A[r];                     // the pivot
  int i = p - 1;                    // highest index into the low side
  for (int j = p; j < r - 1; j++) { // process each element other than the pivot
    if (A[j] <= x) {                // does this element belong on the low side?
      i++;                          // index of a new slot in the low side
      // swap A[i] and A[j]
      int tmp = A[j];
      A[j] = A[i];
      A[i] = tmp;
    }
  }

  // swap A[i + 1] and A[r] - Pivot goes just to the right of the low side
  int tmp = A[r];
  A[r] = A[i + 1];
  A[i + 1] = tmp;

  return i + 1;
}

int randomizedpartition(int *A, int p, int r) {
  int i = randomrange(p, r);
  int tmp = A[r];
  A[r] = A[i];
  A[i] = tmp;

  return partition(A, p, r);
}

void randomizedquicksort(int *A, int p, int r) {
  if (p < r) {
    int q = randomizedpartition(A, p, r);
    randomizedquicksort(A, p, q - 1);
    randomizedquicksort(A, q + 1, r);
  }
}
