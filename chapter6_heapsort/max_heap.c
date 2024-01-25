#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct Heap {
  int *array;
  int heapsize;
} Heap;

int parent(int i);
int left(int i);
int right(int i);

void maxheapify(Heap *, int);   // O(lg n)
void buildmaxheap(Heap *, int); // O(n)
void heapsort(Heap *, int);     // O(n lg n)

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
