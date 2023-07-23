#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// Arr[p:r]
void merge(int arr[], int p, int q, int r);
void mergesort(int arr[], int p, int r);

int main() {
  int arr[SIZE] = {2, 4, 6, 7, 1, 2, 3, 5};

  mergesort(arr, 0, SIZE - 1);

  for (int i = 0; i < SIZE; i++) printf("%d ", arr[i]);

  printf("\n");

  return 0;
}

void merge(int arr[], int p, int q, int r) {
  int nL = q - p + 1; // length of Arr[p:q]
  int nR = r - q; // length of Arr[q + 1 : r]

  int left[nL], right[nR];

  // copy arr[p:q] into left[0:nL - 1]
  for (int i = 0; i < nL; i++) {
    left[i] = arr[p + i];
  }

  // copy arr[q + 1 : r] into right[0 : nR - 1]
  for (int j = 0; j < nR; j++) {
    right[j] = arr[q + j + 1];
  }

  int i = 0; // indexes the smallest remaining element in left[]
  int j = 0; // indexes the smallest remaining element in right[]
  int k = p; // k indexes the location in ar[] to fill

  // As long as each of the arrays left[] and right[] contains unmerged elements, copy the smallest unmerged elements back into arr[p:r]
  while (i < nL && j < nR) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i += 1;
    } else {
      arr[k] = right[j];
      j += 1;
    }

    k += 1;
  }

  // Having gone through one of left[] and right[] entirely, copy the remainder of the other to the end of arr[p:r]
  while (i < nL) {
    arr[k] = left[i];
    i += 1;
    k += 1;
  }

  while (j < nR) {
    arr[k] = right[j];
    j += 1;
    k += 1;
  }
}

void mergesort(int arr[], int p, int r) {
  if (p >= r) return; // zero or one element?

  int q = (p + r) / 2; // midpoint of arr[p:r]

  mergesort(arr, p, q); // recursively sort arr[p:q]
  mergesort(arr, q + 1, r); // recursively sort arr[q+1:r]

  // Merge arr[p:q] and arr[q+1:r] into arr[p:r]
  merge(arr, p, q, r);
}
