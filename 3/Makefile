CC=g++
.c.o:
	echo rebuilding $*.o from $*.c
	$(CC) -ggdb -c $<

all: bitmap

bitmap: bitmap.o main.o
	$(CC) -o ./bitmap $^

bitmap.o: bitmap.cpp bitmap.h
main.o: main.cpp
clean:
	rm -f *.o bitmap
