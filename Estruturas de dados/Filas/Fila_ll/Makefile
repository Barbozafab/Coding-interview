all : main testar clean

main : main.o fila_ll.o
	gcc main.o fila_ll.o -lm -o main

main.o : main.c fila_ll.h
	gcc -std=c99 -Wall -Werror -c main.c

fila_ll.o : fila_ll.c fila_ll.h
	gcc -std=c99 -Wall -Werror -c fila_ll.c

testar : main
	./main

clean :
	rm *.o
	rm main
