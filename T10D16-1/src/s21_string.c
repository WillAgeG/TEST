#include "s21_string.h"

int s21_strlen(const char* str) {
    int result = 0;
    while (*str != '\0') {
        ++result;
        ++str;
    }
    return result;
}
