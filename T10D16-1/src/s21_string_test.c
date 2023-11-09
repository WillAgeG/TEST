#include "s21_string_test.h"

#include <stdio.h>
#include <stdlib.h>

#include "s21_string.h"

#define mas_num 100

void s21_strlen_test() {
    FILE *f;
    
    f = fopen("tested.txt", "a");
    if (f == NULL) f = fopen("tested.txt", "w");

    char c[mas_num+2];
    if (fgets(c, 102, stdin) == NULL) {
        fprintf(f, "%s\n", c);
        fprintf(f, "0\n");
        fprintf(f, "FAIL\n");
        fprintf(f, "=-=-=-=-=-=-=\n");
    } else if (s21_strlen(c) > mas_num) {
        fprintf(f, "%s\n", c);
        fprintf(f, "%d+\n", s21_strlen(c));
        fprintf(f, "FAIL\n");
        fprintf(f, "=-=-=-=-=-=-=\n");
    } else {
        fprintf(f, "%s", c);
        fprintf(f, "%d\n", s21_strlen(c));
        fprintf(f, "SUCCESS\n");
        fprintf(f, "=-=-=-=-=-=-=\n");
    }
    fclose(f);
}