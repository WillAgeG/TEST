#include <stdio.h>
#include <math.h>

double fun();

int main() {
    double res = fun();
    printf("%2.99lf", res);

    return 0;
}

double fun() {
    return (1.0 / 13) * (pow(((2 - 1.0) / (2 + 1.0)), 20));
}