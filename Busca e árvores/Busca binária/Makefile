all : main testar clean

main : main.o bb.o
	gcc main.o bb.o -lm -o main

main.o : main.c bb.h
	gcc -std=c99 -Wall -Werror -c main.c

bb.o : bb.c bb.h
	gcc -std=c99 -Wall -Werror -c bb.c

testar : main
	./main

clean :
	rm *.o
	rm main
