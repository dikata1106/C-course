# this is comment
CC=gcc
CFLAGS=-lm -pthread -fopenmp
CPPFLAGS=-lm -pthread -fopenmp
OBJS=main.o sum.o sub.o mult.o div.o  

.PHONY: all
all: hello program

hello: hello.c
	$(CC) $< -o $@

program: $(OBJS) 
	$(CC) $^ -o $@ $(CFLAGS)

%.o: %.c
	$(CC) -c $< -o $@

.PHONY: clean
clean:
	rm -rf *.o program hello