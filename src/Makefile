CC = gcc
CFLAGS = -g -Wall -I../inc
OUTPUT = ../Graph

$(OUTPUT): main.o
	$(CC) -o $(OUTPUT) main.o  $(CFLAGS) -L../lib/inter -L../lib/calc -lcalc -linter -lm

main.o: main.c
	$(CC) -o main.o $(CFLAGS) -c main.c

clean:
	rm *.o $(OUTPUT)
