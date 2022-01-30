CC=gcc
# Look at the current directory for .h file
CFLAGS=-I.
DEPS = tests.h linkedlist.h
OBJ = main.o tests.o linkedlist.o

# $@: Left of the :
# $<: First in the dependency list (.c)
# $^: All object

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

main: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm main *.o
