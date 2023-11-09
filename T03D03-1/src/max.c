#include <stdio.h>

int findMax(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int max;
    float a, b;

    if (scanf("%f%f", &a, &b) != 2) {
        printf("n/a");

        return 0;
    }

    if ((int)a != a || (int)b != b) {
        printf("n/a");

        return 0;
    }

    a = ((int) a);
    b = ((int) b);

    max = findMax(a, b);
    printf("%d", max);

    return 0;
}

