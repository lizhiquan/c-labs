CC = gcc
CFLAGS = -ansi -pedantic -W -Wall

lab12: main.o list.o io.o
	$(CC) $^ -o $@

main.o: main.c list.h io.h
	$(CC) $(CFLAGS) -c $<

io.o: io.c record.h io.h
	$(CC) $(CFLAGS) -c $<

list.o: list.c record.h list.h
	$(CC) $(CFLAGS) -c $<
