#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void dynamic_array_print(int **A, int N, int M);
int **dynamic_array_alloc(int N, int M);
void dynamic_array_free(int **A, int N);
int **dynamic_array_init(int **A, int N, int M);

int **dynamic_array_init_life(int **A, int N, int M);
int **dynamic_array_init_life2(int **A, int N, int M);
int **dynamic_array_init_life3(int **A, int N, int M);
int **dynamic_array_init_life4(int **A);
int **dynamic_array_init_life5(int **A, int N, int M);

int **dynamic_array_move_life(int **A, int N, int M);

int check_x(int x, int M);
int check_y(int y, int N);

int main() {
    int matrix_height = 25;                                      // Высота
    int matrix_width = 80;                                       // Ширина
    char key = -1;                                               // Для getch
    int **A = dynamic_array_alloc(matrix_height, matrix_width);  // Выделение памяти
    A = dynamic_array_init(A, matrix_height, matrix_width);      // Заполнение нулями
    int speed = 131072;                                          // Скорость игры

    printf("Введите номер программы (1, 2, 3, 4, 5)\n");
    char h = getchar();
    switch (h) {
        case '1':
            A = dynamic_array_init_life(A, matrix_height, matrix_width);  // Заполнение единицами (Лодочка)
            break;
        case '2':
            A = dynamic_array_init_life2(A, matrix_height, matrix_width);
            break;
        case '3':
            A = dynamic_array_init_life3(A, matrix_height, matrix_width);
            break;
        case '4':
            A = dynamic_array_init_life4(A);
            break;
        case '5':
            A = dynamic_array_init_life5(A, matrix_height, matrix_width);
            break;
        default:
            printf("Ты ввел что-то не то");
            return 1;
    }

    while (key != 'q') {
        printf("\n Speed = %d", speed);
        dynamic_array_print(A, matrix_height, matrix_width);          // Графика
        A = dynamic_array_move_life(A, matrix_height, matrix_width);  // Физика

        initscr();
        nodelay(stdscr, TRUE);
        cbreak();
        key = getch();

        if (key == 'k') speed *= 2;
        if (key == 'l') speed /= 2;
        usleep(speed);
        nodelay(stdscr, FALSE);
        endwin();
        system("clear");
    }

    dynamic_array_free(A, matrix_height);  // Освобождение памяти
    return 0;
}

void dynamic_array_print(int **A, int N, int M) {  // Графика
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] == 0)
                printf(" ");
            else
                printf("o");
        }
        printf("\n");
    }
}

int **dynamic_array_alloc(int N, int M) {  // Выделение памяти
    int **A = (int **)malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) A[i] = (int *)malloc(M * sizeof(int));
    return A;
}

void dynamic_array_free(int **A, int N) {  // Освобождение памяти
    for (int i = 0; i < N; i++) free(A[i]);
    free(A);
}

int **dynamic_array_init(int **A, int N, int M) {  // Заполнение нулями
    int x = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++) A[i][j] = x;
    return A;
}

int **dynamic_array_init_life(int **A, int N, int M) {  // Заполнение единицами

    // Создаем лодочку
    A[N / 2][M / 2] = 1;
    A[(N / 2) + 1][(M / 2) + 1] = 1;  // При увеличении N --> 1 спускается
    A[(N / 2) + 2][(M / 2) + 1] = 1;
    A[(N / 2) + 2][(M / 2)] = 1;
    A[(N / 2) + 2][(M / 2) - 1] = 1;

    return A;
}

int **dynamic_array_init_life2(int **A, int N, int M) {
    // Создаем фигуру 2:каравай
    A[(N / 2) + 1][(M / 2) - 1] = 1;
    A[N / 2][M / 2] = 1;
    A[(N / 2)][(M / 2) + 1] = 1;
    A[(N / 2) + 1][(M / 2) + 2] = 1;
    A[(N / 2) + 2][(M / 2) + 2] = 1;
    A[(N / 2) + 2][M / 2] = 1;
    A[(N / 2) + 3][(M / 2) + 1] = 1;

    return A;
}

int **dynamic_array_init_life3(int **A, int N, int M) {
    // Создаем фигуру 3:лодка
    A[N / 2][M / 2] = 1;
    A[(N / 2) + 1][(M / 2) - 1] = 1;
    A[(N / 2) + 1][(M / 2) + 1] = 1;
    A[(N / 2) + 2][(M / 2) + 1] = 1;
    A[(N / 2) + 2][M / 2] = 1;

    return A;
}

int **dynamic_array_init_life4(int **A) {
    // Создаем фигуру 4: автомат
    A[6][2] = 1;
    A[6][3] = 1;
    A[7][2] = 1;
    A[7][3] = 1;
    A[2][26] = 1;
    A[3][26] = 1;
    A[3][24] = 1;
    A[7][24] = 1;
    A[7][26] = 1;
    A[8][26] = 1;
    A[5][13] = 1;
    A[4][14] = 1;
    A[4][15] = 1;
    A[4][22] = 1;
    A[4][23] = 1;
    A[5][22] = 1;
    A[5][23] = 1;
    A[6][22] = 1;
    A[6][23] = 1;
    A[6][12] = 1;
    A[5][17] = 1;
    A[6][18] = 1;
    A[7][18] = 1;
    A[7][19] = 1;
    A[7][16] = 1;
    A[9][17] = 1;
    A[9][13] = 1;
    A[10][14] = 1;
    A[10][15] = 1;
    A[8][18] = 1;
    A[7][12] = 1;
    A[8][12] = 1;
    A[9][13] = 1;
    A[4][36] = 1;
    A[4][37] = 1;
    A[5][36] = 1;
    A[5][37] = 1;

    return A;
}

int **dynamic_array_init_life5(int **A, int N, int M) {
    // Создаем фигуру 5:
    A[N / 2][M / 2] = 1;
    A[(N / 2) + 1][(M / 2) - 1] = 1;
    A[(N / 2) + 1][(M / 2) + 1] = 1;
    A[(N / 2) + 2][(M / 2)] = 1;
    A[(N / 2) + 2][(M / 2) + 2] = 1;
    A[(N / 2) + 3][(M / 2) + 1] = 1;
    A[(N / 2) + 3][(M / 2) + 3] = 1;
    A[(N / 2) + 4][(M / 2) + 2] = 1;
    A[(N / 2) + 4][(M / 2) + 3] = 1;
    A[(N / 2) + 4][(M / 2) + 4] = 1;

    return A;
}

int **dynamic_array_move_life(int **B, int N, int M) {  //
    int counter;
    int **A = dynamic_array_alloc(N, M);  // Создание динамической памяти для буфера

    for (int i = 0; i < N; i++)  // Заполнение буфера значениями из B
        for (int j = 0; j < M; j++) A[i][j] = B[i][j];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            counter = 0;

            if (A[check_y(i + 1, N)][check_x(j, M)] == 1) counter++;  // Проверка вокруг символов
            if (A[check_y(i + 1, N)][check_x(j + 1, M)] == 1) counter++;
            if (A[check_y(i, N)][check_x(j + 1, M)] == 1) counter++;
            if (A[check_y(i - 1, N)][check_x(j + 1, M)] == 1) counter++;
            if (A[check_y(i - 1, N)][check_x(j, M)] == 1) counter++;
            if (A[check_y(i - 1, N)][check_x(j - 1, M)] == 1) counter++;
            if (A[check_y(i, N)][check_x(j - 1, M)] == 1) counter++;
            if (A[check_y(i + 1, N)][check_x(j - 1, M)] == 1) counter++;

            if (A[i][j] == 1 && (counter == 3 || counter == 2))
                B[i][j] = 1;  // Если живой
            else
                B[i][j] = 0;

            if (A[i][j] == 0 && (counter == 3)) B[i][j] = 1;  // Если пусто
        }
    }

    dynamic_array_free(A, N);  // Освобождение памяти
    return B;
}

int check_x(int x, int M) {  // Если x больше или меньше нуля
    int result_x = x;
    if (x >= M) result_x = x - M;
    if (x < 0) result_x = x + M;
    return result_x;
}

int check_y(int y, int N) {  // Если y больше или меньше нуля
    int result_y = y;
    if (y >= N) result_y = y - N;
    if (y < 0) result_y = y + N;
    return result_y;
}
