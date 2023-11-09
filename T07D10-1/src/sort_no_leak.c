#include <stdio.h>
#include <stdlib.h>

int input_one_number(int *length);
int input(int *data, int *length);
void sort(int *data, int *length);
void output(int *numbers, int *length);

int main() {
    int length = 0, *data = NULL;
    if (input_one_number(&length) == -1) return 1;
    data = malloc(sizeof(int) * length);
    if (input(data, &length) == -1) return 1;
    sort(data, &length);
    output(data, &length);

    if (data != NULL) {
        free(data);
        data = NULL;
    }
    return 0;
}

int input_one_number(int *length) {
    char c = 0;
    if (scanf("%d", length) != 1 || *length <= 0 || *length > 10) {
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

int input(int *data, int *length) {
    char c = 0;
    int counter = 0;
    for (int i = 0; i < *length; i++) {
        if (scanf("%d", &data[i]) != 1 || c == '\n' || c == '.') {
            printf("n/a\n");
            return -1;
        }
        c = getchar();
        if (c == ' ') counter++;
        if (counter > *length - 1) {
            printf("n/a\n");
            return -1;
        }
    }
    return 0;
}

void output(int *numbers, int *length) {
    for (int i = 0; i < *length; i++) {
        printf("%d", numbers[i]);
        if (i < *length - 1) printf(" ");
    }
    printf("\n");
}

void sort(int *data, int *length) {
    int temp;
    for (int i = 0; i < *length - 1; i++) {
        for (int j = 0; j <= *length - i - 2; j++) {
            if (data[j] > data[j + 1]) {
                temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}