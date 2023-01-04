all : main testar clean

main : main.o vetor.o
	gcc main.o vetor.o -lm -o main

main.o : main.c vetor.h
	gcc -std=c99 -Wall -Werror -c main.c

vetor.o : vetor.c vetor.h
	gcc -std=c99 -Wall -Werror -c vetor.c

testar : main
	./main

clean :
	rm *.o
	rm main
