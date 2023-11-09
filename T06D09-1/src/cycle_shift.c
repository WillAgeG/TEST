#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
void arrayShift(int *a, int n, int l);

int main() {
    int n, data[NMAX], l;

    l = input(data, &n);
    arrayShift(data, n, l);
    output(data, n);

    return 0;
}

int input(int *a, int *n) {
    int counter = 0;
    int l;
    if (scanf("%d", n) != 1) {
        printf("n/a\n");
        *n = 0;
    }
    for (int *p = a; p - a < *n; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a\n");
            *n = 0;
            break;
        }
        char c2 = getchar();
        if (c2 == '\n' && counter < *n - 1) {
            printf("n/a\n");
            *n = 0;
            break;
        }
        if (c2 == ' ') counter++;
        if (counter > *n - 1) {
            printf("n/a\n");
            *n = 0;
            break;
        }
    }
    if (scanf("%d", &l) != 1) {
        printf("n/a\n");
        *n = 0;
    }
    return l;
}

void output(int *a, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d", a[i]);
        if (i < n - 1) printf(" ");
    }
}

void arrayShift(int *a, int n, int l) {
    for (int i = 0; i < l; i++) {
        if (l <= 0) {
            int tmp = a[n - 1];  //Влево
            for (int i = n - 1; i > 0; --i) a[i] = a[i - 1];
            a[0] = tmp;
        } else {
            int tmp = a[0];  //Вправо
            for (int i = 0; i < n - 1; i++) a[i] = a[i + 1];
            a[n - 1] = tmp;
        }
    }
}