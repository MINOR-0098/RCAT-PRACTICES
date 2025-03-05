CC = gcc
CFLAGS = -Wall -g

SOURCES = main.c add.c sub.c mul.c div.c
HEADERS = add.h sub.h mul.h div.h

calculator: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f calculator

