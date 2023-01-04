all : main

main : main.o pilha_v.o
	gcc main.o pilha_v.o -lm -o main

main.o : main.c pilha_v.h
	gcc -std=c99 -Wall -Werror -c main.c

pilha_v.o : pilha_v.c pilha_v.h
	gcc -std=c99 -Wall -Werror -c pilha_v.c