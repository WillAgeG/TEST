#ifndef DATA_IO_H
#define DATA_IO_H

#define EPS 1E-6
#define GOLDEN_RATIO 0.666

#endif

// Тип int = 1
// Тип double = 2
// Тип char = 3
#define any_type 2

#if any_type == 1
int input_one_number(int n);
int input_numbers_int(int *data, int n);
void output_int(int *data, int n);

int normalization_int(int *data, int n);
void sort_int(int *data, int n);
int make_decision_int(int *data, int n);
int max_int(int *data, int n);
int min_int(int *data, int n);
int mean_int(int *data, int n);
int variance_int(int *data, int n);

#elif any_type == 2
int input_one_number(int n);
int input_numbers(double *data, int n);
void output(double *data, int n);

#elif any_type == 3
int input_one_number(int n);
int input_numbers_char(char *data, int n);
void output_char(char *data, int n);

void sort_char(char *data, int n);

#else
#Нарушена работа макроса.The macro is not working properly

#endif