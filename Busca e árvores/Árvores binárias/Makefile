all : main testar clean

main : main.o ab.o
	gcc main.o ab.o -lm -o main

main.o : main.c ab.h
	gcc -std=c99 -Wall -Werror -c main.c

ab.o : ab.c ab.h
	gcc -std=c99 -Wall -Werror -c ab.c

testar : main
	./main

clean :
	rm *.o
	rm main
