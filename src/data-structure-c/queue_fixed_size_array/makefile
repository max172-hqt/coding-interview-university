CC=gcc
DEPS=queue.h
OBJS=main.o queue.o
CFLAGS=-I.

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm *.o main
