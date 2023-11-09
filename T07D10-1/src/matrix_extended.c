#include <malloc.h>
#include <stdio.h>
#include <stdlib.h>

int input_one_number(int *menu);
int input_matrix_size(int *weight, int *height);
int input(int matrix[][100], int *weight, int *height);
void output(int matrix[][100], int *weight, int *height);

void dynamic_func_1(int *M, int *N);
void dynamic_func_2(int *M, int *N);
void dynamic_func_3(int *M, int *N);

int main() {
    int weight, height, menu = 0, **data = NULL, static_data[100][100];
    if (input_one_number(&menu) == -1) return 1;
    if (input_matrix_size(&weight, &height) == -1) return 1;
    switch (menu) {
        case 1:  // Статистическое выделение памяти
            if (input(static_data, &weight, &height) == -1) return 1;
            output(static_data, &weight, &height);
            break;
        case 2:  // Динамиеское выделение памяти (dynamic_func_1)
            dynamic_func_1(&weight, &height);
            break;
        case 3:  // Динамиеское выделение памяти (dynamic_func_2)
            dynamic_func_2(&weight, &height);
            break;
        case 4:  // Динамиеское выделение памяти (dynamic_func_3)
            dynamic_func_3(&weight, &height);
            break;
        default:
            printf("n/a");
    }

    if (data != NULL) {
        free(data);
        data = NULL;
    }
    return 0;
}

int input_one_number(int *menu) {
    char c = 0;
    if (scanf("%d", menu) != 1 || *menu <= 0 || *menu > 4) {
        printf("n/a\n");
        return -1;
    }
    c = getchar();
    if (c == ' ') {
        printf("n/a\n");
        return -1;
    }
    return 0;
}

int input_matrix_size(int *weight, int *height) {
    char c = 0;
    if (scanf("%d", weight) != 1 || c == '\n' || c == '.') {
        printf("n/a\n");
        return -1;
    }
    if (scanf("%d", height) != 1 || c == '\n' || c == '.') {
        printf("n/a\n");
        return -1;
    }
    return 0;
}

int input(int matrix[][100], int *weight, int *height) {
    for (int i = 0; i < *weight; i++) {
        for (int j = 0; j < *height; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    return 0;
}

void dynamic_func_1(int *M, int *N) {
    int **single_array_matrix = malloc((*M) * (*N) * sizeof(int) + (*M) * sizeof(int *));
    int *ptr = (int *)(single_array_matrix + *M);

    for (int i = 0; i < *M; i++) single_array_matrix[i] = ptr + (*N) * i;

    for (int i = 0; i < *M; i++)
        for (int j = 0; j < *N; j++) scanf("%d", &single_array_matrix[i][j]);

    for (int i = 0; i < *M; i++) {
        for (int j = 0; j < *N; j++) {
            if (j == 0)
                printf("%d", single_array_matrix[i][j]);
            else
                printf(" %d", single_array_matrix[i][j]);
        }
        if (i < *M - 1) printf("\n");
    }

    int max = 0;
    for (int i = 0; i < *M; i++) {
        max = single_array_matrix[i][0];
        for (int j = 0; j < *N; j++) {
            if (single_array_matrix[i][j] > max) max = single_array_matrix[i][j];
        }
        if (i == 0)
            printf("\n%d", max);
        else
            printf(" %d", max);
    }

    int min = 0;
    for (int i = 0; i < *M; i++) {
        min = single_array_matrix[i][0];
        for (int j = 0; j < *N; j++) {
            if (single_array_matrix[i][j] < min) min = single_array_matrix[i][j];
        }
        if (i == 0)
            printf("\n%d", min);
        else
            printf(" %d", min);
    }

    free(single_array_matrix);
}
void dynamic_func_2(int *M, int *N) {
    int **pointer_array = malloc(*M * sizeof(int *));
    for (int i = 0; i < *M; i++) pointer_array[i] = malloc(*N * sizeof(int));

    for (int i = 0; i < *M; i++)
        for (int j = 0; j < *N; j++) scanf("%d", &pointer_array[i][j]);

    for (int i = 0; i < *M; i++) {
        for (int j = 0; j < *N; j++) {
            if (j == 0)
                printf("%d", pointer_array[i][j]);
            else
                printf(" %d", pointer_array[i][j]);
        }
        if (i < *M - 1) printf("\n");
    }

    int max = 0;
    for (int i = 0; i < *M; i++) {
        max = pointer_array[i][0];
        for (int j = 0; j < *N; j++) {
            if (pointer_array[i][j] > max) max = pointer_array[i][j];
        }
        if (i == 0)
            printf("\n%d", max);
        else
            printf(" %d", max);
    }

    int min = 0;
    for (int i = 0; i < *M; i++) {
        min = pointer_array[i][0];
        for (int j = 0; j < *N; j++) {
            if (pointer_array[i][j] < min) min = pointer_array[i][j];
        }
        if (i == 0)
            printf("\n%d", min);
        else
            printf(" %d", min);
    }

    free(pointer_array);
}
void dynamic_func_3(int *M, int *N) {
    int **pointer_array = malloc(*M * sizeof(int *));
    int *values_array = malloc(*M * *N * sizeof(int));

    for (int i = 0; i < *M; i++) pointer_array[i] = values_array + *N * i;

    for (int i = 0; i < *M; i++)
        for (int j = 0; j < *N; j++) scanf("%d", &pointer_array[i][j]);

    for (int i = 0; i < *M; i++) {
        for (int j = 0; j < *N; j++) {
            if (j == 0)
                printf("%d", pointer_array[i][j]);
            else
                printf(" %d", pointer_array[i][j]);
        }
        if (i < *M - 1) printf("\n");
    }

    int max = 0;
    for (int i = 0; i < *M; i++) {
        max = pointer_array[i][0];
        for (int j = 0; j < *N; j++) {
            if (pointer_array[i][j] > max) max = pointer_array[i][j];
        }
        if (i == 0)
            printf("\n%d", max);
        else
            printf(" %d", max);
    }

    int min = 0;
    for (int i = 0; i < *M; i++) {
        min = pointer_array[i][0];
        for (int j = 0; j < *N; j++) {
            if (pointer_array[i][j] < min) min = pointer_array[i][j];
        }
        if (i == 0)
            printf("\n%d", min);
        else
            printf(" %d", min);
    }

    free(values_array);
    free(pointer_array);
}

void output(int matrix[][100], int *weight, int *height) {
    for (int i = 0; i < *weight; i++) {
        for (int j = 0; j < *height; j++) {
            if (j == 0)
                printf("%d", matrix[i][j]);
            else
                printf(" %d", matrix[i][j]);
        }
        if (i < *weight - 1) printf("\n");
    }

    int max = 0;
    for (int i = 0; i < *weight; i++) {
        max = matrix[i][0];
        for (int j = 0; j < *height; j++) {
            if (matrix[i][j] > max) max = matrix[i][j];
        }
        if (i == 0)
            printf("\n%d", max);
        else
            printf(" %d", max);
    }

    int min = 0;
    for (int i = 0; i < *weight; i++) {
        min = matrix[i][0];
        for (int j = 0; j < *height; j++) {
            if (matrix[i][j] < min) min = matrix[i][j];
        }
        if (i == 0)
            printf("\n%d", min);
        else
            printf(" %d", min);
    }
}
