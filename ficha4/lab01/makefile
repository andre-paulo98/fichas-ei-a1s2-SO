# makefile para programa vogals_v2


CFLAGS = -std=c11 -pedantic -Wall -Wextra 

vogals_v2: main.o string_utils.o
	gcc main.o string_utils.o -o vogals_v2

main.o: main.c string_utils.h
	gcc $(CFLAGS) -c main.c

string_utils.o: string_utils.c string_utils.h
	gcc $(CFLAGS) -c string_utils.c