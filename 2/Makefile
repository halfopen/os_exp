CC=g++
.c.o:
	echo rebuilding $*.o from $*.c
	$(CC) -ggdb -c $<

all: mem

mem: mem.o main.o
	$(CC) -o ./mem $^

mem.o: mem.cpp mem.h
main.o: main.cpp
clean:
	rm -f *.o mem
