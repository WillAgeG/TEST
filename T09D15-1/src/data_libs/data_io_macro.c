#include "data_io_macro.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#if any_type == 1  // Тип int = 1
int input_one_number(int n) {
    char c;
    if (scanf("%d%c", &n, &c) != 2 || n <= 0 || c != '\n') {
        return 0;
    }
    return n;
}

int input_numbers_int(int *data, int n) {
    char c;
    for (int i = 0; i < n; i++) {
        if (scanf("%d%c", &data[i], &c) != 2 || (c != ' ' && i != n - 1) || (i == n - 1 && c != '\n'))
            return -1;
    }
    return 0;
}

void output_int(int *data, int n) {
    for (int i = 0; i < n; i++) {
        if (i == 0)
            printf("%d", data[i]);
        else
            printf(" %d", data[i]);
    }
}

int normalization_int(int *data, int n) {
    int result = 1;
    double max_value = max_int(data, n);
    double min_value = min_int(data, n);
    double size = max_value - min_value;

    if (fabs(size) < EPS) {
        for (int i = 0; i < n; i++) {
            if (size != 0)
                data[i] = data[i] / size - min_value / size;
            else
                result = 0;
        }
    } else {
        result = 0;
    }

    return result;
}

void sort_int(int *data, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= n - i - 2; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

int make_decision_int(int *data, int n) {
    int decision = 1;

    double m = mean_int(data, n);
    double sigma = sqrt(variance_int(data, n));
    double max_value = max_int(data, n);
    // double min_value = min(data, n);

    decision &= (max_value <= m + 3 * sigma) && (max_value >= m - 3 * sigma) && (m >= GOLDEN_RATIO);

    return decision;
}

int max_int(int *data, int n) {
    int max_num = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max_num) {
            max_num = data[i];
        }
    }
    return max_num;
}

int min_int(int *data, int n) {
    int min_num = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min_num) {
            min_num = data[i];
        }
    }
    return min_num;
}

int mean_int(int *data, int n) {
    int sum_num = 0;
    for (int i = 0; i < n; i++) {
        sum_num += data[i];
    }
    return sum_num / n;
}

int variance_int(int *data, int n) {
    int variance_num = 0;
    int mean_num = mean_int(data, n);
    for (int i = 0; i < n; i++) {
        variance_num += (data[i] - mean_num) * (data[i] - mean_num);
    }
    return variance_num / n;
}

#elif any_type == 2  // Тип double = 2
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

#elif any_type == 3  // Тип char = 3
int input_one_number(int n) {
    char c;
    if (scanf("%d%c", &n, &c) != 2 || n <= 0 || c != '\n') {
        return 0;
    }
    return n;
}

int input_numbers_char(char *data, int n) {
    char c;
    for (int i = 0; i < n; i++) {
        scanf("%c", &data[i]);
    }
    return 0;
}

void output_char(char *data, int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", data[i]);
    }
}

void sort_char(char *data, int n) {
    char temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j <= n - i - 2; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

#endif