CC=g++
.c.o:
	echo rebuilding $*.o from $*.c
	$(CC) -ggdb -c $<

all: bitmap

bitmap:  main.o
	$(CC) -o ./bitmap $^

main.o: main.cpp
clean:
	rm -f *.o bitmap
