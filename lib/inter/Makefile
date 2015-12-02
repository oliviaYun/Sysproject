CC = gcc
CFLAGS = -g -Wall -I../../inc 
.SUFFIXES: .c .o
OUTPUT = libinter.a
$(OUTPUT): open.o close.o
	ar rv libinter.a open.o close.o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm *.o $(OUTPUT)
