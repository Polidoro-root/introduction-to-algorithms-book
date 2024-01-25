#include <stdio.h>

#define a (1103515245)
#define c (12345)
#define m (1 << 31)

static unsigned int seed = 1;

void srand(unsigned int s) { seed = s; }

int rand() {
  seed = (a * seed + c) % m;
  return seed;
}

int main() {

  printf("%d\n", rand());

  return 0;
}
