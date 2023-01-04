all : main

main : main.o fila_v.o
	gcc main.o fila_v.o -lm -o main

main.o : main.c fila_v.h
	gcc -std=c99 -Wall -Werror -c main.c

fila_v.o : fila_v.c fila_v.h
	gcc -std=c99 -Wall -Werror -c fila_v.c