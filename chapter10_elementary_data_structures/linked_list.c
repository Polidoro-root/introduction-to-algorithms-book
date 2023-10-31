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

typedef struct list_sentinel_nil list_sentinel_nil;

struct list_sentinel_nil {
  uint8_t key;
  list_sentinel_nil *prev;
  list_sentinel_nil *next;
};
typedef struct list_sentinel list_sentinel;

struct list_sentinel {
  uint8_t key;
  list_sentinel *prev;
  list_sentinel *next;
  list_sentinel_nil *nil; // next = head; prev = tail;
};

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

void listdeletesentinel(list_sentinel *x) {
  x->prev->next = x->next;
  x->next->prev = x->prev;
}

void listinsertsentinel(list_sentinel *x, list_sentinel *y) {
  x->next = y->next;
  x->prev = y;
  x->next->prev = x;
  y->next = x;
}

list_sentinel_nil *listsearchsentinel(list_sentinel *l, uint8_t key) {
  list_sentinel_nil *x;

  x = malloc(sizeof(list_sentinel_nil));

  l->nil->key = key; // store the key in the sentinel to guarantee it is in list

  x = l->nil->next; // start at the head of the list

  while (x->key != key) {
    x = x->next;
  }

  if (x == l->nil) {
    return NULL;
  } else {
    return x;
  }
}
