all: fileTest.o
	gcc fileTest.o

fileTest.o: fileTest.c
	gcc -c fileTest.c

clear:
	rm *.o
	rm *.out

run:
	./a.out
