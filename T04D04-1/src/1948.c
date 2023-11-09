#include <math.h>
#include <stdio.h>

int prime_number(int a) {
  int b = a;

  for (int i = 2; i <= sqrt(a); i++) {
    b = a;
    while (b > 0) {
      b -= i;
    }
    if (b == 0)
      return 0;
  }
  return 1;
}

int main() {
  float a;
  int max = 0;

  if (scanf("%f", &a) == 1 && (float)((int)a) == a) {
    if (a < 0)
      a = -a;
    int z = a;

    for (int i = 2; i <= a; ++i, z = a) {
      if (prime_number(i)) {
        while (z > 0) {
          z -= i;
        }
        if (z == 0)
          max = i;
      }
    }
    if (max != 0 && max != 1) {
      printf("%d\n", max);
    } else {
      printf("n/a\n");
    }
  } else {
    printf("n/a\n");
  }
  return 0;
}
