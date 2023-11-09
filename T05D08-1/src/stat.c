#include <stdio.h>
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
  }

  return 0;
}

int input(int *a, int *n) {
  int x = 0;
  if (scanf("%d", n) != 1) {
    printf("n/a");
    x = 1;
  } else {
    for (int *p = a; p - a < *n; p++) {
      if (scanf("%d", p) != 1) {
        printf("n/a");
        x = 1;
        break;
      }
    }
  }
  return x;
}

void output(int *a, int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", a[i]);
    if (i < n - 1)
      printf(" ");
  }
  printf("\n");
}

int max(int *a, int n) {
  int max_num = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] > max_num)
      max_num = a[i];
  }
  return max_num;
}

int min(int *a, int n) {
  int min_num = a[0];
  for (int i = 0; i < n; i++) {
    if (a[i] < min_num)
      min_num = a[i];
  }
  return min_num;
}

double mean(int *a, int n) {
  double sum_num = 0;
  for (int i = 0; i < n; i++) {
    sum_num += a[i];
  }
  double mean_num = sum_num / (double)n;
  return mean_num;
}

double variance(int *a, int n) {
  double sum_dis = 0;
  for (int i = 0; i < n; i++) {
    sum_dis += (a[i] - mean(a, n)) * (a[i] - mean(a, n));
  }
  return sum_dis / n;
}

void output_result(int max_v, int min_v, double mean_v, double variance_v) {
  printf("%d ", max_v);
  printf("%d ", min_v);
  printf("%.6lf ", mean_v);
  printf("%.6lf", variance_v);
}
