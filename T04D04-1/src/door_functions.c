#include <math.h>
#include <stdio.h>

int main() {
  double x, a, b, h;

  x = -3.14159265535897932384626433832795;

  for (int i = 0; i < 42; i++) {
    a = 1.0 / (1.0 + pow(x, 2.0));
    b = sqrt(sqrt(1 + 4 * x * x) - x * x - 1.0);
    h = 1.0 / (x * x);

    printf("%.7lf | %.7lf | ", x, a);
    if ((1 + 4 * x * x >= 0) && (sqrt(1 + 4 * x * x) - x * x - 1.0) >= 0) {
      printf("%.7lf | %.7lf\n", b, h);
    } else {
      printf("- | %.7lf\n", h);
    }

    x = x + 0.1532484222126331377485982604062415;
  }
  return 0;
}