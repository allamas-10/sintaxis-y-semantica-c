CC     = gcc
CFLAGS = -Wall -std=gnu11

calc: main.o parser.o scanner.o calc.o
	$(CC) $(CFLAGS) -o calc main.o parser.o scanner.o calc.o -lm

parser.c parser.h: parser.y
	bison parser.y

scanner.c scanner.h: scanner.l
	flex scanner.l

main.o: main.c parser.h
	$(CC) $(CFLAGS) -c main.c

parser.o: parser.c parser.h calc.h
	$(CC) $(CFLAGS) -c parser.c

scanner.o: scanner.c parser.h
	$(CC) $(CFLAGS) -c scanner.c

calc.o: calc.c calc.h
	$(CC) $(CFLAGS) -c calc.c

clean:
	rm -f calc calc.exe *.o parser.c parser.h scanner.c scanner.h
