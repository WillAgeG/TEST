GCC_FLAG_ERROR = gcc -Wall -Werror -Wextra

all : data_io.o data_process.o decision.o data_stat.o main_executable_module.o
	$(GCC_FLAG_ERROR) ../../build/main_executable_module.o ../../build/data_io.o ../../build/data_process.o ../../build/decision.o ../../build/data_stat.o -lm -o ../../build/Quest_3

build_with_macro : data_io_macro.o data_process.o decision.o data_stat.o main_executable_module.o
	$(GCC_FLAG_ERROR) ../../build/main_executable_module.o ../../build/data_io_macro.o ../../build/data_process.o ../../build/decision.o ../../build/data_stat.o -lm -o ../../build/Quest_4

clean :
	rm ../../build/*.o

rebuild : clean all

main_executable_module.o : main_executable_module.c
	gcc -c main_executable_module.c -o ../../build/main_executable_module.o

data_io.o :
	gcc -c ../data_libs/data_io.c -o ../../build/data_io.o

data_process.o :
	gcc -c ../data_module/data_process.c -o ../../build/data_process.o

decision.o :
	gcc -c ../yet_another_decision_module/decision.c -o ../../build/decision.o

data_stat.o :
	gcc -c ../data_libs/data_stat.c -o ../../build/data_stat.o

data_io_macro.o :
	gcc -c ../data_libs/data_io_macro.c -o ../../build/data_io_macro.o

