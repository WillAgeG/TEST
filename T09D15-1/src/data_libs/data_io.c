#include "data_io.h"

#include <stdio.h>
#include <stdlib.h>

int input_one_number(int n) {
    char c;
    if (scanf("%d%c", &n, &c) != 2 || n <= 0 || c != '\n') {
        return 0;
    }
    return n;
}

int input_numbers(double *data, int n) {
    char c;
    for (int i = 0; i < n; i++) {
        if (scanf("%lf%c", &data[i], &c) != 2 || (c != ' ' && i != n - 1) || (i == n - 1 && c != '\n'))
            return -1;
    }
    return 0;
}

void output(double *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0)
            printf("%.2lf", data[i]);
        else
            printf(" %.2lf", data[i]);
    }
}
