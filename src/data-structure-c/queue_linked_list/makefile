CC=gcc
CFLAGS=-I.
DEPS=queue.h
OBJS=main.o queue.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)
clean:
	rm *.o main
