#include <stdlib.h>
#include <stdio.h>

void matrixmultiply(int a[2][2], int b[2][2], int c[2][2], int n) {
  for (int i = 0; i < n; i++) { // compute entries in each n row
    for (int j = 0; j < n; j++) { // compute n entries in i row
      for (int k = 0; k < n; k++) {
        c[i][j] = c[i][j] + (a[i][k] * b[k][j]);
      }
    } 
  }
}

int main() {
  int a[2][2] = {{1, 2}, {3, 4}};
  int b[2][2] = {{1, 2}, {3, 4}};
  int c[2][2] = {};

  matrixmultiply(a, b, c, 2);

  for (int i = 0; i < 2; i++) { // compute entries in each n row
    for (int j = 0; j < 2; j++) { // compute n entries in i row
      printf("%d ", c[i][j]);
    }
    printf("\n");
  }
 
  return 0;
}


