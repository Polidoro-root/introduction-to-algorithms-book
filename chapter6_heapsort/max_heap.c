#include "max_heap.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

int main() {
  Heap *heap = malloc(sizeof(Heap));
  heap->array = (int[]){16, 14, 10, 8, 7, 9, 3, 2, 4, 1};
  heap->heapsize = 0;

  Heap *heap2 = malloc(sizeof(Heap));
  heap2->array = (int[]){4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  heap2->heapsize = 0;

  heapsort(heap, SIZE);

  for (int i = 0; i < SIZE; i++) {
    printf("%d ", heap->array[i]);
  }

  printf("\n");

  free(heap);
  free(heap2);

  return 0;
}

int parent(int i) { return i >> 1; }

int left(int i) {
  return (i << 1) + 1; // ( 2 * i ) + 1
}

int right(int i) {
  return (i << 1) + 2; // ( 2 * i ) + 2
}

void maxheapify(Heap *A, int i) {
  int l = left(i);
  int r = right(i);

  int largest = i;

  if (l <= A->heapsize && A->array[l] > A->array[i]) {
    largest = l;
  }

  if (r <= A->heapsize && A->array[r] > A->array[largest]) {
    largest = r;
  }

  if (largest != i) {
    int tmp = A->array[i];
    A->array[i] = A->array[largest];
    A->array[largest] = tmp;

    maxheapify(A, largest);
  }
}

void buildmaxheap(Heap *A, int n) {
  A->heapsize = n;

  for (int i = floor(n / 2); i >= 0; i--) {
    maxheapify(A, i);
  }
}

void heapsort(Heap *A, int n) {
  buildmaxheap(A, n);

  for (int i = n; i >= 1; i--) {
    int tmp = A->array[0];
    printf("%d\n", A->array[0]);
    A->array[0] = A->array[i];
    A->array[i] = tmp;
    A->heapsize--;
    maxheapify(A, 0);
  }
}

int maxheapmaximum(Heap *A) {
  if (A->heapsize < 1) {
    perror("heap overflow\n");
  }
  return A->array[0];
}

int maxheapextractmax(Heap *A) {
  int max = maxheapmaximum(A);

  A->array[0] = A->array[A->heapsize--];
  maxheapify(A, 0);

  return max;
}

void maxheapincreasekey(Heap *A, int x, int k) {
  if (k < x) {
    perror("new key is smaller than current key\n");
  }

  x = k;

  int i = 0;

  // find the index i in array A where object x occurs
  while (i > 1 && parent(i) < i) {
    int tmp = A->array[i];
    A->array[i] = A->array[parent(i)];
    A->array[parent(i)] = tmp;
    i = parent(i);
  }
}

void maxheapinsert(Heap *A, int x, int n) {
  if (A->heapsize == n) {
    perror("heap overflow\n");
  }

  A->heapsize++;
  int k = x;
  x = -INFINITY;
  A->array[A->heapsize] = x;

  // map x to index heapsize in the array
  maxheapincreasekey(A, x, k);
}
