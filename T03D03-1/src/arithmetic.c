#include <stdio.h>

int main() {
    float a, b;
    int sum, dif, mul, div;
    
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

    sum = a + b;
    dif = a - b;
    mul = a * b;

    printf("%d %d %d ", sum, dif, mul);

    if (b == 0) {
        printf("n/a");
    }
    else {
        div = a / b;
        printf("%d", div);
    }

    return 0;
}
