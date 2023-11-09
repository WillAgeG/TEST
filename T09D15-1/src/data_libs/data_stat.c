#include "data_stat.h"

double max(double *data, int n) {
    double max_num = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] > max_num) {
            max_num = data[i];
        }
    }
    return max_num;
}

double min(double *data, int n) {
    double min_num = data[0];
    for (int i = 0; i < n; i++) {
        if (data[i] < min_num) {
            min_num = data[i];
        }
    }
    return min_num;
}

double mean(double *data, int n) {
    double sum_num = 0;
    for (int i = 0; i < n; i++) {
        sum_num += data[i];
    }
    return sum_num / (double)n;
}

double variance(double *data, int n) {
    double variance_num = 0;
    double mean_num = mean(data, n);
    for (int i = 0; i < n; i++) {
        variance_num += (data[i] - mean_num) * (data[i] - mean_num);
    }
    return variance_num / (double)n;
}