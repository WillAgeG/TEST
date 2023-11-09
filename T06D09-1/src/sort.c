#include <stdio.h>
#define NMAX 10

int input(int *a);
void output(int *a);
void sort(int *a);

int main() {
    int data[NMAX];
    if (input(data) == 0) {
        sort(data);
        output(data);
    }
    return 0;
}

int input(int *a) {
    int exit = 0;
    int counter = 0;
    char c;
    for (int *p = a; p - a < NMAX; p++) {
        if (scanf("%d", p) != 1) {
            printf("n/a\n");
            exit = -1;
            break;
        }
        c = getchar();
        if (c == '\n' && counter < 9) {
            printf("n/a\n");
            exit = -1;
            break;
        }
        if (c == ' ') counter++;
        if (counter > 9) {
            printf("n/a\n");
            exit = -1;
            break;
        }
    }
    return exit;
}

void output(int *a) {
    for (int i = 0; i < NMAX; i++) {
        printf("%d", a[i]);
        if (i < NMAX - 1) printf(" ");
    }
    printf("\n");
}

void sort(int *a) {
    int vrm;
    for (int i = 0; i < NMAX - 1; i++) {
        for (int j = 0; j <= NMAX - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                vrm = a[j];
                a[j] = a[j + 1];
                a[j + 1] = vrm;
            }
        }
    }
}