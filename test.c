#include <stdio.h>
#define NMAX 10

int input(int *a, int *n, int *c);
void cycle_shift(int *a, int *n, int *c);
void output(int *a, int n);

int main() {
    int n, c;
    int m = 0;
    int a[10];
    if (input(a, &n, &c) == -1) return m;
    cycle_shift(a, &n, &c);
    output(a, n);

    return m;
}
int input(int *a, int *n, int *c) {
    int k = 0;
    if (scanf("%d", n) <= 0 || *n > NMAX || *n <= 0) {
        printf("n/a\n");
        k = -1;
    } else {
        for (int i = 0; i < *n; i++) {
            if (scanf("%d", &a[i]) == 0) {
                printf("n/a\n");
                break;
            }
        }

        if (scanf("%d", c) <= 0) {
            printf("n/a\n");
            k = -1;
        }
    }
    return k;
}

void cycle_shift(int *a, int *n, int *c) {
    if (*c < 0) {
        *c = *n + (*c % *n);
    } else {
        *c = *c % *n;
    }

    int temp;
    for (int i = 0; i < *c; i++) {
        temp = a[0];
        for (int j = 0; j < *n - 1; j++) {
            a[j] = a[j + 1];
        }
        a[*n - 1] = temp;
    }
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        if (i < n - 1) {
            printf("%d ", a[i]);
        } else
            printf("%d", a[i]);
    }
}
