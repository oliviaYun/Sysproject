CC = gcc
CFLAGS = -g -Wall -I../../inc 
.SUFFIXES: .c .o
OUTPUT = libcalc.a
$(OUTPUT): bode.o nyquist.o
	ar rv libcalc.a bode.o nyquist.o
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm *.o $(OUTPUT)
