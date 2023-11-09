#include <stdio.h>
#include <math.h>

int main() {
    double x, y;

    if (scanf("%lf", &x) != 1) {
        printf("n/a");

        return 0;
    }

    if ((int)x != x) {
        printf("n/a");

        return 0;
    }

    y = 7e-3 * pow(x, 4.0) + ((22.8 * pow(x, 1.0/3.0) - 1e3) * x + 3.0) / (x * x / 2.0) - x * pow(10 + x, 2.0/x) - 1.01;

    printf("%.1lf", y);
    return 0;
}

