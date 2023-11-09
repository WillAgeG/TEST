#include <stdio.h>
#include <stdlib.h>

#include "../data_libs/data_io.h"
#include "../data_libs/data_io_macro.h"  // Бонусная задача
#include "../data_libs/data_stat.h"
#include "../data_module/data_process.h"
#include "../yet_another_decision_module/decision.h"

#if any_type == 1
int main() {
    int n = 0;
    int error = 0;
    int *data = 0;

    printf("LOAD DATA...\n");
    n = input_one_number(n);
    if (n == 0) {
        printf("n/a");
        return 1;
    }
    data = (int *)malloc(sizeof(*data) * n);
    error = input_numbers_int(data, n);
    if (error == -1) {
        printf("n/a");
        return 1;
    }

    printf("RAW DATA:\n\t");
    output_int(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization_int(data, n);
    output_int(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort_int(data, n);
    output_int(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision_int(data, n))
        printf("YES");
    else
        printf("NO");
    free(data);
    return 0;
}

#elif any_type == 2
int main() {
    int n = 0;
    int error = 0;
    double *data = 0;

    printf("LOAD DATA...\n");
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

    printf("RAW DATA:\n\t");
    output(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    normalization(data, n);
    output(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort(data, n);
    output(data, n);

    printf("\nFINAL DECISION:\n\t");
    if (make_decision(data, n))
        printf("YES");
    else
        printf("NO");
    free(data);
    return 0;
}

#elif any_type == 3
int main() {
    int n = 0;
    int error = 0;
    char *data = 0;

    printf("LOAD DATA...\n");
    n = input_one_number(n);
    if (n == 0) {
        printf("n/a");
        return 1;
    }
    data = (char *)malloc(sizeof(*data) * n);
    error = input_numbers_char(data, n);
    if (error == -1) {
        printf("n/a");
        return 1;
    }

    printf("RAW DATA:\n\t");
    output_char(data, n);

    printf("\nNORMALIZED DATA:\n\t");
    output_char(data, n);

    printf("\nSORTED NORMALIZED DATA:\n\t");
    sort_char(data, n);
    output_char(data, n);

    printf("\nFINAL DECISION:\n\t");
    printf("n/a\n");

    free(data);
    return 0;
}
#endif