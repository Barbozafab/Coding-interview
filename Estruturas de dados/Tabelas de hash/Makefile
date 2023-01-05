all : main testar clean

main : main.o hash.o
	gcc main.o hash.o -lm -o main

main.o : main.c hash.h
	gcc -std=c99 -Wall -Werror -c main.c

hash.o : hash.c hash.h
	gcc -std=c99 -Wall -Werror -c hash.c

testar : main
	./main

clean :
	rm *.o
	rm main
