#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

void sort_vertical(int **matrix, int n, int m, int **result_matrix);

void input(int **matrix, int *n, int *m);
void output(int **matrix, int n, int m);

int main() {
    int **matrix, **result;
    int n, m;

    input(matrix, &n, &m);

    // sort_vertical(matrix, n, m, result);
    output(result, n, m);

    // sort_horizontal(matrix, n, m, result);
    // output(result, n, m);

    return 0;
}

void input(int **matrix, int *n, int *m) {
    if (scanf("%d %d", n, m) != 2) {
        *n = 0;
        *m = 0;
        printf("n/a");
        exit(1);
    }

    matrix = malloc(*n * *m * sizeof(int) + *n * sizeof(int*));
    int *ptr = (int*) (matrix + *n);
    for (int i = 0; i < *n; i++)
        matrix[i] = ptr + *n * i;

    for (int i = 0; i < *n; i++) {
        for (int j = 0; j < *m; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void sort_vertical(int **matrix, int n, int m, int **result_matrix) {

    result_matrix = malloc(n * m * sizeof(int) + n * sizeof(int*));
    int *ptr1 = (int*) (result_matrix + n);
    for (int i = 0; i < n; i++)
        result_matrix[i] = ptr1 + n * i;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            result_matrix[j][i] = matrix[i][j];
        }
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (j == 0)
                printf("%d", matrix[i][j]);
            else
                printf(" %d", matrix[i][j]);
        }
        if (i < n - 1)
            printf("\n");
    }
}
