CC = gcc
CFLAGS = -Wall -Wextra -std=c23

LIB_OBJS = Strings.o

PROGRAMS = enlineas.exe longitudes.exe mayorlongitud.exe todosiguales.exe suma.exe StringsTest.exe

all: $(PROGRAMS)

test: StringsTest.exe
		./StringsTest.exe

%.exe: %.o $(LIB_OBJS)
		$(CC) $(CFLAGS) $^ -o $@

%.o: %.c Strings.h
		$(CC) $(CFLAGS) -c $<

clean:
		del /f /q *.o $(PROGRAMS)