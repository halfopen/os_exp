CC=g++
.c.o:
	echo rebuilding $*.o from $*.c
	$(CC) -ggdb -c $<

all: disc

disc: disc.o main.o
	$(CC) -o ./disc $^

disc.o: disc.cpp disc.h
main.o: main.cpp
clean:
	rm -f *.o disc
