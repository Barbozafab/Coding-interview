all : main testar clean

main : main.o max_heap.o
	gcc main.o max_heap.o -lm -o main

main.o : main.c max_heap.h
	gcc -std=c99 -Wall -Werror -c main.c

max_heap.o : max_heap.c max_heap.h
	gcc -std=c99 -Wall -Werror -c max_heap.c

testar : main
	./main

clean :
	rm *.o
	rm main
