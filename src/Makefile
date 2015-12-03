CC = gcc
CFLAGS = -g -Wall -I../inc
GTKOPTION = `pkg-config --cflags --libs gtk+-3.0`
OUTPUT = ../Graph

$(OUTPUT): main.o
	$(CC) -o $(OUTPUT) main.o  $(CFLAGS) -L../lib/inter -L../lib/calc -L../lib/disp -ldisp -lcalc -linter -lm $(GTKOPTION)

main.o: main.c
	$(CC) -o main.o $(CFLAGS) -c main.c

clean:
	rm *.o $(OUTPUT)
