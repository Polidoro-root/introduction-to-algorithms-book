#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
  uint8_t head;
  uint8_t tail;
  uint8_t size;
  uint8_t array[10];
} queue;

bool isempty(queue *q) {
  if (q->head == q->tail) {
    return true;
  }

  return false;
}

void enqueue(queue *q, uint8_t value) {
  q->array[q->tail] = value;

  if (q->tail == q->size) {
    q->tail = 0;
  } else if (q->tail >= q->size) {
    perror("overflow");
  } else {
    q->tail++;
  }
}

uint8_t dequeue(queue *q) {
  uint8_t x = q->array[q->head];

  if (isempty(q)) {
    perror("underflow");
  } else if (q->head == q->size) {
    q->head = 0;
  } else {
    q->array[q->head] = 0;
    q->head++;
  }

  return x;
}

int main() {
  queue *q;

  q = malloc(sizeof(queue));
  q->head = 0;
  q->tail = 0;
  q->size = 10;

  enqueue(q, 10);
  enqueue(q, 15);
  enqueue(q, 20);
  enqueue(q, 25);

  for (int i = 0; i < q->tail; i++) {
    printf("index: %d | value: %d\n", i, q->array[i]);
  }

  for (int i = 0; i < q->tail; i++) {
    uint8_t v = dequeue(q);
    printf("index: %d | value: %d | head: %d | tail: %d\n", i, v, q->head,
           q->tail);
  }

  for (int i = 0; i < q->size; i++) {
    printf("index: %d | value: %d\n", i, q->array[i]);
  }

  return 0;
}
