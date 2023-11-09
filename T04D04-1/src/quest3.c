
#include <stdio.h>

int fibonacci(int N) {
  if (N == 1 || N == 2)
    return 1;
  return fibonacci(N - 1) + fibonacci(N - 2);
}

int main() {
  float n;

  if (scanf("%f", &n) != 1) {
    printf("n/a");

    return 0;
  }

  if ((int)n != n) {
    printf("n/a");

    return 0;
  }

  n = ((int)n);
  printf("%d\n", fibonacci(n));

  return 0;
}
