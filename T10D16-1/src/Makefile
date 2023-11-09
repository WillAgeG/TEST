GCC_FLAG_ERROR = gcc -Wall -Werror -Wextra

all : s21_string_test.o s21_string.o main.o
	$(GCC_FLAG_ERROR) main.o s21_string.o s21_string_test.o -o ../build/Quest_1

rebuild : clean all

clean :
	rm *.o
strlen_tests : s21_string_test.o s21_string.o main.o
	$(GCC_FLAG_ERROR) main.o s21_string.o s21_string_test.o -o ../build/Quest_1
s21_string_test.o :
	gcc -c s21_string_test.c -o s21_string_test.o

s21_string.o :
	gcc -c s21_string.c -o s21_string.o

main.o :
	gcc -c main.c -o main.o
