#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct list_item list_item;

struct list_item {
  uint8_t key;
  list_item *prev;
  list_item *next;
};

typedef struct {
  list_item *head;
  list_item *tail;
  uint8_t key;
} doubly_linked_list;

list_item *listsearch(doubly_linked_list *l, uint8_t key) {
  list_item *x = l->head;

  while (x != NULL && x->key != key) {
    x = x->next;
  }

  return x;
}

void listprepend(doubly_linked_list *l, list_item *x) {
  x->next = l->head;
  x->prev = NULL;

  if (l->head != NULL) {
    l->head->prev = x;
  }

  l->head = x;
}

void listinsert(list_item *x, list_item *y) {
  x->next = y->next;
  x->prev = y;

  if (y->next != NULL) {
    y->next->prev = x;
  }

  y->next = x;
}

void listdelete(doubly_linked_list *l, list_item *x) {
  if (x->prev != NULL) {
    x->prev->next = x->next;
  } else {
    l->head = x->next;
  }

  if (x->next != NULL) {
    x->next->prev = x->prev;
  }
}
