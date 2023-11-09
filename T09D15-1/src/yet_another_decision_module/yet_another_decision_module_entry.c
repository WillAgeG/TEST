#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_module/data_process.h"
#include "decision.h"

int main() {
    int n = 0;
    int error = 0;
    double *data = 0;

    n = input_one_number(n);
    if (n == 0) {
        printf("n/a");
        return 1;
    }

    data = (double *)malloc(sizeof(*data) * n);

    error = input_numbers(data, n);
    if (error == -1) {
        printf("n/a");
        return 1;
    }

    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");

    free(data);
    return 0;
}
