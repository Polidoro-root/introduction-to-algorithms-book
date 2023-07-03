#include <stdlib.h>
#include <stdio.h>

int* linear_search(int value, int array[], int size) {
  if (size == 0) {
    return NULL;
  }

  for (int i = 0 ; i < size ; i++) {
    if (array[i] == value) {
      int *index = malloc(sizeof(int));
      *index = i;
      return index;
    }
  }

  return NULL;
}

int main() {
  int array[5] = {1, 2, 3, 4, 5};
  int *index = NULL;
  int value;

  printf("search value: ");
  scanf("%d", &value);

  index = linear_search(value, array, sizeof(array) / sizeof(int));

  if (index == NULL) {
    printf("\nIndex not found\n");

    return 0;
  }

  printf("\nIndex: %d\n", *index);

  free(index);

  return 0;
}
