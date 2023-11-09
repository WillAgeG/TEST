#include <stdio.h>
#include <math.h>
#define NMAX 10

int input(int *a, int *n);
void output(int *a, int n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(int max_v, int min_v, double mean_v, double variance_v);

int main() {
    int n, data[NMAX];
    if (input(data, &n) == 0) {
        output(data, n);
        output_result(max(data, n), min(data, n), mean(data, n), variance(data, n));
    } else {
        printf("n/a");
    }
    return 0;
}


int input(int *a, int *n, int *p)
{
    if (scanf("%d", *n) != 1 || *n <= 0 || *n > NMAX) {
        return -1;
    }
    for (int *p = a; p < a + *n; p++) {
        if (scanf("%d", p) != 1) {
            return -1;
        }
    }
    return 0;
}

void output(int *a, int n, int *p)
{
    for (int *p = a; p < a + n; p++)
        ;
    { printf("%d", *p); }
    printf("\n");
}

int max(int *a, int n, int *p) {
    int max = *a;
    for (int *p = a + 1; p < a + n; p++)
        ;
    {
        if (*p > max) {
            max = *p;
        }
    }
    return max;
}

int min(int *a, int n, int *p) {
    int min = *a;
    for (int *p = a + 1; p < a + n; p++)
        ;
    {
        if (*p < min) {
            min = *p;
        }
    }
    return min;
}

double mean(int *a, int n, int *p) {
    double sum = 0.0;
    for (int *p = a; p < a + n; p++)
        ;
    { sum += *p; }
    return sum / n;
}

double variance(int *a, int n, int *p) {
    double mean_v=mean(a,n);
    double sum=0.0;
    for(int *p=a; p<a+n; p++);
    {
        sum += (*p - mean_v) * (*p - mean_v);
    }
return sum /n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v)
{
    printf("max%d\n", max_v);
    printf("min%d\n", min_v);
    printf("mean%6f\n", mean_v);
    printf("varience=%.6f\n", variance_v);
}
}
