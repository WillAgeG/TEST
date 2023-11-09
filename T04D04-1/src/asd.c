#include <math.h>
#include <stdio.h>

int main() {
  double x, a, b, h;

  x = -3.14159265359;

  for (int i = 0; i <= 42; i++) {
    a = 1.0 / (1.0 + x * x);
    b = sqrt(sqrt(1 + 4 * x * x) - x * x - 1.0);
    h = 1.0 / (x * x);

    printf("%.7lf | %.7lf | ", x, a);
    if ((1 + 4 * x * x >= 0) && (sqrt(1 + 4 * x * x) - x * x - 1.0) >= 0 &&
        (sqrt(sqrt(1 + 4 * x * x) - x * x - 1.0)) >= 0) {
      printf("%.7lf | %.7lf\n", b, h);
    } else {
      printf("- | %.7lf\n", h);
    }

    x += 0.14959965017;
  }
  return 0;
}