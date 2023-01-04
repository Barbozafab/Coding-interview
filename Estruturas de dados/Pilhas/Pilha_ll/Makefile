all : main testar clean

main : main.o pilha_ll.o
	gcc main.o pilha_ll.o -lm -o main

main.o : main.c pilha_ll.h
	gcc -std=c99 -Wall -Werror -c main.c

pilha_ll.o : pilha_ll.c pilha_ll.h
	gcc -std=c99 -Wall -Werror -c pilha_ll.c

testar : main
	./main

clean :
	rm *.o
	rm main
