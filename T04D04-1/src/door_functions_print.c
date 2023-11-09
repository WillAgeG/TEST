#include <math.h>
#include <stdio.h>

int main() {
  double x, a, b, h;

  x = -3.14159265359;
  a = 1.0 / (1.0 + x * x);
  b = sqrt(sqrt(1 + 4 * x * x) - x * x - 1.0);
  h = 1.0 / (x * x);

  for (int i = 0; i < 24; i++) {
    for (int j = 0; j < 42; j++) {
      printf("* ");
    }
    printf("\n");
  }
  return 0;
}