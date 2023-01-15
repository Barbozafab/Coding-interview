all : main testar clean

main : main.o ordenacao.o
	gcc main.o ordenacao.o -lm -o main

main.o : main.c ordenacao.h
	gcc -std=c99 -Wall -Werror -c main.c

ordenacao.o : ordenacao.c ordenacao.h
	gcc -std=c99 -Wall -Werror -c ordenacao.c

testar : main
	./main

clean :
	rm *.o
	rm main
