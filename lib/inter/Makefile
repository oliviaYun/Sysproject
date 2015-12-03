CC = gcc
CFLAGS = -g -Wall -I../../inc 
.SUFFIXES: .c .o
OUTPUT = libinter.a
$(OUTPUT): myopen.o myclose.o
	ar rv libinter.a myopen.o myclose.o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm *.o $(OUTPUT)
