all : main testar clean

main : main.o ll.o
	gcc main.o ll.o -lm -o main

main.o : main.c ll.h
	gcc -std=c99 -Wall -Werror -c main.c

ll.o : ll.c ll.h
	gcc -std=c99 -Wall -Werror -c ll.c

testar : main
	./main

clean :
	rm *.o
	rm main
