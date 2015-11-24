CC=g++
.c.o:
	echo rebuilding $*.o from $*.c
	$(CC) -ggdb -c $<

all: pcb

pcb: pcb.o main.o
	$(CC) -o ./pcb $^

pcb.o: pcb.cpp pcb.h
main.o: main.cpp
clean:
	rm -f *.o pcb
