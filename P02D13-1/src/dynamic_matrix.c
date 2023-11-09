#include <stdio.h>
#include <stdlib.h>

void dynamic_array_print(int **A, size_t N, size_t M);
int **dynamic_array_alloc(size_t N, size_t M);
void dynamic_array_free(int **A, size_t N);
void dynamic_array_test(size_t N, size_t M);

int main() {
    int matrix_height = 25; // Высота
    int matrix_width = 80; // Ширина

    dynamic_array_test(matrix_height, matrix_width);
    return 0;
}

void dynamic_array_print(int **A, size_t N, size_t M) { // Графика
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%d", A[i][j]);
        }
        printf("\n");
    }
}

int **dynamic_array_alloc(size_t N, size_t M) { // Выделение памяти
    int **A = (int**) malloc(N * sizeof(int*));
    for (int i = 0; i < N; i++) {
        A[i] = (int*) malloc(M * sizeof(int));
    }
    return A;
}

void dynamic_array_free(int **A, size_t N) { // Освобождение памяти
    for (int i = 0; i < N; i++) {
        free(A[i]);
    }
    free(A);
}

void dynamic_array_test(size_t N, size_t M) { // Заполнение
    int **A = dynamic_array_alloc(N, M);
    int x = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            A[i][j] = x;
        }
    }
    dynamic_array_print(A, N, M);
    dynamic_array_free(A, N);
}