all : main testar clean

main : main.o abb.o
	gcc main.o abb.o -lm -o main

main.o : main.c abb.h
	gcc -std=c99 -Wall -Werror -c main.c

abb.o : abb.c abb.h
	gcc -std=c99 -Wall -Werror -c abb.c

testar : main
	./main

clean :
	rm *.o
	rm main
