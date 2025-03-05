CC = gcc
CFLAGS = -Wall -g

# wildcards to find all .c and .h files in the current directory
SOURCES := $(wildcard *.c)
HEADERS := $(wildcard *.h)

calculator: $(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -f calculator
