CC=gcc
# Look at the current directory for .h file
CFLAGS=-I.
DEPS = tests.h
OBJ = tests.o main.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main *.o
