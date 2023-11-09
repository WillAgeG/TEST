/*------------------------------------
                                Здравствуй, человек!
                                Чтобы получить ключ
                                поработай с комментариями.
-------------------------------------*/

#include <stdio.h>

void input(int *buffer, int *length);
void output(int *buffer, int length, int sum_num);
int sum_numbers(int *buffer, int length);
int find_numbers(int *buffer, int length, int number, int *numbers);

/*------------------------------------
                                Функция получает массив данных
                                через stdin.
                                Выдает в stdout особую сумму
                                и сформированный массив
                                специальных элементов
                                (выбранных с помощью найденной суммы):
                                это и будет частью ключа
-------------------------------------*/

int main() {
    int length, data[10];
    int number = 0;

    input(data, &length);
    int sum = sum_numbers(data, length);
    int f_n = find_numbers(data, length, number, &sum);
    output(data, f_n, sum);
    return 0;
}

void input(int *a, int *n) {
    int counter = 0;
    if (scanf("%d", n) != 1) {
        printf("n/a\n");
        *n = 0;
    } else {
        // char c1 = getchar();
        // if (c1 = ' ') {
        //     printf("n/a\n");
        //     *n = 0;
        // }
        for (int *p = a; p - a < *n; p++) {
            if (scanf("%d", p) != 1) {
                printf("n/a\n");
                *n = 0;
                break;
            }
            char c2 = getchar();
            if (c2 == '\n' && counter < *n - 1) {
                printf("n/a\n");
                *n = 0;
                break;
            }
            if (c2 == ' ') counter++;
            if (counter > *n - 1) {
                printf("n/a\n");
                *n = 0;
                break;
            }
        }
    }
}

void output(int *buffer, int length, int sum_num) {
    printf("%d\n", sum_num);
    for (int i = 0; i < length; i++) {
        printf("%d", buffer[i]);
        if (i < length - 1) printf(" ");
    }
}

/*------------------------------------
                                Функция должна находить
                                сумму четных элементов
                                с 0-й позиции.
-------------------------------------*/
int sum_numbers(int *buffer, int length) {
    int sum = 0;

    for (int i = 0; i < length; i++) {
        if (buffer[i] % 2 == 0) {
            sum = sum + buffer[i];
        }
    }
    return sum;
}

/*------------------------------------
                                Функция должна находить
                                все элементы, на которые нацело
                                делится переданное число и
                                записывает их в выходной массив.
-------------------------------------*/
int find_numbers(int *buffer, int length, int number, int *numbers) {
    for (int i = 0; i < length; i++) {
        if (buffer[i] == 0) continue;
        if (*numbers % buffer[i] == 0) {
            buffer[number] = buffer[i];
            number++;
        }
    }
    return number;
}
