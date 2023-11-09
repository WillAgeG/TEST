#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void squaring(int *a, int n);

int main() {
  int n, data[NMAX];
  int x;
  x = input(data, &n);
  if (x != 1) {
    squaring(data, n);
    output(data, n);
  } else {
    printf("n/a\n");
    return 1;
  }
  return 0;
}

int input(int *a, int *n) {
  scanf("%d", n);
  if (*n <= NMAX && *n > 0) {
    for (int *p = a; p - a < *n; p++) {
      scanf("%d", p);
      char ch = getchar();
      if (ch != ' ') {
        if (ch == '\n' && p - a + 1 == *n) {
          return 0;
        } else {
          return 1;
        }
      }
    }
  }
  return 1;
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i]);
  }
  printf("\n");
}

void squaring(int *a, int n) {
  for (int i = 0; i < n; i++) {
    a[i] = a[i] * a[i];
  }
}
