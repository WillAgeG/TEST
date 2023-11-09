#include <stdio.h>
#include <stdlib.h>

struct SPoint {
    int x;
    int y;
};

typedef struct SPoint TPoint;

void ShowPoint(TPoint point) {
    printf("x = %d    y = %d\n", point.x, point.y);
}

void SetPoint(TPoint *pointPtr, int xPos, int yPos) {
    if (pointPtr != NULL) {
        (*pointPtr).x = xPos;
        (*pointPtr).y = yPos;
    }
}

int main() {
    TPoint p;
    TPoint *pPtr = NULL; // Указатель на нашу структуру. Всегда приравниваем к нулю,
                         // чтобы не занимать память попусту
    // p.x = 3;             
    // p.y = 7;
    pPtr = &p; // Теперь pPtr указывает на p

    // if (pPtr != NULL) { // Проверка есть ли у указателя, то на кого он указывает
    //     (*pPtr).x = 22; // Мы пишем в скобках *pPtr так как точка (.) имеет более высокий
    //     (*pPtr).y = 44; // приоритет чем звездочка (*)
    // }
    // // printf("x = %d    y = %d\n", p.x, p.y);

    SetPoint(&p, 11, 22); // Можно использовать &p или pPtr
    ShowPoint(p); // Передача данных по значению
    ShowPoint(*pPtr); // Передача данных по ключу (адресу) или по указателю

    return 0;
}