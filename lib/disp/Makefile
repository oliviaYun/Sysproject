CC = gcc
GTKOPTION =`pkg-config --cflags --libs gtk+-3.0` 
CFLAGS = -g -Wall -I../../inc
OUTPUT = libdisp.a
FUNC = callshell.o Nyquistgtk.o gtk2.o
$(OUTPUT): $(FUNC)
	ar rv $(OUTPUT) $(FUNC)

callshell.o: callshell.c
	$(CC) -c $(CFLAGS) -o callshell.o callshell.c

Nyquistgtk.o: Nyquistgtk.c
	$(CC)  -c $(GTKOPTION)  $(CFLAGS) -o Nyquistgtk.o Nyquistgtk.c

gtk2.o: gtk2.c
	$(CC)  -c $(GTKOPTION) $(CFLAGS) -o gtk2.o gtk2.c
clean:
	rm *.o $(OUTPUT)

