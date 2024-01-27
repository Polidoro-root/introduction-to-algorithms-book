// this header file includes max heap definitions for max heap data structure
// and max-priority queue
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

int maxheapmaximum(Heap *);                // O(1)
int maxheapextractmax(Heap *);             // O(lg n)
void maxheapincreasekey(Heap *, int, int); // O(lg n)
void maxheapinsert(Heap *, int, int);      // O(lg n)
