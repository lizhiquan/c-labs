CC = gcc
CFLAGS = -ansi -pedantic -W -Wall

sort_records: main.o list.o io.o sort.o   # dependency line; format - target: prerequisites
	$(CC) $^ -o $@  # command line; $@ = target; $^ = all prereqs

main.o: main.c list.h io.h sort.h
	$(CC) $(CFLAGS) -c $<     # $< = first prereq 

io.o: io.c record.h io.h
	$(CC) $(CFLAGS) -c $<

sort.o: sort.c record.h sort.h
	$(CC) $(CFLAGS) -c $<

list.o: list.c record.h list.h
	$(CC) $(CFLAGS) -c $<
