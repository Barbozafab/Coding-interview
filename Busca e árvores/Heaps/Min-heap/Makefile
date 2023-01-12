all : main testar clean

main : main.o min_heap.o
	gcc main.o min_heap.o -lm -o main

main.o : main.c min_heap.h
	gcc -std=c99 -Wall -Werror -c main.c

min_heap.o : min_heap.c min_heap.h
	gcc -std=c99 -Wall -Werror -c min_heap.c

testar : main
	./main

clean :
	rm *.o
	rm main
