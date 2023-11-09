#include <stdio.h>
 
int main() {
    double x, y, res;
    res = 25;
    scanf("%lf %lf", &x, &y);

    if (res > (x*x + y*y)) {
        printf("GOTCHA");
    }
    else {
        printf("MISS");
    }

    return 0;
}

