#include <stdio.h>
#define NMAX 10

int input(int *a, int *n);
int max(int *a, int n);
int min(int *a, int n);
double mean(int *a, int n);
double variance(int *a, int n);

void output_result(double mean_v, int *a, int n);

int main() {
  int n, data[NMAX];
  if (input(data, &n) == 0) {
    output_result(mean(data, n), data, n);
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

void output_result(double mean_v, int *a, int n) {
  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 0 && a[i] >= mean_v && a[i] < (3 * div) + mean && a[i] != 0) {
      printf("%d", a[i]);
      break;
    }
  }
}
