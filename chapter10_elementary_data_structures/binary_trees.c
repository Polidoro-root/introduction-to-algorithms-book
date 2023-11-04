#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct binary_tree binary_tree;

struct binary_tree {
  int32_t key;
  binary_tree *p;     // parent
  binary_tree *left;  // left child
  binary_tree *right; // right child
};

bool isroot(binary_tree *t) { return t->p == NULL; }
