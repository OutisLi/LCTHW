CC=gcc

CFLAGS=-Wall -g

all:ex1

ex1:ex1.o
	$(CC) $(CFLAGS) ex1.o -o ex1

ex1.o:ex1.c
	$(CC) $(CFLAGS) -c ex1.c -o ex1.o

clean:
	rm -f ex1 ex1.o
.PHONY: all clean
