#include <stdio.h>
#include <stdlib.h>

int input(int *arr, int n);
void output(int *arr, int n);
void bubbleSort(int *arr, int n);

int main() {
    int n, *data = NULL;

    if (scanf("%d", &n) == 0) {
        printf("n/a");
        return 0;
    }
    data = malloc(n * sizeof(int));

    if (input(data, n) == 1) {
        printf("n/a");
        return 1;
    }

    bubbleSort(data, n);
    output(data, n);
    printf("\n");
    free(data);
    return 0;
}

int input(int *arr, int n) {
    // for (int *i = arr; i - arr < n; i++) {
    //     if (scanf("%d", i) == 0) {
    //         return 1;
    //     }
    // }

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    return 0;
}

void output(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
}

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
