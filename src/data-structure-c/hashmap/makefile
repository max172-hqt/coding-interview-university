CC=gcc
CFLAGS=-I.
DEPS=hashmap.h
OBJS=main.o hashmap.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main *.o
